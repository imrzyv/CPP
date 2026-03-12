/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:34:24 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/09 18:34:26 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout << std::endl;
    Animal* a = new Dog();
    Animal* b = new Cat();
    a->makeSound();
    b->makeSound();
    delete a;
    delete b;

    std::cout << std::endl;
    std::cout << "----- Array test -----" << std::endl;

    Animal* animals[4];

    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();
    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();
    
    for (int i = 0; i < 4; i++)
        delete animals[i];

    std::cout << std::endl;
    std::cout << "----- Deep copy test -----" << std::endl;

    Dog dog1;
    dog1.setIdea(0, "I want food");

    Dog dog2 = dog1;

    std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;

    dog2.setIdea(0, "I want a bone");

    std::cout << "After changing dog2:" << std::endl;
    std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;

    return 0;
}
