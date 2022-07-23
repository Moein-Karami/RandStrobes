#include "RandStrobeCreatorSahlinMod2.hpp"

RandStrobeCreatorSahlinMod2::RandStrobeCreatorSahlinMod2(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint64_t mask, uint64_t p)
: RandStrobeCreator2(hasher, comparator, kmer_len, w_min, w_max, mask)
, p(p)
{
}

std::vector<Seed*> RandStrobeCreatorSahlinMod2(const std::string& seq, const std::vector<uint64_t>& hashes)
{
	std::vector<Seed*> seeds;
	Strobe* strobe;
	size_t best_choose;
	for (size_t i = 0; i < seq.size() - kmer_len - w_min)
	{
		strobe = new Strobe();
		strobe->add_kmer(i, hashes[i]);
		best_choose = i + w_min;
		for (size_t j = i + w_min + 1; j < min(i + w_max + 1, hashes.size()); j++)
			if (comparator->is_first_better((hashes[i] + hashes[j]) % p, (hashes[i] + hashes[best_choose]) % p))
				best_choose = j;
		strobe->add_kmer(best_choose, hashes[best_choose]);
		seeds.push_back(strobe);
	}
	return seeds;
}