#ifndef _RandStrobeCreatorMAMode_hpp_
#define _RandStrobeCreatorMAMode_hpp_

#include "RandStrobeCreator.hpp"
typedef std::pair<uint64_t, size_t> pii;

class RandStrobeCreatorMAMod : public RandStrobeCreator
{
	public:
		RandStrobeCreatorMAMod(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK, uint64_t p = 19019684767739993LL);
		
	protected:
		uint64_t get_score(uint64_t curr_hash, uint64_t new_strobe_pos);
		std::vector<Seed*> create_seeds();
		std::vector<Seed*> create_seeds_min();
		std::vector<Seed*> create_seeds_max();
		uint64_t get_final_hash(const Strobemer* strobemer);
		uint64_t get_new_curr_hash(const Strobemer* strobemer);
		uint64_t p;
};

#endif