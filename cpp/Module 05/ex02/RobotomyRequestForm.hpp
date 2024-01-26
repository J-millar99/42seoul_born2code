#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cmath>

class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm
{
    private:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &ref);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &ref);
    
    public:
        ~RobotomyRequestForm();
        RobotomyRequestForm(const std::string formName);
        void informRobotomized() const;
        bool execute(const Bureaucrat &executor) const;
};

#endif