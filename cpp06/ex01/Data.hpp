#pragma once
#include <iostream>

class Data
{
private:
	int numbers;
	std::string name;
public:
	Data(std::string name, int numbers);
	Data(Data &copy);
	Data& operator=(const Data &copy);
	~Data();
	void getInfo();
};
