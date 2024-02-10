#ifndef _SeedCreators_hpp_
#define _SeedCreators_hpp_

#include "LibrariesAndDefines.hpp"
#include "Seed.hpp"
#include "WyHash.hpp"
#include "XXHash.hpp"
#include "ThomasWangHash.hpp"
#include "NoHash.hpp"

class SeedCreator
{
	public:
		virtual std::vector<Seed*> create_seeds(const std::string& seq) = 0;
		SeedCreator(Hasher* hasher);
		uint64_t state;
	protected:
		Hasher* hasher;
		// To stop harmfull optimization
};

#endif