#ifndef _ResultPrinter_hpp
#define _ResultPrinter_hpp 

#include "LibrariesAndDefines.hpp"
#include "Seed.hpp"

class ResultPrinter
{
	public:
		ResultPrinter(std::string output_path, int n);
		void print(std::vector<uint64_t> construction_times, std::vector<int> seeds_size,
				std::string output_path, uint32_t n, uint64_t kmer_len, uint64_t w_min, uint64_t w_max,
				uint64_t mask, std::string seed_method, std::string hash_method, std::string comperator,
				uint64_t seq_len);
		void add_seed(Seed* new_seed, int sample_id);
	private:
		std::ofstream output_csv;
		std::ofstream output_csv2;
};

#endif