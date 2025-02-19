#include "PmergeMe.hpp"


// Constructor & Destructor
PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	(void)copy;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
}


// Other function
std::vector<size_t> PmergeMe::ConvertVector(char **args);
std::deque<size_t> PmergeMe::ConvertDeque(char **args);

const std::vector<size_t> PmergeMe::VectorTime(std::vector<size_t> list, double &time);	
const std::deque<size_t> PmergeMe::DequeTime(std::deque<size_t> list, double &time);

void PmergeMe::PrintVector(const std::vector<size_t> &list);	
void PmergeMe::PrintDeque(const std::deque<size_t> &list);

std::vector<size_t> PmergeMe::VectorSort(std::vector<size_t> list);
std::deque<size_t> PmergeMe::DequeSort(std::deque<size_t> list);

bool PmergeMe::VectorIsSorted(std::vector<size_t> &list);
bool PmergeMe::DequeIsSorted(std::deque<size_t> &list);
