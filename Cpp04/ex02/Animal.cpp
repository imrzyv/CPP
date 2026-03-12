/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:34:37 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/09 18:34:39 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
    std::cout << "Animal Constructor called." << std::endl;
}

Animal::Animal(const Animal& other): type(other.type)
{
    std::cout << "Animal Copy constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal Copy assigment operator called." << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called." << std::endl;
}

void    Animal::makeSound()const
{
    std::cout << "Animal is making a sound!" << std::endl;
}

std::string     Animal::getType()const
{
    return (type);
}
