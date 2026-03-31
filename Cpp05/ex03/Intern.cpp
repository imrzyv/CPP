/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:00:16 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/30 19:00:17 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
    (void)other;
    std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    std::cout << "Intern Copy Assigment operator called" << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called" << std::endl;
}

AForm*  Intern::makeShrubbery(const std::string& target) const
{
    return (new ShrubberyCreationForm(target));
}

AForm*  Intern::makeRobotomy(const std::string& target) const
{
    return (new RobotomyRequestForm(target));
}

AForm*  Intern::makePresidential(const std::string& target) const
{
    return (new PresidentialPardonForm(target));
}

AForm*  Intern::makeForm(const std::string& formName, const std::string& target) const
{
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int index = -1;
    for (int i = 0; i < 3; i++)
    {
        if (formName == names[i])
        {
            index = i;
            break ;
        }
    }
    switch (index)
    {
        case 0:
            std::cout << "Intern creates shrubbery creation" << std::endl;
            return (new ShrubberyCreationForm(target));
        case 1:
            std::cout << "Intern creates robotomy request" << std::endl;
            return (new RobotomyRequestForm(target));
        case 2:
            std::cout << "Intern creates presidential pardon" << std::endl;
            return (new PresidentialPardonForm(target));
        default:
            std::cout << "Intern could not create " << formName << ": unknown form type." << std::endl;
            return (0);
    }
}
