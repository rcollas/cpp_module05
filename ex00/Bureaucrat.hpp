#ifndef CPP_MODULE05_BUREAUCRAT_HPP
#define CPP_MODULE05_BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {

	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &rhs);

		std::string getName() const;
		int getGrade() const;

	private:
		std::string const m_name;
		int m_grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);

#endif
