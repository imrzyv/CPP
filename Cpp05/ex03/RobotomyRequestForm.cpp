/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:03:42 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/30 19:03:43 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>//idk
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
    std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm:: RobotomyRequestForm(const std::string& target):AForm("RobotomyRequestForm", 72, 45), _target(target) 
{
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other._target)
{
    std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    std::cout << "RobotomyRequestForm Copy Assigment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator =(other);
        _target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

void    RobotomyRequestForm::execForm() const
{
    std::cout << "DRILLING NOISES!!!" << std::endl;
    static bool    succes = false;
    if (!succes)//idk revisit this braket
    {
        std::srand(std::time(0));
        succes = true;
    }
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized." << std::endl;
    else
        std:: cout << "Robotomy on " << _target << " has failed." << std::endl;
}
