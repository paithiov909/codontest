#include <cpp11.hpp>
#include "codonlib.h"

using namespace cpp11;

[[cpp11::register]]
int myfun_impl(int n) {
  return foo(n);
}
