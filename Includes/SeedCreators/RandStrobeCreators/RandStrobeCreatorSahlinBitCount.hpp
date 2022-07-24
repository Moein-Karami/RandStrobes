#ifndef _RandStrobeCreatorSahlinBitCount_hpp_
#define _RandStrobeCreatorSahlinBitCount_hpp_

#include "RandStrobeCreator.hpp"

class RandStrobeCreatorSahlinBitCount : public RandStrobeCreator
{
	public:
		RandStrobeCreatorSahlinBitCount(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint8_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK);

		std::vector<Seed*> creat_seeds(const std::string& seed, const std::vector<uint64_t>& hashes);
		
};

#endif