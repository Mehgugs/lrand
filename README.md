## LRand : An updated version of lrandom for 5.3

### About ###
"A library for generating random numbers based on the Mersenne Twister,
a pseudorandom number generating algorithm developped by Makoto Matsumoto
and Takuji Nishimura (alphabetical order) in 1996/1997."

### API ###

#### `table` require"lrand" ####
>The module table containing the API.

#### `string` lrand.version ####
>The version string.

#### `lrand_state` lrand.new([seed]) ####
>Creates a new `lrand_state`, optionally seeded with a lua integer.

#### `lrand_state` lrand.clone(state) ####
> Can also be called from the state `state:clone()`.
>
>Clones the state into a new `lrand_state`.

#### `lrand_state` lrand.seed(state[, seed]) ####
> Can also be called from the state `state:seed([seed])`.
>
>Reseeds the state with an optional lua integer.

#### `integer` lrand.randu64(state) ####
> Can also be called from the state `state:randu64()`.
>
> Consumes a random unsigned int64 from the state which is returned as a lua integer.
>
> (`raw range: [0, 2^64-1]`) (`range in lua: [math.mininteger, math.maxinteger]`)

#### `integer` lrand.randi64(state) ####
> Can also be called from the state `state:randi64()`.
>
> Consumes a random int64 from the state which is returned as a lua integer.
>
> (`raw range: [0, 2^63-1]`) (`range in lua: [0, math.maxinteger] (may overflow in 'small lua')`)

#### `number` lrand.randd(state) ####
> Can also be called from the state `state:randd()`.
>
> Consumes a random real number from the state which is returned as a lua number.
>
> (`raw range: [0, 1]`) (`range in lua: [0,1]`)


