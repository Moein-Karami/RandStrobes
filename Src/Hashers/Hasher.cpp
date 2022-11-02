#include "Hasher.hpp"

uint64_t Hasher::hash(uint64_t key)
{
	return hash(&key, sizeof(key));
}