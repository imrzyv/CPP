/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imirzaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:44:11 by imirzaev          #+#    #+#             */
/*   Updated: 2026/03/30 18:44:13 by imirzaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _signGrade;
    const int           _execGrade;

public:
    AForm();
    AForm (const std::string& name, int signGrade, int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string&   getName(void) const;
    int                 getSignGrade() const;
    int                 getExecGrade() const;
    bool                getIsSigned() const;

    void                beSigned(const Bureaucrat& bureaucrat);
    void                execute(Bureaucrat const& executor) const;
    virtual void        execForm() const = 0;//idk so many questions

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
    class FormNotSignedException: public std::exception//idk
    {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
