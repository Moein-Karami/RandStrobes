#include "RandStrobeCreatorFullyRandom.hpp"

RandStrobeCreatorFullyRandom::RandStrobeCreatorFullyRandom(Hasher* hasher, Comparator* comparator, uint64_t kmer_len,
		uint64_t w_min, uint64_t w_max, uint64_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

std::vector<Seed*> RandStrobeCreatorFullyRandom::create_seeds(const std::string& sequence)
{
	seq = sequence;
	hashes.clear();
	kmers.clear();

	uint64_t curr_kmer = 0;
	uint64_t tmp;
	
	for (uint64_t i = 0; i < kmer_len - 1; i++)
		curr_kmer = (curr_kmer << 2) | get_char_code(seq[i]);

	for (uint64_t i = kmer_len - 1; i < seq.size(); i++)
	{
		curr_kmer = (curr_kmer << 2) | get_char_code(seq[i]);
		tmp = curr_kmer & mask;
		hashes.push_back(tmp);
		kmers.push_back(tmp);
	}

	srand(time(0));

	std::vector<Seed*> seeds;
	Strobemer* strobemer;
	uint64_t best_choose;
	uint64_t offset;

	for (uint64_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		if (n == 2)
			strobemer = new Strobemer2();
		else if (n == 3)
			strobemer = new Strobemer3();
		strobemer->add_kmer(i, kmers[i]);
		
		for (uint64_t j = 1; j < n; j++)
		{
			best_choose = i + w_min + (j - 1) * w_max;
			offset = rand() % (std::min(i + j * w_max + 1, hashes.size()) - (i + w_min + (j - 1) * w_max));
			best_choose += offset;
			strobemer->add_kmer(best_choose, kmers[best_choose]);
		}
		
		seeds.push_back(strobemer);
	}
	return seeds;
}

uint64_t RandStrobeCreatorFullyRandom::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
	return 0;
}