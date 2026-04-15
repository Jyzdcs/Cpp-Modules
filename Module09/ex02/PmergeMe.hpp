#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <climits>
#include "PmergeMe.tpp"

#define GREY        "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define WHITE       "\033[0;37m"

#define BRIGHT_GREY    "\033[1;30m"
#define BRIGHT_RED     "\033[1;31m"
#define BRIGHT_GREEN   "\033[1;32m"
#define BRIGHT_YELLOW  "\033[1;33m"
#define BRIGHT_BLUE    "\033[1;34m"
#define BRIGHT_MAGENTA "\033[1;35m"
#define BRIGHT_CYAN    "\033[1;36m"
#define BRIGHT_WHITE   "\033[1;37m"

#define BLACK_BG       "\033[40m"
#define RED_BG         "\033[41m"
#define GREEN_BG       "\033[42m"
#define YELLOW_BG      "\033[43m"
#define BLUE_BG        "\033[44m"
#define MAGENTA_BG     "\033[45m"
#define CYAN_BG        "\033[46m"
#define WHITE_BG       "\033[47m"

#define BOLD           "\033[1m"
#define UNDERLINE      "\033[4m"
#define RESET          "\033[0m"

#define NC             RESET

class PmergeMe
{
	private:
		std::vector<int> m_data;
		std::deque<int> m_deq;

	public:
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		PmergeMe();

		void setData(const std::vector<int>& data);
		void setDeq(const std::deque<int>& deq);
		std::vector<int>& getData();
		std::deque<int>& getDeq();
};