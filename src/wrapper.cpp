#include "codonlib.h"

using namespace cpp11;

// Takes comma-delimited string of numbers and parses it into ndarray,
// then adds 1.0.
//
// @param file: Path to the file where the array will be saved.
// @param dat: Comma-delimited string representing the array data.
// @param dim: Integer vector specifying the dimensions (rows and columns) of
// the array.
// @return A numeric matrix.
[[cpp11::register]]
doubles add_one_impl(std::string dat, integers dim) {
  if (dim.size() != 2) {
    throw std::runtime_error("dim must be length 2");
  }
  // Get ndarray data as string via `str(ndarray.tolist())`.
  const ndarray_str arr = foo(dat, dim[0], dim[1]);
  // Then, parse it into doubles. This way is ugly, however,
  // I didn't find how to retrieve actual data from ndarray via `double* data`.
  const doubles result = to_doubles(arr);

  return result;
}

// Saves matrix to `file`
//
// @param file: Path to the file where the array will be saved.
// @param dat: Comma-delimited string representing the array data.
// @param dim: Integer vector specifying the dimensions (rows and columns) of
// the array.
// @return A list containing information about the array
[[cpp11::register]]
list save_npy_impl(std::string file, std::string dat, integers dim) {
  if (dim.size() != 2) {
    throw std::runtime_error("dim must be length 2");
  }
  const ndarray_info info = bar(file, dat, dim[0], dim[1]);
  return info_to_list(info);
}

// Reads matrix from `file`
//
// @param file: Path to the file where the array will be saved.
// @param dat: Comma-delimited string representing the array data.
// @param dim: Integer vector specifying the dimensions (rows and columns) of
// the array.
// @return A numeric matrix (needs to be transposed)
[[cpp11::register]]
doubles read_npy_impl(std::string file) {
  const ndarray_str arr = baz(file);
  return to_doubles(arr);
}
