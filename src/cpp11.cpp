// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"
#include <R_ext/Visibility.h>

// wrapper.cpp
int myfun_impl(int n);
extern "C" SEXP _codontest_myfun_impl(SEXP n) {
  BEGIN_CPP11
    return cpp11::as_sexp(myfun_impl(cpp11::as_cpp<cpp11::decay_t<int>>(n)));
  END_CPP11
}

extern "C" {
static const R_CallMethodDef CallEntries[] = {
    {"_codontest_myfun_impl", (DL_FUNC) &_codontest_myfun_impl, 1},
    {NULL, NULL, 0}
};
}

extern "C" attribute_visible void R_init_codontest(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
