#include "RandStrobeCreatorShen.hpp"

RandStrobeCreatorShen::RandStrobeCreatorShen(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask, uint64_t q)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
, q(q)
{
}

inline uint64_t RandStrobeCreatorShen::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
	return (curr_hash + hashes[new_strobe_pos]) & q;
}