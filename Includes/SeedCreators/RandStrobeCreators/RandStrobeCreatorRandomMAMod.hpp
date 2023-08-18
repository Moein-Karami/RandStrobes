#ifndef _RandStrobeCreatorRandomMAMod_hpp_
#define _RandStrobeCreatorRandomMAMod_hpp_

#include "RandStrobeCreator.hpp"

class RandStrobeCreatorRandomMAMod : public RandStrobeCreator
{
	public:
		RandStrobeCreatorRandomMAMod(Hasher* hasher, Comparator* comparator, uint64_t kmer_len, uint64_t w_min, uint64_t w_max,
				uint64_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK);
	protected:
		uint64_t get_score(uint64_t curr_hash, uint64_t new_strobe_pos);
};

#endif