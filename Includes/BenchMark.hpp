#ifndef _BenchMark_hpp_
#define _BenchMark_hpp_

#include "ResultPrinter.hpp"
#include "LibrariesAndDefines.hpp"

#include "Minimizer.hpp"
#include "Maximizer.hpp"

#include "RandomDataGenerator.hpp"
#include "Strobe.hpp"

#include "WyHash.hpp"
#include "XXHash.hpp"
#include "NoHash.hpp"
#include "ThomasWangHash.hpp"

#include "RandStrobeCreatorGuoPibri.hpp"
#include "RandStrobeCreatorSahlinBitCount.hpp"
#include "RandStrobeCreatorSahlinMod.hpp"
#include "RandStrobeCreatorShen.hpp"
#include "RandStrobeCreatorXorVar.hpp"


#include <json\value.h>
#include <json\json.h>

class BenchMark
{
	public:
		void run(std::string config_file_name);
		Comparator* creat_comparator(Json::Reader config);
		Hasher* creat_hasher(Json::Reader config);
		RandStrobeCreator* creat_randstrobe_creator(Json::Reader config);
		DataGenerator* creat_data_generator(Json::Reader config);
		

}

#endif