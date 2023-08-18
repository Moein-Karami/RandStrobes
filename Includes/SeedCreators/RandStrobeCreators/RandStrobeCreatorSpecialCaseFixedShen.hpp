#ifndef _RandStrobeCreatorSpecialCaseFixedShen_hpp_
#define _RandStrobeCreatorSpecialCaseFixedShen_hpp_

#include "RandStrobeCreatorShen.hpp"

class RandStrobeCreatorSpecialCaseFixedShen : public RandStrobeCreatorShen
{
	public:
		RandStrobeCreatorSpecialCaseFixedShen(Hasher* hasher, Comparator* comparator, uint64_t kmer_len, uint64_t w_min, uint64_t w_max,
				uint64_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK, uint64_t q = DEFAULT_Q);
	protected:
		void prepare_data();
		uint64_t get_new_curr_hash(const Strobemer* strobemer);
};

#endif