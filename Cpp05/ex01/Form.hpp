/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:27:37 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/30 18:27:38 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _signGrade;
    const int           _execGrade;

public:
    Form();
    Form (const std::string& name, int signGrade, int execGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string&   getName(void) const;
    int                 getSignGrade() const;
    int                 getExecGrade() const;
    bool                getIsSigned() const;
    void                beSigned(const Bureaucrat& bureaucrat);

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

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
