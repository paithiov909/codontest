# codontest


<!-- README.md is generated from README.Rmd. Please edit that file -->

<!-- badges: start -->

[![Lifecycle:
experimental](https://img.shields.io/badge/lifecycle-experimental-orange.svg)](https://lifecycle.r-lib.org/articles/stages.html#experimental)
<!-- badges: end -->

An experimental R package that compiles
[Codon](https://docs.exaloop.io/codon) scripts at build time.

## Installation

To build from source package, you need to install
[Codon](https://docs.exaloop.io/codon) and set `CODON_DIR` environment
variable. Codon will be installed at `~/.codon` by default, so typically
it will be `"$HOME/.codon"`.

## Example

``` r
pkgload::load_all(export_all = FALSE)
#> ℹ Loading codontest

x <- add_one(matrix(1:9, nrow = 3, ncol = 3))
#> 3 × 3 array of float
#> ╭─────┬─────┬─────╮
#> │  2. │  3. │  4. │
#> ├─────┼─────┼─────┤
#> │  5. │  6. │  7. │
#> ├─────┼─────┼─────┤
#> │  8. │  9. │ 10. │
#> ╰─────┴─────┴─────╯
#> (info: (shape: (3, 3), strides: (24, 8), size: 9), data: '[[2, 3, 4], [5, 6, 7], [8, 9, 10]]')

npy_file <- tempfile(fileext = ".npy")
y <- save_npy(x, npy_file)
#> 3 × 3 array of float
#> ╭─────┬─────┬─────╮
#> │  2. │  3. │  4. │
#> ├─────┼─────┼─────┤
#> │  5. │  6. │  7. │
#> ├─────┼─────┼─────┤
#> │  8. │  9. │ 10. │
#> ╰─────┴─────┴─────╯
y
#> $shape
#> [1] 3 3
#>
#> $strides
#> [1] 24  8
#>
#> $size
#> [1] 9

read_npy(npy_file)
#> 3 × 3 array of float
#> ╭─────┬─────┬─────╮
#> │  2. │  3. │  4. │
#> ├─────┼─────┼─────┤
#> │  5. │  6. │  7. │
#> ├─────┼─────┼─────┤
#> │  8. │  9. │ 10. │
#> ╰─────┴─────┴─────╯
#>      [,1] [,2] [,3]
#> [1,]    2    3    4
#> [2,]    5    6    7
#> [3,]    8    9   10

RcppCNPy::npyLoad(npy_file)
#>      [,1] [,2] [,3]
#> [1,]    2    3    4
#> [2,]    5    6    7
#> [3,]    8    9   10
```
