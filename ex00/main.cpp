#include "Bureaucrat.hpp"

int main() {

	// *Didier's grade is 0. Constructor throw GradeTooHighException

	try {
		Bureaucrat didier(0);

		didier.demote();
		std::cout << didier << std::endl;

	} catch (Bureaucrat::GradeTooHighException& e) { // !Catch GradeTooHighException
		std::cerr << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException& e) {
	std::cerr << e.what() << std::endl;
	}

	// *Jean's grade is 151. Constructor throw GradeTooLowException

	try {
		Bureaucrat jean(151);

		std::cout << jean << std::endl;
		jean.promote();
		jean.demote();

	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException& e) { // !Catch GradeTooLowException
	std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat bernard(150);

		bernard.promote();
		std::cout << bernard << std::endl;
		bernard.demote();
		std::cout << bernard << std::endl;

		// *Bernard's grade is 150. Trying to demote him to 151. Throw GradeTooLowException
		bernard.demote();

	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException& e) { // !Catch GradeTooLowException
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat louis(1);

		louis.demote();
		std::cout << louis << std::endl;
		louis.promote();
		std::cout << louis << std::endl;

		// *Louis's grade is 1. Trying to promote him to 0. Throw GradeTooHighException
		louis.promote();

	} catch (Bureaucrat::GradeTooHighException& e) {  // !Catch GradeTooHighException
		std::cerr << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}