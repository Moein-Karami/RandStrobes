#ifndef _ThomasWangHash_hpp_
#define _ThomasWangHash_hpp_

#include "Hasher.hpp"

class ThomasWangHash : public Hasher
{
	public:
		ThomasWangHash(uint64_t mask = -1);
		inline uint64_t hash(const void* key, size_t len)
		{
			uint64_t key_val = *((const uint64_t*) key);
			key_val = (~key_val + (key_val << 21)) & mask; // key_val = (key_val << 21) - key_val - 1;
			key_val = key_val ^ key_val >> 24;
			key_val = ((key_val + (key_val << 3)) + (key_val << 8)) & mask; // key_val * 265
			key_val = key_val ^ key_val >> 14;
			key_val = ((key_val + (key_val << 2)) + (key_val << 4)) & mask; // key_val * 21
			key_val = key_val ^ key_val >> 28;
			key_val = (key_val + (key_val << 31)) & mask;
			return key_val;
		}
	protected:
		uint64_t mask;
};

#endif