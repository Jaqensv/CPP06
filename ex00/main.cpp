/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:07:36 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/14 23:07:24 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	(void)argc;

	//const std::string& str = argv[1];

	ScalarConverter::convert(argv[1]);

	

	// if (sizeof(argv[1]) * 8 == 32)
	// 	std::cout << "float" << std::endl;

	// else if (sizeof(argv[1]) * 8 == 64)
	// 	std::cout << "double" << std::endl;

	// double a = 2.3;
	// float b = 2.3;
	// int c = 2;
	// char d = b;

	// std::cout << sizeof(a) * 8 << std::endl;
	// std::cout << sizeof(b) * 8 << std::endl;
	// std::cout << sizeof(c) * 8 << std::endl;
	// std::cout << sizeof(d) * 8 << std::endl;
	

	
	return 0;
}


// You have to first detect the type of the literal passed as parameter, convert it from
// string to its actual type, then convert it explicitly to the three other data types. Lastly,
// display the results as shown below.