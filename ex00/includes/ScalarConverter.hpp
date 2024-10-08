#pragma once

#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <bitset>
#include <iomanip>

class ScalarConverter {

public:

	static void convert(const std::string& str);

private:

	ScalarConverter();										// cannonique
	~ScalarConverter();										// cannonique
	ScalarConverter(ScalarConverter const &src);			// cannonique
	ScalarConverter &operator=(ScalarConverter const &rhs);	// cannonique

};
