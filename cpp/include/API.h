
#pragma once

#include "WolframLibrary.h"
#undef True
#undef False


//
// CMake defines z3-wolfram_lib_EXPORTS
//
#ifdef _WIN32
# ifdef z3-wolfram_lib_EXPORTS
#   define Z3WOLFRAMLIB_EXPORTED  __declspec( dllexport )
# else
#   define Z3WOLFRAMLIB_EXPORTED  __declspec( dllimport )
# endif
#else
# define Z3WOLFRAMLIB_EXPORTED
#endif


EXTERN_C DLLEXPORT mint WolframLibrary_getVersion();

EXTERN_C DLLEXPORT int WolframLibrary_initialize(WolframLibraryData libData);

EXTERN_C DLLEXPORT void WolframLibrary_uninitialize(WolframLibraryData libData);

EXTERN_C DLLEXPORT int astMalloc_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int astFree_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int astSet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int astGet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int funcDeclMalloc_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int funcDeclFree_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int funcDeclSet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int funcDeclGet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int constructorMalloc_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int constructorFree_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int constructorSet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int constructorGet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);


EXTERN_C DLLEXPORT int getGlobalErrorHandler_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int getGlobalErrorCode_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3setErrorhandler_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3mkConfig_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3delConfig_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3mkContext_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3delContext_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3mkBoolSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkIntSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkUninterpretedSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3mkInt_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkInt_symbol_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3mkConst_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkNot_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkAnd_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkOr_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkIff_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkAdd_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkSub_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkLt_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkGt_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkEq_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkLe_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkGe_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3mkFunc_decl_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3solverAssert_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3solverCheck_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3mkSolver_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3solverDecRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3solverIncRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3mkStringSymbol_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3modelToString_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3solverGetModel_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3modelDecRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3modelIncRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3solverPush_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3solverPop_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3mkApp_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3mkSetParamValue_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3mkNumeral_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);


EXTERN_C DLLEXPORT int Z3funcDeclToString_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3funcEntryDecRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3funcEntryGetArg_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3funcEntryGetNumArgs_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3funcEntryGetValue_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3funcEntryIncRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3funcInterpDecRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3funcInterpGetElse_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3funcInterpGetEntry_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3funcInterpGetNumEntries_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3funcInterpIncRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getAppArg_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getAppDecl_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getAppNumArgs_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getAstKind_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getDeclName_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getNumeralString_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3modelEval_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3modelGetConstDecl_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3modelGetFuncDecl_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3modelGetFuncInterp_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3modelGetNumConsts_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3modelGetNumFuncs_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3toApp_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3getArraySortDomain_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getArraySortRange_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getBvSortSize_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getDatatypeSortNumConstructors_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getRange_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getSortKind_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getSortName_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getSymbolInt_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getSymbolKind_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getSymbolString_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getTupleSortFieldDecl_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getTupleSortNumFields_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3sortToString_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);


EXTERN_C DLLEXPORT int Z3globalParamSet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3solverGetReasonUnknown_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3globalParamResetAll_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkArraySort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkStore_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkSelect_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkImplies_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3astToString_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkDistinct_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkRealSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkTupleSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkBvSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkBvsub_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkBvsle_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkBvxor_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkBvmul_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getErrorCode_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getErrorMsg_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3parseSmtlib2String_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3astVectorToString_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3astVectorSize_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3astVectorGet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkFalse_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkIte_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkEnumerationSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkListSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkConstructor_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkDatatype_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);

EXTERN_C DLLEXPORT int Z3astVectorDecRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3getNumeralInt_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3modelHasInterp_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3funcDeclToAst_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3addConstInterp_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);


EXTERN_C DLLEXPORT int Z3mkAsArray_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3funcInterpAddEntry_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3astVectorPush_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3astVectorIncRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkAstVector_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkFreshFuncDecl_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkFpaToFpReal_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkFpaToFpIntReal_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkFpaToFpBv_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkFpaFp_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkFpaSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkFpaIsZero_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkFpaIsNan_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkFpaIsInfinite_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkFpaRtz_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkFpaAdd_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkFpaNumeralDouble_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkFpaRoundingModeSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3substituteVars_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkBound_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3substitute_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3decRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3sortToAst_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3incRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkContextRc_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3solverGetProof_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3solverGetUnsatCore_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3solverCheckAssumptions_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3delConstructor_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3queryConstructor_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3delConstructorList_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkDatatypes_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3mkConstructorList_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);


EXTERN_C DLLEXPORT int Z3mkModel_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);
EXTERN_C DLLEXPORT int Z3addFuncInterp_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);



EXTERN_C DLLEXPORT int Z3getTupleSortMkDecl_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res);



