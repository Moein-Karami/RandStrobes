#include "FromFileDataGenerator.hpp"

FromFileDataGenerator::FromFileDataGenerator(std::string file_name)
{
	file.open(file_name);
	std::string seq;
	std::string line;
	while (file >> line)
	{
		if (line[0] == '>')
		{
			if (seq.size() > 0)
				data.push(seq);
			seq = "";
		}
		else if (line.size() > 0)
		{
			for (int i = 0; i < line.size(); i++)
				line[i] = toupper(line[i]);
			seq += line;
		}
			
	}
	if (seq.size() > 0)
		data.push(seq);

	file.close();
}

std::string FromFileDataGenerator::get_data()
{
	std::string seq = data.front();
	data.pop();
	data.push(seq);
	return seq;
}