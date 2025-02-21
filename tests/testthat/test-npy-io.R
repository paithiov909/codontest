test_that("npy io works", {
  temp <- tempfile(fileext = ".npy")
  expected <- matrix(1:9, nrow = 3, ncol = 3)

  capture.output({
    info <- save_npy(expected, temp)
  })
  expect_equal(info[["shape"]], c(3, 3))
  expect_equal(info[["size"]], 9)

  capture.output({
    actual <- read_npy(temp, do_transpose = FALSE)
  })
  expect_equal(actual, expected)
})
