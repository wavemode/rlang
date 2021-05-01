const rlang = require('bindings')('rlang')

rlang.hello("x <- 1:10")
rlang.hello("print(typeof(NA))")
