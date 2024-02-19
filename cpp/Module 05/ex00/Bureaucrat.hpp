#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iomanip>
#include <iostream>

class Bureaucrat
{
    private:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &ref);
        Bureaucrat &operator=(const Bureaucrat &ref);
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

        class MyLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class MyHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ref);

#endif