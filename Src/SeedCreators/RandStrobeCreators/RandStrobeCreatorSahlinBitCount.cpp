#include "RandStrobeCreatorSahlinBitCount.hpp"

RandStrobeCreatorSahlinBitCount::RandStrobeCreatorSahlinBitCount(Hasher* hasher, Comparator* comparator, uint64_t kmer_len,
		uint64_t w_min, uint64_t w_max, uint64_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorSahlinBitCount::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
	return __builtin_popcountll(curr_hash ^ hashes[new_strobe_pos]);
}