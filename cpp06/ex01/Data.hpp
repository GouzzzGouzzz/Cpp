#pragma once
#include <iostream>

class Data
{
public:
	Data(std::string name, int numbers);
	Data(Data &copy);
	Data& operator=(const Data &copy);
	~Data();
	void getInfo();
private:
	int numbers;
	std::string name;
};
