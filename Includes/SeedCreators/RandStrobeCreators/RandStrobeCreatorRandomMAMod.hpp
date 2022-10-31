#ifndef _RandStrobeCreatorRandomMAMod_hpp_
#define _RandStrobeCreatorRandomMAMod_hpp_

#include "RandStrobeCreator.hpp"

class RandStrobeCreatorRandomMAMod : public RandStrobeCreator
{
	public:
		RandStrobeCreatorRandomMAMod(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK);
	protected:
		uint64_t get_score(uint64_t curr_hash, uint64_t ind1, uint64_t ind2);
		uint64_t get_value_to_choose_third_strobe(uint64_t curr_hash, uint64_t ind1, uint64_t ind2);
};

#endif