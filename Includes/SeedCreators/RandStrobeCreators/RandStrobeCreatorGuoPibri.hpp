#ifndef _RandStrobeCreatorGuoPibri_hpp_
#define _RandStrobeCreatorGuoPibri_hpp_

#include "RandStrobeCreator.hpp"

const uint64_t p = 997;

class RandStrobeCreatorGuoPibri : public RandStrobeCreator
{
	public:
		RandStrobeCreatorGuoPibri(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK);

	protected:
		uint64_t get_score(uint64_t curr_hash, uint64_t first_ind, uint64_t last_ind);
		uint64_t get_new_curr_hash(uint64_t curr_hash, uint64_t first_ind, uint64_t last_ind);
};

#endif