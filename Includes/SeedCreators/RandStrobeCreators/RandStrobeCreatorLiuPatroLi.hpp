#ifndef _RandStrobeCreatorLiuPatroLi_hpp_
#define _RandStrobeCreatorLiuPatroLi_hpp_

#include "RandStrobeCreator.hpp"

typedef struct { uint64_t high; uint64_t low; } Int128;

class RandStrobeCreatorLiuPatroLi : public RandStrobeCreator
{
	public:
		RandStrobeCreatorLiuPatroLi(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK);
		uint64_t get_first_hash(size_t ind);

    protected:
		uint64_t get_score(uint64_t curr_hash,uint64_t ind1, uint64_t ind2);
        uint64_t get_hash_concat(uint64_t kmer1, uint64_t kmer2);
		
};

#endif