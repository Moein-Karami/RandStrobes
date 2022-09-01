#ifndef _RandStrobeCreatorFixedSahlinMod_hpp_
#define _RandStrobeCreatorFixedSahlinMod_hpp_

#include "RandStrobeCreatorSahlinMod.hpp"

class RandStrobeCreatorFixedSahlinMod : public RandStrobeCreatorSahlinMod
{
	public:
		RandStrobeCreatorFixedSahlinMod(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK, uint64_t p = DEFAULT_P);
	protected:
		void prepare_data();
};

#endif