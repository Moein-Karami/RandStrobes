#include "RandStrobeCreatorGuoPibri.hpp"

RandStrobeCreatorGuoPibri::RandStrobeCreatorGuoPibri(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint8_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

std::vector<Seed*> RandStrobeCreatorGuoPibri::creat_seeds(const std::string& seq, const std::vector<uint64_t>& kmers,
		const std::vector<uint64_t> hashes)
{
	std::vector<Seed*> seeds;
	Strobe* strobe;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;

	for (size_t i = 0; i < seq.size() - kmer_len - n * w_min; i++)
	{
		strobe = new Strobe();
		strobe->add_kmer(i, hashes[i]);
		curr_hash = hashes[i];

		for (int j = 1; j < n; j++)
		{
			best_choose = i + j * w_min;
			best_value = (curr_hash ^ hashes[best_choose]);

			for (size_t q = i + j * w_min + 1; q < std::min(i + j * w_max + 1, hashes.size()); q++)
			{
				if (comparator->is_first_better((curr_hash ^ hashes[j]), best_value))
				{
					best_choose = j;
					best_value = (curr_hash ^ hashes[best_choose]);
				}
			}

			strobe->add_kmer(best_choose, hashes[best_choose]);
			curr_hash = best_value;
		}
		
		seeds.push_back(strobe);
	}
	return seeds;
}