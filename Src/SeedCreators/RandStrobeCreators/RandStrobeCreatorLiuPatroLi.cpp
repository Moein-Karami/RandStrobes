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
	// seeds.reserve(seq.size());
	// Strobemer* strobemer;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;
	uint64_t new_score;
	std::vector<uint64_t> final_hashes;
	final_hashes.reserve(seq.size());

	bool min_comparator = comparator->is_first_better(1, 2);

    Int128 concated;

    // auto start_time = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		// if (n == 2)
		// 	strobemer = new Strobemer2();
		// else if (n == 3)
		// 	strobemer = new Strobemer3();

		// strobemer->add_kmer(i, kmers[i]);
		// curr_hash = get_first_hash(i);
		concated.low = kmers[i];
		// for (int j = 1; j < n; j++)
		// {
			best_choose = i + w_min;
			// best_value = get_score(curr_hash, best_choose);
            concated.high = kmers[best_choose];
			// best_value = hasher->hash(&concated, sizeof(concated));
            // best_value = wy_hasher->hash(&concated, sizeof(concated));
            // best_value = wyhash(&concated, sizeof(concated), 0, _wyp);
            // best_value = XXH3_64bits_withSeed(&concated, sizeof(concated), 0);
			switch (hasher_code)
			{
				case 2:
					best_value = (wyhash(&concated, sizeof(concated), 0, _wyp));
					break;
				case 3:
					best_value = (XXH3_64bits_withSeed(&concated, sizeof(concated), 0));
					break;
				default:
					break;
			}
			for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
			{
				// new_score = get_score(curr_hash, q);
				// new_score = curr_hash ^ hashes[q];
                concated.high = kmers[q];
                // new_score = hasher->hash(&concated, sizeof(concated));
                // new_score = wy_hasher->hash(&concated, sizeof(concated));
                // new_score = wyhash(&concated, sizeof(concated), 0, _wyp);
                // new_score = XXH3_64bits_withSeed(&concated, sizeof(concated), 0);
				switch (hasher_code)
				{
					case 2:
						new_score = (wyhash(&concated, sizeof(concated), 0, _wyp));
						break;
					case 3:
						new_score = (XXH3_64bits_withSeed(&concated, sizeof(concated), 0));
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
    // auto finish_time = std::chrono::high_resolution_clock::now();
	// 	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
    // std::cout << "TIME: " << duration.count() << std::endl;
	return seeds;
}


inline std::vector<Seed*> RandStrobeCreatorLiuPatroLi::create_seeds(const std::string& sequence)
{
	srand(0);
	for (int i = 0; i < 4; i++)
		_wyp[i] = rand();

	// seq = sequence;
	hashes.clear();
	// kmers.clear();
	hashes.reserve(sequence.size() + 1);
	// real_hashes.reserve(sequence.size());
	// kmers.reserve(seq.size() + 1);
	
	// uint64_t curr_kmer = 0;
	// uint64_t tmp;
	
	// for (int i = 0; i < kmer_len - 1; i++)
	// 	curr_kmer = (curr_kmer << 2) | get_char_code(seq[i]);

	hasher_code = hasher->get_type();
	

	for (int i = 0; i < sequence.size() - kmer_len; i++)
	{
		// curr_kmer = (curr_kmer << 2) | get_char_code(seq[i]);
		// tmp = curr_kmer & mask;
		// hashes.push_back(hasher->hash(&tmp, sizeof(tmp)));
		switch (hasher_code)
		{
			// case 0:
			// 	hashes.push_back(tmp);
			// 	break;
			// case 1:
			// 	hashes.push_back(tw_hasher.hash(&tmp, sizeof(tmp)));
			// 	break;
			case 2:
				hashes.push_back(wyhash(&sequence[i], sizeof(sequence[i]) * kmer_len, 0, _wyp));
				break;
			case 3:
				hashes.push_back(XXH3_64bits_withSeed(&sequence[i], sizeof(sequence[i]) * kmer_len, 0));
				break;
			default:
				break;
		}
		// kmers.push_back(tmp);
	}


	//Create seeds max
	std::vector<Seed*> seeds;
	// seeds.reserve(seq.size());
	// Strobemer* strobemer;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;
	uint64_t new_score;
	std::vector<uint64_t> final_hashes;
	final_hashes.reserve(sequence.size());

	bool min_comparator = comparator->is_first_better(1, 2);

    Int128 concated;
	std::map<uint64_t, double> seen;
    // auto start_time = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < sequence.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		// if (n == 2)
		// 	strobemer = new Strobemer2();
		// else if (n == 3)
		// 	strobemer = new Strobemer3();

		// strobemer->add_kmer(i, kmers[i]);
		// curr_hash = get_first_hash(i);
		concated.low = hashes[i];
		// for (int j = 1; j < n; j++)
		// {
			best_choose = i + w_min;
			// best_value = get_score(curr_hash, best_choose);
            concated.high = hashes[best_choose];
			// best_value = hasher->hash(&concated, sizeof(concated));
            // best_value = wy_hasher->hash(&concated, sizeof(concated));
            // best_value = wyhash(&concated, sizeof(concated), 0, _wyp);
            // best_value = XXH3_64bits_withSeed(&concated, sizeof(concated), 0);
			switch (hasher_code)
			{
				case 2:
					best_value = (wyhash(&concated, sizeof(concated), hashes[i], _wyp));
					break;
				case 3:
					best_value = (XXH3_64bits_withSeed(&concated, sizeof(concated), 0));
					break;
				default:
					break;
			}
			for (size_t q = i + w_min + 1; q < std::min(i + w_max + 1, hashes.size()); q++)
			{
				// new_score = get_score(curr_hash, q);
				// new_score = curr_hash ^ hashes[q];
                concated.high = hashes[q];
                // new_score = hasher->hash(&concated, sizeof(concated));
                // new_score = wy_hasher->hash(&concated, sizeof(concated));
                // new_score = wyhash(&concated, sizeof(concated), 0, _wyp);
                // new_score = XXH3_64bits_withSeed(&concated, sizeof(concated), 0);
				switch (hasher_code)
				{
					case 2:
						new_score = (wyhash(&concated, sizeof(concated), hashes[i], _wyp));
						break;
					case 3:
						new_score = (XXH3_64bits_withSeed(&concated, sizeof(concated), 0));
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
			seen[final_hashes.back()] += 1;
			// strobemer->add_kmer(best_choose, kmers[best_choose]);
			// curr_hash = get_new_curr_hash(strobemer);
		// }
		// strobemer->set_final_hash(get_final_hash(strobemer));
		// seeds.push_back(strobemer);
	}
	double sum_squeared = 0;
	for (auto i : seen)
		sum_squeared += i.second * i.second;
	double number_of_different_seeds = seen.size();
	double number_of_seeds = final_hashes.size();
	std::cout << std::fixed << std::setprecision(6) << "Number of different seeds: " << number_of_different_seeds << std::endl;
	std::cout << std::fixed << std::setprecision(6) << "Ehits: " << sum_squeared/number_of_seeds << std::endl;
    // auto finish_time = std::chrono::high_resolution_clock::now();
	// 	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
    // std::cout << "TIME: " << duration.count() << std::endl;
	return seeds;
}