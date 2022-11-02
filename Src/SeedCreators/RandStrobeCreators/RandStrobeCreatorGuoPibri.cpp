#include "RandStrobeCreatorGuoPibri.hpp"

RandStrobeCreatorGuoPibri::RandStrobeCreatorGuoPibri(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorGuoPibri::get_score(uint64_t curr_hash, uint64_t first_ind, uint64_t last_ind)
{
	return (curr_hash ^ hashes[ind2]);
}

uint64_t RandStrobeCreatorGuoPibri::get_new_curr_hash(uint64_t curr_hash, uint64_t first_ind, uint64_t last_ind)
{
	return hasher->hash(curr_hash) ^ hasher->hash(hashes[last_ind]);
}