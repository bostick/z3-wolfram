
#include "utils.h"

Z3_error_code globalErrorCode = Z3_OK;

void globalErrorHandler(Z3_context c, Z3_error_code e) {
    globalErrorCode = e;
}

Z3_error_code getGlobalErrorCode() {
    return globalErrorCode;
}
