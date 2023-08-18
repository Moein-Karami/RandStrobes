#ifndef _RandStrobeCreatorSahlinMod_hpp_
#define _RandStrobeCreatorSahlinMod_hpp_

#include "RandStrobeCreator.hpp"

class RandStrobeCreatorSahlinMod : public RandStrobeCreator
{
	public:
		RandStrobeCreatorSahlinMod(Hasher* hasher, Comparator* comparator, uint64_t kmer_len, uint64_t w_min, uint64_t w_max,
				uint64_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK, uint64_t p = DEFAULT_P);
	protected:
		uint64_t p;
		uint64_t get_score(uint64_t curr_hash, uint64_t new_strobe_pos);
};

#endif