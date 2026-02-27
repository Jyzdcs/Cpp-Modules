#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
	private:
		std::string _data;

	public:
		Data();
		Data(const Data&);
		Data& operator=(const Data&);
		~Data();

		std::string	getData();

		void				setData(std::string);
};

#endif