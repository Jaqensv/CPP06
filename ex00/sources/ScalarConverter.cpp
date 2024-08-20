/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:29:14 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/20 10:55:05 by mde-lang         ###   ########.fr       */
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
	int min = std::numeric_limits<int>::min();
	int max = std::numeric_limits<int>::max();
	std::istringstream s(str);
	long long int result;
	s >> result;
	if (result < min || result > max)
	{
		std::cerr << "Out of integer range" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return true;
}

bool isChar(const std::string& str)
{
	if (str.length() == 1 && ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z')))
		return true;
	return false;
}

std::string isFloatingPoint(const std::string& str)
{
	int f = 0;
	int f_spot = str.length();
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == 'f' || str[i] == 'F')
		{
			f++;
			f_spot = i + 1;
		}
		if (((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '-' && str[i] != '+' && str[i] != 'f' && str[i] != 'F') || f > 1 || str[f_spot] != '\0')
		{
			std::cerr << "Invalid value" << std::endl;
			std::exit(EXIT_FAILURE);
		}
	}
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '.' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		{
			if (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'F')
				return "float";
			else
				return "double";
		}
	}
	std::cerr << "Invalid value" << std::endl;
	std::exit(EXIT_FAILURE);
}

std::string valueChecker(const std::string& str)
{
	if (isInteger(str))
		return "int";
	else if (isChar(str))
		return "char";
	else 
		return (isFloatingPoint(str));
}

void fullConversionDisplay(void *ptr, std::string type)
{
	char c = '\0';
	int i = 0;
	double d = 0.0;
	float f = 0.0;

	if (type == "char")
	{
		c = *static_cast<char*>(ptr);
		i = static_cast<int>(c);
		d = static_cast<double>(c);
		f = static_cast<float>(c);
	}
	else if (type == "int")
	{
		i = *static_cast<int*>(ptr);
		c = static_cast<char>(i);
		d = static_cast<double>(i);
		f = static_cast<float>(i);
	}
	else if (type == "double")
	{
		d = *static_cast<double*>(ptr);
		c = static_cast<char>(d);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
	}
	else if (type == "float")
	{
		f = *static_cast<float*>(ptr);
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
	}

	if (i < 33 || (i >= 48 && i <= 57) || i > 126)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
	std::string type = valueChecker(str);

	if (type == "char")
	{
		char result = static_cast<char>(str[0]);
		std::cout << "type: " << type << " | value: " << result << std::endl;
		fullConversionDisplay(&result, type);
	}
	else if (type == "int" || type == "double" || type == "float")
	{
		std::stringstream s(str);
		if (type == "int")
		{
			int result = 0;
			s >> result;
			std::cout << "type: " << type << " | value: " << result << std::endl;
			fullConversionDisplay(&result, type);
		}
		else if (type == "double")
		{
			double result = 0.0;
			s >> result;
			std::cout << "type: " << type << " | value: " << std::fixed << std::setprecision(1) << result << std::endl;
			fullConversionDisplay(&result, type);
		}
		else if (type == "float")
		{
			float result = 0.0;
			s >> result;
			std::cout << "type: " << type << " | value: " << std::fixed << std::setprecision(1) << result << "f" << std::endl;
			fullConversionDisplay(&result, type);
		}
	}
	else
		std::exit(EXIT_FAILURE);
}

