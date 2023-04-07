#ifndef _Strobemer3_hpp_
#define _Strobemer3_hpp_

#include "Strobemer.hpp"

class Strobemer3 : public Strobemer
{
	public:
		// ~Strobemer3();
		Strobemer3();
		std::string get_seed();
		std::string to_string();
		void add_kmer(size_t position, uint64_t kmer_hash);
		// std::vector<size_t> positions;
		void set_final_hash(uint64_t hash);
		// uint8_t last;
		virtual std::vector<uint32_t> get_positions() const;

	protected:
		// std::vector<uint64_t> kmers_hash;
		uint64_t kmers_hash[3];
		uint64_t final_hash;
		uint32_t positions[3];
};

#endif