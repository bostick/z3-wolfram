
#pragma once

#include <z3.h>

extern Z3_error_code globalErrorCode;

void globalErrorHandler(Z3_context c, Z3_error_code e);

Z3_error_code getGlobalErrorCode();
