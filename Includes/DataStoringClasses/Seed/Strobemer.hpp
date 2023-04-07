#ifndef _Strobemer_hpp_
#define _Strobemer_hpp_

#include "Seed.hpp"

class Strobemer : public Seed
{
	public:
		~Strobemer();
		Strobemer(int n);
		std::string get_seed();
		std::string to_string();
		void add_kmer(size_t position, uint64_t kmer_hash);
		// std::vector<size_t> positions;
		uint32_t positions[2];
		void set_final_hash(uint64_t hash);
		uint8_t last;

	protected:
		// std::vector<uint64_t> kmers_hash;
		uint64_t kmers_hash[2];
		uint64_t final_hash;
};

#endif