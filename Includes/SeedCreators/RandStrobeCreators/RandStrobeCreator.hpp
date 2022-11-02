#ifndef _RandStrobes_hpp_
#define _RandStrobes_hpp_

#include "LibrariesAndDefines.hpp"
#include "SeedCreator.hpp"
#include "Strobe.hpp"
#include "Maximizer.hpp"
#include "Minimizer.hpp"

class RandStrobeCreator : public SeedCreator
{
	public:
		RandStrobeCreator(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK);
		~RandStrobeCreator();
		virtual std::vector<Seed*> create_seeds(const std::string& sequence);
	
	protected:
		std::string seq;
		std::vector<uint64_t> kmers;
		std::vector<uint64_t> hashes;
		size_t kmer_len;
		size_t w_min;
		size_t w_max;
		uint64_t mask;
		uint32_t n;
		Comparator* comparator;
		virtual uint64_t get_score(uint64_t curr_hash, uint64_t first_ind, uint64_t last_ind) = 0;
		virtual void prepare_data();
		uint32_t get_char_code(char c);
		virtual std::vector<Seed*> create_seeds();
		virtual uint64_t get_first_hash(size_t ind);
		virtual uint64_t get_final_hash(const Strobe* strobe);
};

#endif