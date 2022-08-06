#include "RandStrobeCreatorSahlinMod.hpp"

RandStrobeCreatorSahlinMod::RandStrobeCreatorSahlinMod(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask, uint64_t p)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
, p(p)
{
	std::cerr << "test comparator in sahlin mode constructor: " << comparator->is_first_better(1, 2) <<
			" should be true" << std::endl << std::endl;
}

std::vector<Seed*> RandStrobeCreatorSahlinMod::create_seeds(const std::string& seq, const std::vector<uint64_t>& kmers,
		const std::vector<uint64_t> hashes)
{
	std::cerr << "Start sahlin mode create seeds: " << std::endl;
	std::cerr << "testing seed creator comparator: " << comparator->is_first_better(1, 2) << " sould be true" <<
			std::endl << std::endl;
	std::vector<Seed*> seeds;
	Strobe* strobe;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;

	for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		std::cerr << "start creating seeds, I = " << i << std::endl;
		strobe = new Strobe();
		strobe->add_kmer(i, hashes[i]);
		curr_hash = hashes[i];
		std::cerr << "before choose next kmers" << std::endl;
		for (int j = 1; j < n; j++)
		{
			best_choose = i + w_min + (j - 1) * w_max;
			best_value = (curr_hash + hashes[best_choose]) % p;
			std::cerr << "before choose " << j + 1 << "kmer, best choose is: " << best_choose << std::endl;
			for (size_t q = i + w_min + (j - 1) * w_max + 1; q < std::min(i + j * w_max + 1, hashes.size()); q++)
			{
				std::cerr << "checking " << q << "th kmer in seq " << std::endl;
				std::cerr << "curr value to be hash : " << (curr_hash + hashes[q]) % p << std::endl;
				if (comparator->is_first_better((curr_hash + hashes[q]) % p, best_value))
				{
					std::cerr << "checking results positive" << std::endl;
					best_choose = q;
					best_value = (curr_hash + hashes[best_choose]) % p;
					std::cerr << "best choose changes to " << best_choose << std::endl;
				}
				std::cerr << "checking " << q << "th kmer in seq is done " << std::endl;
					
			}
			strobe->add_kmer(best_choose, hashes[best_choose]);
			curr_hash = best_value;
			std::cerr << "next kmer added, it was: " << best_choose << std::endl;
		}
		
		seeds.push_back(strobe);

		std::cerr << "end of creating seed I = " << i << std::endl << std::endl;
	}
	return seeds;
}