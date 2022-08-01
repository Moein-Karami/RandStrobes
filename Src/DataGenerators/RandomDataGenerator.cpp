#include "RandomDataGenerator.hpp"

RandomDataGenerator::RandomDataGenerator(uint64_t seq_len, uint64_t seed)
: seq_len(seq_len)
, seed(seed)
{
}

std::string RandomDataGenerator::get_data()
{
	char c[] = {'A', 'C', 'T', 'G'};
	srand(seed);
	std::string res;

	for (size_t i = 0; i < seq_len; i++)
		res += c[rand() % 4];
	return res;
}