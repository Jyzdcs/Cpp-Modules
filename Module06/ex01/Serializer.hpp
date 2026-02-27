#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer {
	protected:
		Serializer();
		Serializer& operator=(const Serializer& src);
		Serializer(const Serializer& src);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		Data* deserializer(uintptr_t raw);
};

#endif