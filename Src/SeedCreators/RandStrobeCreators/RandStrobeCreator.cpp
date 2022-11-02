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
	
	for (int i = 0; i < kmer_len - 1; i++)
		curr_kmer = (curr_kmer << 2) | get_char_code(seq[i]);

	for (int i = kmer_len - 1; i < seq.size(); i++)
	{
		curr_kmer = (curr_kmer << 2) | get_char_code(seq[i]);
		tmp = curr_kmer & mask;
		hashes.push_back(hasher->hash(&tmp, sizeof(tmp)));
		kmers.push_back(tmp);
	}

	return create_seeds();
}

std::vector<Seed*> RandStrobeCreator::create_seeds()
{
	prepare_data();

	std::vector<Seed*> seeds;
	Strobe* strobe;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;
	
	for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		strobe = new Strobe();
		strobe->add_kmer(i, kmers[i]);
		curr_hash = get_first_hash(i);
		for (int j = 1; j < n; j++)
		{
			best_choose = i + w_min + (j - 1) * w_max;
			best_value = get_score(curr_hash, i, best_choose);
			for (size_t q = i + w_min + (j - 1) * w_max + 1; q < std::min(i + j * w_max + 1, hashes.size()); q++)
			{
				if (comparator->is_first_better(get_score(curr_hash, i, q), best_value))
				{
					best_choose = q;
					best_value = get_score(curr_hash, i, q);
				}
			}
			strobe->add_kmer(best_choose, kmers[best_choose]);
			curr_hash = get_value_to_choose_third_strobe(curr_hash, i, best_choose);
		}
		
		seeds.push_back(strobe);
	}
	return seeds;
}

uint64_t RandStrobeCreator::get_first_hash(size_t ind)
{
	return hashes[ind];
}

void RandStrobeCreator::prepare_data()
{
	/* Do nothing */
}

uint64_t RandStrobeCreator::get_new_curr_hash(uint64_t curr_hash, size_t ind1, size_t ind2)
{
	return get_score(curr_hash, ind1, ind2);
}

uint64_t RandStrobeCreator::get_value_to_choose_third_strobe(uint64_t curr_hash, size_t ind1, size_t ind2)
{
	return get_score(curr_hash, ind1, ind2);
}