#ifndef _XXHash_hpp_
#define _XXHash_hpp_

#include "LibrariesAndDefines.hpp"
#include "SeedBasedHasher.hpp"
#include "xxhash.h"

class XXHash : public SeedBasedHasher
{
	public:
		XXHash(uint64_t seed = DEFAULT_SEED);
		inline uint64_t hash(const void* key, size_t len)
		{
			return XXH3_64bits_withSeed(key, len, seed);
		}
		inline int get_type()
		{
			return 3;
		}
};

#endif