#include "XXHash.hpp"

XXHash::XXHash(uint64_t seed)
: SeedBasedHasher(seed)
{}

// inline uint64_t XXHash::hash(const void* key, size_t len)
// {
// 	return XXH3_64bits_withSeed(key, len, seed);
// }