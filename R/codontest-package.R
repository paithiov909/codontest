#' @keywords internal
"_PACKAGE"

## usethis namespace: start
#' @useDynLib codontest, .registration = TRUE
## usethis namespace: end
NULL

#' @export
myfun <- function(n) {
  myfun_impl(n)
}
