#include "RandStrobeCreatorFastMAXor.hpp"

RandStrobeCreatorFastMAXor::RandStrobeCreatorFastMAXor(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorFastMAXor::get_score(uint64_t curr_hash, uint64_t ind1, uint64_t ind2)
{
	return -1;
}

std::vector<Seed*> RandStrobeCreatorFastMAXor::create_seeds()
{
	for (int i = 0; i < hashes.size(); i++)
		std::cout << "Hashes " << i << ": " << hashes[i] << " " << std::bitset<64>(hashes[i]) << std::endl;
	std::cout << std::endl;

	bool cmp = comparator->is_first_better(1, 0);

	std::vector<Seed*> seeds;
	Strobe* strobe;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;

	MAXorNode* nodes[n];
	for (size_t i = 1; i < n; i++)
	{
		nodes[i] = new MAXorNode(63);
		for (size_t j = w_min + (i - 1) * w_max ; j < std::min(i * w_max + 1, hashes.size()); j++)
			nodes[i]->add(j, hashes[j]);
	}

	for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		std::cout << "start creating seeds, I = " << i << std::endl;
		std::cout << "CUR HASH: " << hashes[i] << " " << std::bitset<64>(hashes[i]) << std::endl;
		if (i < 1)
			nodes[1]->print_all("");

		strobe = new Strobe();
		strobe->add_kmer(i, hashes[i]);
		curr_hash = get_first_hash(i);
		// std::cout << "before choose next kmers" << std::endl;
		for (int j = 1; j < n; j++)
		{
			std::cout << "start get best for j = " << j << std::endl;
			best_choose = nodes[j]->get_best_ind(curr_hash, cmp);
			strobe->add_kmer(best_choose, hashes[best_choose]);
			curr_hash = (curr_hash ^ hashes[best_choose]);
			nodes[j]->remove(i + w_min + (j - 1) * w_max, hashes[i + w_min + (j - 1) * w_max]);
			if (i + j * w_max + 1 < hashes.size())
				nodes[j]->add(i + j * w_max + 1, hashes[i + j * w_max + 1]);
		}
		
		seeds.push_back(strobe);
		// std::cout << "end of creating seed I = " << i << std::endl << std::endl;
	}
	for (int i = 1; i < n; i++)
		delete nodes[i];
	return seeds;
}
