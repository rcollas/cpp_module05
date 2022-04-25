#ifndef CPP_MODULE05_BUREAUCRAT_HPP
#define CPP_MODULE05_BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Form;

#include "Form.hpp"

class Bureaucrat {

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &rhs);

		std::string getName() const;
		int getGrade() const;
		void promote();
		void demote();
		void signForm(Form &form);
		void executeForm(Form const &form);

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
		int m_grade;

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);

#endif
