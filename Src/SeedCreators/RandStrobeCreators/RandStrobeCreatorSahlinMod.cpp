#include "RandStrobeCreatorSahlinMod.hpp"

RandStrobeCreatorSahlinMod::RandStrobeCreatorSahlinMod(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask, uint64_t p)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
, p(p)
{
}

inline uint64_t RandStrobeCreatorSahlinMod::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
	return (curr_hash + hashes[new_strobe_pos]) % p;
}

inline std::vector<Seed*> RandStrobeCreatorSahlinMod::create_seeds()
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

	if (min_comparator)
	{
		for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
		{
			// if (n == 2)
			// 	strobemer = new Strobemer2();
			// else if (n == 3)
			// 	strobemer = new Strobemer3();

			// strobemer->add_kmer(i, kmers[i]);
			// curr_hash = get_first_hash(i);
			// curr_hash = hashes[i];

			// for (int j = 1; j < n; j++)
			// {
				best_choose = i + w_min;
				// best_value = get_score(curr_hash, best_choose);
				best_value = (hashes[i] + hashes[best_choose]) % 100001;

				for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
				{
					// new_score = get_score(curr_hash, q);
					new_score = (hashes[i] + hashes[q]) % 100001;
					// if (comparator->is_first_better(new_score, best_value))
					// {
					// 	best_choose = q;
					// 	best_value = new_score;
					// }
					if (new_score < best_value)
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
	}
	else
	{
		for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
		{
			// if (n == 2)
			// 	strobemer = new Strobemer2();
			// else if (n == 3)
			// 	strobemer = new Strobemer3();

			// strobemer->add_kmer(i, kmers[i]);
			// curr_hash = get_first_hash(i);
			// curr_hash = hashes[i];

			// for (int j = 1; j < n; j++)
			// {
				best_choose = i + w_min;
				// best_value = get_score(curr_hash, best_choose);
				best_value = (hashes[i] + hashes[best_choose]) % 100001;

				for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
				{
					// new_score = get_score(curr_hash, q);
					new_score = (hashes[i] + hashes[q]) % 100001;
					// if (comparator->is_first_better(new_score, best_value))
					// {
					// 	best_choose = q;
					// 	best_value = new_score;
					// }
					if (new_score > best_value)
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
	}
	state = final_hashes.back();
	// for (auto i : final_hashes)
	// 	state+=i;
	// std::cout << "Mod\n";
	return seeds;
}