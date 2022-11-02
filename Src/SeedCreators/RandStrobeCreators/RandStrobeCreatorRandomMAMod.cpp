#include "RandStrobeCreatorRandomMAMod.hpp"

RandStrobeCreatorRandomMAMod::RandStrobeCreatorRandomMAMod(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
		uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorRandomMAMod::get_score(uint64_t curr_hash, uint64_t ind1, uint64_t ind2)
{
	Int128 tmp;
	tmp.high = curr_hash;
	tmp.low = hashes[ind2];
	uint64_t p = hasher->hash(&tmp, sizeof(tmp));
	return (curr_hash % p + hashes[ind2] % p) % p;
}

uint64_t RandStrobeCreatorRandomMAMod::get_value_to_choose_third_strobe(uint64_t curr_hash, uint64_t ind1, uint64_t ind2)
{
	return hasher->hash(hashes[ind1]) ^ hasher->hash(hashes[ind2]);;
}