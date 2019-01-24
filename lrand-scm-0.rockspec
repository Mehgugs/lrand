package = "lrand"
version = "scm-0"
source = {
    url = "git://github.com/Mehgugs/lrand.git"
}
description = {
    summary = "A 5.3 library for generating random numbers.",
    detailed = [[
        "A library for generating random numbers based on the Mersenne Twister,
        a pseudorandom number generating algorithm developped by Makoto Matsumoto
        and Takuji Nishimura (alphabetical order) in 1996/1997."
        This is based on the package lrandom which is for lua 5.1.
    ]],
    homepage = "https://github.com/Mehgugs/lrand"
}
dependencies = {
    "lua >= 5.3"
}
build = {
    type = "builtin",
    modules = {
       lrand = "lrand.c"
    }
 }