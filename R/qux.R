#' Add 1 to all elements of a matrix
#'
#' @param x Numeric matrix
#' @returns Numeric matrix
#' @export
add_one <- function(x) {
  stopifnot(
    is.numeric(x),
    is.matrix(x)
  )
  shape <- dim(x)
  mat <- paste(as.vector(x), collapse = ",") |>
    gsub(pattern = "NA", replacement = "nan", x = _, fixed = TRUE)
  add_one_impl(mat, shape)
}

#' Save a matrix to a '.npy' file
#'
#' @param x Numeric matrix
#' @param file Path to '.npy' file
#' @returns A list containing information about the saved array.
#' @export
save_npy <- function(x, file = tempfile(fileext = ".npy")) {
  stopifnot(
    is.numeric(x),
    is.matrix(x)
  )
  file <- path.expand(file)
  shape <- dim(x)
  mat <- paste(as.vector(x), collapse = ",") |>
    gsub(pattern = "NA", replacement = "nan", x = _, fixed = TRUE)
  info <- save_npy_impl(file, mat, shape)
  names(info) <- c("shape", "strides", "size")
  info
}

#' Read a matrix from a '.npy' file
#'
#' @param file Path to '.npy' file
#' @param do_transpose Logical. Should the loaded matrix be transposed?
#' @returns Numeric matrix
#' @export
read_npy <- function(file, do_transpose = TRUE) {
  file <- path.expand(file)
  mat <- read_npy_impl(file)
  if (!do_transpose) {
    return(mat)
  }
  t(mat)
}
