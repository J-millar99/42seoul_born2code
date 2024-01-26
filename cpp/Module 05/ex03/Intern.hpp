#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class AForm;

class Intern
{
    private:

    public:
        Intern();
        ~Intern();
        Intern(const Intern &ref);
        Intern &operator=(const Intern &ref);

        AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif