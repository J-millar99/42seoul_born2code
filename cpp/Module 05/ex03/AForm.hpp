#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool sign;
        const unsigned int gradeToSign;
        const unsigned int gradeToExecute;

    public:
        AForm(const std::string _name, const unsigned int _gradeToSign, const unsigned int _gradeToExecute);
        virtual ~AForm();
        void beSigned(const Bureaucrat &ref);
        void SignException() const;
        void GradeTooHighException() const;
        void GradeTooLowException() const;
        std::string getName() const;
        bool getSign() const;
        unsigned int getGradeToSign() const;
        unsigned int getGradeToExecute() const;
        virtual bool execute(const Bureaucrat &executor) const = 0;
        static AForm *nullForm(std::string &target);
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

        class NotSignException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& ref);

#endif