BeginPackage["Z3`Utils`"]

mkContext

mkContextCustom

mkSolver

delSolver

mkVar

mkBoolVar

mkInt

mkIntVar

check

check2

mkUnaryApp

prove

fprintf

stdout

printf

unreachable

mkBinaryApp

assertRetractableCnstr

mkExtContext

retractCnstr

extCheck

delExtContext

exitf

mkRealVar

mkTupleUpdate

assertCommAxiom

mkProofContext

reassertCnstr

Begin["`Private`"]

Needs["Z3`Display`"]
Needs["Z3`Library`"]



unreachable[] := printf["unreachable code was reached\n"]

unreachable[args___] := Throw[Failure["Unhandled", <| "Function" -> unreachable, "Arguments" -> {args} |>], "Unhandled"]


fprintf[stdout, fmt_String, params___] := printf[fmt, params]

fprintf[args___String] := Throw[Failure["Unhandled", <| "Function" -> fprintf, "Arguments" -> {args} |>], "Unhandled"]

printf[fmt_String, params___] :=
Module[{counter, s},
  counter = 0;
  s = ToString[StringForm[StringReplace[fmt, RegularExpression["%."] :> (counter++; "`" <> ToString[counter] <> "`")], params], StandardForm];

  (*
  work-around String functions leaking Module variables
  *)
  Remove[counter];

  WriteString[$Output, s]
]

printf[args___] := Throw[Failure["Unhandled", <| "Function" -> printf, "Arguments" -> {args} |>], "Unhandled"]



mkContext[] :=
Module[{cfg, err, ctx},
  cfg = Z3mkConfig[];
  err = getGlobalErrorHandler[];
  ctx = mkContextCustom[cfg, err];
  Z3delConfig[cfg];
  ctx
]

mkContext[args___] := Throw[Failure["Unhandled", <| "Function" -> mkContext, "Arguments" -> {args} |>], "Unhandled"]


mkContextCustom[cfg_, err_] :=
Module[{ctx},
  Z3setParamValue[cfg, "model", "true"];
  ctx = Z3mkContext[cfg];
  Z3setErrorHandler[ctx, err];
  ctx
]

mkContextCustom[args___] := Throw[Failure["Unhandled", <| "Function" -> mkContextCustom, "Arguments" -> {args} |>], "Unhandled"]


mkSolver[ctx_] :=
Module[{s},
  s = Z3mkSolver[ctx];
  Z3solverIncRef[ctx, s];
  s
]

mkSolver[args___] := Throw[Failure["Unhandled", <| "Function" -> mkSolver, "Arguments" -> {args} |>], "Unhandled"]


delSolver[ctx_, s_] :=
Module[{},
  Z3solverDecRef[ctx, s]
]

delSolver[args___] := Throw[Failure["Unhandled", <| "Function" -> delSolver, "Arguments" -> {args} |>], "Unhandled"]


mkVar[ctx_, name_, ty_] :=
Module[{s},
  s = Z3mkStringSymbol[ctx, name];
  Z3mkConst[ctx, s, ty]
]

mkVar[args___] := Throw[Failure["Unhandled", <| "Function" -> mkVar, "Arguments" -> {args} |>], "Unhandled"]


mkBoolVar[ctx_, name_] :=
Module[{ty},
  ty = Z3mkBoolSort[ctx];
  mkVar[ctx, name, ty]
]

mkBoolVar[args___] := Throw[Failure["Unhandled", <| "Function" -> mkBoolVar, "Arguments" -> {args} |>], "Unhandled"]


mkInt[ctx_, v_] :=
Module[{ty},
  ty = Z3mkIntSort[ctx];
  Z3mkInt[ctx, v, ty]
]

mkInt[args___] := Throw[Failure["Unhandled", <| "Function" -> mkInt, "Arguments" -> {args} |>], "Unhandled"]


mkIntVar[ctx_, name_] :=
Module[{ty},
  ty = Z3mkIntSort[ctx];
  mkVar[ctx, name, ty]
]

mkIntVar[args___] := Throw[Failure["Unhandled", <| "Function" -> mkIntVar, "Arguments" -> {args} |>], "Unhandled"]


check[ctx_, s_, expectedResult_] :=
Module[{m, result},
  m = 0;
  result = Z3solverCheck[ctx, s];
  Switch[result,
    Z3ULUFALSE,
      printf["unsat\n"]
    ,
    Z3ULUUNDEF,
      printf["unknown\n"];
      m = Z3solverGetModel[ctx, s];
      If[m != 0,
        Z3modelIncRef[ctx, m]
      ];
      printf["potential model:\n%s\n", Z3modelToString[ctx, m]];
    ,
    Z3ULUTRUE,
      m = Z3solverGetModel[ctx, s];
      If[m != 0,
        Z3modelIncRef[ctx, m]
      ];
      printf["sat\n%s\n", Z3modelToString[ctx, m]];
    ,
    _,
      unreachable[]
  ];
  If[result != expectedResult,
    exitf["unexpected result"];
  ];
  If[m != 0,
    Z3modelDecRef[ctx, m];
  ]
]

check[args___] := Throw[Failure["Unhandled", <| "Function" -> check, "Arguments" -> {args} |>], "Unhandled"]


check2[ctx_, s_, expectedResult_] :=
Module[{m, result},
  m = 0;
  result = Z3solverCheck[ctx, s];
  Switch[result,
    Z3ULUFALSE,
      printf["unsat\n"];
    ,
    Z3ULUUNDEF,
      printf["unknown\n"];
      printf["potential model:\n"];
      m = Z3solverGetModel[ctx, s];
      If[m != 0,
        Z3modelIncRef[ctx, m];
      ];
      displayModel[ctx, stdout, m];
    ,
    Z3ULUTRUE,
      printf["sat\n"];
      m = Z3solverGetModel[ctx, s];
      If[m != 0,
        Z3modelIncRef[ctx, m];
      ];
      displayModel[ctx, stdout, m];
    ,
    _,
      unreachable[]
  ];
  If[result != expectedResult,
    printf["unexpected result"];
  ];
  If[m != 0,
    Z3modelDecRef[ctx, m];
  ]
]

check2[args___] := Throw[Failure["Unhandled", <| "Function" -> check2, "Arguments" -> {args} |>], "Unhandled"]


mkUnaryApp[ctx_, f_, x_] :=
Module[{args},
  args = {x};
  Z3mkApp[ctx, f, 1, args]
]

mkUnaryApp[args___] := Throw[Failure["Unhandled", <| "Function" -> mkUnaryApp, "Arguments" -> {args} |>], "Unhandled"]



prove[ctx_, s_, f_, isValid_] :=
Module[{m, notF},
  m = 0;

  (* save the current state of the context *)
  Z3solverPush[ctx, s];

  notF = Z3mkNot[ctx, f];
  Z3solverAssert[ctx, s, notF];

  Switch[Z3solverCheck[ctx, s],
    Z3ULUFALSE,
      (* proved *)
      printf["valid\n"];
      If[!isValid,
        exitf["unexpected result"];
      ]
    ,
    Z3ULUUNDEF,
      (* Z3 failed to prove/disprove f. *)
      printf["unknown\n"];
      m = Z3solverGetModel[ctx, s];
      If[m != 0,
        Z3modelIncRef[ctx, m];
        (* m should be viewed as a potential counterexample. *)
        printf["potential counterexample:\n%s\n", Z3modelToString[ctx, m]];
      ];
      If[isValid,
        exitf["unexpected result"];
      ]
    ,
    Z3ULUTRUE,
      (* disproved *)
      printf["invalid\n"];
      m = Z3solverGetModel[ctx, s];
      If[m != 0,
        Z3modelIncRef[ctx, m];
        (* the model returned by Z3 is a counterexample *)
        printf["counterexample:\n%s\n", Z3modelToString[ctx, m]];
      ];
      If[isValid,
        exitf["unexpected result"];
      ]
    ,
    _,
      unreachable[]
  ];

  If[m != 0,
    Z3modelDecRef[ctx, m];
  ];
  (* restore scope *)
  Z3solverPop[ctx, s, 1];
]

prove[args___] := Throw[Failure["Unhandled", <| "Function" -> prove, "Arguments" -> {args} |>], "Unhandled"]


mkBinaryApp[ctx_, f_, x_, y_] :=
Module[{args},
  args = {x, y};
  Z3mkApp[ctx, f, 2, args]
]

mkBinaryApp[args___] := Throw[Failure["Unhandled", <| "Function" -> mkBinaryApp, "Arguments" -> {args} |>], "Unhandled"]


assertRetractableCnstr[args___] := Throw[Failure["Unhandled", <| "Function" -> assertRetractableCnstr, "Arguments" -> {args} |>], "Unhandled"]

mkExtContext[args___] := Throw[Failure["Unhandled", <| "Function" -> mkExtContext, "Arguments" -> {args} |>], "Unhandled"]

retractCnstr[args___] := Throw[Failure["Unhandled", <| "Function" -> retractCnstr, "Arguments" -> {args} |>], "Unhandled"]

extCheck[args___] := Throw[Failure["Unhandled", <| "Function" -> extCheck, "Arguments" -> {args} |>], "Unhandled"]

delExtContext[args___] := Throw[Failure["Unhandled", <| "Function" -> delExtContext, "Arguments" -> {args} |>], "Unhandled"]


exitf[msg_] := Print[msg]

exitf[args___] := Throw[Failure["Unhandled", <| "Function" -> exitf, "Arguments" -> {args} |>], "Unhandled"]


mkRealVar[ctx_, name_] :=
Module[{ty},
  ty = Z3mkRealSort[ctx];
  mkVar[ctx, name, ty]
]

mkRealVar[args___] := Throw[Failure["Unhandled", <| "Function" -> mkRealVar, "Arguments" -> {args} |>], "Unhandled"]



mkTupleUpdate[c_, t_, i_, newVal_] :=
Module[{ty, numFields, newFields, projDecl, mkTupleDecl, result},

  ty = Z3getSort[c, t];

  If[Z3getSortKind[c, ty] != Z3UDATATYPEUSORT,
    exitf["argument must be a tuple"];
  ];

  numFields = Z3getTupleSortNumFields[c, ty];

  If[i >= numFields,
    exitf["invalid tuple update, index is too big"];
  ];

  newFields = Table[
    If[i == j,
      newVal
      ,
      projDecl = Z3getTupleSortFieldDecl[c, ty, j];
      mkUnaryApp[c, projDecl, t]
    ]
    ,
    {j, 0, numFields-1}
  ];
  mkTupleDecl = Z3getTupleSortMkDecl[c, ty];
  result = Z3mkApp[c, mkTupleDecl, numFields, newFields];
  result
]

mkTupleUpdate[args___] := Throw[Failure["Unhandled", <| "Function" -> mkTupleUpdate, "Arguments" -> {args} |>], "Unhandled"]


assertCommAxiom[args___] := Throw[Failure["Unhandled", <| "Function" -> assertCommAxiom, "Arguments" -> {args} |>], "Unhandled"]

mkProofContext[args___] := Throw[Failure["Unhandled", <| "Function" -> mkProofContext, "Arguments" -> {args} |>], "Unhandled"]

reassertCnstr[args___] := Throw[Failure["Unhandled", <| "Function" -> reassertCnstr, "Arguments" -> {args} |>], "Unhandled"]

End[]

EndPackage[]
