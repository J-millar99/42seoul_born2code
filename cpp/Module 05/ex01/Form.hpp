#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        Form();
        Form(const Form &ref);
        Form &operator=(const Form &ref);
        const std::string name;
        bool sign; // default false(0)
        const unsigned int gradeToSign;
        const unsigned int gradeToExecute;

    public:
        Form(const std::string _name, const unsigned int _gradeToSign, const unsigned int _gradeToExecute);
        ~Form();
        void beSigned(const Bureaucrat &ref);
        void GradeTooHighException() const;
        void GradeTooLowException() const;
        const std::string getName() const;
        bool getSign() const;
        unsigned int getGradeToSign() const;
        unsigned int getGradeToExecute() const;

        class FormLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class FormHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& ref);

#endif