#include "RandStrobeCreatorLiuPatroLi.hpp"

RandStrobeCreatorLiuPatroLi::RandStrobeCreatorLiuPatroLi(Hasher* hasher, Comparator* comparator, uint64_t kmer_len,
		uint64_t w_min, uint64_t w_max, uint64_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorLiuPatroLi::get_hash_concat(uint64_t kmer1, uint64_t kmer2)
{
    Int128 concated;
    concated.high = kmer1;
    concated.low = kmer2;
    return hasher->hash(&concated, sizeof(concated));
}

uint64_t  RandStrobeCreatorLiuPatroLi::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
    uint64_t score = get_hash_concat(curr_hash, kmers[new_strobe_pos]);
	return score;
}

uint64_t RandStrobeCreatorLiuPatroLi::get_first_hash(uint64_t ind)
{
    return kmers[ind];
}