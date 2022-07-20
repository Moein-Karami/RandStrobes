#ifndef _DataGenerator_hpp_
#define _DataGenerator_hpp_

#include "LibrariesAndDefines.hpp"

class DataGenerator
{
	public:
		virtual std::string get_data() = 0;
};

#endif