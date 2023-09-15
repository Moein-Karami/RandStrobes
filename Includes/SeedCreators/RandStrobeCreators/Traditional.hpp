#ifndef _Traditional_hpp_
#define _Traditional_hpp_

#include "RandStrobeCreator.hpp"

class Traditional : public RandStrobeCreator
{
	public:
		Traditional(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK);
		inline std::vector<Seed*> create_seeds(const std::string& sequence);

	protected:
		inline uint64_t get_score(uint64_t curr_hash, uint64_t new_strobe_pos);
};

#endif