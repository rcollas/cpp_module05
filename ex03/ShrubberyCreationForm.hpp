#ifndef CPP_MODULE05_SHRUBBERYCREATIONFORM_HPP
#define CPP_MODULE05_SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form {

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

		void execute(Bureaucrat const &executor) const;

	private:
		std::string m_target;
};


#endif
