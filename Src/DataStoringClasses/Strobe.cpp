#include "Strobe.hpp"

void Strobe::add_kmer(size_t position, uint64_t kmer_hash)
{
	positions.push_back(position);
	kmers_hash.push_back(kmer_hash);
}

std::string Strobe::get_seed()
{
	std::string seed;
	for (auto i : kmers_hash)
		seed += std::to_string(i);
	return seed;
}

std::string Strobe::to_string()
{
	std::string res;
	for (auto i : kmers_hash)
		res += std::to_string(i);
	res += '/';
	for (auto i : positions)
		res += std::to_string(i) + ' ';
	return res;
}