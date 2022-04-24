#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Didier"), m_grade(150) {}

// *Bureaucrat's grade goes from 150 (lowest) to 1 (highest)
// *Values below 1 or above 150 throw exceptions

Bureaucrat::Bureaucrat(int grade) : m_name("Didier"), m_grade(grade) {

		if (grade < 1) {
			throw GradeTooHighException();
		} else if (grade > 150) {
			throw GradeTooLowException();
		}
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {

	*this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {

	this->m_grade = rhs.m_grade;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs) {

	out << rhs.getName() << ", bureaucrat grade ";
	out << rhs.getGrade() << ".";
	return out;
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

const char * Bureaucrat::GradeTooHighException::what() const throw() {

	return "Grade is too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {

	return "Grade is too low";
}

void Bureaucrat::promote() {

	if (m_grade - 1 < 1) {
		throw GradeTooHighException();
	} else {
		m_grade--;
	}
}

void Bureaucrat::demote() {

	if (m_grade + 1 > 150) {
		throw GradeTooLowException();
	} else {
		m_grade++;
	}
}