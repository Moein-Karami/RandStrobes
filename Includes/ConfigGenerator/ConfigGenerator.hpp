#ifndef _ConfigGenerator_hpp_
#define _ConfigGenerator_hpp_

#include "LibrariesAndDefines.hpp"
#include "json.h"
#include "json-forwards.h"

const uint64_t NUMBER_OF_SAMPLES = 10;
const uint64_t SEQ_LEN = 10000;

class ConfigGenerator
{
	public:
		ConfigGenerator(size_t kmer_len, uint64_t w_min, uint64_t w_max, uint32_t n, uint64_t mask);
		void add_data_generator_config(std::string output_path);
		void add_hasher_config(std::string output_path, Json::Value config);
		void add_comparator_config(std::string output_path, Json::Value config);
		void add_seed_creator_config(std::string output_path, Json::Value config);
		void add_number_of_samples_config(std::string output_path, Json::Value config);

	protected:
		size_t kmer_len;
		uint64_t w_min;
		uint64_t w_max;
		uint32_t n;
		uint64_t mask;
};

#endif