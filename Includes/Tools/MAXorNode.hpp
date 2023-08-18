#ifndef _MAXorNode_hpp_
#define _MAXorNode_hpp_

#include "LibrariesAndDefines.hpp"

class MAXorNode
{
	public:
		MAXorNode(int64_t bit_ind);
		~MAXorNode();
		void add(uint64_t ind, uint64_t val);
		void remove(uint64_t ind, uint64_t val);
		uint64_t get_best_ind(uint64_t val, bool cmp);
		bool is_empty();
		void print_all(std::string until_now);
	protected:
		int64_t bit_ind;
		std::set<uint64_t> inds;
		MAXorNode* childs[2];
};

#endif