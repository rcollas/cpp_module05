#ifndef CPP_MODULE05_FORM_HPP
#define CPP_MODULE05_FORM_HPP

#include <iostream>

class Bureaucrat;

#include "Bureaucrat.hpp"

class Form {

	public:
		Form();
		Form(std::string name, int reqSignGrade, int reqExecGrade);
		Form(Form const &src);
		~Form();

		Form &operator=(Form const &rhs);

		void beSigned(Bureaucrat& bureaucrat);
		std::string getName();
		std::string isSigned();
		int getReqSignGrade();
		int getReqExecGrade();

		class GradeTooHighException : public std::exception {
			public :
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char * what() const throw();
		};

	private:
		std::string const m_name;
		bool m_isSigned;
		int const m_reqSignGrade;
		int const m_reqExecGrade;

};

std::ostream &operator<<(std::ostream &out, Form &form);


#endif
