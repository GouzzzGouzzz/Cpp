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
	std::stack<float> _data;
	float top_pop();
	bool check_size(void) const;
	bool parse(std::string data) const;
	bool is_data(std::string str) const;
};
