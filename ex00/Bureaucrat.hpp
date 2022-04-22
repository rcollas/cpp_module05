#ifndef CPP_MODULE05_BUREAUCRAT_HPP
#define CPP_MODULE05_BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {

	public:
		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &rhs);

		std::string getName() const;
		int getGrade() const;
		void promote();
		void demote();

	private:
		std::string const m_name;
		int m_grade;

	class GradeTooHighException : public std::exception {
		public :
			virtual const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public :
			virtual const char * what() const throw();
	};

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);

#endif
