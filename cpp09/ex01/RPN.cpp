#include "RPN.hpp"
#include <cstdlib>

RPN::RPN()
{

}

RPN::RPN(const RPN &copy)
{
	std::cout << "RPN created with copy constructor\n";
	(void) copy;
}

RPN& RPN::operator=(const RPN &copy)
{
	std::cout << "RPN created with operator constructor\n";
	(void) copy;
	return *this;
}

RPN::~RPN()
{

}

bool RPN::is_data(std::string str) const
{
	if (isdigit(str[0]))
		return true;
	if (str[0] == '-' || str[0] == '*' || str[0] == '/' || str[0] == '+')
		return true;
	return false;
}

bool RPN::parse(std::string data) const
{
	bool space_data = false; // false == need token, true = need space
	int digits = 0, tokens = 0;
	for (size_t i = 0; i < data.size(); i++)
	{
		if (space_data)
		{
			if (data[i] != ' ')
				return false;
			else
				space_data = !space_data;
		}
		else
		{
			if (is_data(&data[i]) == false)
				return false;
			else
				space_data = !space_data;
			if (isdigit(data[i]))
				digits++;
			else
				tokens++;
		}
	}
	if (digits - 1 != tokens)
		return false;
	return true;
}

float RPN::top_pop()
{
	int temp;
	temp = this->_data.top();
	this->_data.pop();
	return temp;
}

bool RPN::check_size(void) const
{
	if (this->_data.size() < 2)
	{
		std::cout << "ERROR" << std::endl;
		return false;
	}
	return true;
}

void RPN::calcul(std::string str)
{
	if (parse(str) == false){
		std::cout << "ERROR" << std::endl;
		return ;
	}
	bool output = true;
	float first, second, result;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (output == false)
			break;
		if (isdigit(str[i]))
			this->_data.push(atoi(str.substr(i,1).c_str()));
		else if (str[i] != ' ')
		{
			if (str[i] == '-')
			{
				if (check_size() == false)
				{
					output = false;
					break;
				}
				second = top_pop();
				first = top_pop();
				result = first - second;
				this->_data.push(result);
			}
			else if (str[i] == '+')
			{
				if (check_size() == false)
				{
					output = false;
					break;
				}
				second = top_pop();
				first = top_pop();
				result = first + second;
				this->_data.push(result);
			}
			else if (str[i] == '*')
			{
				if (check_size() == false)
				{
					output = false;
					break;
				}
				second = top_pop();
				first = top_pop();
				result = first * second;
				this->_data.push(result);
			}
			else
			{
				if (check_size() == false)
				{
					output = false;
					break;
				}
				second = top_pop();
				first = top_pop();
				if (second == 0) //dividing by zero
				{
					std::cout << "ERROR" << std::endl;
					output = false;
					break;
				}
				result = first / second;
				this->_data.push(result);
			}
		}
	}
	if (output == true)
		std::cout << this->_data.top() << std::endl;
}
