#ifndef _RandStrobeCreatorSpecialCaseFixedShen_hpp_
#define _RandStrobeCreatorSpecialCaseFixedShen_hpp_

#include "RandStrobeCreatorShen.hpp"

class RandStrobeCreatorSpecialCaseFixedShen : public RandStrobeCreatorShen
{
	public:
		RandStrobeCreatorSpecialCaseFixedShen(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
				uint32_t n = DEFAULT_N, uint64_t mask = DEFAULT_MASK, uint64_t q = DEFAULT_Q);
	protected:
		void prepare_data();
};

#endif