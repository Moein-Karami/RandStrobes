#ifndef _RandStrobes_hpp_
#define _RandStrobes_hpp_

#include "LibrariesAndDefines.hpp"
#include "SeedCreator.hpp"

class RandStrobeCreator : private SeedCreator
{
	public:
		RandStrobeCreator(size_t kmer_len, size_t w_min, size_t w_max);

	protected:
		size_t kmer_len;
		size_t w_min;
		size_t w_max;
};

#endif