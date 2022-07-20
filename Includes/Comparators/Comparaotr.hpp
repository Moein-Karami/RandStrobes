#ifndef _Comparator_hpp_
#define _Comparator_hpp_

#include "LibrariesAndDefines.hpp"

class Comparator
{
	public:
		virtual bool is_first_better(uint64_t first, uint64_t second) = 0;
};

#endif