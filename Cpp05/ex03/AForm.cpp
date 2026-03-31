/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:59:29 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/30 18:59:31 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("Default"), _isSigned(0), _signGrade(150), _execGrade(150)
{
    std::cout << "AForm Default Constructor called" << std::endl;
}

AForm:: AForm (const std::string& name, int signGrade, int execGrade): _name(name), _isSigned(0), _signGrade(signGrade), _execGrade(execGrade) 
{
    std::cout << "AForm Constructor called" << std::endl;
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other): _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
    std::cout << "AForm Copy Constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    std::cout << "AForm Copy Assigment operator called" << std::endl;
    if (this != &other)
        _isSigned = other._isSigned;//idk why?
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm Destructor called" << std::endl;
}

const std::string&   AForm::getName(void) const
{
    return (_name);
}

int   AForm::getSignGrade() const
{
    return (_signGrade);
}

int   AForm::getExecGrade() const
{
    return (_execGrade);
}

bool    AForm::getIsSigned() const
{
    return (_isSigned);
}

void    AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = 1;
}

void    AForm::execute(Bureaucrat const& executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
    execForm();
}

const char* AForm::GradeTooHighException:: what() const throw()
{
    return ("grade too high");
}

const char* AForm::GradeTooLowException:: what() const throw()
{
    return ("grade too low");
}

const char* AForm::FormNotSignedException:: what() const throw()
{
    return ("form is not signed");
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << "AForm " << form.getName() ;
    if (form.getIsSigned())
        out << " is signed";
    else
        out << " is not signed. ";
    out << "Grade to sign: " << form.getSignGrade();
    out << ", Grade to execute: " << form.getExecGrade() << "."; 
    return (out); 
}
