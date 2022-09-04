#include "FromFileDataGenerator.hpp"

FromFileDataGenerator::FromFileDataGenerator(std::string file_name)
{
	file.open(file_name);
}

std::string FromFileDataGenerator::get_data()
{
	std::string res;
	file >> res;
	return res;
}