#include "RandStrobeCreatorLiuPatroLi.hpp"

RandStrobeCreatorLiuPatroLi::RandStrobeCreatorLiuPatroLi(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorLiuPatroLi::get_hash_concat(uint64_t kmer1, uint64_t kmer2)
{
    if(kmer_len * 2 <= 64)
    {
        return hasher->hash(kmer1 << kmer_len + kmer2);
    }
    uint64_t arr_concat[2];
    arr_concat[0] = kmer1 + kmer2 >> (64 - kmer_len);
    arr_concat[1] = kmer2 << (64 - kmer_len);
    return hasher->hash(&arr_concat, kmer_len * 2);
}

uint64_t  RandStrobeCreatorLiuPatroLi::get_score(uint64_t curr_hash, uint64_t ind1, uint64_t ind2)
{
	return get_hash_concat(kmers[ind1], kmers[ind2]);
}
