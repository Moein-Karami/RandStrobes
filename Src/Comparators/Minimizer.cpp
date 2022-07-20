#include "Minimizer.hpp"

bool Minimizer::is_first_better(uint64_t first, uint64_t second)
{
	return first < second;
}