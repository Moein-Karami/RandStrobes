#ifndef _ResultPrinter_hpp
#define _ResultPrinter_hpp 

#include "LibrariesAndDefines.hpp"
#include "Seed.hpp"

class ResultPrinter
{
	public:
		void print(std::vector<uint64_t> construction_times, std::vector<std::vector<Seed*>> seeds_collection,
				std::string output_path, uint32_t n, uint64_t kmer_len, uint64_t w_min, uint64_t w_max,
				uint64_t mask, std::string seed_method, std::string hash_method, std::string comperator,
				uint64_t seq_len);
};

#endif