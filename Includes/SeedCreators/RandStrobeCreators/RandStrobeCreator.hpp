#ifndef _RandStrobes_hpp_
#define _RandStrobes_hpp_

#include "LibrariesAndDefines.hpp"
#include "SeedCreator.hpp"
#include "Strobe.hpp"
#include "Maximizer.hpp"
#include "Minimizer.hpp"

class RandStrobeCreator : private SeedCreator
{
	public:
		RandStrobeCreator(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max, uint64_t mask = DEFAULT_MASK);
		std::vector<Seed*> creat_seeds(const std::string& seq);
		uint8_t get_char_code(char c);
		virtual std::vector<Seed*> creat_seeds(const std::string& seq, const std::vector<uint64_t> hashes) = 0;

	protected:
		size_t kmer_len;
		size_t w_min;
		size_t w_max;
		uint64_t mask;
		Comparator* Comparator;
};

#endif