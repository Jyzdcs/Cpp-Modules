#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "[Serializer] ctor called\n";	
};

Serializer&	Serializer::operator=(const Serializer& src) {
	if (this == &src)	return *this;
	std::cout << "[Serializer] assignement called\n";	
	return *this;
};

Serializer::Serializer(const Serializer& src) {
	*this = src;
};

Serializer::~Serializer() {
	std::cout << "[Serializer] dtor called\n";	
};

uintptr_t	Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
};

Data*			Serializer::deserializer(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
};