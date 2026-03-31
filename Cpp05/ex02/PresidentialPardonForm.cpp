/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:44:54 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/30 18:44:55 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
    std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm:: PresidentialPardonForm (const std::string& target):AForm("PresidentialPardonForm", 25, 5), _target(target) 
{
    std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):AForm(other), _target(other._target)
{
    std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    std::cout << "PresidentialPardonForm Copy Assigment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator =(other);
        _target = other._target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

void    PresidentialPardonForm::execForm() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
