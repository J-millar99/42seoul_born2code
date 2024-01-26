#include "RobotomyRequestForm.hpp"

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
    if (this != &ref)
        return *this;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() { }

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequest", 72, 45)
{
    informRobotomized();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
: AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
    informRobotomized();
}

RobotomyRequestForm::RobotomyRequestForm(const std::string formName)
: AForm(formName, 72, 45)
{
    informRobotomized();
}

void RobotomyRequestForm::informRobotomized() const
{
    srand(time(NULL));
    std::cout << "(Drilling noises...)" << std::endl;
    std::cout << "Robotomize Mode : ";
    rand() % 2 ? std::cout << "success\n" : std::cout << "fail\n";
}

bool RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!getSign())
        SignException();
    if (getGradeToExecute() < executor.getGrade())
        GradeTooLowException();
    return true;
}

AForm *RobotomyRequestForm::clone(const std::string &target)
{
    return new RobotomyRequestForm(target);
}