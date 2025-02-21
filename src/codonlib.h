#include <cpp11.hpp>
#include <sstream>
#include <vector>
#include <charconv>

// See https://docs.exaloop.io/codon/interoperability/cpp#converting-types
struct codon_str {
  int64_t len;
  char* data;
  codon_str(const std::string& str)
      : len(str.size() + 1), data(strdup(str.c_str())) {}
};

// For 2d array.
// See https://docs.exaloop.io/codon/interoperability/numpy#array-abi
struct ndarray_info {
  int64_t shape[2];
  int64_t strides[2];
  int64_t size;
};

struct ndarray_str {
  ndarray_info info;
  codon_str data;
};

inline cpp11::list info_to_list(ndarray_info info) {
  cpp11::integers dim(
      {static_cast<int>(info.shape[0]), static_cast<int>(info.shape[1])});
  cpp11::integers strides(
      {static_cast<int>(info.strides[0]), static_cast<int>(info.strides[1])});
  cpp11::integers len({static_cast<int>(info.size)});
  return cpp11::writable::list({dim, strides, len});
}

inline cpp11::doubles to_doubles(ndarray_str arr) {
  std::string body = arr.data.data;
  body.erase(std::remove_if(body.begin(), body.end(),
                            [](char c) {
                              return c == '[' || c == ']' || std::isspace(c);
                            }),
             body.end());

  std::istringstream iss(body);
  std::string token;
  double val;

  cpp11::writable::doubles result(static_cast<int>(arr.info.size));
  auto itr = result.begin();

  while (std::getline(iss, token, ',')) {
    auto [p, ec] =
        std::from_chars(token.data(), token.data() + token.size(), val);
    if (ec != std::errc()) {
      *itr = NA_REAL;
    } else {
      *itr = val;
    }
    ++itr;
  }
  result.attr("dim") = {static_cast<int>(arr.info.shape[0]),
                        static_cast<int>(arr.info.shape[1])};
  return result;
}

extern "C" {
ndarray_str foo(codon_str, int64_t, int64_t);
ndarray_info bar(codon_str, codon_str, int64_t, int64_t);
ndarray_str baz(codon_str);
}
