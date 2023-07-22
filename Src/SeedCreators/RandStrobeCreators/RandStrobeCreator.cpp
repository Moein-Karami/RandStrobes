#include "RandStrobeCreator.hpp"

RandStrobeCreator::RandStrobeCreator(Hasher* hasher, Comparator* comparator, size_t kmer_len, size_t w_min, size_t w_max,
		uint32_t n, uint64_t mask)
: SeedCreator(hasher)
, comparator(comparator)
, kmer_len(kmer_len)
, w_min(w_min)
, w_max(w_max)
, n(n)
, mask(mask)
{
	uint64_t tmp_mask = -1;
	tmp_mask = tmp_mask >> (64 - kmer_len * 2);
	this->mask &= tmp_mask;
	wy_hasher = new WyHash();
	xx_hasher = new XXHash();
}

RandStrobeCreator::~RandStrobeCreator()
{
	delete(hasher);
	delete(comparator);
	delete(wy_hasher);
	delete(xx_hasher);
}

uint32_t RandStrobeCreator::get_char_code(char c)
{
	switch (c)
	{
	case 'A':
		return 0;
		break;
	case 'C':
		return 1;
		break;
	case 'G':
		return 2;
		break;
	default:
		return 3;
		break;
	}
	return 0;
}

std::vector<Seed*> RandStrobeCreator::create_seeds(const std::string& sequence)
{
	seq = sequence;
	hashes.clear();
	kmers.clear();
	hashes.reserve(seq.size() + 1);
	kmers.reserve(seq.size() + 1);
	
	uint64_t curr_kmer = 0;
	uint64_t tmp;
	
	for (int i = 0; i < kmer_len - 1; i++)
		curr_kmer = (curr_kmer << 2) | get_char_code(seq[i]);

	for (int i = kmer_len - 1; i < seq.size(); i++)
	{
		curr_kmer = (curr_kmer << 2) | get_char_code(seq[i]);
		tmp = curr_kmer & mask;
		hashes.push_back(hasher->hash(&tmp, sizeof(tmp)));
		kmers.push_back(tmp);
	}

	return create_seeds();
}

std::vector<Seed*> RandStrobeCreator::create_seeds()
{
	prepare_data();

	std::vector<Seed*> seeds;
	seeds.reserve(seq.size());
	Strobemer* strobemer;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;
	
	for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		if (n == 2)
			strobemer = new Strobemer2();
		else if (n == 3)
			strobemer = new Strobemer3();

		strobemer->add_kmer(i, kmers[i]);
		curr_hash = get_first_hash(i);
		for (int j = 1; j < n; j++)
		{
			best_choose = i + w_min + (j - 1) * w_max;
			best_value = get_score(curr_hash, best_choose);
			for (size_t q = i + w_min + (j - 1) * w_max + 1; q < std::min(i + j * w_max + 1, hashes.size()); q++)
			{
				if (comparator->is_first_better(get_score(curr_hash, q), best_value))
				{
					best_choose = q;
					best_value = get_score(curr_hash, q);
				}
			}
			strobemer->add_kmer(best_choose, kmers[best_choose]);
			curr_hash = get_new_curr_hash(strobemer);
		}
		strobemer->set_final_hash(get_final_hash(strobemer));
		seeds.push_back(strobemer);
	}
	return seeds;
	// for (int i = 0; i < seeds.size(); i++)
	// 	delete(seeds[i]);
	// seeds.clear();
	// std::vector<Seed*> tmp;
	// return tmp;

}

uint64_t RandStrobeCreator::get_first_hash(size_t ind)
{
	return hashes[ind];
}

void RandStrobeCreator::prepare_data()
{
	/* Do nothing */
}

uint64_t RandStrobeCreator::get_final_hash(const Strobemer* strobemer)
{
	uint64_t final_hash = 0;
	std::vector<uint32_t> positions = strobemer->get_positions();
	// for (auto pos : positions)
	// 	final_hash ^= hasher->hash(hashes[pos]);

	// for (int i = 0; i < positions.size(); i++)
	// {
	// 	if (i % 2 == 0)
	// 		final_hash ^= wy_hasher->hash(xx_hasher->hash(kmers[positions[i]]));
	// 	else
	// 		final_hash ^= xx_hasher->hash(wy_hasher->hash(kmers[positions[i]]));
	// }

	// for (int i = 0; i < strobemer->last; i++)
	// 	final_hash ^= hasher->hash(hashes[strobemer->positions[i]]);

	// final_hash = xx_hasher->hash(kmers[positions[0]]);
	final_hash = kmers[positions[0]];
	Int128 tmp;
	for (int i = 1; i < positions.size(); i++)
	{
		tmp.low = xx_hasher->hash(final_hash);
		tmp.high = xx_hasher->hash(kmers[positions[i]]);
		final_hash = wy_hasher->hash(&tmp, sizeof(tmp));
	}

	return final_hash;
}

uint64_t RandStrobeCreator::get_new_curr_hash(const Strobemer* strobemer)
{
	return get_final_hash(strobemer);
}