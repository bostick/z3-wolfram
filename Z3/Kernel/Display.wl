
BeginPackage["Z3`Display`"]

displayModel

displayAst

displayFunctionInterpretations

displaySort

displaySymbol

Begin["`Private`"]


Needs["Z3`Library`"]
Needs["Z3`Utils`"]


displayModel[ctx_, out_, m_] :=
Catch[
Module[{numConstants, cnst, name, a, v, vPtr, ok},

  If[m == 0,
    Throw[Null]
  ];

  numConstants = Z3modelGetNumConsts[ctx, m];
  Do[
    cnst = Z3modelGetConstDecl[ctx, m, i];
    name = Z3getDeclName[ctx, cnst];
    displaySymbol[ctx, out, name];
    fprintf[out, " = "];
    a = Z3mkApp[ctx, cnst, 0, {}];
    v = a;
    vPtr = astMalloc[1];
    astSet[vPtr, 0, v];
    ok = Z3modelEval[ctx, m, a, True, vPtr];
    displayAst[ctx, out, v];
    astFree[vPtr];
    fprintf[out, "\n"];
    ,
    {i, 0, numConstants-1}
  ];

  displayFunctionInterpretations[ctx, out, m];
]]

displayModel[args___] := Throw[Failure["Unhandled", <| "Function" -> displayModel, "Arguments" -> {args} |>], "Unhandled"]



displayAst[ctx_, out_, v_] :=
Module[{t, app, numFields, d},
	Switch[Z3getAstKind[ctx, v],
	  Z3UNUMERALUAST,
      fprintf[out, Z3getNumeralString[ctx, v]];
      t = Z3getSort[ctx, v];
      fprintf[out, ":"];
      displaySort[ctx, out, t];
	  ,
	  Z3UAPPUAST,
      app = Z3toApp[ctx, v];
      numFields = Z3getAppNumArgs[ctx, app];
      d = Z3getAppDecl[ctx, app];
      fprintf[out, Z3funcDeclToString[ctx, d]];
      If[numFields > 0,
        fprintf[out, "["];
        Do[
          If[i > 0,
              fprintf[out, ", "];
          ];
          displayAst[ctx, out, Z3getAppArg[ctx, app, i]];
          ,
          {i, 0, numFields}
        ];
        fprintf[out, "]"];
      ]
	  ,
	  Z3UQUANTIFIERUAST,
      fprintf[out, "quantifier"];
	  ,
	  _,
      fprintf[out, "#unknown"];
	]
]

displayAst[args___] := Throw[Failure["Unhandled", <| "Function" -> displayAst, "Arguments" -> {args} |>], "Unhandled"]


displayFunctionInterpretations[ctx_, out_, m_] :=
Module[{numFunctions, numEntries, fdecl, finterp, name, fentry, numArgs, funcElse},

    fprintf[out, "function interpretations:\n"];

    numFunctions = Z3modelGetNumFuncs[ctx, m];
    Do[
	    numEntries = 0;

	    fdecl = Z3modelGetFuncDecl[ctx, m, i];
	    finterp = Z3modelGetFuncInterp[ctx, m, fdecl];
	    Z3funcInterpIncRef[ctx, finterp];
	    name = Z3getDeclName[ctx, fdecl];
	    displaySymbol[ctx, out, name];
	    fprintf[out, " = {"];
	    If[finterp != 0,
	      numEntries = Z3funcInterpGetNumEntries[ctx, finterp];
	    ];
	    Do[
	      fentry = Z3funcInterpGetEntry[ctx, finterp, j];
	      Z3funcEntryIncRef[ctx, fentry];
	      If[j > 0,
	      	fprintf[out, ", "];
	      ];
	      numArgs = Z3funcEntryGetNumArgs[ctx, fentry];
	      fprintf[out, "("];
	      Do[
	        If[k > 0,
	            fprintf[out, ", "];
	        ];
	        displayAst[ctx, out, Z3funcEntryGetArg[ctx, fentry, k]];
	        ,
	        {k, 0, numArgs}
	      ];
	      fprintf[out, "|->"];
	      displayAst[ctx, out, Z3funcEntryGetValue[ctx, fentry]];
	      fprintf[out, ")"];
	      Z3funcEntryDecRef[ctx, fentry];
	      ,
	      {j, 0, numEntries-1}
	    ];
	    If[numEntries > 0,
	    	fprintf[out, ", "];
	    ];
	    fprintf[out, "(else|->"];
	    funcElse = Z3funcInterpGetElse[ctx, finterp];
	    displayAst[ctx, out, funcElse];
	    fprintf[out, ")}\n"];
	    Z3funcInterpDecRef[ctx, finterp];
	    ,
	    {i, 0, numFunctions-1}
    ]
]

displayFunctionInterpretations[args___] := Throw[Failure["Unhandled", <| "Function" -> displayFunctionInterpretations, "Arguments" -> {args} |>], "Unhandled"]



displaySort[ctx_, out_, ty_] :=
Module[{numFields, field},
  Switch[Z3getSortKind[ctx, ty],
    Z3UUNINTERPRETEDUSORT,
      displaySymbol[ctx, out, Z3getSortName[ctx, ty]];
    ,
    Z3UBOOLUSORT,
      fprintf[out, "bool"];
    ,
    Z3UINTUSORT,
      fprintf[out, "int"];
    ,
    Z3UREALUSORT,
      fprintf[out, "real"];
    ,
    Z3UBVUSORT,
      fprintf[out, "bv%d", Z3getBvSortSize[ctx, ty]];
    ,
    Z3UARRAYUSORT,
      fprintf[out, "["];
      displaySort[ctx, out, Z3getArraySortDomain[ctx, ty]];
      fprintf[out, "->"];
      displaySort[ctx, out, Z3getArraySortRange[ctx, ty]];
      fprintf[out, "]"];
    ,
    Z3UDATATYPEUSORT,
      If[Z3getDatatypeSortNumConstructors[ctx, ty] != 1,
        fprintf[out, "%s", Z3sortToString[ctx,ty]];
      	,
        numFields = Z3getTupleSortNumFields[ctx, ty];
        fprintf[out, "("];
        Do[
	        field = Z3getTupleSortFieldDecl[ctx, ty, i];
	        If[i > 0,
	          fprintf[out, ", "];
	        ];
	        displaySort[ctx, out, Z3getRange[ctx, field]];
	        ,
	        {i, 0, numFields-1}
        ];
        fprintf[out, ")"];
    	]
    ,
    _,
      fprintf[out, "unknown["];
      displaySymbol[ctx, out, Z3getSortName[ctx, ty]];
      fprintf[out, "]"];
  ]
]

displaySort[args___] := Throw[Failure["Unhandled", <| "Function" -> displaySort, "Arguments" -> {args} |>], "Unhandled"]



displaySymbol[ctx_, out_, s_] :=
Module[{},
  Switch[Z3getSymbolKind[ctx, s],
	  Z3UINTUSYMBOL,
      fprintf[out, "#%d", Z3getSymbolInt[ctx, s]];
     ,
	  Z3USTRINGUSYMBOL,
      fprintf[out, "%s", Z3getSymbolString[ctx, s]];
    ,
	  _,
	    unreachable[];
  ]
]

displaySymbol[args___] := Throw[Failure["Unhandled", <| "Function" -> displaySymbol, "Arguments" -> {args} |>], "Unhandled"]



End[]

EndPackage[]
