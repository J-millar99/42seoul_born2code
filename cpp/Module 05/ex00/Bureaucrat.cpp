#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("const_name"), grade(150) { }

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : name(ref.name), grade(ref.grade) { }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref)
{
    if (this != &ref)
        grade = ref.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() { }

Bureaucrat::Bureaucrat(const std::string _name, unsigned int _grade) : name(_name)
{
    if (_grade < 1)
        GradeTooHighException();
    else if (_grade > 150)
        GradeTooLowException();
    else
        grade = _grade;
}

void Bureaucrat::GradeTooHighException() const
{
    throw MyHighException();
}

void Bureaucrat::GradeTooLowException() const
{
    throw MyLowException();
}

const std::string Bureaucrat::getName() const
{
    return name;
}

unsigned int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::increaseGrade()
{
    if (grade >= 150)
        GradeTooLowException();
    else
        ++grade;
}

void Bureaucrat::decreaseGrade()
{
    if (grade <= 1)
        GradeTooHighException();
    else
        --grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ref)
{
    os << ref.getName() + ", bureaucrat grade " << ref.getGrade() << std::endl;
	return os;
}

// exception
const char *Bureaucrat::MyLowException::what() const throw()    
{
    return "LowException";
}

const char *Bureaucrat::MyHighException::what() const throw()   
{
    return "HighException";
}