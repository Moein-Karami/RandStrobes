#include "RandStrobeCreatorRandomMAMod.hpp"

RandStrobeCreatorRandomMAMod::RandStrobeCreatorRandomMAMod(Hasher* hasher, Comparator* comparator, uint64_t kmer_len, uint64_t w_min, uint64_t w_max,
		uint64_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorRandomMAMod::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
	Int128 tmp;
	tmp.high = curr_hash;
	tmp.low = hashes[new_strobe_pos];
	uint64_t p = hasher->hash(&tmp, sizeof(tmp));
	return (curr_hash % p + hashes[new_strobe_pos] % p) % p;
}
