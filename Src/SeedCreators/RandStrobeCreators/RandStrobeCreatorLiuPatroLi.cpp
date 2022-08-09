#include "RandStrobeCreatorLiuPatroLi.hpp"

RandStrobeCreatorLiuPatroLi::RandStrobeCreatorLiuPatroLi(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

uint64_t RandStrobeCreatorLiuPatroLi::get_hash_concat(uint64_t kmer1, uint64_t kmer2)
{
    if(kmer_len * 2 <= 64)
    {
        return hasher->hash(kmer1 << kmer_len + kmer2);
    }
    uint64_t arr_concat[2];
    arr_concat[0] = kmer1 + kmer2 >> (64 - kmer_len);
    arr_concat[1] = kmer2 << (64 - kmer_len);
    return hasher->hash(&arr_concat, kmer_len * 2);
}

std::vector<Seed*> RandStrobeCreatorLiuPatroLi::create_seeds(const std::string& seq, const std::vector<uint64_t>& kmers,
		const std::vector<uint64_t> hashes)
{
	std::vector<Seed*> seeds;
	Strobe* strobe;
	size_t best_choose;
	uint64_t curr_hash;
	uint64_t best_value;

	for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		strobe = new Strobe();
		strobe->add_kmer(i, hashes[i]);
		curr_hash = hashes[i];

		for (int j = 1; j < n; j++)
		{
			best_choose = i + w_min + (j - 1) * w_max;
			best_value = get_hash_concat(kmers[i], kmers[best_choose]);

			for (size_t q = i + w_min + (j - 1) * w_max + 1; q < std::min(i + j * w_max + 1, hashes.size()); q++)
			{
				if (comparator->is_first_better(get_hash_concat(kmers[i], kmers[j]), best_value))
				{
					best_choose = j;
					best_value = get_hash_concat(kmers[i], kmers[j]);
				}
			}

			strobe->add_kmer(best_choose, hashes[best_choose]);
			curr_hash = best_value;
		}
		
		seeds.push_back(strobe);
	}
	return seeds;
}

