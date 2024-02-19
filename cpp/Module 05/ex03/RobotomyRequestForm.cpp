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

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
: AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string formName)
: AForm(formName, 72, 45)
{

}

void RobotomyRequestForm::drillingNoiseAnimation() const
{
    int animationDelay = 250;
    const int animationCount = 3;

    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < animationCount + 1; ++j)
        {
            std::cout << "Drilling noises";
            for (int k = 0; k < j; ++k)
                std::cout << ".";
            std::cout.flush();
            clock_t start_time = clock();
            while (static_cast<double>(clock() - start_time) / CLOCKS_PER_SEC * 1000 < animationDelay) {}
            std::cout << "\r\033[K";
        }
    }
}

void RobotomyRequestForm::informRobotomized() const
{
    srand(time(NULL));
    drillingNoiseAnimation();
    std::cout << getName() + "'s Robotomize Mode : ";
    rand() % 2 ? std::cout << "success\n" : std::cout << "fail\n";
}

bool RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!getSign())
        SignException();
    if (getGradeToExecute() < executor.getGrade())
        GradeTooLowException();
    informRobotomized();
    return true;
}
