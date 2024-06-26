#include "Form.hpp"

Form::Form()
: name("const form"), sign(false), gradeToSign(1), gradeToExecute(1) { }

Form::Form(const Form &ref)
: name(ref.name), sign(false), gradeToSign(ref.gradeToSign), gradeToExecute(ref.gradeToExecute) { }

Form &Form::operator=(const Form &ref)
{
    if (this != &ref)
        sign = ref.sign;
    return *this;
}


Form::Form(const std::string _name, const unsigned int _gradeToSign, const unsigned int _gradeToExecute)
: name(_name), sign(false), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        GradeTooHighException();
    else if (_gradeToSign > 150 || _gradeToExecute > 150)
        GradeTooLowException();
}

Form::~Form() { }

void Form::beSigned(const Bureaucrat &ref)
{
    if (ref.getGrade() > gradeToSign)
        GradeTooLowException();
    sign = true;
}

void Form::GradeTooHighException() const
{
    throw FormHighException();
}

void Form::GradeTooLowException() const
{
    throw FormLowException();
}

const std::string Form::getName() const
{
    return name;
}

bool Form::getSign() const
{
    return sign;
}

unsigned int Form::getGradeToSign() const
{
    return gradeToSign;
}
unsigned int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

std::ostream& operator<<(std::ostream& os, const Form &ref)
{
    os << "----- Form Information -----" << std::endl
        << "Form : " + ref.getName() << std::endl
        << "Sign : ";
    os << ref.getSign() << std::endl;
    os << "GradeToSign : " << ref.getGradeToSign() << std::endl;
    os << "GradeToExecute : " << ref.getGradeToExecute() << std::endl;
	return os;
}

const char *Form::FormLowException::what() const throw()
{
    return "GradeTooLowException";
}

const char *Form::FormHighException::what() const throw()
{
    return "GradeTooHighException";
}