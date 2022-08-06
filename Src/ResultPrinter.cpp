#include "ResultPrinter.hpp"

void ResultPrinter::print(std::vector<uint64_t> construction_times, std::vector<std::vector<Seed*>> seeds_collection,
				std::string output_path)
{
	std::ofstream output;
	output.open(output_path);
	output << construction_times.size() << std::endl;

	for (int i = 0; i < construction_times.size(); i++)
	{
		output << construction_times[i] << std::endl << seeds_collection[i].size() << std::endl;
		for (auto seed : seeds_collection[i])
			output << seed->to_string() << std::endl;
		output << std::endl;
	}
	
	output.close();
}