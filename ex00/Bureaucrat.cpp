#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}


Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {

	*this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {

	this->m_name = rhs.m_name;
	this->m_grade = rhs.m_grade;
	return *this;
}

std::ostream& Bureaucrat::operator<<(std::ostream& out, const Bureaucrat& rhs) {

	out << this->getName() << ", bureaucrat grade ";
	out << this->getGrade() << " ." << std::endl;
}

std::string Bureaucrat::getName() const {

	if (m_name.empty()) {
		return "Name is missing";
	}
	return this->m_name;
}

int Bureaucrat::getGrade() const {

	return this->m_grade;
}