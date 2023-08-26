#include "RandStrobeCreatorMAMod.hpp"

RandStrobeCreatorMAMod::RandStrobeCreatorMAMod(Hasher* hasher, Comparator* comparator, uint64_t kmer_len,
		uint64_t w_min, uint64_t w_max, uint64_t n, uint64_t mask, uint64_t p)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
, p(p)
{
}

std::vector<Seed*> RandStrobeCreatorMAMod::create_seeds()
{
	for (uint64_t i = 0; i < hashes.size(); i++)
		new_hashes.push_back(hashes[i] % p);

	if (comparator->is_first_better(1, 2))
		return create_seeds_min();
	else
		return create_seeds_max();
}

std::vector<Seed*> RandStrobeCreatorMAMod::create_seeds_min()
{
	std::set<uint64_t> final_hashes;

	std::set<pii> hash_values[n];
	for (uint64_t i = 1; i < n; i++)
		for (uint64_t j = w_min + (i - 1) * w_max ; j < std::min(i * w_max + 1, hashes.size()); j++)
			hash_values[i].insert(pii(hashes[j], j));
	
	
	std::vector<Seed*> seeds;
	Strobemer* strobemer;
	uint64_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;
	pii tmp;
	pii candidate;
	std::set<pii>::iterator it;
	std::map<uint64_t, long double> appearances;

	for (uint64_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		if (n == 2)
			strobemer = new Strobemer2();
		else if (n == 3)
			strobemer = new Strobemer3();
		strobemer->add_kmer(i, kmers[i]);
		curr_hash = get_first_hash(i);
		for (uint64_t j = 1; j < n; j++)
		{
			tmp = *(hash_values[j].begin());
			it = hash_values[j].lower_bound({p - curr_hash, std::numeric_limits<uint64_t>::min()});
			if (it != hash_values[j].end())
			{
				candidate = *it;
				if ((tmp.first + curr_hash) % p > (candidate.first + curr_hash) % p)
					tmp = candidate;
			}
			strobemer->add_kmer(tmp.second, kmers[tmp.second]);
			curr_hash = get_new_curr_hash(strobemer) % p;
			hash_values[j].erase(pii(hashes[i + w_min + (j - 1) * w_max], i + w_min + (j - 1) * w_max));
			if (i + j * w_max + 1 < hashes.size())
				hash_values[j].insert(pii(hashes[i + j * w_max + 1], i + j * w_max + 1));
		}
		// strobemer->set_final_hash(get_final_hash(strobemer));
		// seeds.push_back(strobemer);
		final_hashes.insert(get_final_hash(strobemer));
		appearances[get_final_hash(strobemer)]++;
		delete(strobemer);
	}
	std::cout << "Number of different final seed hash values: " << final_hashes.size() << std::endl;
	
	long double sum = 0;
	for (auto it = appearances.begin(); it != appearances.end(); it++)
		sum += it->second * it->second;
	long double diff = final_hashes.size();	
	std::cout << std::fixed << std::setprecision(6) << "ehits: " << sum / diff << std::endl;
	
	return seeds;
}

std::vector<Seed*> RandStrobeCreatorMAMod::create_seeds_max()
{
	std::set<uint64_t> final_hashes;

	uint64_t maximal_uint = std::numeric_limits<uint64_t>::max();

	std::set<pii, std::greater<pii>> hash_values[n];
	for (uint64_t i = 1; i < n; i++)
		for (uint64_t j = w_min + (i - 1) * w_max ; j < std::min(i * w_max + 1, new_hashes.size()); j++)
			hash_values[i].insert(pii(new_hashes[j], maximal_uint - j));
	
	
	std::vector<Seed*> seeds;
	Strobemer* strobemer;
	uint64_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;
	pii tmp;
	pii candidate;
	std::set<pii>::iterator it;
	std::map<uint64_t, long double> appearances;
	std::cout << "SIZE: " << seq.size() << std::endl;
	for (uint64_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		// std::cout << i << std::endl;
		if (n == 2)
			strobemer = new Strobemer2();
		else if (n == 3)
			strobemer = new Strobemer3();
			// std::cout << "before add" << std::endl;
		strobemer->add_kmer(i, kmers[i]);
		// std::cout << "nigga what??" << std::endl;
		curr_hash = get_first_hash(i);
		// std::cout << "before j:" <<std::endl;
		for (uint64_t j = 1; j < n; j++)
		{
			// std::cout << "J: " << j << std::endl;
			tmp = *(hash_values[j].begin());
			it = hash_values[j].lower_bound({p - curr_hash - 1, maximal_uint});
			if (it != hash_values[j].end())
			{
				candidate = *it;
				if ((tmp.first + curr_hash) % p < (candidate.first + curr_hash) % p)
					tmp = candidate;
			}
			// std::cout << "done" << std::endl;
			// std::cout << "test" << std::endl;
			// std::cout << tmp.second << " " << maximal_uint - tmp.second << std::endl;
			// std::cout <<"middle" << std::endl;
			strobemer->add_kmer(maximal_uint - tmp.second, kmers[maximal_uint - tmp.second]);
			// std::cout << "here" << std::endl;
			curr_hash = get_new_curr_hash(strobemer) % p;
			// std::cout << "no here " << std::endl;
			hash_values[j].erase(pii(new_hashes[i + w_min + (j - 1) * w_max], maximal_uint - (i + w_min + (j - 1) * w_max)));
			// std::cout << "kir shodi" << std::endl;
			if (i + j * w_max + 1 < new_hashes.size())
				hash_values[j].insert(pii(new_hashes[i + j * w_max + 1], maximal_uint - (i + j * w_max + 1)));
		}
		// strobemer->set_final_hash(get_final_hash(strobemer));
		// seeds.push_back(strobemer);
		// if (i <= 10)
		// {
		// 	std::vector<uint64_t> positions = strobemer->get_positions();
		// 	for (auto pos : positions)
		// 		std::cout << pos << " " << hashes[pos] << std::endl;
		// 	std::cout<< std::endl << get_final_hash(strobemer) << std::endl << "______________" << std::endl;
		// }
		// else
		// break;
		// std::cout<<"after" << std::endl;
		final_hashes.insert(get_final_hash(strobemer));
		appearances[get_final_hash(strobemer)]++;
		delete(strobemer);
	}
	std::cout << "Number of different final seed hash values: " << final_hashes.size() << std::endl;
	
	long double sum = 0;
	for (auto it = appearances.begin(); it != appearances.end(); it++)
		sum += it->second * it->second;
	long double diff = final_hashes.size();	
	std::cout << std::fixed << std::setprecision(6) << "ehits: " << sum / diff << std::endl;

	return seeds;
}

uint64_t RandStrobeCreatorMAMod::get_score(uint64_t curr_hash, uint64_t new_strobe_pos)
{
	return -1;
}

// uint64_t RandStrobeCreatorMAMod::get_final_hash(const Strobemer* strobemer)
// {
// 	uint64_t final_hash = 0;
// 	std::vector<uint64_t> positions = strobemer->get_positions();
// 	// for (auto pos : positions)
// 	// 	final_hash ^= hasher->hash(hasher->hash(kmers[pos]));

// 	// for (uint64_t i = 0; i < positions.size(); i++)
// 	// {
// 	// 	if (i % 2 == 0)
// 	// 		final_hash ^= wy_hasher->hash(xx_hasher->hash(kmers[positions[i]]));
// 	// 	else
// 	// 		final_hash ^= xx_hasher->hash(wy_hasher->hash(kmers[positions[i]]));
// 	// }

// 	// for (uint64_t i = 0; i < strobemer->last; i++)
// 	// 	final_hash ^= hasher->hash(hasher->hash(kmers[strobemer->positions[i]]));

// 	// final_hash = xx_hasher->hash(kmers[positions[0]]);
// 	final_hash = hashes[positions[0]];
// 	Int128 tmp;
// 	for (uint64_t i = 1; i < positions.size(); i++)
// 	{
// 		tmp.low = xx_hasher->hash(final_hash);
// 		tmp.high = xx_hasher->hash(hashes[positions[i]]);
// 		final_hash = wy_hasher->hash(&tmp, sizeof(tmp));
// 	}

// 	return final_hash;
// }

uint64_t RandStrobeCreatorMAMod::get_new_curr_hash(const Strobemer* strobemer)
{
	return get_final_hash(strobemer);
}