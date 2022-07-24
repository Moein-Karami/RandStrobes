#ifndef _RandStrobeCreatorGuoPibri_hpp_
#define _RandStrobeCreatorGuoPibri_hpp_

#include "RandStrobeCreator.hpp"

class RandStrobeCreatorGuoPibri : public RandStrobeCreator
{
	public:
		RandStrobeCreatorGuoPibri(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint8_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK);

		std::vector<Seed*> creat_seeds(const std::string& seq, const std::vector<uint64_t>& kmers,
				const std::vector<uint64_t> hashes);
};

#endif