#include "RandStrobeCreatorMAMod.hpp"

RandStrobeCreatorMAMod::RandStrobeCreatorMAMod(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask, uint64_t p)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
, p(p)
{
}

inline std::vector<Seed*> RandStrobeCreatorMAMod::create_seeds()
{
	real_hashes.reserve(seq.size());
	for (size_t i = 0; i < hashes.size(); i++)
	{
		real_hashes.push_back(hashes[i]);
		hashes[i] %= 100001;
	}
		

	if (comparator->is_first_better(1, 2))
		return create_seeds_min();
	else
		return create_seeds_max();
}

inline std::vector<Seed*> RandStrobeCreatorMAMod::create_seeds_min()
{
	std::set<pii> hash_values;
	// for (size_t i = 1; i < n; i++)
		for (size_t j = w_min ; j < std::min(w_max + 1, hashes.size()); j++)
			hash_values.insert(pii(hashes[j], j));
	
	
	std::vector<Seed*> seeds;
	std::vector<uint64_t> final_hashes;
	final_hashes.reserve(seq.size());

	Strobemer* strobemer;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;
	pii tmp;
	pii candidate;
	std::set<pii>::iterator it;

	for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		// if (n == 2)
		// 	strobemer = new Strobemer2();
		// else if (n == 3)
		// 	strobemer = new Strobemer3();
		// strobemer->add_kmer(i, kmers[i]);
		// curr_hash = get_first_hash(i);
		curr_hash = hashes[i];
		// for (int j = 1; j < n; j++)
		// {
			tmp = *(hash_values.begin());
			it = hash_values.lower_bound({p - curr_hash, std::numeric_limits<uint64_t>::min()});
			if (it != hash_values.end())
			{
				candidate = *it;
				if ((tmp.first + curr_hash) % p > (candidate.first + curr_hash) % p)
					tmp = candidate;
			}
			// strobemer->add_kmer(tmp.second, kmers[tmp.second]);
			// curr_hash = get_new_curr_hash(strobemer) % p;
			hash_values.erase(pii(hashes[i + w_min], i + w_min));
			if (i + w_max + 1 < hashes.size())
				hash_values.insert(pii(hashes[i + w_max + 1], i + w_max + 1));
		// }
		// strobemer->set_final_hash(get_final_hash(strobemer));
		// seeds.push_back(strobemer);
		final_hashes.push_back((real_hashes[i] << 1) - real_hashes[tmp.second]);
	}
	return seeds;
}

inline std::vector<Seed*> RandStrobeCreatorMAMod::create_seeds_max()
{
	uint64_t maximal_uint = std::numeric_limits<uint64_t>::max();

	std::set<pii, std::greater<pii>> hash_values;
	// for (size_t i = 1; i < n; i++)
		for (size_t j = w_min ; j < std::min(w_max + 1, hashes.size()); j++)
			hash_values.insert(pii(hashes[j], maximal_uint - j));
	
	std::vector<uint64_t> final_hashes;
	final_hashes.reserve(seq.size());
	std::vector<Seed*> seeds;
	// Strobemer* strobemer;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;
	pii tmp;
	pii candidate;
	std::set<pii>::iterator it;

	for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		// if (n == 2)
		// 	strobemer = new Strobemer2();
		// else if (n == 3)
		// 	strobemer = new Strobemer3();
		// strobemer->add_kmer(i, kmers[i]);
		// curr_hash = get_first_hash(i);
		curr_hash = hashes[i];
		// for (int j = 1; j < n; j++)
		// {
			tmp = *(hash_values.begin());
			it = hash_values.lower_bound({p - curr_hash - 1, maximal_uint});
			if (it != hash_values.end())
			{
				candidate = *it;
				if ((tmp.first + curr_hash) % p < (candidate.first + curr_hash) % p)
					tmp = candidate;
			}
			// strobemer->add_kmer(maximal_uint - tmp.second, kmers[maximal_uint - tmp.second]);
			// curr_hash = get_new_curr_hash(strobemer) % p;
			hash_values.erase(pii(hashes[i + w_min], maximal_uint - (i + w_min )));
			if (i + w_max + 1 < hashes.size())
				hash_values.insert(pii(hashes[i + w_max + 1], maximal_uint - (i + w_max + 1)));
		// }
		// strobemer->set_final_hash(get_final_hash(strobemer));
		// seeds.push_back(strobemer);
		final_hashes.push_back((real_hashes[i] << 1) - real_hashes[maximal_uint - tmp.second]);
	}
	return seeds;
}

inline uint64_t RandStrobeCreatorMAMod::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
	return -1;
}

inline uint64_t RandStrobeCreatorMAMod::get_final_hash(const Strobemer* strobemer)
{
	uint64_t final_hash = 0;
	std::vector<uint32_t> positions = strobemer->get_positions();
	// for (auto pos : positions)
	// 	final_hash ^= hasher->hash(hasher->hash(kmers[pos]));

	// for (int i = 0; i < positions.size(); i++)
	// {
	// 	if (i % 2 == 0)
	// 		final_hash ^= wy_hasher->hash(xx_hasher->hash(kmers[positions[i]]));
	// 	else
	// 		final_hash ^= xx_hasher->hash(wy_hasher->hash(kmers[positions[i]]));
	// }

	// for (int i = 0; i < strobemer->last; i++)
	// 	final_hash ^= hasher->hash(hasher->hash(kmers[strobemer->positions[i]]));

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

inline uint64_t RandStrobeCreatorMAMod::get_new_curr_hash(const Strobemer* strobemer)
{
	return get_final_hash(strobemer);
}