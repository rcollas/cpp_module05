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
		virtual ~Form();

		Form &operator=(Form const &rhs);

		void beSigned(Bureaucrat& bureaucrat);
		std::string getName() const;
		std::string isSigned() const;
		int getReqSignGrade() const;
		int getReqExecGrade() const;
		virtual void execute(Bureaucrat const &executor) const = 0;
		void execAuthorization(Bureaucrat const &bureaucrat) const;

		class GradeTooHighException : public std::exception {
			public :
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char * what() const throw();
		};

		class ExecuteRequirementException : public std::exception {
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
