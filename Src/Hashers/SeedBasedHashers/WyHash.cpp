#include "WyHash.hpp"

WyHash::WyHash(uint64_t seed)
: SeedBasedHasher(seed)
{
	srand(seed);
	for (int i = 0; i < 4; i++)
		_wyp[i] = rand();
	// for (int i = 0; i < 4; i++)
	// 	_wyp[i] = i;
}

uint64_t WyHash::hash(const void* key, size_t len)
{
		return wyhash(key, len, seed, _wyp);
}