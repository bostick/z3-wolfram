
#include "API.h"

#include "utils.h"

#include <z3.h>

#include <stdlib.h> // for malloc


DLLEXPORT mint WolframLibrary_getVersion() {
    return WolframLibraryVersion;
}

DLLEXPORT int WolframLibrary_initialize(WolframLibraryData libData) {
    
    return 0;
}

DLLEXPORT void WolframLibrary_uninitialize(WolframLibraryData libData) {
    ;
}


DLLEXPORT int astMalloc_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    int n = (int)arg1;

    Z3_ast *p = malloc(sizeof(Z3_ast) * n);

    uintptr_t res = (uintptr_t)p;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int astFree_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_ast *p = (Z3_ast *)(uintptr_t)arg1;

    free(p);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int astSet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_ast *p = (Z3_ast *)(uintptr_t)arg1;

    int i = (int)arg2;

    Z3_ast v = (Z3_ast)(uintptr_t)arg3;

    p[i] = v;

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int astGet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_ast *p = (Z3_ast *)(uintptr_t)arg1;

    int i = (int)arg2;

    Z3_ast n = p[i];

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}


DLLEXPORT int funcDeclMalloc_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    int n = (int)arg1;

    Z3_func_decl *p = malloc(sizeof(Z3_func_decl) * n);

    uintptr_t res = (uintptr_t)p;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int funcDeclFree_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_func_decl *p = (Z3_func_decl *)(uintptr_t)arg1;

    free(p);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int funcDeclSet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_func_decl *p = (Z3_func_decl *)(uintptr_t)arg1;

    int i = (int)arg2;

    Z3_func_decl v = (Z3_func_decl)(uintptr_t)arg3;

    p[i] = v;

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int funcDeclGet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_func_decl *p = (Z3_func_decl *)(uintptr_t)arg1;

    int i = (int)arg2;

    Z3_func_decl n = p[i];

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}


DLLEXPORT int constructorMalloc_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    int n = (int)arg1;

    Z3_constructor *p = malloc(sizeof(Z3_constructor) * n);

    uintptr_t res = (uintptr_t)p;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int constructorFree_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_constructor *p = (Z3_constructor *)(uintptr_t)arg1;

    free(p);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int constructorSet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_constructor *p = (Z3_constructor *)(uintptr_t)arg1;

    int i = (int)arg2;

    Z3_constructor v = (Z3_constructor)(uintptr_t)arg3;

    p[i] = v;

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int constructorGet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_constructor *p = (Z3_constructor *)(uintptr_t)arg1;

    int i = (int)arg2;

    Z3_constructor n = p[i];

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}


DLLEXPORT int getGlobalErrorHandler_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    uintptr_t res = (uintptr_t)globalErrorHandler;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int getGlobalErrorCode_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    int res = globalErrorCode;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3setErrorhandler_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_error_handler *errorhandler = (Z3_error_handler *)(uintptr_t)arg2;

    Z3_set_error_handler(ctx, errorhandler);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkConfig_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    Z3_config cfg = Z3_mk_config();

    uintptr_t res = (uintptr_t)cfg;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3delConfig_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_config cfg = (Z3_config)(uintptr_t)arg1;

    Z3_del_config(cfg);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkContext_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_config cfg = (Z3_config)(uintptr_t)arg1;

    Z3_context ctx = Z3_mk_context(cfg);

    uintptr_t res = (uintptr_t)ctx;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3delContext_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_del_context(ctx);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkBoolSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_sort bool_sort = Z3_mk_bool_sort(ctx);

    uintptr_t res = (uintptr_t)bool_sort;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkIntSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_sort int_sort = Z3_mk_int_sort(ctx);

    uintptr_t res = (uintptr_t)int_sort;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkUninterpretedSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_symbol U_name = (Z3_symbol)(uintptr_t)arg2;

    Z3_sort U = Z3_mk_uninterpreted_sort(ctx, U_name);

    uintptr_t res = (uintptr_t)U;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkInt_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    int v = arg2;
    
    Z3_sort ty = (Z3_sort)(uintptr_t)arg3;

    Z3_ast i = Z3_mk_int(ctx, v, ty);

    uintptr_t res = (uintptr_t)i;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkIntSymbol_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    int val = (int)arg2;

    Z3_symbol symbol_x = Z3_mk_int_symbol(ctx, val);

    uintptr_t res = (uintptr_t)symbol_x;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkConst_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_symbol sym = (Z3_symbol)(uintptr_t)arg2;

    Z3_sort sort = (Z3_sort)(uintptr_t)arg3;

    Z3_ast x = Z3_mk_const(ctx, sym, sort);

    uintptr_t res = (uintptr_t)x;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkNot_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_ast x = (Z3_ast)(uintptr_t)arg2;

    Z3_ast not_x = Z3_mk_not(ctx, x);

    uintptr_t res = (uintptr_t)not_x;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkAnd_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    MTensor arg3 = MArgument_getMTensor(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    mint len = arg2;

    Z3_ast const *args = (Z3_ast const *)libData->MTensor_getIntegerData(arg3);

    Z3_ast res1 = Z3_mk_and(ctx, len, args);

    uintptr_t res2 = (uintptr_t)res1;

    MArgument_setInteger(Res, res2);
    
    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkOr_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    MTensor arg3 = MArgument_getMTensor(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    mint len = arg2;

    Z3_ast const *args = (Z3_ast const *)libData->MTensor_getIntegerData(arg3);

    Z3_ast res1 = Z3_mk_or(ctx, len, args);

    uintptr_t res2 = (uintptr_t)res1;

    MArgument_setInteger(Res, res2);
    
    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkIff_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_ast ls = (Z3_ast)(uintptr_t)arg2;

    Z3_ast rs = (Z3_ast)(uintptr_t)arg3;

    Z3_ast conjecture = Z3_mk_iff(ctx, ls, rs);

    uintptr_t res = (uintptr_t)conjecture;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkAdd_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    MTensor arg3 = MArgument_getMTensor(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    mint len = arg2;

    Z3_ast const *args = (Z3_ast const *)libData->MTensor_getIntegerData(arg3);

    Z3_ast res1 = Z3_mk_add(ctx, len, args);

    uintptr_t res2 = (uintptr_t)res1;

    MArgument_setInteger(Res, res2);
    
    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkSub_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    MTensor arg3 = MArgument_getMTensor(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    mint len = arg2;

    Z3_ast const *args = (Z3_ast const *)libData->MTensor_getIntegerData(arg3);

    Z3_ast res1 = Z3_mk_sub(ctx, len, args);

    uintptr_t res2 = (uintptr_t)res1;

    MArgument_setInteger(Res, res2);
    
    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkLt_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_ast x = (Z3_ast)(uintptr_t)arg2;

    Z3_ast y = (Z3_ast)(uintptr_t)arg3;

    Z3_ast lt = Z3_mk_lt(ctx, x, y);

    uintptr_t res = (uintptr_t)lt;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkGt_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_ast x = (Z3_ast)(uintptr_t)arg2;

    Z3_ast y = (Z3_ast)(uintptr_t)arg3;

    Z3_ast gt = Z3_mk_gt(ctx, x, y);

    uintptr_t res = (uintptr_t)gt;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkEq_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_ast x = (Z3_ast)(uintptr_t)arg2;

    Z3_ast y = (Z3_ast)(uintptr_t)arg3;

    Z3_ast eq = Z3_mk_eq(ctx, x, y);

    uintptr_t res = (uintptr_t)eq;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkLe_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_ast x = (Z3_ast)(uintptr_t)arg2;

    Z3_ast y = (Z3_ast)(uintptr_t)arg3;

    Z3_ast eq = Z3_mk_le(ctx, x, y);

    uintptr_t res = (uintptr_t)eq;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkGe_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_ast x = (Z3_ast)(uintptr_t)arg2;

    Z3_ast y = (Z3_ast)(uintptr_t)arg3;

    Z3_ast eq = Z3_mk_ge(ctx, x, y);

    uintptr_t res = (uintptr_t)eq;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkFuncDecl_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    MTensor arg4 = MArgument_getMTensor(Args[3]);

    mint arg5 = MArgument_getInteger(Args[4]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_symbol g_name = (Z3_symbol)(uintptr_t)arg2;

    mint len = arg3;

    Z3_sort U = (Z3_sort)(uintptr_t)arg5;

    Z3_sort const *g_domain = (Z3_sort const *)libData->MTensor_getIntegerData(arg4);

    Z3_func_decl g = Z3_mk_func_decl(ctx, g_name, len, g_domain, U);

    uintptr_t res = (uintptr_t)g;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3solverAssert_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_solver s = (Z3_solver)(uintptr_t)arg2;

    Z3_ast conjecture = (Z3_ast)(uintptr_t)arg3;

    Z3_solver_assert(ctx, s, conjecture);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3solverCheck_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_solver s = (Z3_solver)(uintptr_t)arg2;

    Z3_lbool n = Z3_solver_check(ctx, s);

    mint res = (mint)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkXor_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_ast x = (Z3_ast)(uintptr_t)arg2;

    Z3_ast y = (Z3_ast)(uintptr_t)arg3;

    Z3_ast x_xor_y = Z3_mk_xor(ctx, x, y);

    uintptr_t res = (uintptr_t)x_xor_y;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkSolver_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_solver s = Z3_mk_solver(ctx);

    uintptr_t res = (uintptr_t)s;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3solverDecRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_solver s = (Z3_solver)(uintptr_t)arg2;

    Z3_solver_dec_ref(ctx, s);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3solverIncRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_solver s = (Z3_solver)(uintptr_t)arg2;

    Z3_solver_inc_ref(ctx, s);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkStringSymbol_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    char *arg2 = MArgument_getUTF8String(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_string name = (Z3_string)arg2;

    Z3_symbol s = Z3_mk_string_symbol(ctx, name);

    libData->UTF8String_disown(arg2);

    uintptr_t res = (uintptr_t)s;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3modelToString_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_model m = (Z3_model)(uintptr_t)arg2;

    Z3_string s = Z3_model_to_string(ctx, m);

    char *res = (char *)s;

    MArgument_setUTF8String(Res, res);

    return LIBRARY_NO_ERROR;
}


DLLEXPORT int Z3solverGetModel_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_solver s = (Z3_solver)(uintptr_t)arg2;

    Z3_model m = Z3_solver_get_model(ctx, s);

    uintptr_t res = (uintptr_t)m;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3modelDecRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_model m = (Z3_model)(uintptr_t)arg2;

    Z3_model_dec_ref(ctx, m);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3modelIncRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_model m = (Z3_model)(uintptr_t)arg2;

    Z3_model_inc_ref(ctx, m);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3solverPush_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_solver s = (Z3_solver)(uintptr_t)arg2;

    Z3_solver_push(ctx, s);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3solverPop_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_solver s = (Z3_solver)(uintptr_t)arg2;

    int n = arg3;

    Z3_solver_pop(ctx, s, n);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkApp_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    MTensor arg4 = MArgument_getMTensor(Args[3]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_func_decl d = (Z3_func_decl)(uintptr_t)arg2;

    int num_args = arg3;

    Z3_ast const *args = (Z3_ast const *)libData->MTensor_getIntegerData(arg4);

    Z3_ast app = Z3_mk_app(ctx, d, num_args, args);

    uintptr_t res = (uintptr_t)app;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}


DLLEXPORT int Z3setParamValue_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_config cfg = (Z3_config)(uintptr_t)arg1;

    char *key = (char *)(uintptr_t)arg2;

    char *value = (char *)(uintptr_t)arg3;

    Z3_set_param_value(cfg, key, value);

    return LIBRARY_NO_ERROR;
}


DLLEXPORT int Z3mkNumeral_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    char *arg2 = MArgument_getUTF8String(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_string n = (Z3_string)arg2;

    Z3_sort ty = (Z3_sort)(uintptr_t)arg3;

    Z3_ast numeral = Z3_mk_numeral(ctx, n, ty);

    libData->UTF8String_disown(arg2);

    uintptr_t res = (uintptr_t)numeral;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3solverGetNumScopes_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_solver s = (Z3_solver)(uintptr_t)arg2;

    int n = Z3_solver_get_num_scopes(ctx, s);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}



DLLEXPORT int Z3funcDeclToString_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_func_decl d = (Z3_func_decl)(uintptr_t)arg2;

    Z3_string n = Z3_func_decl_to_string(ctx, d);

    char *res = (char *)n;

    MArgument_setUTF8String(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3funcEntryDecRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_func_entry e = (Z3_func_entry)(uintptr_t)arg2;

    Z3_func_entry_dec_ref(ctx, e);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3funcEntryGetArg_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_func_entry e = (Z3_func_entry)(uintptr_t)arg2;

    unsigned i = (unsigned)arg3;

    Z3_ast n = Z3_func_entry_get_arg(ctx, e, i);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3funcEntryGetNumArgs_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_func_entry e = (Z3_func_entry)(uintptr_t)arg2;

    unsigned n = Z3_func_entry_get_num_args(ctx, e);

    mint res = (mint)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3funcEntryGetValue_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_func_entry e = (Z3_func_entry)(uintptr_t)arg2;

    Z3_ast n = Z3_func_entry_get_value(ctx, e);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3funcEntryIncRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_func_entry e = (Z3_func_entry)(uintptr_t)arg2;

    Z3_func_entry_inc_ref(ctx, e);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3funcInterpDecRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_func_interp f = (Z3_func_interp)(uintptr_t)arg2;

    Z3_func_interp_dec_ref(ctx, f);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3funcInterpGetElse_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_func_interp f = (Z3_func_interp)(uintptr_t)arg2;

    Z3_ast n = Z3_func_interp_get_else(ctx, f);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3funcInterpGetEntry_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_func_interp f = (Z3_func_interp)(uintptr_t)arg2;

    unsigned i = (unsigned)arg3;

    Z3_func_entry n = Z3_func_interp_get_entry(ctx, f, i);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3funcInterpGetNumEntries_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_func_interp f = (Z3_func_interp)(uintptr_t)arg2;

    unsigned n = Z3_func_interp_get_num_entries(ctx, f);

    mint res = (mint)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3funcInterpIncRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_func_interp f = (Z3_func_interp)(uintptr_t)arg2;

    Z3_func_interp_inc_ref(ctx, f);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getAppArg_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_app a = (Z3_app)(uintptr_t)arg2;

    unsigned i = (unsigned)arg3;

    Z3_ast n = Z3_get_app_arg(ctx, a, i);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getAppDecl_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_app a = (Z3_app)(uintptr_t)arg2;

    Z3_func_decl n = Z3_get_app_decl(ctx, a);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getAppNumArgs_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_app a = (Z3_app)(uintptr_t)arg2;

    unsigned n = Z3_get_app_num_args(ctx, a);

    mint res = (mint)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getAstKind_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_ast a = (Z3_ast)(uintptr_t)arg2;

    Z3_ast_kind n = Z3_get_ast_kind(ctx, a);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getDeclName_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_func_decl d = (Z3_func_decl)(uintptr_t)arg2;

    Z3_symbol n = Z3_get_decl_name(ctx, d);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getNumeralString_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_ast a = (Z3_ast)(uintptr_t)arg2;

    Z3_string n = Z3_get_numeral_string(ctx, a);

    char *res = (char *)n;

    MArgument_setUTF8String(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_ast a = (Z3_ast)(uintptr_t)arg2;

    Z3_sort n = Z3_get_sort(ctx, a);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3modelEval_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    mbool arg4 = MArgument_getBoolean(Args[3]);

    mint arg5 = MArgument_getInteger(Args[4]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_model m = (Z3_model)(uintptr_t)arg2;

    Z3_ast t = (Z3_ast)(uintptr_t)arg3;

    bool model_completion = (bool)arg4;

    Z3_ast *v = (Z3_ast*)(uintptr_t)arg5;

    Z3_bool_opt n = Z3_model_eval(ctx, m, t, model_completion, v);

    mbool res = (mbool)n;

    MArgument_setBoolean(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3modelGetConstDecl_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_model m = (Z3_model)(uintptr_t)arg2;

    unsigned i = (unsigned)arg3;

    Z3_func_decl n = Z3_model_get_const_decl(ctx, m, i);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3modelGetFuncDecl_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_model m = (Z3_model)(uintptr_t)arg2;

    unsigned i = (unsigned)arg3;

    Z3_func_decl n = Z3_model_get_func_decl(ctx, m, i);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3modelGetFuncInterp_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_model m = (Z3_model)(uintptr_t)arg2;

    Z3_func_decl f = (Z3_func_decl)(uintptr_t)arg3;

    Z3_func_interp_opt n = Z3_model_get_func_interp(ctx, m, f);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3modelGetNumConsts_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_model m = (Z3_model)(uintptr_t)arg2;

    unsigned n = Z3_model_get_num_consts(ctx, m);

    mint res = (mint)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3modelGetNumFuncs_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_model m = (Z3_model)(uintptr_t)arg2;

    unsigned n = Z3_model_get_num_funcs(ctx, m);

    mint res = (mint)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3toApp_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_ast a = (Z3_ast)(uintptr_t)arg2;

    Z3_app n = Z3_to_app(ctx, a);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}



DLLEXPORT int Z3getArraySortDomain_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_sort t = (Z3_sort)(uintptr_t)arg2;

    Z3_sort n = Z3_get_array_sort_domain(ctx, t);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getArraySortRange_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_sort t = (Z3_sort)(uintptr_t)arg2;

    Z3_sort n = Z3_get_array_sort_range(ctx, t);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getBvSortSize_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_sort t = (Z3_sort)(uintptr_t)arg2;

    unsigned n = Z3_get_bv_sort_size(ctx, t);

    mint res = (mint)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getDatatypeSortNumConstructors_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_sort t = (Z3_sort)(uintptr_t)arg2;

    unsigned n = Z3_get_datatype_sort_num_constructors(ctx, t);

    mint res = (mint)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getRange_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_func_decl d = (Z3_func_decl)(uintptr_t)arg2;

    Z3_sort n = Z3_get_range(ctx, d);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getSortKind_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_sort t = (Z3_sort)(uintptr_t)arg2;

    Z3_sort_kind n = Z3_get_sort_kind(ctx, t);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getSortName_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_sort d = (Z3_sort)(uintptr_t)arg2;

    Z3_symbol n = Z3_get_sort_name(ctx, d);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getSymbolInt_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_symbol s = (Z3_symbol)(uintptr_t)arg2;

    int n = Z3_get_symbol_int(ctx, s);

    int res = n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getSymbolKind_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_symbol s = (Z3_symbol)(uintptr_t)arg2;

    Z3_symbol_kind n = Z3_get_symbol_kind(ctx, s);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getSymbolString_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_symbol s = (Z3_symbol)(uintptr_t)arg2;

    Z3_string n = Z3_get_symbol_string(ctx, s);

    char *res = (char *)n;

    MArgument_setUTF8String(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getTupleSortFieldDecl_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_sort t = (Z3_sort)(uintptr_t)arg2;

    unsigned i = (unsigned)arg3;

    Z3_func_decl n = Z3_get_tuple_sort_field_decl(ctx, t, i);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getTupleSortNumFields_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_sort t = (Z3_sort)(uintptr_t)arg2;

    unsigned n = Z3_get_tuple_sort_num_fields(ctx, t);

    mint res = (mint)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3sortToString_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context ctx = (Z3_context)(uintptr_t)arg1;

    Z3_sort s = (Z3_sort)(uintptr_t)arg2;

    Z3_string n = Z3_sort_to_string(ctx, s);

    char *res = (char *)n;

    MArgument_setUTF8String(Res, res);

    return LIBRARY_NO_ERROR;
}






DLLEXPORT int Z3globalParamSet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    char *arg1 = MArgument_getUTF8String(Args[0]);

    char *arg2 = MArgument_getUTF8String(Args[1]);

    Z3_string param_id = (Z3_string)arg1;

    Z3_string param_value = (Z3_string)arg2;

    Z3_global_param_set(param_id, param_value);

    libData->UTF8String_disown(arg1);

    libData->UTF8String_disown(arg2);

    return LIBRARY_NO_ERROR;
}


DLLEXPORT int Z3solverGetReasonUnknown_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_solver s = (Z3_solver)(uintptr_t)arg2;

    Z3_string n = Z3_solver_get_reason_unknown(c, s);

    char *res = (char *)n;

    MArgument_setUTF8String(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3globalParamResetAll_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    Z3_global_param_reset_all();

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkArraySort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_sort domain = (Z3_sort)(uintptr_t)arg2;

    Z3_sort range = (Z3_sort)(uintptr_t)arg3;

    Z3_sort n = Z3_mk_array_sort(c, domain, range);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkStore_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    mint arg4 = MArgument_getInteger(Args[3]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast a = (Z3_ast)(uintptr_t)arg2;

    Z3_ast i = (Z3_ast)(uintptr_t)arg3;

    Z3_ast v = (Z3_ast)(uintptr_t)arg4;

    Z3_ast n = Z3_mk_store(c, a, i, v);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkSelect_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast a = (Z3_ast)(uintptr_t)arg2;

    Z3_ast i = (Z3_ast)(uintptr_t)arg3;

    Z3_ast n = Z3_mk_select(c, a, i);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkImplies_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast t1 = (Z3_ast)(uintptr_t)arg2;

    Z3_ast t2 = (Z3_ast)(uintptr_t)arg3;

    Z3_ast n = Z3_mk_implies(c, t1, t2);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3astToString_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast a = (Z3_ast)(uintptr_t)arg2;

    Z3_string n = Z3_ast_to_string(c, a);

    char *res = (char *)n;

    MArgument_setUTF8String(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkDistinct_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    MTensor arg3 = MArgument_getMTensor(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    unsigned num_args = (unsigned)arg2;

    Z3_ast const *args = (Z3_ast const *)libData->MTensor_getIntegerData(arg3);

    Z3_ast n = Z3_mk_distinct(c, num_args, args);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkRealSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_sort n = Z3_mk_real_sort(c);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkTupleSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    MTensor arg4 = MArgument_getMTensor(Args[3]);

    MTensor arg5 = MArgument_getMTensor(Args[4]);

    mint arg6 = MArgument_getInteger(Args[5]);

    mint arg7 = MArgument_getInteger(Args[6]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_symbol mk_tuple_name = (Z3_symbol)(uintptr_t)arg2;

    unsigned num_fields = (unsigned)arg3;
    
    Z3_symbol const *field_names = (Z3_symbol const *)libData->MTensor_getIntegerData(arg4);
    
    Z3_sort const *field_sorts = (Z3_sort const *)libData->MTensor_getIntegerData(arg5);
    
    Z3_func_decl *mk_tuple_decl = (Z3_func_decl *)(uintptr_t)arg6;
    
    Z3_func_decl *proj_decl = (Z3_func_decl *)(uintptr_t)arg7;

    Z3_sort n = Z3_mk_tuple_sort(c, mk_tuple_name, num_fields, field_names, field_sorts, mk_tuple_decl, proj_decl);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkBvSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    unsigned sz = (unsigned)arg2;

    Z3_sort n = Z3_mk_bv_sort(c, sz);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkBvsub_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast t1 = (Z3_ast)(uintptr_t)arg2;

    Z3_ast t2 = (Z3_ast)(uintptr_t)arg3;

    Z3_ast n = Z3_mk_bvsub(c, t1, t2);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkBvsle_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast t1 = (Z3_ast)(uintptr_t)arg2;

    Z3_ast t2 = (Z3_ast)(uintptr_t)arg3;

    Z3_ast n = Z3_mk_bvsle(c, t1, t2);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkBvxor_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast t1 = (Z3_ast)(uintptr_t)arg2;

    Z3_ast t2 = (Z3_ast)(uintptr_t)arg3;

    Z3_ast n = Z3_mk_bvxor(c, t1, t2);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkBvmul_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast t1 = (Z3_ast)(uintptr_t)arg2;

    Z3_ast t2 = (Z3_ast)(uintptr_t)arg3;

    Z3_ast n = Z3_mk_bvmul(c, t1, t2);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getErrorCode_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_error_code n = Z3_get_error_code(c);

    int res = (int)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getErrorMsg_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_error_code err = arg2;

    Z3_string n = Z3_get_error_msg(c, err);

    char *res = (char *)n;

    MArgument_setUTF8String(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3parseSmtlib2String_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    char *arg2 = MArgument_getUTF8String(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    MTensor arg4 = MArgument_getMTensor(Args[3]);

    MTensor arg5 = MArgument_getMTensor(Args[4]);

    mint arg6 = MArgument_getInteger(Args[5]);

    MTensor arg7 = MArgument_getMTensor(Args[6]);

    MTensor arg8 = MArgument_getMTensor(Args[7]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_string str = (Z3_string)arg2;

    unsigned num_sorts = (unsigned)arg3;
    
    Z3_symbol const *sort_names = (Z3_symbol const *)libData->MTensor_getIntegerData(arg4);
    
    Z3_sort const *sorts = (Z3_sort const *)libData->MTensor_getIntegerData(arg5);
    
    unsigned num_decls = (unsigned)arg6;
    
    Z3_symbol const *decl_names = (Z3_symbol const *)libData->MTensor_getIntegerData(arg7);
    
    Z3_func_decl const *decls = (Z3_func_decl const *)libData->MTensor_getIntegerData(arg8);

    Z3_ast_vector n = Z3_parse_smtlib2_string(c, str, num_sorts, sort_names, sorts, num_decls, decl_names, decls);

    libData->UTF8String_disown(arg2);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3astVectorToString_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast_vector v = (Z3_ast_vector)(uintptr_t)arg2;

    Z3_string n = Z3_ast_vector_to_string(c, v);

    char *res = (char *)n;

    MArgument_setUTF8String(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3astVectorSize_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast_vector v = (Z3_ast_vector)(uintptr_t)arg2;

    unsigned n = Z3_ast_vector_size(c, v);

    mint res = (mint)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3astVectorGet_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast_vector v = (Z3_ast_vector)(uintptr_t)arg2;

    unsigned i = (unsigned)arg3;

    Z3_ast n = Z3_ast_vector_get(c, v, i);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkFalse_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast n = Z3_mk_false(c);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkIte_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    mint arg4 = MArgument_getInteger(Args[3]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast t1 = (Z3_ast)(uintptr_t)arg2;

    Z3_ast t2 = (Z3_ast)(uintptr_t)arg3;

    Z3_ast t3 = (Z3_ast)(uintptr_t)arg4;

    Z3_ast n = Z3_mk_ite(c, t1, t2, t3);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkEnumerationSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    MTensor arg4 = MArgument_getMTensor(Args[3]);

    mint arg5 = MArgument_getInteger(Args[4]);

    mint arg6 = MArgument_getInteger(Args[5]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_symbol name = (Z3_symbol)(uintptr_t)arg2;

    unsigned n = (unsigned)arg3;
    
    Z3_symbol const *enum_names = (Z3_symbol const *)libData->MTensor_getIntegerData(arg4);
    
    Z3_func_decl *enum_consts = (Z3_func_decl *)(uintptr_t)arg5;
    
    Z3_func_decl *enum_testers = (Z3_func_decl *)(uintptr_t)arg6;

    Z3_sort nn = Z3_mk_enumeration_sort(c, name, n, enum_names, enum_consts, enum_testers);

    uintptr_t res = (uintptr_t)nn;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkListSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    mint arg4 = MArgument_getInteger(Args[3]);

    mint arg5 = MArgument_getInteger(Args[4]);

    mint arg6 = MArgument_getInteger(Args[5]);

    mint arg7 = MArgument_getInteger(Args[6]);

    mint arg8 = MArgument_getInteger(Args[7]);

    mint arg9 = MArgument_getInteger(Args[8]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_symbol name = (Z3_symbol)(uintptr_t)arg2;
    
    Z3_sort elem_sort = (Z3_sort)(uintptr_t)arg3;
    
    Z3_func_decl* nil_decl = (Z3_func_decl* )(uintptr_t)arg4;
    
    Z3_func_decl* is_nil_decl = (Z3_func_decl*)(uintptr_t)arg5;
    
    Z3_func_decl* cons_decl = (Z3_func_decl*)(uintptr_t)arg6;
    
    Z3_func_decl* is_cons_decl = (Z3_func_decl* )(uintptr_t)arg7;
    
    Z3_func_decl* head_decl = (Z3_func_decl*)(uintptr_t)arg8;

    Z3_func_decl* tail_decl = (Z3_func_decl* )(uintptr_t)arg9;

    Z3_sort n = Z3_mk_list_sort(c, name, elem_sort, nil_decl, is_nil_decl, cons_decl, is_cons_decl, head_decl, tail_decl);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}


DLLEXPORT int Z3mkConstructor_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    mint arg4 = MArgument_getInteger(Args[3]);

    MTensor arg5 = MArgument_getMTensor(Args[4]);

    MTensor arg6 = MArgument_getMTensor(Args[5]);

    mint arg7 = MArgument_getInteger(Args[6]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_symbol name = (Z3_symbol)(uintptr_t)arg2;
    
    Z3_symbol recognizer = (Z3_symbol)(uintptr_t)arg3;
    
    unsigned num_fields = (unsigned)arg4;
    
    Z3_symbol const *field_names = (Z3_symbol const *)libData->MTensor_getIntegerData(arg5);
    
    Z3_sort_opt const *sorts = (Z3_sort_opt const *)libData->MTensor_getIntegerData(arg6);
    
    unsigned *sort_refs = (unsigned *)(uintptr_t)arg7;

    Z3_constructor n = Z3_mk_constructor(c, name, recognizer, num_fields, field_names, sorts, sort_refs);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkDatatype_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    mint arg4 = MArgument_getInteger(Args[3]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_symbol name = (Z3_symbol)(uintptr_t)arg2;

    unsigned num_constructors = (unsigned)arg3;

    Z3_constructor *constructors = (Z3_constructor *)(uintptr_t)arg4;

    Z3_sort n = Z3_mk_datatype(c, name, num_constructors, constructors);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}



DLLEXPORT int Z3astVectorDecRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast_vector v = (Z3_ast_vector)(uintptr_t)arg2;

    Z3_ast_vector_dec_ref(c, v);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3getNumeralInt_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast v = (Z3_ast)(uintptr_t)arg2;

    int64_t* i = (int64_t *)(uintptr_t)arg3;

    bool n = Z3_get_numeral_int64(c, v, i);

    mbool res = (mbool)n;

    MArgument_setBoolean(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3modelHasInterp_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_model m = (Z3_model)(uintptr_t)arg2;

    Z3_func_decl a = (Z3_func_decl)(uintptr_t)arg3;

    bool n = Z3_model_has_interp(c, m, a);

    mbool res = (mbool)n;

    MArgument_setBoolean(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3funcDeclToAst_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_func_decl f = (Z3_func_decl)(uintptr_t)arg2;

    Z3_ast n = Z3_func_decl_to_ast(c, f);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3addConstInterp_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    mint arg4 = MArgument_getInteger(Args[3]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_model m = (Z3_model)(uintptr_t)arg2;

    Z3_func_decl f = (Z3_func_decl)(uintptr_t)arg3;

    Z3_ast a = (Z3_ast)(uintptr_t)arg4;

    Z3_add_const_interp(c, m, f, a);

    return LIBRARY_NO_ERROR;
}




DLLEXPORT int Z3mkAsArray_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_func_decl f = (Z3_func_decl)(uintptr_t)arg2;

    Z3_ast n = Z3_mk_as_array(c, f);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3funcInterpAddEntry_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    mint arg4 = MArgument_getInteger(Args[3]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_func_interp fi = (Z3_func_interp)(uintptr_t)arg2;

    Z3_ast_vector args = (Z3_ast_vector)(uintptr_t)arg3;

    Z3_ast value = (Z3_ast)(uintptr_t)arg4;

    Z3_func_interp_add_entry(c, fi, args, value);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3astVectorPush_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast_vector v = (Z3_ast_vector)(uintptr_t)arg2;

    Z3_ast a = (Z3_ast)(uintptr_t)arg3;

    Z3_ast_vector_push(c, v, a);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3astVectorIncRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast_vector v = (Z3_ast_vector)(uintptr_t)arg2;

    Z3_ast_vector_inc_ref(c, v);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkAstVector_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast_vector n = Z3_mk_ast_vector(c);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkFreshFuncDecl_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    char *arg2 = MArgument_getUTF8String(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    MTensor arg4 = MArgument_getMTensor(Args[3]);

    mint arg5 = MArgument_getInteger(Args[4]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_string prefix = (Z3_string)arg2;

    unsigned domain_size = (unsigned)arg3;

    Z3_sort const *domain = (Z3_sort const *)libData->MTensor_getIntegerData(arg4);

    Z3_sort range = (Z3_sort)(uintptr_t)arg5;

    Z3_func_decl n = Z3_mk_fresh_func_decl(c, prefix, domain_size, domain, range);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkFpaToFpReal_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    mint arg4 = MArgument_getInteger(Args[3]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast rm = (Z3_ast)(uintptr_t)arg2;

    Z3_ast t = (Z3_ast)(uintptr_t)arg3;

    Z3_sort s = (Z3_sort)(uintptr_t)arg4;

    Z3_ast n = Z3_mk_fpa_to_fp_real(c, rm, t, s);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkFpaToFpIntReal_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    mint arg4 = MArgument_getInteger(Args[3]);

    mint arg5 = MArgument_getInteger(Args[4]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast rm = (Z3_ast)(uintptr_t)arg2;

    Z3_ast exp = (Z3_ast)(uintptr_t)arg3;

    Z3_ast sig = (Z3_ast)(uintptr_t)arg4;

    Z3_sort s = (Z3_sort)(uintptr_t)arg5;

    Z3_ast n = Z3_mk_fpa_to_fp_int_real(c, rm, exp, sig, s);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkFpaToFpBv_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast bv = (Z3_ast)(uintptr_t)arg2;

    Z3_sort s = (Z3_sort)(uintptr_t)arg3;

    Z3_ast n = Z3_mk_fpa_to_fp_bv(c, bv, s);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkFpaFp_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    mint arg4 = MArgument_getInteger(Args[3]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast sgn = (Z3_ast)(uintptr_t)arg2;

    Z3_ast exp = (Z3_ast)(uintptr_t)arg3;

    Z3_ast sig = (Z3_ast)(uintptr_t)arg4;

    Z3_ast n = Z3_mk_fpa_fp(c, sgn, exp, sig);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkFpaSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    unsigned ebits = (unsigned)arg2;

    unsigned sbits = (unsigned)arg3;

    Z3_sort n = Z3_mk_fpa_sort(c, ebits, sbits);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkFpaIsZero_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast t = (Z3_ast)(uintptr_t)arg2;

    Z3_ast n = Z3_mk_fpa_is_zero(c, t);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkFpaIsNan_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast t = (Z3_ast)(uintptr_t)arg2;

    Z3_ast n = Z3_mk_fpa_is_nan(c, t);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkFpaIsInfinite_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast t = (Z3_ast)(uintptr_t)arg2;

    Z3_ast n = Z3_mk_fpa_is_infinite(c, t);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkFpaRtz_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast n = Z3_mk_fpa_rtz(c);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkFpaAdd_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    mint arg4 = MArgument_getInteger(Args[3]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast rm = (Z3_ast)(uintptr_t)arg2;

    Z3_ast t1 = (Z3_ast)(uintptr_t)arg3;

    Z3_ast t2 = (Z3_ast)(uintptr_t)arg4;

    Z3_ast n = Z3_mk_fpa_add(c, rm, t1, t2);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkFpaNumeralDouble_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mreal arg2 = MArgument_getReal(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    double v = (double)arg2;

    Z3_sort ty = (Z3_sort)(uintptr_t)arg3;

    Z3_ast n = Z3_mk_fpa_numeral_double(c, v, ty);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkFpaRoundingModeSort_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_sort n = Z3_mk_fpa_rounding_mode_sort(c);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3substituteVars_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    MTensor arg4 = MArgument_getMTensor(Args[3]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast a = (Z3_ast)(uintptr_t)arg2;

    unsigned num_exprs = (unsigned)arg3;

    Z3_ast const *to = (Z3_ast const *)libData->MTensor_getIntegerData(arg4);

    Z3_ast n = Z3_substitute_vars(c, a, num_exprs, to);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkBound_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    unsigned index = (unsigned)arg2;

    Z3_sort ty = (Z3_sort)(uintptr_t)arg3;

    Z3_ast n = Z3_mk_bound(c, index, ty);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3substitute_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    MTensor arg4 = MArgument_getMTensor(Args[3]);

    MTensor arg5 = MArgument_getMTensor(Args[4]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast a = (Z3_ast)(uintptr_t)arg2;

    unsigned num_exprs = (unsigned)arg3;

    Z3_ast const *from = (Z3_ast const *)libData->MTensor_getIntegerData(arg4);

    Z3_ast const *to = (Z3_ast const *)libData->MTensor_getIntegerData(arg5);

    Z3_ast n = Z3_substitute(c, a, num_exprs, from, to);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3decRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast a = (Z3_ast)(uintptr_t)arg2;

    Z3_dec_ref(c, a);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3sortToAst_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_sort s = (Z3_sort)(uintptr_t)arg2;

    Z3_ast n = Z3_sort_to_ast(c, s);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3incRef_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_ast a = (Z3_ast)(uintptr_t)arg2;

    Z3_inc_ref(c, a);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkContextRc_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_config c = (Z3_config)(uintptr_t)arg1;

    Z3_context n = Z3_mk_context_rc(c);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3solverGetProof_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_solver s = (Z3_solver)(uintptr_t)arg2;

    Z3_ast n = Z3_solver_get_proof(c, s);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3solverGetUnsatCore_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_solver s = (Z3_solver)(uintptr_t)arg2;

    Z3_ast_vector n = Z3_solver_get_unsat_core(c, s);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3solverCheckAssumptions_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    MTensor arg4 = MArgument_getMTensor(Args[3]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_solver s = (Z3_solver)(uintptr_t)arg2;

    unsigned num_assumptions = (unsigned)arg3;

    Z3_ast const *assumptions = (Z3_ast const *)libData->MTensor_getIntegerData(arg4);

    Z3_lbool n = Z3_solver_check_assumptions(c, s, num_assumptions, assumptions);

    mint res = (mint)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3delConstructor_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_constructor constr = (Z3_constructor)(uintptr_t)arg2;

    Z3_del_constructor(c, constr);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3queryConstructor_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    mint arg4 = MArgument_getInteger(Args[3]);

    mint arg5 = MArgument_getInteger(Args[4]);

    mint arg6 = MArgument_getInteger(Args[5]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_constructor constr = (Z3_constructor)(uintptr_t)arg2;

    unsigned num_fields = (unsigned)arg3;

    Z3_func_decl *constructor = (Z3_func_decl *)(uintptr_t)arg4;

    Z3_func_decl *tester = (Z3_func_decl *)(uintptr_t)arg5;

    Z3_func_decl *accessors = (Z3_func_decl *)(uintptr_t)arg6;

    Z3_query_constructor(c, constr, num_fields, constructor, tester, accessors);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3delConstructorList_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_constructor_list clist = (Z3_constructor_list)(uintptr_t)arg2;

    Z3_del_constructor_list(c, clist);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkDatatypes_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    MTensor arg3 = MArgument_getMTensor(Args[2]);

    mint arg4 = MArgument_getInteger(Args[3]);

    mint arg5 = MArgument_getInteger(Args[4]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    unsigned num_sorts = (unsigned)arg2;

    Z3_symbol const *sort_names = (Z3_symbol const *)libData->MTensor_getIntegerData(arg3);

    Z3_sort *sorts = (Z3_sort *)(uintptr_t)arg4;

    Z3_constructor_list *constructor_lists = (Z3_constructor_list *)(uintptr_t)arg5;

    Z3_mk_datatypes(c, num_sorts, sort_names, sorts, constructor_lists);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3mkConstructorList_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
    
    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    MTensor arg3 = MArgument_getMTensor(Args[2]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    unsigned num_constructors = (unsigned)arg2;

    Z3_constructor const *constructors = (Z3_constructor const *)libData->MTensor_getIntegerData(arg3);

    Z3_constructor_list n = Z3_mk_constructor_list(c, num_constructors, constructors);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}


DLLEXPORT int Z3mkModel_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_model n = Z3_mk_model(c);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}

DLLEXPORT int Z3addFuncInterp_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    mint arg3 = MArgument_getInteger(Args[2]);

    mint arg4 = MArgument_getInteger(Args[3]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_model m = (Z3_model)(uintptr_t)arg2;

    Z3_func_decl f = (Z3_func_decl)(uintptr_t)arg3;

    Z3_ast default_value = (Z3_ast)(uintptr_t)arg4;

    Z3_func_interp n = Z3_add_func_interp(c, m, f, default_value);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}


DLLEXPORT int Z3getTupleSortMkDecl_LibraryLink(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {

    mint arg1 = MArgument_getInteger(Args[0]);

    mint arg2 = MArgument_getInteger(Args[1]);

    Z3_context c = (Z3_context)(uintptr_t)arg1;

    Z3_sort t = (Z3_sort)(uintptr_t)arg2;

    Z3_func_decl n = Z3_get_tuple_sort_mk_decl(c, t);

    uintptr_t res = (uintptr_t)n;

    MArgument_setInteger(Res, res);

    return LIBRARY_NO_ERROR;
}






