#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    AForm *form = NULL;
    try
    {
        Bureaucrat man("man", 1);
        form = new ShrubberyCreationForm("test");
        // form = new RobotomyRequestForm("test");
        // form = new PresidentialPardonForm("test");
        // man.executeForm(*form);
        form->beSigned(man);
        man.executeForm(*form);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete form;
}