#ifndef _RandStrobeCreatorMAMode_hpp_
#define _RandStrobeCreatorMAMode_hpp_

#include "RandStrobeCreator.hpp"
typedef std::pair<uint64_t, size_t> pii;

class RandStrobeCreatorMAMod : public RandStrobeCreator
{
	public:
		RandStrobeCreatorMAMod(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK, uint64_t p = DEFAULT_P);
		
	protected:
		inline uint64_t get_score(uint64_t curr_hash, uint64_t new_strobe_pos);
		inline std::vector<Seed*> create_seeds();
		inline std::vector<Seed*> create_seeds_min();
		inline std::vector<Seed*> create_seeds_max();
		inline uint64_t get_final_hash(const Strobemer* strobemer);
		inline uint64_t get_new_curr_hash(const Strobemer* strobemer);
		uint64_t p;
		std::vector<uint64_t> real_hashes;
};

#endif