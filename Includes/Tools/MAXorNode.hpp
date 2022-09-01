#ifndef _MAXorNode_hpp_
#define _MAXorNode_hpp_

#include "LibrariesAndDefines.hpp"

class MAXorNode
{
	public:
		MAXorNode(int64_t bit_ind);
		~MAXorNode();
		void add(size_t ind, uint64_t val);
		void remove(size_t ind, uint64_t val);
		size_t get_best_ind(uint64_t val, bool cmp);
		bool is_empty();
	protected:
		int64_t bit_ind;
		std::set<size_t> inds;
		MAXorNode* childs[2];
};

#endif