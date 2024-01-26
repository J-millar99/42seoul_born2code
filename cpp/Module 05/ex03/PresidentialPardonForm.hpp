#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm : public AForm
{
    private:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &ref);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);
    
    public:
        PresidentialPardonForm(const std::string formName);
        ~PresidentialPardonForm();
        void informPardoned() const;
        bool execute(const Bureaucrat &executor) const;
        static AForm *clone(const std::string &target);
};

#endif