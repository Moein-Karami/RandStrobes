#ifndef _Comparator_hpp_
#define _Comparator_hpp_

#include "LibrariesAndDefines.hpp"

class Comparator
{
	public:
		inline virtual bool is_first_better(uint64_t first, uint64_t second)
		{
			// This is a pure virtual function, so it must be overriden by the child class.
		}
};

#endif