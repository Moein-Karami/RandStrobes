#ifndef _Hasher_hpp_
#define _Hasher_hpp_

#include "LibrariesAndDefines.hpp"

class Hasher
{
	public:
		virtual uint64_t hash(const void* key, size_t len) = 0;
		virtual uint64_t hash(uint64_t key);
};

#endif