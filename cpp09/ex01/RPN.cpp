#include "RPN.hpp"


// Constructor & Destructor
RPN::RPN(const std::string &recup_argv)
{
	// lire la chaine de character et la parser
	// en fonction du parse ajouter a la stack / faire l'operation

	std::stringstream ss(recup_argv);
	std::string token;
	int num;

	while (std::getline(ss, token, ' '))
	{
		if ((token.length() == 1 && isdigit(token[0])) || (token.length() == 2 && token[0] == '-' && isdigit(token[1])))
		{
			std::stringstream(token) >> num;
			_stack.push(num);
		}
		else if (token == "+")
		{
			int a;
			int b;
			if (this->_stack.size() < 2)
				throw StackEmptyException();
			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			_stack.push(b + a);
		}
		else if (token == "-")
		{
			int a;
			int b;
			if (this->_stack.size() < 2)
				throw StackEmptyException();
			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			_stack.push(b - a);
		}
		else if (token == "*")
		{
			int a;
			int b;
			if (this->_stack.size() < 2)
				throw StackEmptyException();
			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			_stack.push(b * a);
		}
		else if (token == "/")
		{
			int a;
			int b;
			if (this->_stack.size() < 2)
				throw StackEmptyException();
			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			_stack.push(b / a);
		}
		else
			throw InvalidArgumentException();
	}
}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
	{
		this->_stack = copy._stack;
	}
	return (*this);
}

RPN::~RPN(void)
{
}


// Other function
int RPN::getResult(void) const
{
	if (this->_stack.empty() == true)
		throw StackEmptyException();
	if (this->_stack.size() > 1)
		throw StackTooHighException();
	return (this->_stack.top());
}
