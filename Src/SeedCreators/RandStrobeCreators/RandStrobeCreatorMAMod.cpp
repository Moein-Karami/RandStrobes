#include "RandStrobeCreatorMAMod.hpp"

RandStrobeCreatorMAMod::RandStrobeCreatorMAMod(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask, uint64_t p)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
, p(p)
{
}

std::vector<Seed*> RandStrobeCreatorMAMod::create_seeds()
{
	for (size_t i = 0; i < hashes.size(); i++)
		hashes[i] %= p;

	if (comparator->is_first_better(1, 2))
		return create_seeds_min();
	else
		return create_seeds_max();
}

std::vector<Seed*> RandStrobeCreatorMAMod::create_seeds_min()
{
	std::set<pii> hash_values[n];
	for (size_t i = 1; i < n; i++)
		for (size_t j = w_min + (i - 1) * w_max ; j < std::min(i * w_max + 1, hashes.size()); j++)
			hash_values[i].insert(pii(hashes[j], j));
	
	
	std::vector<Seed*> seeds;
	Strobe* strobe;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;
	pii tmp;
	pii candidate;
	std::set<pii>::iterator it;

	for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		// std::cout << "start creating seeds, I = " << i << std::endl;
		strobe = new Strobe();
		strobe->add_kmer(i, kmers[i]);
		curr_hash = get_first_hash(i);
		// std::cout << "before choose next kmers" << std::endl;
		for (int j = 1; j < n; j++)
		{
			tmp = *(hash_values[j].begin());
			it = hash_values[j].lower_bound({p - curr_hash, std::numeric_limits<uint64_t>::min()});
			if (it != hash_values[j].end())
			{
				candidate = *it;
				if ((tmp.first + curr_hash) % p > (candidate.first + curr_hash) % p)
					tmp = candidate;
			}
			strobe->add_kmer(tmp.second, kmers[tmp.second]);
			curr_hash = get_value_to_choose_third_strobe(curr_hash, i, tmp.second);
			hash_values[j].erase(pii(hashes[i + w_min + (j - 1) * w_max], i + w_min + (j - 1) * w_max));
			if (i + j * w_max + 1 < hashes.size())
				hash_values[j].insert(pii(hashes[i + j * w_max + 1], i + j * w_max + 1));
		}
		
		seeds.push_back(strobe);
		// std::cout << "end of creating seed I = " << i << std::endl << std::endl;
	}
	return seeds;
}

std::vector<Seed*> RandStrobeCreatorMAMod::create_seeds_max()
{
	uint64_t maximal_uint = std::numeric_limits<uint64_t>::max();

	std::set<pii, std::greater<pii>> hash_values[n];
	for (size_t i = 1; i < n; i++)
		for (size_t j = w_min + (i - 1) * w_max ; j < std::min(i * w_max + 1, hashes.size()); j++)
			hash_values[i].insert(pii(hashes[j], maximal_uint - j));
	
	
	std::vector<Seed*> seeds;
	Strobe* strobe;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;
	pii tmp;
	pii candidate;
	std::set<pii>::iterator it;

	for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		// std::cout << "start creating seeds, I = " << i << std::endl;
		strobe = new Strobe();
		strobe->add_kmer(i, kmers[i]);
		curr_hash = get_first_hash(i);
		// std::cout << "Curr hash: " << curr_hash << std::endl;
		// std::cout << "before choose next kmers" << std::endl;
		for (int j = 1; j < n; j++)
		{
			// std::cout << "candidates: " << std::endl;
			// if (i < 5)
			// {
			// 	for (auto el : hash_values[j])
			// 	std::cout << el.first << " " << el.second << std::endl;
			// }
			tmp = *(hash_values[j].begin());
			// std::cout << "tmp: " << tmp.first << " " << tmp.second << std::endl;
			it = hash_values[j].lower_bound({p - curr_hash - 1, maximal_uint});
			// std::cout << "P - curr_hash = " << p - curr_hash << std::endl;
			if (it != hash_values[j].end())
			{
				// std::cout << "Candidate: " << it->first << " " << it->second << std::endl;
				candidate = *it;
				if ((tmp.first + curr_hash) % p < (candidate.first + curr_hash) % p)
					tmp = candidate;
			}
			strobe->add_kmer(maximal_uint - tmp.second, kmers[maximal_uint - tmp.second]);
			curr_hash = get_value_to_choose_third_strobe(curr_hash, i, tmp.second);;
			hash_values[j].erase(pii(hashes[i + w_min + (j - 1) * w_max], maximal_uint - (i + w_min + (j - 1) * w_max)));
			if (i + j * w_max + 1 < hashes.size())
				hash_values[j].insert(pii(hashes[i + j * w_max + 1], maximal_uint - (i + j * w_max + 1)));
			// std::cout << "______________" << std::endl;
		}
		
		seeds.push_back(strobe);
		// std::cout << "end of creating seed I = " << i << std::endl << std::endl;
	}
	return seeds;
}

uint64_t RandStrobeCreatorMAMod::get_score(uint64_t curr_hash, uint64_t ind1, uint64_t ind2)
{
	return NULL;
}

uint64_t RandStrobeCreatorMAMod::get_value_to_choose_third_strobe(uint64_t curr_hash, uint64_t ind1, uint64_t ind2)
{
	return (hasher->hash(kmers[ind1]) ^ hasher->hash(kmers[ind2])) % p;
}