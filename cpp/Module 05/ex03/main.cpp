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
              rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
              delete rrf;
       }
       catch(std::exception & e)
       {
              std::cerr << e.what() << std::endl;
       }
}