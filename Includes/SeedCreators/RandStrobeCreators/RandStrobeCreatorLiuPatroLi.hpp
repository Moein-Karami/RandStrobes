#ifndef _RandStrobeCreatorLiuPatroLi_hpp_
#define _RandStrobeCreatorLiuPatroLi_hpp_

#include "RandStrobeCreator.hpp"

class RandStrobeCreatorLiuPatroLi : public RandStrobeCreator
{
	public:
		RandStrobeCreatorLiuPatroLi(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK);

		std::vector<Seed*> create_seeds(const std::string& seq, const std::vector<uint64_t>& kmers,
				const std::vector<uint64_t> hashes);
    
    private: 
        uint64_t get_hash_concat(uint64_t kmer1, uint64_t kmer2);
		
};

#endif