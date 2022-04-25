#ifndef CPP_MODULE05_INTERN_HPP
#define CPP_MODULE05_INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

	public:
		Intern();
		Intern(Intern const &src);
		~Intern();

		Intern &operator=(Intern const &rhs);

		Form *makeForm(std::string form, std::string target);

	class InvalidFormException : public std::exception {
		public :
			virtual const char * what() const throw();
	};

	private:
		std::string m_availableForm[3];
		int isValidForm(std::string form);
};


#endif
