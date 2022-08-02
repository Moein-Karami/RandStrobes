#include "ResultPrinter.hpp"

void ResultPrinter::print(uint64_t construction_time, std::vector<Seed*> seeds, std::string output_path)
{
	std::ofstream output;
	output.open(output_path);

	output << construction_time << std::endl;
	for (auto seed : seeds)
		output << seed->to_string() << std::endl;
	output.close();
}