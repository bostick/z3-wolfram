BeginPackage["Z3`Library`"]

setupLibraries

loadAllFuncs

libraryFunctionWrapper


(*
library functions calling INTO lib
*)

astMalloc
astFree
astSet
astGet

funcDeclMalloc
funcDeclFree
funcDeclSet
funcDeclGet

constructorMalloc
constructorFree
constructorSet
constructorGet


getGlobalErrorHandler
getGlobalErrorCode

Z3setErrorHandler



Z3mkConfig
Z3delConfig

Z3mkContext
Z3delContext

Z3mkBoolSort
Z3mkIntSort
Z3mkUninterpretedSort

Z3mkInt
Z3mkIntSymbol

Z3mkConst
Z3mkNot
Z3mkAnd
Z3mkOr
Z3mkIff
Z3mkAdd
Z3mkSub
Z3mkLt
Z3mkGt
Z3mkEq
Z3mkLe
Z3mkGe

Z3mkFuncDecl

Z3solverAssert
Z3solverCheck

Z3mkXor

Z3mkSolver
Z3solverDecRef
Z3solverIncRef

Z3mkStringSymbol

Z3modelToString

Z3solverGetModel
Z3modelDecRef
Z3modelIncRef


Z3solverPush
Z3solverPop

Z3mkApp

Z3setParamValue

Z3mkNumeral

Z3solverGetNumScopes




Z3funcDeclToString
Z3funcEntryDecRef
Z3funcEntryGetArg
Z3funcEntryGetNumArgs
Z3funcEntryGetValue
Z3funcEntryIncRef
Z3funcInterpDecRef
Z3funcInterpGetElse
Z3funcInterpGetEntry
Z3funcInterpGetNumEntries
Z3funcInterpIncRef
Z3getAppArg
Z3getAppDecl
Z3getAppNumArgs
Z3getAstKind
Z3getDeclName
Z3getNumeralString
Z3getSort
Z3modelEval
Z3modelGetConstDecl
Z3modelGetFuncDecl
Z3modelGetFuncInterp
Z3modelGetNumConsts
Z3modelGetNumFuncs
Z3toApp



Z3getArraySortDomain
Z3getArraySortRange
Z3getBvSortSize
Z3getDatatypeSortNumConstructors
Z3getRange
Z3getSortKind
Z3getSortName
Z3getSymbolInt
Z3getSymbolKind
Z3getSymbolString
Z3getTupleSortFieldDecl
Z3getTupleSortNumFields
Z3sortToString



Z3globalParamSet
Z3solverGetReasonUnknown
Z3globalParamResetAll
Z3mkArraySort
Z3mkStore
Z3mkSelect
Z3mkImplies
Z3astToString
Z3mkDistinct
Z3mkRealSort
Z3mkTupleSort
Z3mkBvSort
Z3mkBvsub
Z3mkBvsle
Z3mkBvxor
Z3mkBvmul
Z3getErrorCode
Z3getErrorMsg
Z3parseSmtlib2String
Z3astVectorToString
Z3astVectorSize
Z3astVectorGet
Z3astVectorToString
Z3mkFalse
Z3mkIte
Z3mkEnumerationSort
Z3mkListSort
Z3mkConstructor
Z3mkDatatype


Z3astVectorDecRef
Z3getNumeralInt
Z3modelHasInterp
Z3funcDeclToAst
Z3addConstInterp




Z3mkAsArray
Z3funcInterpAddEntry
Z3astVectorPush
Z3astVectorIncRef
Z3mkAstVector
Z3mkFreshFuncDecl
Z3mkFpaToFpReal
Z3mkFpaToFpIntReal
Z3mkFpaToFpBv
Z3mkFpaFp
Z3mkFpaSort
Z3mkFpaIsZero
Z3mkFpaIsNan
Z3mkFpaIsInfinite
Z3mkFpaRtz
Z3mkFpaAdd
Z3mkFpaNumeralDouble
Z3mkFpaRoundingModeSort
Z3substituteVars
Z3mkBound
Z3substitute
Z3decRef
Z3sortToAst
Z3incRef
Z3mkContextRc
Z3solverGetProof
Z3solverGetUnsatCore
Z3solverCheckAssumptions
Z3delConstructor
Z3queryConstructor
Z3delConstructorList
Z3mkDatatypes
Z3mkConstructorList

Z3mkModel
Z3addFuncInterp

Z3getTupleSortMkDecl












(*
constants

z3_api.h
*)
Z3ULUFALSE
Z3ULUUNDEF
Z3ULUTRUE


Z3UOK
Z3USORTUERROR
Z3UIOB
Z3UINVALIDUARG
Z3UPARSERUERROR
Z3UNOUPARSER
Z3UINVALIDUPATTERN
Z3UMEMOUTUFAIL
Z3UFILEUACCESSUERROR
Z3UINTERNALUFATAL
Z3UINVALIDUUSAGE
Z3UDECUREFUERROR
Z3UEXCEPTION



Z3UNUMERALUAST 
Z3UAPPUAST
Z3UVARUAST
Z3UQUANTIFIERUAST
Z3USORTUAST
Z3UFUNCUDECLUAST
Z3UUNKNOWNUAST



Z3UUNINTERPRETEDUSORT
Z3UBOOLUSORT
Z3UINTUSORT
Z3UREALUSORT
Z3UBVUSORT
Z3UARRAYUSORT
Z3UDATATYPEUSORT
Z3URELATIONUSORT
Z3UFINITEUDOMAINUSORT
Z3UFLOATINGUPOINTUSORT
Z3UROUNDINGUMODEUSORT
Z3USEQUSORT
Z3UREUSORT
Z3UCHARUSORT
Z3UUNKNOWNUSORT


Z3UINTUSYMBOL
Z3USTRINGUSYMBOL



Begin["`Private`"]

Needs["Z3`"]
Needs["PacletManager`"] (* for PacletInformation *)


(*
constants

z3_api.h
*)
Z3ULUFALSE = -1
Z3ULUUNDEF = 0
Z3ULUTRUE = 1


(*
Z3_error_code

z3_api.h
*)
Z3UOK = 0
Z3USORTUERROR = 1
Z3UIOB = 2
Z3UINVALIDUARG = 3
Z3UPARSERUERROR = 4
Z3UNOUPARSER = 5
Z3UINVALIDUPATTERN = 6
Z3UMEMOUTUFAIL = 7
Z3UFILEUACCESSUERROR = 8
Z3UINTERNALUFATAL = 9
Z3UINVALIDUUSAGE = 10
Z3UDECUREFUERROR = 11
Z3UEXCEPTION = 12



Z3UNUMERALUAST = 0
Z3UAPPUAST = 1
Z3UVARUAST = 2
Z3UQUANTIFIERUAST = 3
Z3USORTUAST = 4
Z3UFUNCUDECLUAST = 5
Z3UUNKNOWNUAST = 1000



Z3UUNINTERPRETEDUSORT = 0
Z3UBOOLUSORT = 1
Z3UINTUSORT = 2
Z3UREALUSORT = 3
Z3UBVUSORT = 4
Z3UARRAYUSORT = 5
Z3UDATATYPEUSORT = 6
Z3URELATIONUSORT = 7
Z3UFINITEUDOMAINUSORT = 8
Z3UFLOATINGUPOINTUSORT = 9
Z3UROUNDINGUMODEUSORT = 10
Z3USEQUSORT = 11
Z3UREUSORT = 12
Z3UCHARUSORT = 13
Z3UUNKNOWNUSORT = 1000



Z3UINTUSYMBOL = 0
Z3USTRINGUSYMBOL = 1




$Z3WolframLib := $Z3WolframLib =
Catch[
Module[{res},
	res = FindLibrary["Z3Wolfram"];
	If[FailureQ[res],
		Throw[Failure["Z3WolframNativeLibraryNotFound", <||>]]
	];
	res
]]



$sharedExt = 
	Switch[$OperatingSystem, 
		"MacOSX", "dylib",
		"Windows", "dll",
		_, "so"
	]


loadFunc[name_String, params_, ret_] :=
Catch[
Module[{loaded},

	If[FailureQ[$Z3WolframLib],
		Throw[$Z3WolframLib]
	];

	loaded = LibraryFunctionLoad[$Z3WolframLib, name, params, ret];

	If[Head[loaded] =!= LibraryFunction,
		Message[];
		Throw[Failure["LibraryFunctionLoad", <| "Result" -> loaded |>]]
	];

	With[{loaded = loaded},
		Function[{res},
			If[MatchQ[res, HoldPattern[LibraryFunction[___]][___]],
				Message[LibraryFunction::unevaluated, loaded, {##}];
				Failure["Unevaluated", <| "Function" -> loaded, "Arguments" -> {##} |>]
				,
				res
			]
		][loaded[##]]&
	]
]]

loadFunc[args___] := Throw[Failure["Unhandled", <| "Function" -> loadFunc, "Arguments" -> {args} |>], "Unhandled"]



loadAllFuncs[] := (

astMalloc := astMalloc = loadFunc["astMalloc_LibraryLink", {Integer}, Integer];
astFree := astFree = loadFunc["astFree_LibraryLink", {Integer}, "Void"];
astSet := astSet = loadFunc["astSet_LibraryLink", {Integer, Integer, Integer}, "Void"];
astGet := astGet = loadFunc["astGet_LibraryLink", {Integer, Integer}, Integer];

funcDeclMalloc := funcDeclMalloc = loadFunc["funcDeclMalloc_LibraryLink", {Integer}, Integer];
funcDeclFree := funcDeclFree = loadFunc["funcDeclFree_LibraryLink", {Integer}, "Void"];
funcDeclSet := funcDeclSet = loadFunc["funcDeclSet_LibraryLink", {Integer, Integer, Integer}, "Void"];
funcDeclGet := funcDeclGet = loadFunc["funcDeclGet_LibraryLink", {Integer, Integer}, Integer];

constructorMalloc := constructorMalloc = loadFunc["constructorMalloc_LibraryLink", {Integer}, Integer];
constructorFree := constructorFree = loadFunc["constructorFree_LibraryLink", {Integer}, "Void"];
constructorSet := constructorSet = loadFunc["constructorSet_LibraryLink", {Integer, Integer, Integer}, "Void"];
constructorGet := constructorGet = loadFunc["constructorGet_LibraryLink", {Integer, Integer}, Integer];


getGlobalErrorHandler := getGlobalErrorHandler = loadFunc["getGlobalErrorHandler_LibraryLink", {}, Integer];
getGlobalErrorCode := getGlobalErrorCode = loadFunc["getGlobalErrorCode_LibraryLink", {}, Integer];

Z3setErrorHandler := Z3setErrorHandler = loadFunc["Z3setErrorhandler_LibraryLink", {Integer, Integer}, Integer];

Z3mkConfig := Z3mkConfig = loadFunc["Z3mkConfig_LibraryLink", {}, Integer];
Z3delConfig := Z3delConfig = loadFunc["Z3delConfig_LibraryLink", {Integer}, "Void"];

Z3mkContext := Z3mkContext = loadFunc["Z3mkContext_LibraryLink", {Integer}, Integer];
Z3delContext := Z3delContext = loadFunc["Z3delContext_LibraryLink", {Integer}, "Void"];

Z3mkBoolSort := Z3mkBoolSort = loadFunc["Z3mkBoolSort_LibraryLink", {Integer}, Integer];
Z3mkIntSort := Z3mkIntSort = loadFunc["Z3mkIntSort_LibraryLink", {Integer}, Integer];
Z3mkUninterpretedSort := Z3mkUninterpretedSort = loadFunc["Z3mkUninterpretedSort_LibraryLink", {Integer, Integer}, Integer];

Z3mkInt := Z3mkInt = loadFunc["Z3mkInt_LibraryLink", {Integer, Integer, Integer}, Integer];
Z3mkIntSymbol := Z3mkIntSymbol = loadFunc["Z3mkIntSymbol_LibraryLink", {Integer, Integer}, Integer];

Z3mkConst := Z3mkConst = loadFunc["Z3mkConst_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3mkNot := Z3mkNot = loadFunc["Z3mkNot_LibraryLink", {Integer, Integer}, Integer];
Z3mkAnd := Z3mkAnd = loadFunc["Z3mkAnd_LibraryLink", {Integer, Integer, {Integer, 1}}, Integer];
Z3mkOr := Z3mkOr = loadFunc["Z3mkOr_LibraryLink", {Integer, Integer, {Integer, 1}}, Integer];
Z3mkIff := Z3mkIff = loadFunc["Z3mkIff_LibraryLink", {Integer, Integer, Integer}, Integer];
Z3mkAdd := Z3mkAdd = loadFunc["Z3mkAdd_LibraryLink", {Integer, Integer, {Integer, 1}}, Integer];
Z3mkSub := Z3mkSub = loadFunc["Z3mkSub_LibraryLink", {Integer, Integer, {Integer, 1}}, Integer];
Z3mkLt := Z3mkLt = loadFunc["Z3mkLt_LibraryLink", {Integer, Integer, Integer}, Integer];
Z3mkGt := Z3mkGt = loadFunc["Z3mkGt_LibraryLink", {Integer, Integer, Integer}, Integer];
Z3mkEq := Z3mkEq = loadFunc["Z3mkEq_LibraryLink", {Integer, Integer, Integer}, Integer];
Z3mkLe := Z3mkLe = loadFunc["Z3mkLe_LibraryLink", {Integer, Integer, Integer}, Integer];
Z3mkGe := Z3mkGe = loadFunc["Z3mkGe_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3mkFuncDecl := Z3mkFuncDecl = loadFunc["Z3mkFuncDecl_LibraryLink", {Integer, Integer, Integer, {Integer, 1}, Integer}, Integer];

Z3solverAssert := Z3solverAssert = loadFunc["Z3solverAssert_LibraryLink", {Integer, Integer, Integer}, Integer];
Z3solverCheck := Z3solverCheck = loadFunc["Z3solverCheck_LibraryLink", {Integer, Integer}, Integer];

Z3mkXor := Z3mkXor = loadFunc["Z3mkXor_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3mkSolver := Z3mkSolver = loadFunc["Z3mkSolver_LibraryLink", {Integer}, Integer];

Z3solverDecRef := Z3solverDecRef = loadFunc["Z3solverDecRef_LibraryLink", {Integer, Integer}, "Void"];
Z3solverIncRef := Z3solverIncRef = loadFunc["Z3solverIncRef_LibraryLink", {Integer, Integer}, "Void"];

Z3mkStringSymbol := Z3mkStringSymbol = loadFunc["Z3mkStringSymbol_LibraryLink", {Integer, "UTF8String"}, Integer];

Z3modelToString := Z3modelToString = loadFunc["Z3modelToString_LibraryLink", {Integer, Integer}, "UTF8String"];

Z3solverGetModel := Z3solverGetModel = loadFunc["Z3solverGetModel_LibraryLink", {Integer, Integer}, Integer];

Z3modelDecRef := Z3modelDecRef = loadFunc["Z3modelDecRef_LibraryLink", {Integer, Integer}, "Void"];
Z3modelIncRef := Z3modelIncRef = loadFunc["Z3modelIncRef_LibraryLink", {Integer, Integer}, "Void"];

Z3solverPush := Z3solverPush = loadFunc["Z3solverPush_LibraryLink", {Integer, Integer}, "Void"];
Z3solverPop := Z3solverPop = loadFunc["Z3solverPop_LibraryLink", {Integer, Integer, Integer}, "Void"];

Z3mkApp := Z3mkApp = loadFunc["Z3mkApp_LibraryLink", {Integer, Integer, Integer, {Integer, 1}}, Integer];

Z3setParamValue := Z3setParamValue = loadFunc["Z3setParamValue_LibraryLink", {Integer, "UTF8String", "UTF8String"}, "Void"];

Z3mkNumeral := Z3mkNumeral = loadFunc["Z3mkNumeral_LibraryLink", {Integer, "UTF8String", Integer}, Integer];

Z3solverGetNumScopes := Z3solverGetNumScopes = loadFunc["Z3solverGetNumScopes_LibraryLink", {Integer, Integer}, Integer];

Z3funcDeclToString := Z3funcDeclToString = loadFunc["Z3funcDeclToString_LibraryLink", {Integer, Integer}, "UTF8String"];

Z3funcEntryDecRef := Z3funcEntryDecRef = loadFunc["Z3funcEntryDecRef_LibraryLink", {Integer, Integer}, "Void"];

Z3funcEntryGetArg := Z3funcEntryGetArg = loadFunc["Z3funcEntryGetArg_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3funcEntryGetNumArgs := Z3funcEntryGetNumArgs = loadFunc["Z3funcEntryGetNumArgs_LibraryLink", {Integer, Integer}, Integer];

Z3funcEntryGetValue := Z3funcEntryGetValue = loadFunc["Z3funcEntryGetValue_LibraryLink", {Integer, Integer}, Integer];

Z3funcEntryIncRef := Z3funcEntryIncRef = loadFunc["Z3funcEntryIncRef_LibraryLink", {Integer, Integer}, "Void"];

Z3funcInterpDecRef := Z3funcInterpDecRef = loadFunc["Z3funcInterpDecRef_LibraryLink", {Integer, Integer}, "Void"];

Z3funcInterpGetElse := Z3funcInterpGetElse = loadFunc["Z3funcInterpGetElse_LibraryLink", {Integer, Integer}, Integer];

Z3funcInterpGetEntry := Z3funcInterpGetEntry = loadFunc["Z3funcInterpGetEntry_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3funcInterpGetNumEntries := Z3funcInterpGetNumEntries = loadFunc["Z3funcInterpGetNumEntries_LibraryLink", {Integer, Integer}, Integer];

Z3funcInterpIncRef := Z3funcInterpIncRef = loadFunc["Z3funcInterpIncRef_LibraryLink", {Integer, Integer}, "Void"];

Z3getAppArg := Z3getAppArg = loadFunc["Z3getAppArg_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3getAppDecl := Z3getAppDecl = loadFunc["Z3getAppDecl_LibraryLink", {Integer, Integer}, Integer];

Z3getAppNumArgs := Z3getAppNumArgs = loadFunc["Z3getAppNumArgs_LibraryLink", {Integer, Integer}, Integer];

Z3getAstKind := Z3getAstKind = loadFunc["Z3getAstKind_LibraryLink", {Integer, Integer}, Integer];

Z3getDeclName := Z3getDeclName = loadFunc["Z3getDeclName_LibraryLink", {Integer, Integer}, Integer];

Z3getNumeralString := Z3getNumeralString = loadFunc["Z3getNumeralString_LibraryLink", {Integer, Integer}, "UTF8String"];

Z3getSort := Z3getSort = loadFunc["Z3getSort_LibraryLink", {Integer, Integer}, Integer];

Z3modelEval := Z3modelEval = loadFunc["Z3modelEval_LibraryLink", {Integer, Integer, Integer, "Boolean", Integer}, "Boolean"];

Z3modelGetConstDecl := Z3modelGetConstDecl = loadFunc["Z3modelGetConstDecl_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3modelGetFuncDecl := Z3modelGetFuncDecl = loadFunc["Z3modelGetFuncDecl_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3modelGetFuncInterp := Z3modelGetFuncInterp = loadFunc["Z3modelGetFuncInterp_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3modelGetNumConsts := Z3modelGetNumConsts = loadFunc["Z3modelGetNumConsts_LibraryLink", {Integer, Integer}, Integer];

Z3modelGetNumFuncs := Z3modelGetNumFuncs = loadFunc["Z3modelGetNumFuncs_LibraryLink", {Integer, Integer}, Integer];

Z3toApp := Z3toApp = loadFunc["Z3toApp_LibraryLink", {Integer, Integer}, Integer];

Z3getArraySortDomain := Z3getArraySortDomain = loadFunc["Z3getArraySortDomain_LibraryLink", {Integer, Integer}, Integer];

Z3getArraySortRange := Z3getArraySortRange = loadFunc["Z3getArraySortRange_LibraryLink", {Integer, Integer}, Integer];

Z3getBvSortSize := Z3getBvSortSize = loadFunc["Z3getBvSortSize_LibraryLink", {Integer, Integer}, Integer];

Z3getDatatypeSortNumConstructors := Z3getDatatypeSortNumConstructors = loadFunc["Z3getDatatypeSortNumConstructors_LibraryLink", {Integer, Integer}, Integer];

Z3getRange := Z3getRange = loadFunc["Z3getRange_LibraryLink", {Integer, Integer}, Integer];

Z3getSortKind := Z3getSortKind = loadFunc["Z3getSortKind_LibraryLink", {Integer, Integer}, Integer];

Z3getSortName := Z3getSortName = loadFunc["Z3getSortName_LibraryLink", {Integer, Integer}, Integer];

Z3getSymbolInt := Z3getSymbolInt = loadFunc["Z3getSymbolInt_LibraryLink", {Integer, Integer}, Integer];

Z3getSymbolKind := Z3getSymbolKind = loadFunc["Z3getSymbolKind_LibraryLink", {Integer, Integer}, Integer];

Z3getSymbolString := Z3getSymbolString = loadFunc["Z3getSymbolString_LibraryLink", {Integer, Integer}, "UTF8String"];

Z3getTupleSortFieldDecl := Z3getTupleSortFieldDecl = loadFunc["Z3getTupleSortFieldDecl_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3getTupleSortNumFields := Z3getTupleSortNumFields = loadFunc["Z3getTupleSortNumFields_LibraryLink", {Integer, Integer}, Integer];

Z3sortToString := Z3sortToString = loadFunc["Z3sortToString_LibraryLink", {Integer, Integer}, "UTF8String"];

Z3globalParamSet := Z3globalParamSet = loadFunc["Z3globalParamSet_LibraryLink", {Integer, Integer}, "Void"];

Z3solverGetReasonUnknown := Z3solverGetReasonUnknown = loadFunc["Z3solverGetReasonUnknown_LibraryLink", {Integer, Integer}, Integer];

Z3globalParamResetAll := Z3globalParamResetAll = loadFunc["Z3globalParamResetAll_LibraryLink", {}, "Void"];

Z3mkArraySort := Z3mkArraySort = loadFunc["Z3mkArraySort_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3mkStore := Z3mkStore = loadFunc["Z3mkStore_LibraryLink", {Integer, Integer, Integer, Integer}, Integer];

Z3mkSelect := Z3mkSelect = loadFunc["Z3mkSelect_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3mkImplies := Z3mkImplies = loadFunc["Z3mkImplies_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3astToString := Z3astToString = loadFunc["Z3astToString_LibraryLink", {Integer, Integer}, "UTF8String"];

Z3mkDistinct := Z3mkDistinct = loadFunc["Z3mkDistinct_LibraryLink", {Integer, Integer, {Integer, 1}}, Integer];

Z3mkRealSort := Z3mkRealSort = loadFunc["Z3mkRealSort_LibraryLink", {Integer}, Integer];

Z3mkTupleSort := Z3mkTupleSort = loadFunc["Z3mkTupleSort_LibraryLink", {Integer, Integer, Integer, {Integer, 1}, {Integer, 1}, Integer, Integer}, Integer];

Z3mkBvSort := Z3mkBvSort = loadFunc["Z3mkBvSort_LibraryLink", {Integer, Integer}, Integer];

Z3mkBvsub := Z3mkBvsub = loadFunc["Z3mkBvsub_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3mkBvsle := Z3mkBvsle = loadFunc["Z3mkBvsle_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3mkBvxor := Z3mkBvxor = loadFunc["Z3mkBvxor_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3mkBvmul := Z3mkBvmul = loadFunc["Z3mkBvmul_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3getErrorCode := Z3getErrorCode = loadFunc["Z3getErrorCode_LibraryLink", {Integer}, Integer];

Z3getErrorMsg := Z3getErrorMsg = loadFunc["Z3getErrorMsg_LibraryLink", {Integer, Integer}, "UTF8String"];

Z3parseSmtlib2String := Z3parseSmtlib2String = loadFunc["Z3parseSmtlib2String_LibraryLink", {Integer, "UTF8String", Integer, {Integer, 1}, {Integer, 1}, Integer, {Integer, 1}, {Integer, 1}}, Integer];

Z3astVectorToString := Z3astVectorToString = loadFunc["Z3astVectorToString_LibraryLink", {Integer, Integer}, "UTF8String"];

Z3astVectorSize := Z3astVectorSize = loadFunc["Z3astVectorSize_LibraryLink", {Integer, Integer}, Integer];

Z3astVectorGet := Z3astVectorGet = loadFunc["Z3astVectorGet_LibraryLink", {Integer, Integer, Integer}, Integer];

Z3astVectorToString := Z3astVectorToString = loadFunc["Z3astVectorToString_LibraryLink", {Integer, Integer}, "UTF8String"];

Z3mkFalse := Z3mkFalse = loadFunc["Z3mkFalse_LibraryLink", {Integer}, Integer];

Z3mkIte := Z3mkIte = loadFunc["Z3mkIte_LibraryLink", {Integer, Integer, Integer, Integer}, Integer];

Z3mkEnumerationSort := Z3mkEnumerationSort = loadFunc["Z3mkEnumerationSort_LibraryLink", {Integer, Integer, Integer, {Integer, 1}, Integer, Integer}, Integer];

Z3mkListSort := Z3mkListSort = loadFunc["Z3mkListSort_LibraryLink", {Integer, Integer, Integer, Integer, Integer, Integer, Integer, Integer, Integer}, Integer];

Z3mkConstructor := Z3mkConstructor = loadFunc["Z3mkConstructor_LibraryLink", {Integer, Integer, Integer, Integer, {Integer, 1}, {Integer, 1}, Integer}, Integer];

Z3mkDatatype := Z3mkDatatype = loadFunc["Z3mkDatatype_LibraryLink", {Integer, Integer, Integer, Integer}, Integer];

Z3astVectorDecRef := Z3astVectorDecRef = loadFunc["Z3astVectorDecRef_LibraryLink", {Integer, Integer}, "Void"];

Z3getNumeralInt := Z3getNumeralInt = loadFunc["Z3getNumeralInt_LibraryLink", {Integer, Integer, Integer}, "Boolean"];

Z3modelHasInterp := Z3modelHasInterp = loadFunc["Z3modelHasInterp_LibraryLink", {Integer, Integer, Integer}, "Boolean"];

Z3funcDeclToAst := Z3funcDeclToAst = loadFunc["Z3funcDeclToAst_LibraryLink", {Integer, Integer}, Integer];

Z3addConstInterp := Z3addConstInterp = loadFunc["Z3addConstInterp_LibraryLink", {Integer, Integer, Integer, Integer}, "Void"];

Z3mkAsArray := Z3mkAsArray = loadFunc["Z3mkAsArray_LibraryLink", {Integer, Integer}, Integer];
Z3funcInterpAddEntry := Z3funcInterpAddEntry = loadFunc["Z3funcInterpAddEntry_LibraryLink", {Integer, Integer, Integer, Integer}, "Void"];
Z3astVectorPush := Z3astVectorPush = loadFunc["Z3astVectorPush_LibraryLink", {Integer, Integer, Integer}, "Void"];
Z3astVectorIncRef := Z3astVectorIncRef = loadFunc["Z3astVectorIncRef_LibraryLink", {Integer, Integer}, "Void"];
Z3mkAstVector := Z3mkAstVector = loadFunc["Z3mkAstVector_LibraryLink", {Integer}, Integer];
Z3mkFreshFuncDecl := Z3mkFreshFuncDecl = loadFunc["Z3mkFreshFuncDecl_LibraryLink", {Integer, "UTF8String", Integer, {Integer, 1}, Integer}, Integer];
Z3mkFpaToFpReal := Z3mkFpaToFpReal = loadFunc["Z3mkFpaToFpReal_LibraryLink", {Integer, Integer, Integer, Integer}, Integer];
Z3mkFpaToFpIntReal := Z3mkFpaToFpIntReal = loadFunc["Z3mkFpaToFpIntReal_LibraryLink", {Integer, Integer, Integer, Integer, Integer}, Integer];
Z3mkFpaToFpBv := Z3mkFpaToFpBv = loadFunc["Z3mkFpaToFpBv_LibraryLink", {Integer, Integer, Integer}, Integer];
Z3mkFpaFp := Z3mkFpaFp = loadFunc["Z3mkFpaFp_LibraryLink", {Integer, Integer, Integer, Integer}, Integer];
Z3mkFpaSort := Z3mkFpaSort = loadFunc["Z3mkFpaSort_LibraryLink", {Integer, Integer, Integer}, Integer];
Z3mkFpaIsZero := Z3mkFpaIsZero = loadFunc["Z3mkFpaIsZero_LibraryLink", {Integer, Integer}, Integer];
Z3mkFpaIsNan := Z3mkFpaIsNan = loadFunc["Z3mkFpaIsNan_LibraryLink", {Integer, Integer}, Integer];
Z3mkFpaIsInfinite := Z3mkFpaIsInfinite = loadFunc["Z3mkFpaIsInfinite_LibraryLink", {Integer, Integer}, Integer];
Z3mkFpaRtz := Z3mkFpaRtz = loadFunc["Z3mkFpaRtz_LibraryLink", {Integer}, Integer];
Z3mkFpaAdd := Z3mkFpaAdd = loadFunc["Z3mkFpaAdd_LibraryLink", {Integer, Integer, Integer, Integer}, Integer];
Z3mkFpaNumeralDouble := Z3mkFpaNumeralDouble = loadFunc["Z3mkFpaNumeralDouble_LibraryLink", {Integer, Real, Integer}, Integer];
Z3mkFpaRoundingModeSort := Z3mkFpaRoundingModeSort = loadFunc["Z3mkFpaRoundingModeSort_LibraryLink", {Integer}, Integer];
Z3substituteVars := Z3substituteVars = loadFunc["Z3substituteVars_LibraryLink", {Integer, Integer, Integer, {Integer, 1}}, Integer];
Z3mkBound := Z3mkBound = loadFunc["Z3mkBound_LibraryLink", {Integer, Integer, Integer}, Integer];
Z3substitute := Z3substitute = loadFunc["Z3substitute_LibraryLink", {Integer, Integer, Integer, {Integer, 1}, {Integer, 1}}, Integer];
Z3decRef := Z3decRef = loadFunc["Z3decRef_LibraryLink", {Integer, Integer}, "Void"];
Z3sortToAst := Z3sortToAst = loadFunc["Z3sortToAst_LibraryLink", {Integer, Integer}, Integer];
Z3incRef := Z3incRef = loadFunc["Z3incRef_LibraryLink", {Integer, Integer}, "Void"];
Z3mkContextRc := Z3mkContextRc = loadFunc["Z3mkContextRc_LibraryLink", {Integer}, Integer];
Z3solverGetProof := Z3solverGetProof = loadFunc["Z3solverGetProof_LibraryLink", {Integer, Integer}, Integer];
Z3solverGetUnsatCore := Z3solverGetUnsatCore = loadFunc["Z3solverGetUnsatCore_LibraryLink", {Integer, Integer}, Integer];
Z3solverCheckAssumptions := Z3solverCheckAssumptions = loadFunc["Z3solverCheckAssumptions_LibraryLink", {Integer, Integer, Integer, {Integer, 1}}, Integer];
Z3delConstructor := Z3delConstructor = loadFunc["Z3delConstructor_LibraryLink", {Integer, Integer}, "Void"];
Z3queryConstructor := Z3queryConstructor = loadFunc["Z3queryConstructor_LibraryLink", {Integer, Integer, Integer, Integer, Integer, Integer}, "Void"];
Z3delConstructorList := Z3delConstructorList = loadFunc["Z3delConstructorList_LibraryLink", {Integer, Integer}, "Void"];
Z3mkDatatypes := Z3mkDatatypes = loadFunc["Z3mkDatatypes_LibraryLink", {Integer, Integer, {Integer, 1}, Integer, Integer}, "Void"];
Z3mkConstructorList := Z3mkConstructorList = loadFunc["Z3mkConstructorList_LibraryLink", {Integer, Integer, {Integer, 1}}, Integer];

Z3mkModel := Z3mkModel = loadFunc["Z3mkModel_LibraryLink", {Integer}, Integer];
Z3addFuncInterp := Z3addFuncInterp = loadFunc["Z3addFuncInterp_LibraryLink", {Integer, Integer, Integer, Integer}, Integer];

Z3getTupleSortMkDecl := Z3getTupleSortMkDecl = loadFunc["Z3getTupleSortMkDecl_LibraryLink", {Integer, Integer}, Integer];

)

loadAllFuncs[args___] := Throw[Failure["Unhandled", <| "Function" -> loadAllFuncs, "Arguments" -> {args} |>], "Unhandled"]



End[]

EndPackage[]
