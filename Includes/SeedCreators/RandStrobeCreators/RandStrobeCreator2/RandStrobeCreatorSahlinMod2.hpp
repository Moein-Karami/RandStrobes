#ifndef _RandStrobeCreatorSahlinMod2_hpp_
#define _RandStrobeCreatorSahlinMod2_hpp_

#include "RandStrobeCreator2.hpp"

class RandStrobeCreatorSahlinMod2 : public RandStrobeCreator2
{
	public:
		RandStrobeCreatorSahlinMod2(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint64_t mask = DEFAULT_MASK, uint64_t p = DEFALUT_P);
		std::vector<Seed*> creat_seeds(const std::string& seed, const std::vector<uint64_t>& hashes);
	private:
		uint64_t p;

};

#endif