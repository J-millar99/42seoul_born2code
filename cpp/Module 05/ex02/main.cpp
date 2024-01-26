#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
       try
       {
              Bureaucrat c("c", 1);
              AForm *t = new ShrubberyCreationForm("test");
              // AForm *t = new RobotomyRequestForm("test");
              // AForm *t = new PresidentialPardonForm("test");
              // c.executeForm(*t);
              t->beSigned(c);
              c.executeForm(*t);
              delete t;
       }
       catch (std::exception &e)
       {
              std::cerr << e.what() << std::endl;
       }
}