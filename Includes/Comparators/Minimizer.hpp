#ifndef _Minimizer_hpp_
#define _Minimizer_hpp_

#include "Comparaotr.hpp"

class Minimizer : public Comparator
{
	public:
		bool is_first_better(uint64_t first, uint64_t second);
};

#endif