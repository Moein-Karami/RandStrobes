#include "RandomDataGenerator.hpp"

RandomDataGenerator::RandomDataGenerator(uint64_t seq_len, uint64_t seed)
: seq_len(seq_len)
, seed(seed)
{
	// srand(seed);
	// std::ofstream file;
	// file.open("CreatedSequences/seq.txt");
	// file << seed << " " << seq_len << std::endl;
	// file.close();
	// std::cout << "initial" << std::endl;
}

std::string RandomDataGenerator::get_data()
{
	srand(seed);
	seed += rand();

	char c[] = {'A', 'C', 'T', 'G'};
	std::string res;

	for (size_t i = 0; i < seq_len; i++)
		res += c[rand() % 4];

	// std::cout << "shit\n";
	// std::cout << rand() << " " << rand() << " " << rand() << " " << rand() << std::endl;
	// std::fstream file;
	// file.open("CreatedSequences/seq.txt", std::ios::app | std::ios_base::in);
	// file << res << std::endl;
	// file.close();

	return res;
}