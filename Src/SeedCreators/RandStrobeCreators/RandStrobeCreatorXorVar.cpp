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
	// seeds.reserve(seq.size());
	// Strobemer* strobemer;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;
	uint64_t new_score;
	std::vector<uint64_t> final_hashes;
	final_hashes.reserve(seq.size());

	bool min_comparator = comparator->is_first_better(1, 2);
	uint64_t tmp_xor;

	for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		// if (n == 2)
		// 	strobemer = new Strobemer2();
		// else if (n == 3)
		// 	strobemer = new Strobemer3();

		// strobemer->add_kmer(i, kmers[i]);
		// curr_hash = get_first_hash(i);
		// curr_hash = kmers[i];

		// for (int j = 1; j < n; j++)
		// {
			best_choose = i + w_min;
			// best_value = get_score(curr_hash, best_choose);
			// best_value = curr_hash ^ hashes[best_choose];
			tmp_xor = kmers[i] ^ kmers[best_choose];
			switch (hasher_code)
			{
			case 0:
				best_value = (tmp_xor);
				break;
			case 1:
				best_value = (tw_hasher.hash(&tmp_xor, sizeof(tmp_xor)));
				break;
			case 2:
				best_value = (wyhash(&tmp_xor, sizeof(tmp_xor), 0, _wyp));
				break;
			case 3:
				best_value = (XXH3_64bits_withSeed(&tmp_xor, sizeof(tmp_xor), 0));
				break;
			default:
				break;
			}

			for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
			{
				// new_score = get_score(curr_hash, q);
				tmp_xor = kmers[i] ^ kmers[q];
				switch (hasher_code)
				{
				case 0:
					new_score = (tmp_xor);
					break;
				case 1:
					new_score = (tw_hasher.hash(&tmp_xor, sizeof(tmp_xor)));
					break;
				case 2:
					new_score = (wyhash(&tmp_xor, sizeof(tmp_xor), 0, _wyp));
					break;
				case 3:
					new_score = (XXH3_64bits_withSeed(&tmp_xor, sizeof(tmp_xor), 0));
					break;
				default:
					break;
				}

				// if (comparator->is_first_better(new_score, best_value))
				// {
				// 	best_choose = q;
				// 	best_value = new_score;
				// }
				if (min_comparator && new_score < best_value)
				{
					best_choose = q;
					best_value = new_score;
				}
				else if (!min_comparator && new_score > best_value)
				{
					best_choose = q;
					best_value = new_score;
				}
			}
			final_hashes.push_back((hashes[i] << 1) - hashes[best_choose]);
			// strobemer->add_kmer(best_choose, kmers[best_choose]);
			// curr_hash = get_new_curr_hash(strobemer);
		// }
		// strobemer->set_final_hash(get_final_hash(strobemer));
		// seeds.push_back(strobemer);
	}
	return seeds;
}