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

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    memberFunctionPTR formArr[4]
    = {&ShrubberyCreationForm::clone, &RobotomyRequestForm::clone, &PresidentialPardonForm::clone, &AForm::nullForm};
    int idx = 0;

    for (int i = 0; i < 3; i++)
        form[i] == formName ? idx = i : idx = 3;
    idx != 3 ? std::cout << "Intern create " + formName << std::endl : std::cerr << "undefined form" << std::endl;
    return (formArr[idx])(target);
}
