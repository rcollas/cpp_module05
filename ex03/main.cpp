#include "Bureaucrat.hpp"
#include "Intern.hpp"

void printTest(std::string msg) {

	std::string line((20 - msg.length() / 2) * 2 + msg.length(), '*');
	std::string fill(20 - msg.length() / 2, '*');
	std::cout << "\x1B[34m";
	std::cout << line << std::endl;
	std::cout << fill << msg << fill << std::endl;
	std::cout << line << "\033[0m" << std::endl;
}

int main() {

	Intern bob;
	Bureaucrat ross("ross", 1);
	Form *form;

	form = bob.makeForm("shrubbery creation", "garden");
	form->beSigned(ross);
	form->execute(ross);

	try {
		form = bob.makeForm("invalid form", "defautl");
		form->beSigned(ross);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}