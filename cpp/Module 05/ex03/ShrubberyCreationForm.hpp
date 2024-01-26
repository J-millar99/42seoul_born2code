#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm 
{
    private:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &ref);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);

    public:
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string formName);

        void createASCII_TreeFile() const;
        std::string ASCII_Tree() const;
        bool execute(const Bureaucrat &executor) const;
        static AForm *clone(const std::string &target);
};

#endif