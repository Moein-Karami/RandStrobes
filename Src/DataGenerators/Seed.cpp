#include "Seed.hpp"

Seed::Seed(uint64_t construction_time)
: construction_time(construction_time)
{}

uint64_t Seed::get_construction_time()
{
	return construction_time;
}