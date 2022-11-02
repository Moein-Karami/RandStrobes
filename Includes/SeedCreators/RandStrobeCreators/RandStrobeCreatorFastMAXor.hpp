#ifndef _RandStrobeCreatorFastMAXor_hpp_
#define _RandStrobeCreatorFastMAXor_hpp_

#include "RandStrobeCreator.hpp"
#include "MAXorNode.hpp"

class RandStrobeCreatorFastMAXor : public RandStrobeCreator
{
	public:
		RandStrobeCreatorFastMAXor(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK);
		std::vector<Seed*> create_seeds();
	protected:
		uint64_t get_score(uint64_t curr_hash, uint64_t first_ind, uint64_t last_ind);
};

#endif