#include "Intern.hpp"

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
    int idx = 0;

    for (int i = 0; i < 3; i++)
    {
        if (form[i] == formName)
            idx = i;
    }

    switch (idx)
    {
    case 0:
        std::cout << "Intern create " + formName << std::endl;
        return new ShrubberyCreationForm(target);
    case 1:
        std::cout << "Intern create " + formName << std::endl;
        return new RobotomyRequestForm(target);
    case 2:
        std::cout << "Intern create " + formName << std::endl;
        return new PresidentialPardonForm(target);
    default:
        std::cerr << "undefined form" << std::endl;
        return NULL;
    }
}
