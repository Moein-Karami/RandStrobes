#ifndef _SeedCreators_hpp_
#define _SeedCreators_hpp_

#include "LibrariesAndDefines.hpp"
#include "Seed.hpp"

class SeedCreator
{
	public:
		virtual std::vector<Seed*> creat_seeds() = 0;
};

#endif