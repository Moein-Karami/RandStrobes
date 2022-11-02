#include "RandStrobeCreatorXorVar.hpp"

RandStrobeCreatorXorVar::RandStrobeCreatorXorVar(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorXorVar::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
	return hasher->hash(curr_hash ^ kmers[new_strobe_pos]);
}

uint64_t RandStrobeCreatorXorVar::get_first_hash(size_t ind)
{
    return kmers[ind];
}