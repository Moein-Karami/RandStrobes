#include "NoHash.hpp"

uint64_t NoHash::hash(const void* key, size_t len)
{
	uint64_t res = *((uint64_t*) key);
	return res;
}