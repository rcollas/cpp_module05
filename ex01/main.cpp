#include "Bureaucrat.hpp"
#include "Form.hpp"

void printTest(int i) {

	std::string line(20, '*');
	std::cout << "\x1B[34m";
	std::cout << line << std::endl;
	std::cout << "*******Test " << i << "*******" << std::endl;
	std::cout << line << "\033[0m" << std::endl;
}

int main() {

	// *TEST 1 : Dider's grade is too low to sign
	printTest(1);

	try {
		Form fA1b2("A1B2", 12, 150);
		Bureaucrat didier("didier", 13);

		std::cout << fA1b2 << std::endl;
		fA1b2.beSigned(didier); 				// !grade expect >= 12. Didier = 13
	} catch (Form::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}

	// *TEST 2 : Invalid Sign Grade (HIGH)
	printTest(2);

	try {
		Form A2("A2", 0, 150); // !signGrade too high
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// *TEST 3 : Invalid Sign Grade (LOW)
	printTest(3);

	try {
		Form A2("A2", 151, 1); // !signGrade too low
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// *TEST 4 : Invalid Exec Grade (HIGH)
	printTest(4);

	try {
		Form A2("A2", 150, -10); // !execGrade too high
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// *TEST 5 : Invalid Exec Grade (LOW)
	printTest(5);

	try {
		Form A2("A2", 1, 154); // !execGrade too low
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// *TEST 6 : jean.signForm() with grade too low
	printTest(6);
	{
		Form A3("A3", 149, 150);
		Bureaucrat jean("Jean", 150);

		jean.signForm(A3); // !grade's too low
		jean.promote(); // *jean's grade is now 149
		jean.signForm(A3);
	}

	return 0;
}