#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
       try
       {
              Intern someRandomIntern;
              AForm *rrf;
              rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
              delete rrf;
              rrf = someRandomIntern.makeForm("robotomy request", "Bender");
              delete rrf;
              rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
              delete rrf;
              rrf = someRandomIntern.makeForm("unknown", "Bender");
              delete rrf;
       }
       catch(std::exception & e)
       {
              std::cerr << e.what() << std::endl;
       }
}