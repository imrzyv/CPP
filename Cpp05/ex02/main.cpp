/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:44:42 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/30 18:44:44 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat low("Low", 140);
    Bureaucrat mid("Mid", 40);
    Bureaucrat high("High", 1);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << std::endl << "----- Signing -----" << std::endl;
    low.signForm(shrub);
    low.signForm(robot);
    low.signForm(pardon);
    high.signForm(pardon);

    std::cout << std::endl << "----- Executing -----" << std::endl;
    low.executeForm(shrub);
    mid.executeForm(robot);
    mid.executeForm(shrub);
    high.executeForm(pardon);

    std::cout << std::endl << "----- Unsigned form test -----" << std::endl;
    ShrubberyCreationForm unsignedForm("garden");
    high.executeForm(unsignedForm);

    return 0;
}
