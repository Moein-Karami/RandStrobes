#include "RandStrobeCreatorSahlinBitCount.hpp"

RandStrobeCreatorSahlinBitCount::RandStrobeCreatorSahlinBitCount(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorSahlinBitCount::get_score(const std::string& seq, const std::vector<uint64_t>& kmers,
			const std::vector<uint64_t> hashes, uint64_t curr_hash, uint64_t ind1, uint64_t ind2)
{
	return __builtin_popcount(curr_hash ^ hashes[ind2]);
}

