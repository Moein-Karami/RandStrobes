#ifndef _ResultPrinter_hpp
#define _ResultPrinter_hpp 

#include "LibrariesAndDefines.hpp"
#include "Seed.hpp"

class ResultPrinter
{
	public:
		void print(uint64_t construction_time, std::vector<Seed*> seeds, std::string output_path);
};

#endif