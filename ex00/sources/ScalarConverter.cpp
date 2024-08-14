/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:29:14 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/15 00:19:34 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {(void)src;}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {(void)rhs; return *this;}

bool isInteger(const std::string& str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '.' || (str[i] >= 'A' && str[i] <= 'z'))
			return false;
	}
	return true;
}

bool isChar(const std::string& str)
{
	if (str.length() == 1 && ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z')))
		return true;
	return false;
}

bool isFloatingPoint(const std::string& str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '.')
			return true;
	}
	return false;
}

bool isFloat(const std::string& str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == 'f' || str[i] == 'F')
			return true;
	}
	return false;
}

// bool isDouble(const std::string& str)
// {
// 	for (int i = 0; str[i]; i++)
// 	{
// 		if (str[i] == 'f')
// 			return false;
// 	}
// 	return true;
// }

void ScalarConverter::convert(const std::string& str)
{
	if (isInteger(str))
	{
		std::stringstream s(str);
		int result = 0;
		s >> result;
		std::cout << "value: " << result << std::endl;
		std::cout << "bits: " << sizeof(result) * 8 << std::endl;
	}

	if (isChar(str))
	{
		std::cout << "char" << std::endl;
	}
	
	if (isFloatingPoint(str))
	{
		if (isFloat(str))
			std::cout << "float" << std::endl;
		else
			std::cout << "double" << std::endl;
	}
}
