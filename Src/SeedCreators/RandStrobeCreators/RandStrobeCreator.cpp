#include "RandStrobeCreator.hpp"

RandStrobeCreator::RandStrobeCreator(Hasher* hasher, Comparator* omparator, size_t kmer_len, size_t w_min, size_t w_max,
		uint8_t n, uint64_t mask)
: SeedCreator(hasher)
, comparator(comparator)
, kmer_len(kmer_len)
, w_min(w_min)
, w_max(w_max)
, n(n)
, mask(mask)
{
}

uint8_t RandStrobeCreator::get_char_code(char c)
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

std::vector<Seed*> RandStrobeCreator::creat_seeds(const std::string& seq)
{
	std::vector<uint64_t> hashes;
	uint64_t curr_kmer = 0;
	uint64_t tmp;

	for (int i = 0; i < kmer_len - 1; i++)
		curr_kmer = (curr_kmer << 1) | get_char_code(seq[i]);
	for (int i = kmer_len - 1; i < seq.size() - kmer_len; i++)
	{
		curr_kmer = (curr_kmer << 1) | get_char_code(seq[i]);
		tmp = curr_kmer & mask;
		hashes.push_back(hasher->hash(&tmp, sizeof(tmp)));	
	}
	return creat_seeds(seq, hashes);
}