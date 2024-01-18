#pragma once

#include <iostream>
#include <stack>

class RPN
{
public:
	RPN();
	RPN(const RPN &copy);
	RPN& operator=(const RPN &cpy);
	~RPN();
	void calcul(std::string str);
private:
	std::stack<int> _data;
	int top_pop();
	bool parse(std::string data) const;
	bool is_data(std::string str) const;
};
