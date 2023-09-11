#ifndef _NoHash_hpp_
#define _NoHash_hpp_
#include "Hasher.hpp"

class NoHash : public Hasher
{
	public:
		inline uint64_t hash(const void* key, size_t len)
		{
			uint64_t res = *((uint64_t*) key);
			return res;
		}
};

#endif