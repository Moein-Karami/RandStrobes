#ifndef _RandStrobeCreatorFullyRandom_hpp_
#define _RandStrobeCreatorFullyRandom_hpp_

#include "RandStrobeCreator.hpp"

class RandStrobeCreatorFullyRandom : public RandStrobeCreator
{
	public:
		RandStrobeCreatorFullyRandom(Hasher* hasher, Comparator* comparator, uint64_t kmer_len, uint64_t w_min, uint64_t w_max,
				uint64_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK);
		std::vector<Seed*> create_seeds(const std::string& sequence);
		uint64_t get_score(uint64_t curr_hash, uint64_t new_strobe_pos);
};

#endif 