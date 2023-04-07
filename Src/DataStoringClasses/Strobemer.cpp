#include "Strobemer.hpp"

Strobemer::Strobemer(int n)
{
	// positions.reserve(n);
	// kmers_hash.reserve(n);
	// positions = new uint32_t[n];
	// kmers_hash = new uint64_t[n];
	// positions = (uint32_t*) malloc(n * sizeof(uint32_t));
	// kmers_hash = (uint64_t*) malloc(n * sizeof(uint64_t));

	last = 0;
}

Strobemer::~Strobemer()
{
	// delete(positions);
	// delete(kmers_hash);
	// positions.clear();
	// kmers_hash.clear();
}

void Strobemer::add_kmer(size_t position, uint64_t kmer_hash)
{
	positions[last] = position;
	kmers_hash[last] = kmer_hash;
	last++;
	// positions.push_back(position);
	// kmers_hash.push_back(kmer_hash);
}

std::string Strobemer::get_seed()
{
	std::string seed;
	for (int i = 0; i < last; i++)
		seed += std::to_string(kmers_hash[i]);
	// for (auto i : kmers_hash)
	// 	seed += std::to_string(i);
	return seed;
}

std::string Strobemer::to_string()
{
	std::string res;

	// for(int i = 0; i < positions.size(); i++)
	// {
	// 	res += std::to_string(positions[i]) + ',' + std::to_string(kmers_hash[i]);
	// 	res += ",";
	// }
	for(int i = 0; i < last; i++)
	{
		res += std::to_string(positions[i]) + ',' + std::to_string(kmers_hash[i]);
		res += ",";
	}

	res += (std::to_string(final_hash) + ",");
	
	return res;
}

void Strobemer::set_final_hash(uint64_t hash)
{
	final_hash = hash;
}