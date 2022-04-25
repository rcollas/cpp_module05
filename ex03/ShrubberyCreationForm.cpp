#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	:	Form("ShrubberyCreationForm", 145, 137),
		m_target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:	Form("ShrubberyCreationForm", 145, 137),
		m_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
	: Form(src) {

	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {

	this->m_target = rhs.m_target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void createTree(std::string name) {

	std::string outfileName = name + "_shrubbery";
	std::ofstream outfile(outfileName.c_str());

	outfile << "    ^     \n"
			   "   /o\\   \n"
			   "  / o \\  \n"
			   " /__o__\\ \n"
			   "    o     \n"
			   "    o     \n";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

	this->execAuthorization(executor);
	createTree(this->m_target);
	std::cout << this->m_target + "_shrubbery created" << std::endl;
}
