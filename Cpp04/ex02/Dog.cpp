/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:12:53 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/11 18:12:54 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog Constructor called." << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Dog Copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog Copy assigment operator called." << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor called." << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Wof!" << std::endl;
}

void    Dog::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    return (brain->getIdea(index));
}
