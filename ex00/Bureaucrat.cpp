#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Didier"), m_grade(150) {}

Bureaucrat::Bureaucrat(int grade) : m_name("Didier") {

	try {
		if (grade < 1) {
			throw GradeTooHighException();
		} else if (grade > 150) {
			throw GradeTooLowException();
		} else {
			m_grade = grade;
		}
	} catch (GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
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

	return "Grade is too high. Set to 1";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {

	return "Grade is too low";
}

void Bureaucrat::promote() {

	try {
		if (m_grade - 1 < 1) {
			throw GradeTooHighException();
		} else {
			m_grade--;
		}
	} catch (GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::demote() {

	try {
		if (m_grade + 1 > 150) {
			throw GradeTooLowException();
		} else {
			m_grade++;
		}
	} catch (GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
}