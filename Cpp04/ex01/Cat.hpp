/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:12:31 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/11 18:12:33 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain* brain;

public:
    Cat();
    Cat(const Cat& other);
    Cat&operator=(const Cat& other);
    ~Cat();

    void        makeSound()const;
    void        setIdea(int index, const std::string& idea);
    std::string getIdea(int index)const;
} ;

#endif
