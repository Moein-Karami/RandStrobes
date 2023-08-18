#include "RandStrobeCreatorFastMAXor.hpp"

RandStrobeCreatorFastMAXor::RandStrobeCreatorFastMAXor(Hasher* hasher, Comparator* comparator, uint64_t kmer_len,
		uint64_t w_min, uint64_t w_max, uint64_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorFastMAXor::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
	return -1;
}

std::vector<Seed*> RandStrobeCreatorFastMAXor::create_seeds()
{
	bool cmp = comparator->is_first_better(1, 0);

	std::vector<Seed*> seeds;
	Strobemer* strobemer;
	uint64_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;

	MAXorNode* nodes[n];
	for (uint64_t i = 1; i < n; i++)
	{
		nodes[i] = new MAXorNode(63);
		for (uint64_t j = w_min + (i - 1) * w_max ; j < std::min(i * w_max + 1, hashes.size()); j++)
			nodes[i]->add(j, hashes[j]);
	}

	for (uint64_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		if (n == 2)
			strobemer = new Strobemer2();
		else if (n == 3)
			strobemer = new Strobemer3();
			
		strobemer->add_kmer(i, kmers[i]);
		curr_hash = get_first_hash(i);
		for (uint64_t j = 1; j < n; j++)
		{
			best_choose = nodes[j]->get_best_ind(curr_hash, cmp);
			strobemer->add_kmer(best_choose, kmers[best_choose]);
			curr_hash = get_final_hash(strobemer);
			nodes[j]->remove(i + w_min + (j - 1) * w_max, hashes[i + w_min + (j - 1) * w_max]);
			if (i + j * w_max + 1 < hashes.size())
				nodes[j]->add(i + j * w_max + 1, hashes[i + j * w_max + 1]);
		}
		strobemer->set_final_hash(get_final_hash(strobemer));
		seeds.push_back(strobemer);
	}
	for (uint64_t i = 1; i < n; i++)
		delete nodes[i];
	return seeds;
}
