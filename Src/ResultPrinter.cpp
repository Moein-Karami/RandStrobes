#include "ResultPrinter.hpp"


ResultPrinter::ResultPrinter(std::string output_path, int n)
{	
	std::string output_path_result = "BenchMarkResults/Results/" + output_path;
	std::string output_path_header = "BenchMarkResults/Headers/" + output_path;

	output_csv.open(output_path_result);
	output_csv2.open(output_path_header);

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
			output_csv << "," << "FinalHash";
			output_csv << "," << "Sample";
			output_csv << std::endl;
		}
	}
}

void ResultPrinter::add_seed(Seed* new_seed, int sample_id)
{
	output_csv << new_seed->to_string() << sample_id + 1 << std::endl;
}

void ResultPrinter::print(std::vector<uint64_t> construction_times, std::vector<int> seeds_size,
				std::string output_path, uint32_t n, uint64_t kmer_len, uint64_t w_min, uint64_t w_max,
				uint64_t mask, std::string seed_method, std::string hash_method, std::string comperator,
				uint64_t seq_len)
{
	
	output_csv2 << "TimeExecution,NumberofSeeds,n,kmer_len,w_min,w_max,mask,SeedGeneratorMethod,HashMethod,seq_len,Sample,Comperator" << std::endl;
	for (int i = 0; i < construction_times.size(); i++)
	{
		if(comperator == "")
			comperator = "max";
		output_csv2 << construction_times[i] << "," << seeds_size[i] << "," << n << "," <<
			kmer_len << "," << w_min << "," << w_max << "," << mask << "," << seed_method << 
			"," << hash_method << "," <<  seq_len << "," <<  i + 1 << "," << comperator << std::endl;
	}
	
	output_csv.close();
	output_csv2.close();
}

