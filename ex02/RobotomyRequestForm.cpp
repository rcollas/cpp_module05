#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:	Form("RobotomyRequestForm", 72, 45),
		 m_target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:	Form("RobotomyRequestForm", 72, 45),
		 m_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
	: Form(src) {

	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {

	this->m_target = rhs.m_target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void robotomyze(std::string target) {

	srand(time(0));
	std::cout << "BzzzZZZZZzzzZZzzzZZ" << std::endl;
	if ((rand() % 2) == 0) {
		std::cout << target + " has been robotomyze" << std::endl;
	} else {
		std::cout << "Robotomy failed on " + target << std::endl;
	}
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {

	try {
		this->execAuthorization(executor);
		robotomyze(this->m_target);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

