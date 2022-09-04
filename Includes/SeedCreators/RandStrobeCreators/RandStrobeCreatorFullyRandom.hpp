#ifndef _RandStrobeCreatorFullyRandom_hpp_
#define _RandStrobeCreatorFullyRandom_hpp_

#include "RandStrobeCreator.hpp"

class RandStrobeCreatorFullyRandom : public RandStrobeCreator
{
	public:
		RandStrobeCreatorFullyRandom(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK);
		std::vector<Seed*> create_seeds(const std::string& sequence);
		uint64_t get_score(uint64_t curr_hash, uint64_t ind1, uint64_t ind2);
};

#endif 