#include "Traditional.hpp"

Traditional::Traditional(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

inline std::vector<Seed*> Traditional::create_seeds(const std::string& sequence)
{
	srand(0);
	for (int i = 0; i < 4; i++)
		_wyp[i] = rand();

	// seq = sequence;
	hashes.clear();
	kmers.clear();
	hashes.reserve(sequence.size() + 1);
	// prepare_data();

	std::vector<Seed*> seeds;
	// seeds.reserve(seq.size());
	// Strobemer* strobemer;
	// size_t best_choose;
	// uint64_t curr_hash;
	
	// for (size_t i = 0; i < seq.size() - n * kmer_len; i++)
	// {
	// 	if (n == 2)
	// 		strobemer = new Strobemer2();
	// 	else if (n == 3)
	// 		strobemer = new Strobemer3();

	// 	strobemer->add_kmer(i, kmers[i]);
	// 	curr_hash = get_first_hash(i);
	// 	for (int j = 1; j < n; j++)
	// 	{
	// 		best_choose = i + j * kmer_len;
	// 		strobemer->add_kmer(best_choose, kmers[best_choose]);
	// 		curr_hash = get_new_curr_hash(strobemer);
	// 	}
	// 	strobemer->set_final_hash(get_final_hash(strobemer));
	// 	seeds.push_back(strobemer);
	// }
	std::vector<uint64_t> final_hashes;
	final_hashes.reserve(sequence.size());
	hasher_code = hasher->get_type();
	hasher_code = 2;
	std::map<uint64_t, double> seen;
	for (size_t i = 0; i < sequence.size() - n * kmer_len; i++)
	{
		hashes.push_back(wyhash(&sequence[i], sizeof(sequence[i]) * kmer_len * n, 0, _wyp));
		// switch (hasher_code)
		// {
		// case 2:
		// 	hashes.push_back(wyhash(&sequence[i], sizeof(sequence[i]) * kmer_len * n, 0, _wyp));
		// 	break;
		// case 3:
		// 	hashes.push_back(XXH3_64bits_withSeed(&sequence[i], sizeof(sequence[i]) * kmer_len * n, 0));
		// 	break;
		// default:
		// 	break;
		// }
		seen[hashes.back()] += 1;
	}
	double sum_squeared = 0;
	for (auto i : seen)
		sum_squeared += i.second * i.second;
	double number_of_different_seeds = seen.size();
	double number_of_seeds = hashes.size();
	std::cout << std::fixed << std::setprecision(6) << "Number of different seeds: " << number_of_different_seeds << std::endl;
	std::cout << std::fixed << std::setprecision(6) << "Ehits: " << sum_squeared/number_of_seeds << std::endl;

	return seeds;

}

inline uint64_t Traditional::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
	return 0;
}