/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:51:29 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/19 01:30:31 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data* ptr = new(Data);
	Data* ptr2;
	uintptr_t raw = 0;

	ptr->value = 42;
	std::cout << "ptr address: " << ptr << "| ptr value: " << ptr->value << std::endl;
	raw = Serializer::serialize(ptr);
	std::cout << "encoded raw address: " << raw << std::endl;
	std::cout << "raw address: " << reinterpret_cast<Data*>(raw) << std::endl;
	ptr2 = Serializer::deserialize(raw);
	std::cout << "ptr2 address: " << ptr2 << "| ptr2 value: " << ptr2->value << std::endl;
	delete ptr;

	return 0;
}
