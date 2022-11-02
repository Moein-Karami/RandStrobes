#ifndef _Strobemer_hpp_
#define _Strobemer_hpp_

#include "Seed.hpp"

class Strobemer : public Seed
{
	public:
		std::string get_seed();
		std::string to_string();
		void add_kmer(size_t position, uint64_t kmer_hash);
		std::vector<size_t> positions;
		void set_final_hash(uint64_t hash);

	protected:
		std::vector<uint64_t> kmers_hash;
		uint64_t final_hash;
};

#endif