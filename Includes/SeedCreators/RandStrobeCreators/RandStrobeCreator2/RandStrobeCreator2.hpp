#ifndef _RandStrobeCreator2_hpp_
#define _RandStrobeCreator2_hpp_

#include "RandStrobeCreator.hpp"

class RandStrobeCreator2 : public RandStrobeCreator
{
	public:
		RandStrobeCreator2(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max, uint64_t mask = DEFAULT_MASK);
};

#endif