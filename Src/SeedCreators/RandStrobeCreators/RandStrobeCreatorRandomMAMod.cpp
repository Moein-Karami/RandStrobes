#include "RandStrobeCreatorRandomMAMod.hpp"

RandStrobeCreatorRandomMAMod::RandStrobeCreatorRandomMAMod(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
		uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorRandomMAMod::get_score(uint64_t curr_hash, uint64_t first_ind, uint64_t last_ind)
{
	Int128 tmp;
	tmp.high = curr_hash;
	tmp.low = hashes[last_ind];
	uint64_t p = hasher->hash(&tmp, sizeof(tmp));
	return (curr_hash % p + hashes[last_ind] % p) % p;
}
