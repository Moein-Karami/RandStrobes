#ifndef _Hasher_hpp_
#define _Hasher_hpp_

#include "LibrariesAndDefines.hpp"

class Hasher
{
	public:
		inline virtual uint64_t hash(const void* key, size_t len) = 0;
		inline virtual uint64_t hash(uint64_t key)
		{
			return hash(&key, sizeof(key));
		}
};

#endif