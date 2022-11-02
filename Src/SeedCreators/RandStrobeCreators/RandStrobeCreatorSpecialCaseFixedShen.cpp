#include "RandStrobeCreatorSpecialCaseFixedShen.hpp"

RandStrobeCreatorSpecialCaseFixedShen::RandStrobeCreatorSpecialCaseFixedShen(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
		uint32_t n, uint64_t mask, uint64_t q)
: RandStrobeCreatorShen(hasher, comparator, kmer_len, w_min, w_max, n, mask, q)
{
}

void RandStrobeCreatorSpecialCaseFixedShen::prepare_data()
{
	for (size_t i = 0; i < hashes.size(); i++)
		hashes[i] &= q;
}

uint64_t RandStrobeCreatorSpecialCaseFixedShen::get_value_to_choose_third_strobe(uint64_t curr_hash, uint64_t ind1, uint64_t ind2)
{
	return (hasher->hash(hashes[ind1]) ^ hasher->hash(hashes[ind2])) & q;
}