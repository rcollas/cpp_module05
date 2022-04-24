#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
		:	Form("PresidentialPardonForm", 25, 5),
			 m_target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
		:	Form("PresidentialPardonForm", 25, 5),
			 m_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
	: Form(src) {

	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {

	this->m_target = rhs.m_target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {

	try {
		this->execAuthorization(executor);
		std::cout << "Zaphod Beeblebrox pardon " + this->m_target << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
