#include "Form.hpp"

void checkGrade(int grade) {

	if (grade < 1) {
		throw Form::GradeTooHighException();
	} else if (grade > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::Form() : m_name("default"),
				m_isSigned(false),
				m_reqSignGrade(1),
				m_reqExecGrade(1) {}

Form::Form(std::string name, int reqSignGrade, int reqExecGrade)
	:	m_name(name),
		m_isSigned(false),
		m_reqSignGrade(reqSignGrade),
		m_reqExecGrade(reqExecGrade) {

	checkGrade(this->m_reqSignGrade);
	checkGrade(this->m_reqExecGrade);
}

Form::Form(Form const &src)
	:	m_name(src.m_name),
		m_isSigned(src.m_isSigned),
		m_reqSignGrade(src.m_reqSignGrade),
		m_reqExecGrade(src.m_reqExecGrade) {

	checkGrade(this->m_reqSignGrade);
	checkGrade(this->m_reqExecGrade);
}

Form &Form::operator=(Form const &rhs) {

	this->m_isSigned = rhs.m_isSigned;
	return *this;
}

Form::~Form() {}

void Form::beSigned(Bureaucrat &bureaucrat) {

	if (bureaucrat.getGrade() > this->getReqSignGrade()) {
		throw Form::GradeTooLowException();
	} else {
		this->m_isSigned = true;
		std::cout << "Bureaucrat " + bureaucrat.getName();
		std::cout << " signed form " + this->getName() << std::endl;
	}
}

std::string Form::getName() const {

	return this->m_name;
}

std::string Form::isSigned() const {

	if (!this->m_isSigned) {
		return "not signed";
	} else {
		return "signed";
	}
}

int	Form::getReqSignGrade() const {

	return this->m_reqSignGrade;
}

int Form::getReqExecGrade() const {

	return this->m_reqExecGrade;
}

void Form::execAuthorization(Bureaucrat const &bureaucrat) const {

	if (bureaucrat.getGrade() > this->m_reqExecGrade
		|| !this->m_isSigned) {
		throw ExecuteRequirementException();
	}
}

const char * Form::GradeTooHighException::what() const throw() {

	return "Grade is too high";
}

const char * Form::GradeTooLowException::what() const throw() {

	return "Grade is too low";
}

const char * Form::ExecuteRequirementException::what() const throw() {

	return "Execution denied. Make sure that the form is signed and that the bureaucrat's grade is valid";
}

std::ostream &operator<<(std::ostream &out, Form &form) {

	out << "Form " + form.getName() << std::endl;
	out << "Required grade to sign: " << form.getReqSignGrade() << std::endl;
	out << "Required grade to execute: " << form.getReqExecGrade() << std::endl;
	out << "Actual status: " + form.isSigned();
	return out;
}
