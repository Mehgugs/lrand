local lrand = require"lrand"

print(lrand.version)

--- new
local rng = lrand.new(12345)
print(rng)

--- clone
print"Testing clone"
local rng2 = rng:clone()
assert(rng() == rng2(), "Clone did not return an identical state!")
print"Clone passed"

--- seed
print"Testing seed"
rng:seed()
assert(rng() == 6708800777304496116)
print"Seed passed"

---signedness
print"Testing randu64 vs. randi64"
rng()
rng2 = rng:clone()
assert(rng:randu64() < 0 and rng2:randi64() >= 0, "randi64 wasn't in the correct range.")
print"randu64 and randi64 pass"

---type
print"Checking math.type agrees"
assert(
    math.type(rng:randu64()) == math.type(rng:randi64())
    and math.type(rng:randu64()) == 'integer'
    ,"integers are not returned by randu64 and/or randi64"
)
print"Type passed"

---doubles
print"Test randd"
assert(math.type(rng:randd()) == 'float')
print"randd passed"

print"OK"