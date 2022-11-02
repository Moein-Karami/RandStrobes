#ifndef _RandStrobeCreatorSahlinMod_hpp_
#define _RandStrobeCreatorSahlinMod_hpp_

#include "RandStrobeCreator.hpp"

class RandStrobeCreatorSahlinMod : public RandStrobeCreator
{
	public:
		RandStrobeCreatorSahlinMod(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK, uint64_t p = DEFAULT_P);
	protected:
		uint64_t p;
		uint64_t get_score(uint64_t curr_hash, uint64_t first_ind, uint64_t last_ind);
};

#endif