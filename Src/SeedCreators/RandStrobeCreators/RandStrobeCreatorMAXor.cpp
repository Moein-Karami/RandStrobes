#include "RandStrobeCreatorMAXor.hpp"

RandStrobeCreatorMAXor::RandStrobeCreatorMAXor(Hasher* hasher, Comparator* comparator, uint64_t kmer_len, uint64_t w_min, uint64_t w_max,
		uint64_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorMAXor::get_first_hash(uint64_t ind)
{
	return kmers[ind];
}

uint64_t RandStrobeCreatorMAXor::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
	return curr_hash ^ hashes[new_strobe_pos] ^ hasher->hash(curr_hash ^ kmers[new_strobe_pos]);
}