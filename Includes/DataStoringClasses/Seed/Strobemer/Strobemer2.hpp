#ifndef _Strobemer2_hpp_
#define _Strobemer2_hpp_

#include "Strobemer.hpp"

class Strobemer2 : public Strobemer
{
	public:
		// ~Strobemer2();
		Strobemer2();
		std::string get_seed();
		std::string to_string();
		void add_kmer(size_t position, uint64_t kmer_hash);
		// std::vector<size_t> positions;
		void set_final_hash(uint64_t hash);
		virtual std::vector<uint32_t> get_positions() const;

	protected:
		// std::vector<uint64_t> kmers_hash;
		uint64_t kmers_hash[2];
		uint32_t positions[2];
};

#endif