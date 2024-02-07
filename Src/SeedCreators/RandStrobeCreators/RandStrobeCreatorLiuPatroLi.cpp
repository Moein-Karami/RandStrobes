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
    uint64_t score = get_hash_concat(curr_hash, kmers[new_strobe_pos]);
	return score;
}

inline uint64_t RandStrobeCreatorLiuPatroLi::get_first_hash(size_t ind)
{
    return kmers[ind];
}

inline std::vector<Seed*> RandStrobeCreatorLiuPatroLi::create_seeds()
{
	std::vector<Seed*> seeds;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;
	uint64_t new_score;
	std::vector<uint64_t> final_hashes;
	final_hashes.reserve(seq.size());

	bool min_comparator = comparator->is_first_better(1, 2);

    Int128 concated;

	if (min_comparator)
	{
		switch (hasher_code)
		{
			case 2:
				for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
				{
					concated.low = kmers[i];
					best_choose = i + w_min;
					concated.high = kmers[best_choose];
					best_value = (wyhash(&concated, sizeof(concated), kmers[i], _wyp));
					for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
					{
						concated.high = kmers[q];
						new_score = (wyhash(&concated, sizeof(concated), kmers[i], _wyp));
						if (new_score < best_value)
						{
							best_choose = q;
							best_value = new_score;
						}
					}
					final_hashes.push_back((hashes[i] << 1) - hashes[best_choose]);
				}
				break;
			case 3:
				for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
				{
					concated.low = kmers[i];
					best_choose = i + w_min;
					concated.high = kmers[best_choose];
					best_value = (XXH3_64bits_withSeed(&concated, sizeof(concated), 0));
					for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
					{
						concated.high = kmers[q];
						new_score = (XXH3_64bits_withSeed(&concated, sizeof(concated), 0));
						if (new_score < best_value)
						{
							best_choose = q;
							best_value = new_score;
						}
					}
					final_hashes.push_back((hashes[i] << 1) - hashes[best_choose]);
				}
				break;
			default:
				break;
		}
	}
	else
	{
		switch (hasher_code)
		{
			case 2:
				for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
				{
					concated.low = kmers[i];
					best_choose = i + w_min;
					concated.high = kmers[best_choose];
					best_value = (wyhash(&concated, sizeof(concated), kmers[i], _wyp));
					for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
					{
						concated.high = kmers[q];
						new_score = (wyhash(&concated, sizeof(concated), kmers[i], _wyp));
						if (new_score > best_value)
						{
							best_choose = q;
							best_value = new_score;
						}
					}
					final_hashes.push_back((hashes[i] << 1) - hashes[best_choose]);
				}
				break;
			case 3:
				for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
				{
					concated.low = kmers[i];
					best_choose = i + w_min;
					concated.high = kmers[best_choose];
					best_value = (XXH3_64bits_withSeed(&concated, sizeof(concated), 0));
					for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
					{
						concated.high = kmers[q];
						new_score = (XXH3_64bits_withSeed(&concated, sizeof(concated), 0));
						if (new_score > best_value)
						{
							best_choose = q;
							best_value = new_score;
						}
					}
					final_hashes.push_back((hashes[i] << 1) - hashes[best_choose]);
				}
				break;
			default:
				break;
		}
	}
	return seeds;
}