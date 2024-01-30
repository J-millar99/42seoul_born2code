#include "AForm.hpp"

AForm::AForm(const std::string _name, const unsigned int _gradeToSign, const unsigned int _gradeToExecute)
: name(_name), sign(false), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
    if (_gradeToSign < 1)
        GradeTooHighException();
    else if (_gradeToSign > 150)
        GradeTooLowException();
    if (_gradeToExecute < 1)
        GradeTooHighException();
    else if (_gradeToExecute > 150)
        GradeTooLowException();
}

AForm::~AForm() { }

void AForm::beSigned(const Bureaucrat &ref)
{
    if (ref.getGrade() > gradeToSign)
        GradeTooLowException();
    ref.signForm(*this);
    sign = true;
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getSign() const
{
    return sign;
}

unsigned int AForm::getGradeToSign() const
{
    return gradeToSign;
}
unsigned int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

std::ostream& operator<<(std::ostream& os, const AForm &ref)
{
    os << "----- Form Information -----" << std::endl
        << "Form : " + ref.getName() << std::endl
        << "Sign : ";
    os << ref.getSign() << std::endl;
    os << "GradeToSign : " << ref.getGradeToSign() << std::endl;
    os << "GradeToExecute : " << ref.getGradeToExecute() << std::endl;
	return os;
}

void AForm::SignException() const
{
    throw NotSignException();
}

void AForm::GradeTooHighException() const
{
    throw FormHighException();
}

void AForm::GradeTooLowException() const
{
    throw FormLowException();
}

const char *AForm::NotSignException::what() const throw()
{
    return "NotSignException";
}

const char *AForm::FormLowException::what() const throw()
{
    return "FormLowException";
}

const char *AForm::FormHighException::what() const throw()
{
    return "FormHighException";
<<<<<<< HEAD
}
=======
}
>>>>>>> 4d5ecd54aeb9273abe4f31da99b2753c8f924e16
