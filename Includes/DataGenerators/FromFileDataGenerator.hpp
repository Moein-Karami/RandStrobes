#ifndef _FromFileDataGenerator_hpp_
#define _FromFileDataGenerator_hpp_

#include "DataGenerator.hpp"

class FromFileDataGenerator : public DataGenerator
{
	public:
		FromFileDataGenerator(std::string file_name);
		std::string get_data();
	private:
		std::ifstream file;
		std::queue<std::string> data;
};

#endif