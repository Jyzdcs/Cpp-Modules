#include "Serializer.hpp"

int main() {
	Serializer* serializer = NULL;
	Data data;

	std::cout << &data << std::endl;
	std::cout << serializer->deserializer(serializer->serialize(&data)) << std::endl;
}