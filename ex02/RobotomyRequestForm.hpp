#ifndef CPP_MODULE05_ROBOTOMYREQUESTFORM_HPP
#define CPP_MODULE05_ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public Form {

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

		void execute(Bureaucrat const &executor) const;

	private:
		std::string m_target;
};


#endif
