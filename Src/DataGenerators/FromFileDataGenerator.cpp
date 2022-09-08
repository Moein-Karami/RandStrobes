#include "FromFileDataGenerator.hpp"

FromFileDataGenerator::FromFileDataGenerator(std::string file_name)
{
	file.open(file_name);
	std::string seq;
	std::string line;
	while (file >> line)
	{
		if (line[0] == '>')
			data.push(seq);
		else 
			seq += line;
	}
	file.close();
}

std::string FromFileDataGenerator::get_data()
{
	std::string seq = data.front();
	data.pop();
	data.push(seq);
	return seq;
}