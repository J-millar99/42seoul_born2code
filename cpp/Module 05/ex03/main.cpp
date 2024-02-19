#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void test(Bureaucrat &man, AForm *form)
{
       if (form)
       {
              man.signForm(*form);
              man.executeForm(*form);
       }
}

int main()
{
       try
       {
              Bureaucrat c("c", 1);
              Intern someRandomIntern;
              AForm *rrf;
              rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
              test(c, rrf);
              delete rrf;
              rrf = someRandomIntern.makeForm("robotomy request", "Bender");
              test(c, rrf);
              delete rrf;
              rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
              test(c, rrf);
              delete rrf;
              rrf = someRandomIntern.makeForm("unknown", "Bender");
              test(c, rrf);
              delete rrf;
       }
       catch(std::exception & e)
       {
              std::cerr << e.what() << std::endl;
       }
}