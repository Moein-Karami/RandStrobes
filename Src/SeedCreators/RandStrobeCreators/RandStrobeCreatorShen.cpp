#include "RandStrobeCreatorShen.hpp"

RandStrobeCreatorShen::RandStrobeCreatorShen(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask, uint64_t p)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
, p(p)
{
}

uint64_t RandStrobeCreatorShen::get_score(const std::string& seq, const std::vector<uint64_t>& kmers,
			const std::vector<uint64_t> hashes, uint64_t curr_hash, uint64_t ind1, uint64_t ind2)
{
	return (curr_hash + hashes[ind2]) & p;
}
