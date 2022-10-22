#ifndef _RandomDataGenerator_hpp_
#define _RandomDataGenerator_hpp_

#include "DataGenerator.hpp"

class RandomDataGenerator : public DataGenerator
{
	public:
		RandomDataGenerator(uint64_t seq_len, uint64_t seed = DEFAULT_SEED);
		std::string get_data();

	protected:
		uint64_t seq_len;
		uint64_t seed;
};


#endif