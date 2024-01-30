#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
    if (this != &ref)
        return *this;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { }

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Shrubbery", 145, 137)
{
    createASCII_TreeFile();
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref)
: AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
    createASCII_TreeFile();
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string formName)
: AForm(formName, 145, 137)
{
    createASCII_TreeFile();
}

std::string ShrubberyCreationForm::ASCII_Tree() const
{
    return "      *\n"
        "     ***\n"
        "    *****\n"
        "   *******\n"
        "  *********\n"
        " ***********\n"
        "*************\n"
        "      |\n";
}

void ShrubberyCreationForm::createASCII_TreeFile() const
{
    std::ofstream file((getName() + "_shrubbery").c_str());

    if (file.is_open()) 
		file << ASCII_Tree();
	else
		std::cerr << "Error: Failed to open output file." << std::endl;
}

bool ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!getSign())
        SignException();
    if (getGradeToExecute() < executor.getGrade())
        GradeTooLowException();
    return true;
}