#include "RandStrobeCreatorMAXor.hpp"

RandStrobeCreatorMAXor::RandStrobeCreatorMAXor(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
		uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorMAXor::get_first_hash(size_t ind)
{
	return kmers[ind];
}

uint64_t RandStrobeCreatorMAXor::get_score(uint64_t curr_hash, uint64_t ind1, uint64_t ind2)
{
	return curr_hash ^ hashes[ind2] ^ hasher->hash(curr_hash ^ kmers[ind2]);
}

uint64_t RandStrobeCreatorMAXor::get_new_curr_hash(uint64_t curr_hash, uint64_t ind1, uint64_t ind2)
{
	return hasher->hash(hashes[ind1]) ^ hasher->hash(hashes[ind2]);;
}