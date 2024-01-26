#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iomanip>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &ref);
        Bureaucrat(const Bureaucrat &ref);
        const std::string name;
        unsigned int grade; // 1 (highest) ~ 150 (lowest)

    public:
        ~Bureaucrat();
        Bureaucrat(const std::string _name, unsigned int _grade);
    
        void GradeTooHighException() const;
        void GradeTooLowException() const;
    
        const std::string getName() const;
        unsigned int getGrade() const;

        void increaseGrade();
        void decreaseGrade();
    
        void signForm(const AForm &ref) const;
        void executeForm(AForm const &ref) const;
        class BureaucratLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class BureaucratHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ref);

#endif