/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:26:52 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/30 18:27:05 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150)
{
    std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade)
{
    std::cout << "Bureaucrat Constructor called" << std::endl;
    if (_grade < 1)//idk
        throw GradeTooHighException();
    if (_grade > 150)//idk
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat Copy assigment operator called" << std::endl;
    if (this != &other)
        _grade = other._grade;//idk
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const
{
    return (_name);
}

int    Bureaucrat::getGrade() const
{
    return (_grade);
}

void    Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

void    Bureaucrat::signForm(Form &form) const//new
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << "." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
    
}

//idk for the whole section 
const char* Bureaucrat::GradeTooHighException:: what() const throw()
{
    return ("grade too high");
}

const char* Bureaucrat::GradeTooLowException:: what() const throw()
{
    return ("grade too low");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade() << ".";
    return (out); 
}
