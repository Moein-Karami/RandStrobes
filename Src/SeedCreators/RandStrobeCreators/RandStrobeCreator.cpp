#include "RandStrobeCreator.hpp"

RandStrobeCreator::RandStrobeCreator(Hasher* hasher, Comparator* omparator, size_t kmer_len, size_t w_min, size_t w_max,
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
	mask &= tmp_mask;
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

std::vector<Seed*> RandStrobeCreator::create_seeds(const std::string& seq)
{
	std::vector<uint64_t> hashes;
	std::vector<uint64_t> kmers;

	uint64_t curr_kmer = 0;
	uint64_t tmp;

	for (int i = 0; i < kmer_len - 1; i++)
		curr_kmer = (curr_kmer << 1) | get_char_code(seq[i]);
	for (int i = kmer_len - 1; i < seq.size() - kmer_len; i++)
	{
		curr_kmer = (curr_kmer << 1) | get_char_code(seq[i]);
		tmp = curr_kmer & mask;
		hashes.push_back(hasher->hash(&tmp, sizeof(tmp)));
		kmers.push_back(tmp);
	}
	return create_seeds(seq, kmers, hashes);
}