#include "RandStrobeCreatorShen.hpp"

RandStrobeCreatorShen::RandStrobeCreatorShen(Hasher* hasher, Comparator* comparator, uint64_t kmer_len,
		uint64_t w_min, uint64_t w_max, uint64_t n, uint64_t mask, uint64_t q)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
, q(q)
{
}

uint64_t RandStrobeCreatorShen::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
	return (curr_hash + hashes[new_strobe_pos]) & q;
}