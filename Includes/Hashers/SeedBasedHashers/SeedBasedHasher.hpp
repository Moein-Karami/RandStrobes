#ifndef _SeedBasedHasher_hpp_
#define _SeedBasedHasher_hpp_

#include "Hasher.hpp"

class SeedBasedHasher : public Hasher
{
	public:
		SeedBasedHasher(uint64_t seed = DEFAULT_SEED);

	protected:
		uint64_t seed;
};

#endif