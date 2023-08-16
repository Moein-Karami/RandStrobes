#include "Traditional.hpp"

Traditional::Traditional(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

std::vector<Seed*> Traditional::create_seeds()
{
	// prepare_data();

	std::set<uint64_t> final_hashes;
	std::map<uint64_t, long double> appearances;

	std::vector<Seed*> seeds;
	seeds.reserve(seq.size());
	Strobemer* strobemer;
	size_t best_choose;
	uint64_t curr_hash;
	
	for (size_t i = 0; i < seq.size() - n * kmer_len; i++)
	{
		if (n == 2)
			strobemer = new Strobemer2();
		else if (n == 3)
			strobemer = new Strobemer3();

		strobemer->add_kmer(i, kmers[i]);
		curr_hash = get_first_hash(i);
		for (int j = 1; j < n; j++)
		{
			best_choose = i + j * kmer_len;
			strobemer->add_kmer(best_choose, kmers[best_choose]);
			curr_hash = get_new_curr_hash(strobemer);
		}
		strobemer->set_final_hash(get_final_hash(strobemer));
		// strobemer->set_final_hash(get_final_hash(strobemer));
		// seeds.push_back(strobemer);
		final_hashes.insert(get_final_hash(strobemer));
		appearances[get_final_hash(strobemer)]++;
		delete(strobemer);
	}
	std::cout << "Number of different final seed hash values: " << final_hashes.size() << std::endl;
	
	long double sum = 0;
	for (auto it = appearances.begin(); it != appearances.end(); it++)
		sum += it->second * it->second;
	long double diff = final_hashes.size();	
	std::cout << std::fixed << std::setprecision(6) << "ehits: " << sum / diff << std::endl;

	return seeds;
}

uint64_t Traditional::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
	return 0;
}