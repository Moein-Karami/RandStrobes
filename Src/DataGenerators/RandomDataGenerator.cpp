#include "RandomDataGenerator.hpp"

RandomDataGenerator::RandomDataGenerator(uint64_t seq_len, uint64_t seed)
: seq_len(seq_len)
, seed(seed)
{
	srand(seed);
	std::ofstream file;
	file.open("CreatedSequences/seq.txt");
	file << seed << " " << seq_len << std::endl;
	file.close();
}

std::string RandomDataGenerator::get_data()
{
	char c[] = {'A', 'C', 'T', 'G'};
	std::string res;

	for (uint64_t i = 0; i < seq_len; i++)
		res += c[rand() % 4];

	std::fstream file;
	file.open("CreatedSequences/seq.txt", std::ios::app | std::ios_base::in);
	file << res << std::endl;
	file.close();

	return res;
}