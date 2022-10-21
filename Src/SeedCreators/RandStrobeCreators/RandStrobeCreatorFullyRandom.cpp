#include "RandStrobeCreatorFullyRandom.hpp"

RandStrobeCreatorFullyRandom::RandStrobeCreatorFullyRandom(Hasher* hasher, Comparator* comparator, size_t kmer_len,
		size_t w_min, size_t w_max, uint32_t n, uint64_t mask)
: RandStrobeCreator(hasher, comparator, kmer_len, w_min, w_max, n, mask)
{
}

std::vector<Seed*> RandStrobeCreatorFullyRandom::create_seeds(const std::string& sequence)
{
	seq = sequence;
	// for (int i = 0; i < seq.size(); i++)
		// std::cout << i << " : " << seq[i] << std::endl;
	hashes.clear();
	kmers.clear();

	uint64_t curr_kmer = 0;
	uint64_t tmp;

	// std::cout << "before create kmers" << std::endl;
	
	for (int i = 0; i < kmer_len - 1; i++)
		curr_kmer = (curr_kmer << 2) | get_char_code(seq[i]);
	// std::cout << "first uncomplete kmer: " << std::endl;

	for (int i = kmer_len - 1; i < seq.size(); i++)
	{
		// std::cout << "i: " << i << std::endl;
		curr_kmer = (curr_kmer << 2) | get_char_code(seq[i]);
		// std::cout << "curr_kmer: " << curr_kmer << std::endl;
		tmp = curr_kmer & mask;
		// std::cout << "tmp: " << tmp << std::endl;
		hashes.push_back(tmp);
		kmers.push_back(tmp);
		// std::cout << "pushed" << std::endl;
		// std::cout << "kmer number " << hashes.size() - 1 << ": value and hash: " <<" " << hashes.back()
		// 		<< std::endl;
	}

	srand(time(0));

	std::vector<Seed*> seeds;
	Strobe* strobe;
	uint64_t best_choose;
	uint64_t offset;

	for (size_t i = 0; i < seq.size() - kmer_len - w_min - (n - 2) * w_max; i++)
	{
		// std::cout << "creating the " << i << "th strobe, its kmer and hash: " << kmers[i] << " " << hashes[i] << std::endl;
		strobe = new Strobe();
		strobe->add_kmer(i, kmers[i]);
		
		for (int j = 1; j < n; j++)
		{
			best_choose = i + w_min + (j - 1) * w_max;
			offset = rand() % (std::min(i + j * w_max + 1, hashes.size()) - (i + w_min + (j - 1) * w_max));
			best_choose += offset;
			strobe->add_kmer(best_choose, kmers[best_choose]);
		}
		
		seeds.push_back(strobe);
		// std::cout << "end of creating seed I = " << i << std::endl << std::endl;
	}
	return seeds;
}

uint64_t RandStrobeCreatorFullyRandom::get_score(uint64_t curr_hash, uint64_t ind1, uint64_t ind2)
{
	return 0;
}