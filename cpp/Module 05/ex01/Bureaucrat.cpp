 #include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("const bureaucrat"), grade(150) { }

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
    throw BureaucratHighException();
}

void Bureaucrat::GradeTooLowException() const
{
    throw BureaucratLowException();
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
    if (grade == 1)
        GradeTooHighException();
    else
        --grade;
}

void Bureaucrat::decreaseGrade()
{
    if (grade == 150)
        GradeTooLowException();
    else
        ++grade;
}

void Bureaucrat::signForm(Form &ref)
{
    ref.getSign() ?
    std::cout << name + " couldn't sign " + ref.getName() + " because " + "already signed\n" :
    (ref.beSigned(*this), std::cout << name + " singed " + ref.getName() << std::endl);
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& ref)
{
    os << ref.getName() + ", bureaucrat grade " << ref.getGrade() << std::endl;
	return os;
}

const char *Bureaucrat::BureaucratLowException::what() const throw()    
{
    return "BureaucratLowException";
}

const char *Bureaucrat::BureaucratHighException::what() const throw()   
{
    return "BureaucratHighException";
}