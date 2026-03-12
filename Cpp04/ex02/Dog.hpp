/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:12:44 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/11 18:12:45 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain* brain;

public:
    Dog();
    Dog(const Dog& other);
    Dog&operator=(const Dog& other);
    ~Dog();

    void        makeSound()const;
    void        setIdea(int index, const std::string& idea);
    std::string getIdea(int index)const;
} ;

#endif
