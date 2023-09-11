#include "Strobemer3.hpp"

Strobemer3::Strobemer3()
: Strobemer()
{
}

// Strobemer3::~Strobemer3()
// {
	// delete(positions);
	// delete(kmers_hash);
	// positions.clear();
	// kmers_hash.clear();
// }

inline void Strobemer3::add_kmer(size_t position, uint64_t kmer_hash)
{
	positions[last] = position;
	kmers_hash[last] = kmer_hash;
	last++;
	// positions.push_back(position);
	// kmers_hash.push_back(kmer_hash);
}

std::string Strobemer3::get_seed()
{
	std::string seed;
	for (int i = 0; i < last; i++)
		seed += std::to_string(kmers_hash[i]);
	// for (auto i : kmers_hash)
	// 	seed += std::to_string(i);
	return seed;
}

std::string Strobemer3::to_string()
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

inline void Strobemer3::set_final_hash(uint64_t hash)
{
	final_hash = hash;
}

inline std::vector<uint32_t> Strobemer3::get_positions() const
{
	std::vector<uint32_t> res;
	for (int i = 0; i < last; i++)
		res.push_back(positions[i]);
	return res;
}