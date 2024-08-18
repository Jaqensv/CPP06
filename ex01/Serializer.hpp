#pragma once

#include <iostream>
#include <stdint.h>

struct Data {
	int value;
};

class Serializer {

public:

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:

	Serializer();
	~Serializer();
	Serializer(Serializer const &src);
	Serializer &operator=(Serializer const &rhs);

};