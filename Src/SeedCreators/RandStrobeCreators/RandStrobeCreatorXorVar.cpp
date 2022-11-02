#include "RandStrobeCreatorXorVar.hpp"

RandStrobeCreatorXorVar::RandStrobeCreatorXorVar(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorXorVar::get_score(uint64_t curr_hash, uint64_t first_ind, uint64_t last_ind)
{
	return hasher->hash(curr_hash ^ kmers[last_ind]);
}

uint64_t RandStrobeCreatorXorVar::get_first_hash(size_t ind)
{
    return kmers[ind];
}