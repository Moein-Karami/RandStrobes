#ifndef _NoHash_hpp_
#define _NoHash_hpp_
#include "Hasher.hpp"

class NoHash : public Hasher
{
	public:
		uint64_t hash(const void* key, size_t len);
};

#endif