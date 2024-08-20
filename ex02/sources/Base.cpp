/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 02:17:43 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/20 09:40:29 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::~Base() {}

Base* Base::generate()
{
	Base *ptr;
	srand(time(0));
	if (rand() % 3 == 0)
	{
		A* a = new(A);
		ptr = a;
		std::cout << "A instantiated" << std::endl;
	}
	else if (rand() % 3 == 1)
	{
		B* b = new(B);
		ptr = b;
		std::cout << "B instantiated" << std::endl;
	}
	else
	{
		C* c = new(C);
		ptr = c;
		std::cout << "C instantiated" << std::endl;
	}
	if (!ptr)
		throw NullPtr();
	return (ptr);
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "type: A" << std::endl; 
	else if (dynamic_cast<B*>(p))
		std::cout << "type: B" << std::endl; 
	else if (dynamic_cast<C*>(p))
		std::cout << "type: C" << std::endl; 
	else
		throw NullPtr();
}

void Base::identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "reference type: A" << std::endl; 
	}
	catch (const std::exception &e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "reference type: B" << std::endl; 
	}
	catch (const std::exception &e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "reference type: C" << std::endl;	
	}
	catch (const std::exception &e) {}
}
