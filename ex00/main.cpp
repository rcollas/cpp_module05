#include "Bureaucrat.hpp"

int main() {

	Bureaucrat didier(0);
	Bureaucrat jean(150);

	didier.demote();
	std::cout << didier << std::endl;
	jean.demote();
	return 0;
}