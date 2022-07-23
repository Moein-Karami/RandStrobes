#ifndef _Seed_hpp_
#define _Seed_hpp_

#include "LibrariesAndDefines.hpp"

class Seed
{
	public:
		virtual std::string get_seed() = 0;
		virtual std::string to_string() = 0;
};

#endif