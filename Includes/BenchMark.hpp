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
#include "RandStrobeCreatorLiuPatroLi.hpp"
#include "RandStrobeCreatorMAMod.hpp"
#include "RandStrobeCreatorFastMAXor.hpp"
#include "RandStrobeCreatorFixedSahlinMod.hpp"
#include "RandStrobeCreatorSpecialCaseFixedShen.hpp"
#include "RandStrobeCreatorMAXor.hpp"


#include "json-forwards.h"
#include "json.h"

class BenchMark
{
	public:
		void run(Json::Value config, std::string output_path);
		Comparator* create_comparator(Json::Value config);
		Hasher* create_hasher(Json::Value config);
		SeedCreator* create_seed_creator(Json::Value config);
		DataGenerator* create_data_generator(Json::Value config);
};

#endif