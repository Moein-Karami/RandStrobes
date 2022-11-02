#ifndef _RandStrobeCreatorXorVar_hpp_
#define _RandStrobeCreatorXorVar_hpp_

#include "RandStrobeCreator.hpp"

class RandStrobeCreatorXorVar : public RandStrobeCreator
{
	public:
		RandStrobeCreatorXorVar(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK);

	protected:
		uint64_t get_score(uint64_t curr_hash, uint64_t new_strobe_pos);
		uint64_t get_first_hash(size_t ind);
};

#endif