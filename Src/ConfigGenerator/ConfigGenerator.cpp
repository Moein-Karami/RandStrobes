#include "ConfigGenerator.hpp"

ConfigGenerator::ConfigGenerator(size_t kmer_len, uint64_t w_min, uint64_t w_max, uint8_t n, uint64_t mask)
: kmer_len(kmer_len)
, w_min(w_min)
, w_max(w_max)
, n(n)
, mask(mask)
{
}

void ConfigGenerator::add_data_generator_config(std::string path)
{
	Json::Value config;
	config["DataGenerator"] = "RandomDataGenerator";

	Json::Value data_generator_config;
	data_generator_config["seq_len"] = SEQ_LEN;
	config["DataGeneratorConfig"] = data_generator_config;

	add_hasher_config(path + "_RandomDataGenerator", config);
}

void ConfigGenerator::add_hasher_config(std::string output_path, Json::Value config)
{
	std::vector<std::string> simple_hashers = {"NoHash", "ThomasWangHash"};
	std::vector<std::string> seed_based_hashers = {"WyHash", "XXHash"};
	Json::Value hasher_config;

	config["Hasher"] = "SimpleHasher";
	for (auto method : simple_hashers)
	{
		hasher_config["method"] = method;
		config["HasherConfig"] = hasher_config;
		add_comparator_config(output_path + "_" + method, config);
	}

	config["Hasher"] = "SeedBasedHasher";
	for (auto method : seed_based_hashers)
	{
		hasher_config["method"] = method;
		config["HasherConfig"] = hasher_config;
		add_comparator_config(output_path + "_" + method, config);
	}
}

void ConfigGenerator::add_comparator_config(std::string output_path, Json::Value config)
{
	std::vector<std::string> comparators = {"min", "max"};

	for (auto comparator : comparators)
	{
		config["Comparator"] = comparator;
		add_seed_creator_config(output_path + "_" + comparator, config);
	}
}

void ConfigGenerator::add_seed_creator_config(std::string output_path, Json::Value config)
{
	std::vector<std::string> seed_creators = {"GuoPibri", "LiuPatroLi", "SahlinBitCount", "SahlinMod", "Shen", "XorVar"};

	config["SeedCreator"] = "RandStrobeCreator";
	
	Json::Value seed_creator_config;
	seed_creator_config["kmer_len"] = kmer_len;
	seed_creator_config["w_min"] = w_min;
	seed_creator_config["w_max"] = w_max;
	seed_creator_config["n"] = n;
	seed_creator_config["mask"] = mask;

	for (auto seed_creator : seed_creators)
	{
		seed_creator_config["method"] = seed_creator;
		config["SeedCreatorConfig"] = seed_creator_config;
		add_number_of_samples_config(output_path + "_" + seed_creator, config);
	}
}

void ConfigGenerator::add_number_of_samples_config(std::string output_path, Json::Value config)
{
	output_path += "_" + std::to_string(NUMBER_OF_SAMPLES) + ".json";
	Json::StyledWriter writer;

	std::ofstream file(output_path);
	file << writer.write(config);
	file.close();
}

int32_t main()
{

	std::string output_path;
	size_t kmer_len;
	uint64_t w_min;
	uint64_t w_max;
	uint8_t n;
	uint64_t mask;

	std::cin >> output_path >> kmer_len >> w_min >> w_max >> n >> mask;
	ConfigGenerator config_generator(kmer_len, w_min, w_max, n, mask);
	config_generator.add_data_generator_config(output_path);
}