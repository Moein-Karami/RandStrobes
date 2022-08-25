#include "RandomDataGenerator.hpp"

RandomDataGenerator::RandomDataGenerator(uint64_t seq_len, uint64_t seed)
: seq_len(seq_len)
, seed(seed)
{
	srand(seed);
}

std::string RandomDataGenerator::get_data()
{
	char c[] = {'A', 'C', 'T', 'G'};
	std::string res;

	for (size_t i = 0; i < seq_len; i++)
		res += c[rand() % 4];
	return res;
}