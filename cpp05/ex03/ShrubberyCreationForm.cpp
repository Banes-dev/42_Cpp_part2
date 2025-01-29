#include "ShrubberyCreationForm.hpp"

// Construtor / Destructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &recup_target) : AForm("ShrubberyCreationForm", 145, 137), _target(recup_target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Other function
std::string const ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() >  this->getGradeToExecute())
		throw ShrubberyCreationForm::GradeTooLowForExecutionException();
	if (this->getIsSigned() == false)
		throw ShrubberyCreationForm::NotSignedException();
	std::ofstream file;
	file.open((this->_target + "_shruberry").c_str());
	if (!file.is_open())
		throw ShrubberyCreationForm::FileNotOpenException();
	file << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⠤⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡾⠁⠀⠀⠈⣷⠻⠛⣦⠴⠶⠤⣤⠞⠉⠀⠀⠀⠙⢳⡄⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠾⢧⠀⠀⠀⠀⠀⠀⢸⣁⠀⠀⠀⠈⠳⠀⠀⠀⠀⠀⣨⡷⠶⢤⡀⠀⠀⠀⠀" << std::endl;
	file << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠚⠛⠓⠾⣄⠀⠀⢀⡴⠚⠛⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡿⠀⠀⠀⠀" << std::endl;
	file << " ⠀⠀⠀⠀⠀⠀⠀⠀⢼⡁⠀⠀⠀⠀⠀⠚⠉⠉⠛⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠾⠧⣄⠀⠀⠀" << std::endl;
	file << " ⠀⠀⠀⠀⠀⠀⣠⡴⠛⠉⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣧⡄⠀" << std::endl;
	file << " ⠀⠀⠀⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠤⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠟⠃⠀" << std::endl;
	file << " ⠀⠀⠀⠀⢰⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠈⢳⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠚⢧⡀⠀⠀" << std::endl;
	file << " ⠀⢀⡴⠚⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⢀⣼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡧⠀⠀" << std::endl;
	file << " ⢀⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⠢⠖⠚⣧⠀⠀⠀⠀⠀⠀⠀⠰⣤⣤⣤⡞⠁⠀⠀" << std::endl;
	file << " ⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠰⣦⣀⡀⢀⣠⠏⠀⠀⠀⠐⠶⠤⠴⠚⠁⠠⠿⠧⢤⡀⠀" << std::endl;
	file << " ⠙⣆⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹⠚⠻⡄⠉⣽⣄⣀⣠⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠆" << std::endl;
	file << " ⠀⢘⡷⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡗⢶⡏⠀⠀⠙⠶⠋⠈⠁⡞⢿⣀⠀⣀⠀⠀⠀⠀⠀⠀⠴⠴⣟⡁" << std::endl;
	file << " ⠀⢺⡀⠀⠀⢀⡄⠀⠀⠀⠀⠀⠀⠀⣤⣴⢿⣧⡀⢳⡀⠀⠀⠀⠀⠀⢰⠇⠀⣿⣿⣥⣠⣄⡀⠀⢀⠀⠀⠀⣽⡇" << std::endl;
	file << " ⠀⠀⠙⠦⠤⢾⠀⠀⠀⠀⣀⠀⠀⠀⠀⣻⣦⡿⠙⠛⠃⠀⠀⠀⠀⠀⣼⠀⣼⣯⡿⠛⠉⠿⠤⡤⠟⢣⡤⠿⠋⠁" << std::endl;
	file << " ⠀⠀⠀⠀⠀⠘⢦⣀⣀⣀⡼⠓⠒⠒⠚⠁⠈⠳⡄⠀⠀⠀⠀⠀⠀⢀⣿⣾⣿⠻⣄⣀⢀⡼⠦⣄⣀⣰⠇⠀⠀⠀" << std::endl;
	file << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⢸⣿⣰⠃⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠈⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢳⠀⠀⠀⠀⠀⠀⢹⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⠈⠀⠀⠀⠀⠀⠀⠈⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠶⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀⠘⢦⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⠛⠓⠒⠒⠒⠒⠒⠶⣤⣀⠀⠀⢶⣤⣀⣀⣀⣉⣙⣲⣦⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠒⠾⡇⠀⠈⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⣢⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file.close();
}

const char *ShrubberyCreationForm::GradeTooLowForExecutionException::what() const throw()
{
	return ("\033[0;31mThe grade is too low\033[0m");
}
const char *ShrubberyCreationForm::NotSignedException::what() const throw()
{
	return ("\033[0;31mThe form is not signed\033[0m");
}
const char *ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return ("\033[0;31mThe file did not open\033[0m");
}
