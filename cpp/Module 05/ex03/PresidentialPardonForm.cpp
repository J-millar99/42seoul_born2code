#include "PresidentialPardonForm.hpp"

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
    if (this != &ref)
        return *this;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() { }

PresidentialPardonForm::PresidentialPardonForm()
: AForm("RobotomyRequest", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref)
: AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string formName)
: AForm(formName, 25, 5)
{

}

void PresidentialPardonForm::informPardoned() const
{
    std::cout << getName() + " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

bool PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!getSign())
        SignException();
    if (getGradeToExecute() < executor.getGrade())
        GradeTooLowException();
    informPardoned();
    return true;
}
