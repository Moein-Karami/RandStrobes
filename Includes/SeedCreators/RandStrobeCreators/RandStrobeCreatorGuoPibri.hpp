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
		inline uint64_t get_score(uint64_t curr_hash, uint64_t new_strobe_pos);
		inline std::vector<Seed*> create_seeds();
};

#endif