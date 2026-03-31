/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:44:31 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/30 18:44:33 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int         _grade;
public:
    Bureaucrat();
    Bureaucrat (const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string&     getName(void) const;
    int             getGrade(void) const;
    void            incrementGrade();
    void            decrementGrade();

    void            signForm(AForm &form) const;
    void            executeForm(AForm const & form) const;

    class GradeTooHighException: public std::exception//idk
    {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception//idk
    {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
