#ifndef _Seed_hpp_
#define _Seed_hpp_

#include "LibrariesAndDefines.hpp"

class Seed
{
	public:
		Seed(uint64_t construction_time);
		uint64_t get_construction_time();
		virtual std::string get_seed() = 0;

	protected:
		uint64_t construction_time;
};

#endif