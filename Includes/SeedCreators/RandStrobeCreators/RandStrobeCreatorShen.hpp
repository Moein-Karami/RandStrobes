#ifndef _RandStrobeCreatorShen_hpp_
#define _RandStrobeCreatorShen_hpp_

#include "RandStrobeCreator.hpp"

class RandStrobeCreatorShen : public RandStrobeCreator
{
	public :
		RandStrobeCreatorShen(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK, uint64_t q = DEFAULT_Q);
	
	protected:
		uint64_t q;
		inline uint64_t get_score(uint64_t curr_hash, uint64_t new_strobe_pos);
		inline std::vector<Seed*> create_seeds();
};

#endif
