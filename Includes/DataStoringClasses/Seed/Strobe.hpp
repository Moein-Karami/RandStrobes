#ifndef _Strobe_hpp_
#define _Strobe_hpp_

#include "Seed.hpp"

class Strobe : public Seed
{
	public:
		std::string get_seed();
		std::string to_string();
		void add_kmer(size_t position, uint64_t kmer_hash);

	protected:
		std::vector<uint64_t> kmers_hash;
		std::vector<size_t> positions;
};

#endif