/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:51:19 by mde-lang          #+#    #+#             */
/*   Updated: 2024/08/20 10:58:40 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(Serializer const &src) {(void)src;}

Serializer &Serializer::operator=(Serializer const &rhs) {(void)rhs; return *this;}

uintptr_t Serializer::serialize(Data* ptr) {return (reinterpret_cast<uintptr_t>(ptr));}

Data* Serializer::deserialize(uintptr_t raw) {return (reinterpret_cast<Data*>(raw));}