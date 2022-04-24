#ifndef CPP_MODULE05_PRESIDENTIALPARDONFORM_HPP
#define CPP_MODULE05_PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

		void execute(Bureaucrat const &executor) const;

	private:
		std::string m_target;
};


#endif
