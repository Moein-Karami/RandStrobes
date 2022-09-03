#include "MAXorNode.hpp"

MAXorNode::MAXorNode(int64_t bit_ind)
: bit_ind(bit_ind)
{
	childs[0] = NULL;
	childs[1] = NULL;
}

MAXorNode::~MAXorNode()
{
	for (int i = 0; i < 2; i++)
		if (childs[i] != NULL)
			delete childs[i];
}

void MAXorNode::add(size_t ind, uint64_t val)
{
	inds.insert(ind);
	if (bit_ind < 0)
		return;

	for (int i = 0; i < 2; i++)
		if (childs[i] == NULL)
			childs[i] = new MAXorNode(bit_ind - 1);

	childs[(val & (1LL << bit_ind)) != 0]->add(ind, val);
}

void MAXorNode::remove(size_t ind, uint64_t val)
{
	inds.erase(ind);
	if (bit_ind < 0)
		return;

	childs[(val & (1LL << bit_ind)) != 0]->remove(ind, val);
}

size_t MAXorNode::get_best_ind(uint64_t val, bool cmp)
{
	if (bit_ind < 0 || inds.size() == 1)
		return *inds.begin();

	std::cout << "Bit ind: " << bit_ind << std::endl;
	if (childs[cmp ^ ((val & (1LL << bit_ind)) != 0)]->is_empty() == false)
	{
		std::cout << "go to 0" << std::endl;
		return childs[cmp ^ ((val & (1LL << bit_ind)) != 0)]->get_best_ind(val, cmp);
	}
	else
	{
		std::cout << "go to 1" << std::endl;
		return childs[(cmp ^ ((val & (1LL << bit_ind)) != 0)) ^ 1]->get_best_ind(val, cmp);
	}
		
	
	return -1;
}

bool MAXorNode::is_empty()
{
	return inds.empty();
}

void MAXorNode::print_all(std::string until_now)
{
	std::cout << "Bit ind: " << bit_ind << std::endl;
	std::cout << "Until now: " << until_now << std::endl;
	for (auto i : inds)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << "_______**********________" << std::endl;
	for (int i = 0; i < 2; i++)
		if (childs[i] != NULL)
			childs[i]->print_all(until_now + std::to_string(i));
}