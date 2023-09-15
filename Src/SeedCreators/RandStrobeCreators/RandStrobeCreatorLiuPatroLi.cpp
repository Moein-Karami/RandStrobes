#include "RandStrobeCreatorLiuPatroLi.hpp"

RandStrobeCreatorLiuPatroLi::RandStrobeCreatorLiuPatroLi(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

inline uint64_t RandStrobeCreatorLiuPatroLi::get_hash_concat(uint64_t kmer1, uint64_t kmer2)
{
    Int128 concated;
    concated.high = kmer1;
    concated.low = kmer2;
    return hasher->hash(&concated, sizeof(concated));
}

inline uint64_t  RandStrobeCreatorLiuPatroLi::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
    uint64_t score = get_hash_concat(curr_hash, hashes[new_strobe_pos]);
	return score;
}

inline uint64_t RandStrobeCreatorLiuPatroLi::get_first_hash(size_t ind)
{
    return hashes[ind];
}

inline uint64_t RandStrobeCreatorLiuPatroLi::get_final_hash(const Strobemer* strobemer)
{
	uint64_t final_hash = 0;
	std::vector<uint32_t> positions = strobemer->get_positions();
	// for (auto pos : positions)
	// 	final_hash ^= hasher->hash(hashes[pos]);

	// for (int i = 0; i < positions.size(); i++)
	// {
	// 	if (i % 2 == 0)
	// 		final_hash ^= wy_hasher->hash(xx_hasher->hash(kmers[positions[i]]));
	// 	else
	// 		final_hash ^= xx_hasher->hash(wy_hasher->hash(kmers[positions[i]]));
	// }

	// for (int i = 0; i < strobemer->last; i++)
	// 	final_hash ^= hasher->hash(hashes[strobemer->positions[i]]);

	// final_hash = xx_hasher->hash(kmers[positions[0]]);
	final_hash = hashes[positions[0]];
	Int128 tmp;
	for (int i = 1; i < positions.size(); i++)
	{
		tmp.low = xx_hasher->hash(final_hash);
		tmp.high = xx_hasher->hash(hashes[positions[i]]);
		final_hash = wy_hasher->hash(&tmp, sizeof(tmp));
        // final_hash = hashes[positions[i]] + final_hash;
	}

	return final_hash;
}