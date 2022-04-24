#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void printTest(int i) {

	std::string line(20, '*');
	std::cout << "\x1B[34m";
	std::cout << line << std::endl;
	std::cout << "*******Test " << i << "*******" << std::endl;
	std::cout << line << "\033[0m" << std::endl;
}

int main() {

	ShrubberyCreationForm garden("garden");
	Bureaucrat denis("denis", 1);

	garden.execute(denis);
	garden.beSigned(denis);
	garden.execute(denis);

	RobotomyRequestForm glados("glados");

	glados.execute(denis);
	glados.beSigned(denis);
	glados.execute(denis);

	PresidentialPardonForm franklin("franklin");

	franklin.execute(denis);
	franklin.beSigned(denis);
	franklin.execute(denis);

	ShrubberyCreationForm newGarden("garden");
	denis.executeForm(newGarden);

	return 0;
}