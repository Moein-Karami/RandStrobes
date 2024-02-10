#include "RandStrobeCreatorXorVar.hpp"

RandStrobeCreatorXorVar::RandStrobeCreatorXorVar(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

inline uint64_t RandStrobeCreatorXorVar::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
	return hasher->hash(curr_hash ^ kmers[new_strobe_pos]);
}

inline uint64_t RandStrobeCreatorXorVar::get_first_hash(size_t ind)
{
    return kmers[ind];
}

inline std::vector<Seed*> RandStrobeCreatorXorVar::create_seeds()
{
	std::vector<Seed*> seeds;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;
	uint64_t new_score;
	std::vector<uint64_t> final_hashes;
	final_hashes.reserve(seq.size());

	bool min_comparator = comparator->is_first_better(1, 2);
	uint64_t tmp_xor;

	if (min_comparator)
	{
		switch (hasher_code)
		{
		case 0:
			for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
			{
				best_choose = i + w_min;
				best_value = kmers[i] ^ kmers[best_choose];

				for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
				{
					new_score = kmers[i] ^ kmers[q];
					if (new_score < best_value)
					{
						best_choose = q;
						best_value = new_score;
					}
				}
				final_hashes.push_back((hashes[i] << 1) - hashes[best_choose]);
			}
			break;
		case 1:
			for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
			{
				best_choose = i + w_min;
				tmp_xor = kmers[i] ^ kmers[best_choose];
				best_value = (tw_hasher.hash(&tmp_xor, sizeof(tmp_xor)));

				for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
				{
					tmp_xor = kmers[i] ^ kmers[q];
					new_score = (tw_hasher.hash(&tmp_xor, sizeof(tmp_xor)));
					if (new_score < best_value)
					{
						best_choose = q;
						best_value = new_score;
					}
				}
				final_hashes.push_back((hashes[i] << 1) - hashes[best_choose]);
			}
			break;
		case 2:
			for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
			{
				best_choose = i + w_min;
				tmp_xor = kmers[i] ^ kmers[best_choose];
				best_value = (wyhash(&tmp_xor, sizeof(tmp_xor), kmers[i], _wyp));

				for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
				{
					tmp_xor = kmers[i] ^ kmers[q];
					new_score = (wyhash(&tmp_xor, sizeof(tmp_xor), kmers[i], _wyp));

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
				best_choose = i + w_min;
				tmp_xor = kmers[i] ^ kmers[best_choose];
				best_value = (XXH3_64bits_withSeed(&tmp_xor, sizeof(tmp_xor), 0));

				for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
				{
					tmp_xor = kmers[i] ^ kmers[q];
					new_score = (XXH3_64bits_withSeed(&tmp_xor, sizeof(tmp_xor), 0));
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
		case 0:
			for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
			{
				best_choose = i + w_min;
				best_value = kmers[i] ^ kmers[best_choose];

				for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
				{
					new_score = kmers[i] ^ kmers[q];
					if (new_score > best_value)
					{
						best_choose = q;
						best_value = new_score;
					}
				}
				final_hashes.push_back((hashes[i] << 1) - hashes[best_choose]);
			}
			break;
		case 1:
			for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
			{
				best_choose = i + w_min;
				tmp_xor = kmers[i] ^ kmers[best_choose];
				best_value = (tw_hasher.hash(&tmp_xor, sizeof(tmp_xor)));

				for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
				{
					tmp_xor = kmers[i] ^ kmers[q];
					new_score = (tw_hasher.hash(&tmp_xor, sizeof(tmp_xor)));
					if (new_score > best_value)
					{
						best_choose = q;
						best_value = new_score;
					}
				}
				final_hashes.push_back((hashes[i] << 1) - hashes[best_choose]);
			}
			break;
		case 2:
			for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
			{
				best_choose = i + w_min;
				tmp_xor = kmers[i] ^ kmers[best_choose];
				best_value = (wyhash(&tmp_xor, sizeof(tmp_xor), kmers[i], _wyp));

				for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
				{
					tmp_xor = kmers[i] ^ kmers[q];
					new_score = (wyhash(&tmp_xor, sizeof(tmp_xor), kmers[i], _wyp));

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
				best_choose = i + w_min;
				tmp_xor = kmers[i] ^ kmers[best_choose];
				best_value = (XXH3_64bits_withSeed(&tmp_xor, sizeof(tmp_xor), 0));

				for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
				{
					tmp_xor = kmers[i] ^ kmers[q];
					new_score = (XXH3_64bits_withSeed(&tmp_xor, sizeof(tmp_xor), 0));
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
	state = final_hashes.back();
	// for (auto i : final_hashes)
	// 	state+=i;
	// std::cout << "XV\n";
	return seeds;
}