#include "Utils.hpp"

#include "PmergeMe.hpp"

int main(int argc, char**argv)
{
    // check args
    if (argc < 2)
    {
        std::cerr << Deny << Red << "Error wrong args\n" << Yellow << "Try : ./PmergeMe <nb_to_sort>" << Reset_Color << std::endl;
        return (1);
    }

    try {
        // Convert args to container
        argv++;
        std::vector<size_t> vector = PmergeMe::ConvertVector(argv);
		std::deque<size_t> deque = PmergeMe::ConvertDeque(argv);

        // Calculate time and sort
        double time_vector = 0;
		double time_deque = 0;
		std::vector<size_t> vector_sorted = PmergeMe::VectorTime(vector, time_vector);
        std::deque<size_t> deque_sorted = PmergeMe::DequeTime(deque, time_deque);

        // Print the result
        std::cout << Cyan << "Before : " << Yellow; PmergeMe::PrintVector(vector); std::cout << Reset_Color << std::endl;
        std::cout << Cyan << "After : " << Yellow; PmergeMe::PrintVector(vector_sorted); std::cout << Reset_Color << std::endl;
        std::cout << Cyan << "Time to process a range of " << vector.size() << " elements with std::vector : " << Yellow << time_vector << Cyan << " us" << Reset_Color << std::endl;
        std::cout << Cyan << "Time to process a range of " << deque.size() << " elements with std::deque : " << Yellow << time_deque << Cyan << " us" << Reset_Color << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	return (0);
}
