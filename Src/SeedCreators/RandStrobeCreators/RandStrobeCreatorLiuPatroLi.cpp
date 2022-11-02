#include "RandStrobeCreatorLiuPatroLi.hpp"

RandStrobeCreatorLiuPatroLi::RandStrobeCreatorLiuPatroLi(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorLiuPatroLi::get_hash_concat(uint64_t kmer1, uint64_t kmer2)
{
    Int128 strobeconcat;
    strobeconcat.high = kmer1;
    strobeconcat.low = kmer2;
    return hasher->hash(&strobeconcat, sizeof(strobeconcat));
}

uint64_t  RandStrobeCreatorLiuPatroLi::get_score(uint64_t curr_hash, uint64_t first_ind, uint64_t last_ind)
{
    uint64_t score = get_hash_concat(curr_hash, kmers[last_ind]);
	return score;
}

uint64_t RandStrobeCreatorLiuPatroLi::get_first_hash(size_t ind)
{
    return kmers[ind];
}

uint64_t RandStrobeCreatorLiuPatroLi::get_new_curr_hash(uint64_t curr_hash, size_t first_ind, size_t last_ind)
{
	return hasher->hash(hashes[first_ind]) ^ hasher->hash(hashes[last_ind]);
}