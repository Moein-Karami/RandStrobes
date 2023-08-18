#include "RandStrobeCreatorFixedSahlinMod.hpp"

RandStrobeCreatorFixedSahlinMod::RandStrobeCreatorFixedSahlinMod(Hasher* hasher, Comparator* comparator, uint64_t kmer_len, uint64_t w_min, uint64_t w_max,
		uint64_t n, uint64_t mask, uint64_t p)
: RandStrobeCreatorSahlinMod(hasher, comparator, kmer_len, w_min, w_max, n, mask, p)
{
}

void RandStrobeCreatorFixedSahlinMod::prepare_data()
{
	for (uint64_t i = 0; i < hashes.size(); i++)
		hashes[i] %= p;
}

uint64_t RandStrobeCreatorFixedSahlinMod::get_new_curr_hash(const Strobemer* strobemer)
{
	return get_final_hash(strobemer) % p;
}