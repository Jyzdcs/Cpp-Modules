#include "PmergeMe.hpp"

bool isPositiveInteger(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return !str.empty();
}

std::string formatWithSpaces(int number, int maxWidth)
{
	std::ostringstream oss;
	oss << number;
	std::string str = oss.str();
	int numSpaces = maxWidth - str.length();
	for (int i = 0; i < numSpaces; ++i)
	{
		str = " " + str;
	}
	return str;
}

std::string intToString(int number)
{
	std::ostringstream oss;
	oss << number;
	return oss.str();
}

int	fillContainers(int argc, char* argv[], std::vector<int> *data, std::deque<int> *deq) {
	for (int i = 1; i < argc; ++i)
	{
		if (!isPositiveInteger(argv[i]))
		{
			std::cerr << NC << RED_BG << "Error: Invalid input '" << argv[i] << "'. All inputs must be positive integers." << NC << std::endl << std::endl;
			return false;
		}

		long long verify = std::strtoll(argv[i], NULL, 10);

		if (verify > INT_MAX)
		{
			std::cerr << NC << RED_BG << "Error: Input value '" << argv[i] << "' exceeds the maximum allowed integer value (INT_MAX)." << NC << std::endl;
			return false;
		}

		int num = std::atoi(argv[i]);

		data->push_back(num);
		deq->push_back(num);
	}
	return true;
};

int main(int argc, char* argv[])
{
	try
	{
		if (argc < 2 || (argc > 3 && strcmp(argv[1], "tester") == 0))
		{
			std::cerr << NC << RED_BG << "Usage: " << argv[0] << " num1 num2 ... numN or " << argv[0] << " tester num or " << argv[0] << " tester" << NC << std::endl;
			return false;
		}
		else {
			std::vector<int> data;
			std::deque<int> deq;

			if (!fillContainers(argc, argv, &data, &deq))
				return false;

			PmergeMe pmergeMe;
			pmergeMe.setData(data);
			pmergeMe.setDeq(deq);

			std::cout << RED << " --------------------\n" << NC;
			std::cout << RED << "|       VECTOR       |\n" << NC;
			std::cout << RED << " --------------------\n" << NC;
			std::cout << BRIGHT_BLUE << "Before" << NC << " : ";
			printContainer(pmergeMe.getData().begin(), pmergeMe.getData().end());

			std::clock_t startVector = std::clock();
			sortsFordJohnson(pmergeMe.getData());
			std::clock_t endVector = std::clock();
			double durationVector = 1000000.0 * (endVector - startVector) / CLOCKS_PER_SEC;

			std::cout << BRIGHT_BLUE << "After" << NC << " : ";
			printContainer(pmergeMe.getData().begin(), pmergeMe.getData().end());
			std::cout << std::endl;

			std::cout << GREEN << " --------------------\n" << NC;
			std::cout << GREEN << "|        DEQUE       |\n" << NC;
			std::cout << GREEN << " --------------------\n" << NC;
			std::cout << BRIGHT_BLUE << "Before" << NC << " : ";
			printContainer(pmergeMe.getDeq().begin(), pmergeMe.getDeq().end());

			std::clock_t startDeque = std::clock();
			sortsFordJohnson(pmergeMe.getDeq());
			std::clock_t endDeque = std::clock();
			double durationDeque = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;

			std::cout << BRIGHT_BLUE << "After" << NC << " : ";
			printContainer(pmergeMe.getDeq().begin(), pmergeMe.getDeq().end());
			std::cout << std::endl;

			std::cout << YELLOW << " --------------------\n" << NC;
			std::cout << YELLOW << "|      RESULTAT      |\n" << NC;
			std::cout << YELLOW << " --------------------\n" << NC;

			const char* vectorColor = (durationVector <= durationDeque) ? GREEN_BG : RED_BG;
			const char* dequeColor = (durationDeque <= durationVector) ? GREEN_BG : RED_BG;

			int maxWidth = std::max(intToString(durationVector).length(), intToString(durationDeque).length());

			std::cout << BRIGHT_MAGENTA << "Time to process a range of " << pmergeMe.getData().size() << " elements with std::\n" << NC << vectorColor << " vector "
								<< NC << ": " << formatWithSpaces(durationVector, maxWidth) << " us" << std::endl;
			std::cout << dequeColor << "  deque " << NC << ": " << formatWithSpaces(durationDeque, maxWidth) << " us" << NC << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << NC << RED_BG << "Exception: " << e.what() << NC << std::endl;
		return false;
	}
	return true;
}

/* main.cpp */