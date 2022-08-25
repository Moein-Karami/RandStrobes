#include "RandStrobeCreator.hpp"

RandStrobeCreator::RandStrobeCreator(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
		uint32_t n, uint64_t mask)
: SeedCreator(hasher)
, comparator(comparator)
, kmer_len(kmer_len)
, w_min(w_min)
, w_max(w_max)
, n(n)
, mask(mask)
{
	uint64_t tmp_mask = -1;
	tmp_mask = tmp_mask >> (64 - kmer_len * 2);
	this->mask &= tmp_mask;
}

RandStrobeCreator::~RandStrobeCreator()
{
	delete(hasher);
	delete(comparator);
}

uint32_t RandStrobeCreator::get_char_code(char c)
{
	switch (c)
	{
	case 'A':
		return 0;
		break;
	case 'C':
		return 1;
		break;
	case 'G':
		return 2;
		break;
	default:
		return 3;
		break;
	}
	return 0;
}

std::vector<Seed*> RandStrobeCreator::create_seeds(const std::string& sequence)
{
	seq = sequence;
	hashes.clear();
	kmers.clear();

	uint64_t curr_kmer = 0;
	uint64_t tmp;

	// std::cerr << "before create kmers" << std::endl;
	
	for (int i = 0; i < kmer_len - 1; i++)
		curr_kmer = (curr_kmer << 2) | get_char_code(seq[i]);
	// std::cerr << "first uncomplete kmer: "
	for (int i = kmer_len - 1; i < seq.size(); i++)
	{
		curr_kmer = (curr_kmer << 2) | get_char_code(seq[i]);
		tmp = curr_kmer & mask;
		hashes.push_back(hasher->hash(&tmp, sizeof(tmp)));
		kmers.push_back(tmp);
	}

	std::cerr << "before specialize create_seeds" << std::endl;

	return create_seeds();
}

std::vector<Seed*> RandStrobeCreator::create_seeds()
{
	std::vector<Seed*> seeds;
	Strobe* strobe;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;

	for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		std::cerr << "creating the " << i << "th strobe" << std::endl;
		strobe = new Strobe();
		strobe->add_kmer(i, hashes[i]);
		curr_hash = hashes[i];
		for (int j = 1; j < n; j++)
		{
			best_choose = i + w_min + (j - 1) * w_max;
			best_value = get_score(curr_hash, i, best_choose);
			for (size_t q = i + w_min + (j - 1) * w_max + 1; q < std::min(i + j * w_max + 1, hashes.size()); q++)
			{
				// std::cerr << "checking " << q << "th kmer in seq " << std::endl;
				if (comparator->is_first_better(get_score(curr_hash, i, q), best_value))
				{
					// std::cerr << "checking results positive" << std::endl;
					best_choose = q;
					best_value = get_score(curr_hash, i, q);
					// std::cerr << "best choose changes to " << best_choose << std::endl;
				}
			}
			strobe->add_kmer(best_choose, hashes[best_choose]);
			curr_hash = best_value;
			// std::cerr << "next kmer added, it was: " << best_choose << std::endl;
		}
		
		seeds.push_back(strobe);
		// std::cerr << "end of creating seed I = " << i << std::endl << std::endl;
	}
	return seeds;
}
