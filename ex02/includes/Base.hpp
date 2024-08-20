#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class Base {

public:

	virtual ~Base();
	Base* generate();
	void identify(Base* p);
	void identify(Base& p);

	class NullPtr : public std::exception {
	public:
		const char* what() const throw() {
		return "Error: nullptr"; }
	};
};
