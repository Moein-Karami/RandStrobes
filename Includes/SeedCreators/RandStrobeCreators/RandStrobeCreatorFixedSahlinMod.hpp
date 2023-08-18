#ifndef _RandStrobeCreatorFixedSahlinMod_hpp_
#define _RandStrobeCreatorFixedSahlinMod_hpp_

#include "RandStrobeCreatorSahlinMod.hpp"

class RandStrobeCreatorFixedSahlinMod : public RandStrobeCreatorSahlinMod
{
	public:
		RandStrobeCreatorFixedSahlinMod(Hasher* hasher, Comparator* comparator, uint64_t kmer_len, uint64_t w_min, uint64_t w_max,
				uint64_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK, uint64_t p = DEFAULT_P);
	protected:
		void prepare_data();
		uint64_t get_new_curr_hash(const Strobemer* strobemer);
};

#endif