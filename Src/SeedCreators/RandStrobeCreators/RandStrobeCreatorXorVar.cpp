#include "RandStrobeCreatorXorVar.hpp"

RandStrobeCreatorXorVar::RandStrobeCreatorXorVar(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

std::vector<Seed*> RandStrobeCreatorXorVar::create_seeds()
{

	std::vector<Seed*> seeds;
	Strobe* strobe;
	size_t best_choose;
	uint64_t curr_kmer;
	uint64_t best_value;

	for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		strobe = new Strobe();
		strobe->add_kmer(i, hashes[i]);
		curr_kmer = kmers[i];

		for (int j = 1; j < n; j++)
		{
			best_choose = i + w_min + (j - 1) * w_max;
			best_value = hasher->hash(curr_kmer ^ kmers[best_choose]);

			for (size_t q = i + w_min + (j - 1) * w_max + 1; q < std::min(i + j * w_max + 1, hashes.size()); q++)
			{
				if (comparator->is_first_better(hasher->hash(curr_kmer ^ kmers[q]), best_value))
				{
					best_choose = q;
					best_value = hasher->hash(curr_kmer ^ kmers[q]);
				}
			}

			strobe->add_kmer(best_choose, hashes[best_choose]);
			curr_kmer = best_value;
		}
		
		seeds.push_back(strobe);
	}
	return seeds;
}

uint64_t RandStrobeCreatorXorVar::get_score(uint64_t curr_hash, uint64_t ind1, uint64_t ind2)
{
	return -1;
}
