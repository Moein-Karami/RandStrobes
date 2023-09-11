#ifndef _Minimizer_hpp_
#define _Minimizer_hpp_

#include "Comparaotr.hpp"

class Minimizer : public Comparator
{
	public:
		inline bool is_first_better(uint64_t first, uint64_t second)
		{
			return first < second;
		}
};

#endif