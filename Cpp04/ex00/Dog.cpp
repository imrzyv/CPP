/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:09:38 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/11 18:09:40 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog Constructor called." << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
    std::cout << "Dog Copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog Copy assigment operator called." << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called." << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Wof!" << std::endl;
}
