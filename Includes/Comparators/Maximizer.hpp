#ifndef _Maximizer_hpp_
#define _Maximizer_hpp_

#include "Comparaotr.hpp"

class Maximizer : public Comparator
{
	public:
		bool is_first_better(uint64_t first, uint64_t second);
};

#endif