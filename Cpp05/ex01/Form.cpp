#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Default"), _isSigned(0), _signGrade(150), _execGrade(150)
{
    std::cout << "Form Default Constructor called" << std::endl;
}

Form:: Form (const std::string& name, int signGrade, int execGrade): _name(name), _isSigned(0), _signGrade(signGrade), _execGrade(execGrade) 
{
    std::cout << "Form Constructor called" << std::endl;
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other): _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
    std::cout << "Form Copy Constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    std::cout << "Form Copy Assigment operator called" << std::endl;
    if (this != &other)
        _isSigned = other._isSigned;//idk why?
    return (*this);
}

Form::~Form()
{
    std::cout << "Form Destructor called" << std::endl;
}

const std::string&   Form::getName(void) const
{
    return (_name);
}

int   Form::getSignGrade() const
{
    return (_signGrade);
}

int   Form::getExecGrade() const
{
    return (_execGrade);
}

bool    Form::getIsSigned() const
{
    return (_isSigned);
}

void    Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = 1;
}

const char* Form::GradeTooHighException:: what() const throw()
{
    return ("grade too high");
}

const char* Form::GradeTooLowException:: what() const throw()
{
    return ("grade too low");
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Form " << form.getName() ;
    if (form.getIsSigned())
        out << " is signed";
    else
        out << " is not signed. ";
    out << "Grade to sign: " << form.getSignGrade();
    out << ", Grade to execute: " << form.getExecGrade() << "."; 
    return (out); 
}