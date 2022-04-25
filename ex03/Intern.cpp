#include "Intern.hpp"

Intern::Intern() {

	this->m_availableForm[0] = "shrubbery creation";
	this->m_availableForm[1] = "robotomy request";
	this->m_availableForm[2] = "presidential pardon";
}

Intern::Intern(Intern const &src) {

	*this = src;
}

Intern &Intern::operator=(Intern const &rhs) {

	(void)rhs;
	return *this;
}

Intern::~Intern() {}

int Intern::isValidForm(std::string form) {

	for (int i = 0; i < 3; i++) {
		if (form == this->m_availableForm[i]) {
			return i;
		}
	}
	return 4;
}

Form *Intern::makeForm(std::string form, std::string target) {

	int i = isValidForm(form);
	Form* ret;
	switch (i) {
		case 0: ret = new ShrubberyCreationForm(target); break;
		case 1: ret = new RobotomyRequestForm(target); break;
		case 2: ret = new PresidentialPardonForm(target); break;
		default: throw InvalidFormException();
	}
	std::cout << "Intern creates " + form << std::endl;
	return ret;
}

const char *Intern::InvalidFormException::what() const throw() {

	return "Can't create form: invalid type";
}
