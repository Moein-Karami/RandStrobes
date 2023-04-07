#ifndef _Strobemer_hpp_
#define _Strobemer_hpp_

#include "Seed.hpp"

class Strobemer : public Seed
{
	public:
		// ~Strobemer();
		Strobemer();
		virtual std::string get_seed() = 0;
		virtual std::string to_string() = 0;
		virtual void add_kmer(size_t position, uint64_t kmer_hash) = 0;
		// std::vector<size_t> positions;
		// uint32_t positions[2];
		virtual void set_final_hash(uint64_t hash) = 0;
		virtual std::vector<uint32_t> get_positions() const = 0;

	protected:
		// std::vector<uint64_t> kmers_hash;
		// uint64_t kmers_hash[2];
		// uint64_t final_hash;
		uint8_t last;
};

#endif