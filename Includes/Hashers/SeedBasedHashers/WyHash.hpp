#ifndef _WyHash_hpp_
#define _WyHash_hpp_

#include "SeedBasedHasher.hpp"
#include "wyhash.h"


class WyHash : public SeedBasedHasher
{
	public:
		WyHash(uint64_t seed = DEFAULT_SEED);
		uint64_t hash(const void* key, size_t len);
	protected:
		uint64_t _wyp[4];
};

#endif 