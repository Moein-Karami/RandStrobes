#ifndef _ThomasWangHash_hpp_
#define _ThomasWangHash_hpp_

#include "Hasher.hpp"

class ThomasWangHash : public Hasher
{
	public:
		ThomasWangHash(uint64_t mask = -1);
		uint64_t hash(const void* key, size_t len);
	protected:
		uint64_t mask;
};

#endif