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
std::vector<size_t> PmergeMe::ConvertVector(char **argv)
{
	std::vector<size_t> list;
	int i = 0;
	while (argv[i])
	{
		std::stringstream ss(argv[i]);
		size_t num;
		ss >> num;
		if (ss.fail())
			throw InvalidArgsException();
		list.push_back(num);
		i++;
	}
	return (list);
}
std::deque<size_t> PmergeMe::ConvertDeque(char **argv)
{
	std::deque<size_t> list;
	int i = 0;
	while (argv[i])
	{
		std::stringstream ss(argv[i]);
		size_t num;
		ss >> num;
		if (ss.fail())
			throw InvalidArgsException();
		list.push_back(num);
		i++;
	}
	return (list);
}

const std::vector<size_t> PmergeMe::VectorTime(std::vector<size_t> list, double &time)
{
	std::clock_t start = std::clock();
	list = VectorSort(list);
	// std::sort(list.begin(), list.end());
	std::clock_t end = std::clock();
	time = ((end - start) * 1000000) / CLOCKS_PER_SEC;
	return (list);
}
const std::deque<size_t> PmergeMe::DequeTime(std::deque<size_t> list, double &time)
{
	std::clock_t start = std::clock();
	list = DequeSort(list);
	std::clock_t end = std::clock();
	time = ((end - start) * 1000000) / CLOCKS_PER_SEC;
	return (list);
}

void PmergeMe::PrintVector(const std::vector<size_t> &list)
{
	std::vector<size_t>::const_iterator it = list.begin();
	while (it != list.end())
	{
		std::cout << *it << " ";
		it++;
	}
}
void PmergeMe::PrintDeque(const std::deque<size_t> &list)
{
	std::deque<size_t>::const_iterator it = list.begin();
	while (it != list.end())
	{
		std::cout << *it << " ";
		it++;
	}
}

// Utils function
void Merge(std::vector<size_t>& arr, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid + 1;
    std::vector<size_t> temp;

    while (i <= mid && j <= right)
	{
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (size_t k = 0; k < temp.size(); k++)
        arr[left + k] = temp[k];
}

void MergeSort(std::vector<size_t>& arr, size_t left, size_t right)
{
    if (left < right)
	{
        size_t mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}
std::vector<size_t> GenerateInsertionSequence(size_t n)
{
    std::vector<size_t> sequence;
    if (n == 0)
		return (sequence);

    size_t a = 1, b = 1;
    while (b < n)
	{
        sequence.push_back(b - 1);
        size_t temp = a + b;
        a = b;
        b = temp;
    }

    // Ajout des indices manquants
    for (size_t i = 0; i < n; i++)
	{
        if (std::find(sequence.begin(), sequence.end(), i) == sequence.end())
            sequence.push_back(i);
    }
    
    return (sequence);
}

std::vector<size_t> PmergeMe::VectorSort(std::vector<size_t> list)
{
	if (VectorIsSorted(list) == true)
		return (list);

    std::vector<size_t> sorted;
    std::vector<size_t> pending;

    // Étape 1 : Division en paires et tri manuel des paires
    size_t i = 0;
    for (; i + 1 < list.size(); i += 2) {
        if (list[i] > list[i + 1]) {
            sorted.push_back(list[i]);
            pending.push_back(list[i + 1]);
        } else {
            sorted.push_back(list[i + 1]);
            pending.push_back(list[i]);
        }
    }
    if (i < list.size()) // Si un élément reste seul
        sorted.push_back(list[i]);

    // Étape 2 : Tri initial de `sorted` avec Merge-Sort (on l'implémente à la main)
    MergeSort(sorted, 0, sorted.size() - 1);

    // Étape 3 : Générer la séquence d'insertion optimisée
    std::vector<size_t> insertion_order = GenerateInsertionSequence(pending.size());

    // Étape 4 : Insertion des éléments de `pending` dans `sorted` dans l'ordre optimal
    for (size_t i = 0; i < insertion_order.size(); i++) {
    	size_t index = insertion_order[i];
        if (index < pending.size()) {
            size_t num = pending[index];

            // Recherche binaire pour trouver la bonne position
            size_t left = 0;
            size_t right = sorted.size();
            while (left < right) {
                size_t mid = left + (right - left) / 2;
                if (sorted[mid] < num)
                    left = mid + 1;
                else
                    right = mid;
            }

            // Insérer num dans sorted à la position trouvée
            sorted.insert(sorted.begin() + left, num);
        }
    }
    return (sorted);
}
std::deque<size_t> PmergeMe::DequeSort(std::deque<size_t> list)
{
	if (DequeIsSorted(list) == true)
		return (list);
	return (list);
}

bool PmergeMe::VectorIsSorted(std::vector<size_t> &list)
{
	if (list.size() <= 1)
		return (true);
	std::vector<size_t>::iterator it = list.begin();
	size_t prev = *it;
	++it;
	while (it != list.end())
	{
		if (*it < prev)
			return (false);
		prev = *it;
		++it;
	}
	return (true);
}
bool PmergeMe::DequeIsSorted(std::deque<size_t> &list)
{
	if (list.size() <= 1)
		return (true);
	std::deque<size_t>::iterator it = list.begin();
	size_t prev = *it;
	++it;
	while (it != list.end())
	{
		if (*it < prev)
			return (false);
		prev = *it;
		++it;
	}
	return (true);
}
