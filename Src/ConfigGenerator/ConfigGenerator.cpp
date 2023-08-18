#include "ConfigGenerator.hpp"

ConfigGenerator::ConfigGenerator(uint64_t kmer_len, uint64_t w_min, uint64_t w_max, uint32_t n, uint64_t mask,
		uint64_t number_of_samples, uint64_t seq_len, std::string data_generator, std::string data_file_name)
: kmer_len(kmer_len)
, w_min(w_min)
, w_max(w_max)
, n(n)
, mask(mask)
, number_of_samples(number_of_samples)
, seq_len(seq_len)
, data_generator(data_generator)
, data_file_name(data_file_name)
{
}

void ConfigGenerator::add_data_generator_config(std::string path)
{
	Json::Value config;
	Json::Value data_generator_config;

	if (data_generator == "Random")
	{
		config["DataGenerator"] = "RandomDataGenerator";
		data_generator_config["seq_len"] = seq_len;
		config["DataGeneratorConfig"] = data_generator_config;
		add_hasher_config(path + "_RandomDataGenerator", config);
	}
	else if (data_generator == "FromFile")
	{
		std::vector<std::string> file_names = {data_file_name};
		config["DataGenerator"] = "FromFileDataGenerator";
		for (auto name : file_names)
		{
			data_generator_config["file_name"] = "Data/" + name;
			config["DataGeneratorConfig"] = data_generator_config;
			add_hasher_config(path + "_FromFileDataGenerator_" + name, config);
		}
	}
	else
	{
		std::cout << "Unknown data generator: " << data_generator << std::endl;
		exit(1);
	}
}

void ConfigGenerator::add_hasher_config(std::string output_path, Json::Value config)
{
	std::vector<std::string> simple_hashers = {"NoHash", "ThomasWangHash"};
	std::vector<std::string> seed_based_hashers = {"WyHash", "XXHash"};
	Json::Value hasher_config;

	config["Hasher"] = "Uniform";
	add_comparator_config(output_path + "_Uniform", config);

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

	// if (config["Hasher"] == "FullyRandom")
	// {
	// 	add_seed_creator_config(output_path, config);
	// 	return ;
	// }

	for (auto comparator : comparators)
	{
		config["Comparator"] = comparator;
		add_seed_creator_config(output_path + "_" + comparator, config);
	}
}

void ConfigGenerator::add_seed_creator_config(std::string output_path, Json::Value config)
{
	std::vector<std::string> seed_creators = {"GuoPibri", "LiuPatroLi", "SahlinBitCount", "SahlinMod", "Shen", "XorVar",
		"MAMod", "Traditional"};//, "FixedSahlinMod", "SpecialCaseFixedShen", "MAXor", "RandomMAMod", "MAXorVar", "FastMAXor"};

	config["SeedCreator"] = "RandStrobeCreator";
	
	Json::Value seed_creator_config;
	seed_creator_config["kmer_len"] = kmer_len;
	seed_creator_config["w_min"] = w_min;
	seed_creator_config["w_max"] = w_max;
	seed_creator_config["n"] = (uint64_t) n;
	seed_creator_config["mask"] = mask;

	if (config["Hasher"] == "Uniform")
	{
		seed_creator_config["method"] = "Uniform";
		config["SeedCreatorConfig"] = seed_creator_config;
		add_number_of_samples_config(output_path + "_" + std::to_string(n), config);
		return ;
	}

	for (auto seed_creator : seed_creators)
	{
		if ((seed_creator == "LiuPatroLi" || seed_creator == "RandomMAMod") && (config["HasherConfig"]["method"] ==
				"NoHash" || config["HasherConfig"]["method"] == "ThomasWangHash"))
			continue;
		if (seed_creator == "MAXor" && config["HasherConfig"]["method"] == "NoHash")
			continue;
		if (seed_creator == "Traditional" && config["HasherConfig"]["method"] != "NoHash")
			continue;

		seed_creator_config["method"] = seed_creator;
		config["SeedCreatorConfig"] = seed_creator_config;
		add_number_of_samples_config(output_path + "_" + seed_creator + "_" + std::to_string(n), config);
	}
}

void ConfigGenerator::add_number_of_samples_config(std::string output_path, Json::Value config)
{
	output_path += "_" + std::to_string(number_of_samples) + ".json";
	config["NumberOfSamples"] = number_of_samples;
	Json::StyledWriter writer;

	std::ofstream file(output_path);
	file << writer.write(config);
	file.close();
}

int32_t main()
{

	std::string output_path;
	uint64_t kmer_len;
	uint64_t w_min;
	uint64_t w_max;
	uint32_t n;
	uint64_t mask;
	uint64_t number_of_samples;
	uint64_t seq_len;
	std::string data_generator;
	std::string data_file_name;

	std::cout << "Directory: ";
	std::cin >> output_path; 
	
	std::cout << "kmer len: ";
	std::cin >> kmer_len;

	std::cout << "w_min and w_max: ";
	std::cin >> w_min >> w_max;

	std::cout << "n: ";
	std::cin >> n;

	std::cout << "mask: ";
	std::cin >> mask;

	std::cout << "number of samples: ";
	std::cin >> number_of_samples;

	std::cout << "DataGenerator: ";
	std::cin >> data_generator;

	if (data_generator == "Random")
	{
		seq_len = 0;
		std::cout << "seq len: ";
		std::cin >> seq_len;
	}
	else if (data_generator == "FromFile")
	{
		std::cout << "Date file name: ";
		std::cin >> data_file_name;
	}

	ConfigGenerator config_generator(kmer_len, w_min, w_max, n, mask, number_of_samples, seq_len, data_generator,
			data_file_name);
	config_generator.add_data_generator_config(output_path);
}