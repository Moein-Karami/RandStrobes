#ifndef _XXHash_hpp_
#define _XXHash_hpp_

#include "LibrariesAndDefines.hpp"
#include "SeedBasedHasher.hpp"
#include "xxhash.h"

class XXHash : public SeedBasedHasher
{
	public:
		XXHash(uint64_t seed = DEFAULT_SEED);
		uint64_t hash(const void* key, size_t len);
};

#endif