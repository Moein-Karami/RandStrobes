#include "ResultPrinter.hpp"

void ResultPrinter::print(std::vector<uint64_t> construction_times, std::vector<std::vector<Seed*>> seeds_collection,
				std::string output_path, uint32_t n, uint64_t kmer_len, uint64_t w_min, uint64_t w_max,
				uint64_t mask, std::string seed_method, std::string hash_method, std::string comperator)
{
	std::ofstream output_csv;
	std::ofstream output_csv2;
	
	std::string output_path_result = "BenchMarkResults/Results/" + output_path;
	std::string output_path_header = "BenchMarkResults/Headers/" + output_path;

	// std::cout << "****** In ResultPrinter::output_path_result : " << output_path_result << 
	// "\n output_path_header: " << output_path_header << " ******" << std::endl;

	output_csv.open(output_path_result);
	output_csv2.open(output_path_header);
	// output_txt << construction_times.size() << std::endl;
	for(int i = 1; i <= n; i++)
	{
		std::stringstream string_to_int;
		string_to_int << i;
		std::string i_string;
		string_to_int >> i_string;
		output_csv << "kmer_" << i_string << "," << "hash_" << i_string;
		if(i != n)
			output_csv << ",";
		else 
		{
			output_csv << "," << "Sample";
			output_csv << std::endl;
		}
	}
	output_csv2 << "TimeExecution,NumberofSeeds,n,kmer_len,w_min,w_max,mask,SeedGeneratorMethod,HashMethod,Sample" << std::endl;
	for (int i = 0; i < construction_times.size(); i++)
	{
		output_csv2 << construction_times[i] << "," << seeds_collection[i].size() << "," << n << "," <<
			kmer_len << "," << w_min << "," << w_max << "," << mask << "," << seed_method << "," << 
			hash_method + "-" + comperator << "," <<  i + 1 << std::endl;
		for (auto seed : seeds_collection[i])
			output_csv << seed->to_string() << i + 1 << std::endl;
		output_csv << std::endl;
	}
	
	output_csv.close();
	output_csv2.close();
}

