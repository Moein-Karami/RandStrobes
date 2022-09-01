#ifndef _RandStrobeCreatorFastMAXor_hpp_
#define _RandStrobeCreatorFastMAXor_hpp_

#include "RandStrobeCreator.hpp"

class RandStrobeCreatorFastMAXor : public RandStrobeCreator
{
	public:
		RandStrobeCreatorFastMAXor(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK);
		std::vector<Seed*> create_seeds();
	protected:
		std::vector<size_t> indexes;
};

#endif