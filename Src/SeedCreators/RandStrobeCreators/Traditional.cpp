#include "Traditional.hpp"

Traditional::Traditional(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

inline std::vector<Seed*> Traditional::create_seeds(const std::string& sequence)
{
	// std::cout << "start creating" << std::endl;
	// prepare_data();

	std::vector<Seed*> seeds;
	// seeds.reserve(seq.size());
	Strobemer* strobemer;
	size_t best_choose;
	uint64_t curr_hash;

	std::vector<uint64_t> final_hash_values;
	final_hash_values.reserve(sequence.size());
	std::map<uint64_t, uint64_t> seen;
	
	// std::cout << "every thing is ready" << std::endl;
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
	// uint64_t curr_hash;
	for (uint64_t i = 0; i < sequence.size() - n * kmer_len; i++)
	{
		// if (i % 1000000 == 0)
		// 	std::cout << "I: " << i << std::endl;
		curr_hash = wy_hasher->hash(&sequence[i], n * kmer_len * sizeof(sequence[i]));
		final_hash_values.push_back(curr_hash);
		// std::cout << "Map is shit" << std::endl;
		seen[final_hash_values.back()] += 1;
	}

	// std::cout << "seeds are created" << std::endl;

	double sum_squeared = 0;
	for (auto i : seen)
		sum_squeared += i.second * i.second;
	double number_of_different_seeds = seen.size();
	double number_of_seeds = final_hash_values.size();
	std::cout << std::fixed << std::setprecision(6) << "Number of different seeds: " << number_of_different_seeds << std::endl;
	// std::cout << "_____Divide is shit" << std::endl;
	std::cout << std::fixed << std::setprecision(6) << "Ehits: " << sum_squeared/number_of_seeds << std::endl;
	
	return seeds;

}

inline uint64_t Traditional::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
	return 0;
}