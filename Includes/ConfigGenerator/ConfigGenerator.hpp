#ifndef _ConfigGenerator_hpp_
#define _ConfigGenerator_hpp_

#include "LibrariesAndDefines.hpp"
#include "json.h"
#include "json-forwards.h"

class ConfigGenerator
{
	public:
		ConfigGenerator(uint64_t kmer_len, uint64_t w_min, uint64_t w_max, uint32_t n, uint64_t mask,
				uint64_t number_of_samples, uint64_t seq_len, std::string data_generator, std::string data_file_name);
		void add_data_generator_config(std::string output_path);
		void add_hasher_config(std::string output_path, Json::Value config);
		void add_comparator_config(std::string output_path, Json::Value config);
		void add_seed_creator_config(std::string output_path, Json::Value config);
		void add_number_of_samples_config(std::string output_path, Json::Value config);

	protected:
		uint64_t kmer_len;
		uint64_t w_min;
		uint64_t w_max;
		uint32_t n;
		uint64_t mask;
		uint64_t number_of_samples;
		uint64_t seq_len;
		std::string data_generator;
		std::string data_file_name;
};

#endif