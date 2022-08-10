#ifndef _RandStrobeCreatorXorVar_hpp_
#define _RandStrobeCreatorXorVar_hpp_

#include "RandStrobeCreator.hpp"

class RandStrobeCreatorXorVar : public RandStrobeCreator
{
	public:
		RandStrobeCreatorXorVar(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK);

		std::vector<Seed*> create_seeds(const std::string& seq, const std::vector<uint64_t>& kmers,
				const std::vector<uint64_t> hashes);
	protected:
		uint64_t get_score(const std::string& seq, const std::vector<uint64_t>& kmers,
			const std::vector<uint64_t> hashes, uint64_t curr_hash, uint64_t ind1, uint64_t ind2);
};

#endif