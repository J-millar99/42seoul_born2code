#include "Intern.hpp"
typedef AForm* (*memberFunctionPTR)(const std::string&);

Intern::Intern() { }

Intern::~Intern() { }

Intern::Intern(const Intern &ref)
{
    (void)ref;
}

Intern &Intern::operator=(const Intern &ref)
{
    (void)ref;
    return *this;
}

AForm *Intern::cloneShrubberyCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}


AForm *Intern::cloneRobotomyRequestForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}


AForm *Intern::clonePresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::cloneNullForm(const std::string &target)
{
    std::cerr << target << std::endl;
    return NULL;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    memberFunctionPTR formArr[4]
    = {
        &Intern::cloneShrubberyCreationForm,
        &Intern::cloneRobotomyRequestForm, 
        &Intern::clonePresidentialPardonForm,
        &Intern::cloneNullForm
      };
    int idx = 3;
    for (int i = 0; i < 3; i++)
        form[i] == formName ? idx = i : 0;
    idx == 3 ? 
    std::cerr << "undefined form: " :
    std::cout << "Intern create " + formName << std::endl;
    return (formArr[idx])(target);
}