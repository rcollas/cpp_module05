#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void printTest(std::string msg) {

	std::string line((20 - msg.length() / 2) * 2 + msg.length(), '*');
	std::string fill(20 - msg.length() / 2, '*');
	std::cout << "\x1B[34m";
	std::cout << line << std::endl;
	std::cout << fill << msg << fill << std::endl;
	std::cout << line << "\033[0m" << std::endl;
}

int main() {

	Bureaucrat denis("denis", 1);

	printTest("Shrubbery not signed");

	try {
		ShrubberyCreationForm garden("garden");

		garden.execute(denis);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	printTest("Robotomy not signed");

	try {
		RobotomyRequestForm glados("glados");

		glados.execute(denis);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	printTest("PresidentialPardon not signed");

	try {
		PresidentialPardonForm franklin("franklin");

		franklin.execute(denis);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	printtest("executeform missing signature");

	{
		shrubberycreationform newgarden("garden");
		denis.executeform(newgarden);
		denis.signform(newgarden);
		denis.executeform(newgarden);
	}

	printtest("executeform invalid grade");

	{
		bureaucrat phil("phil", 25);
		presidentialpardonform pardon("pardon");

		phil.executeForm(pardon);
		pardon.beSigned(denis);
		phil.executeForm(pardon);
		for (int i = 0; i < 24; i++) {
			phil.promote();
		}
		phil.executeForm(pardon);
	}

	return 0;
}