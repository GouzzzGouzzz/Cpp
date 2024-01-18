#pragma once
#include <iostream>

template<class T>
class Array
{
public:
	class OOB : public std::exception
	{
		public :
			virtual const char* what() const throw()
			{
				return "Error : Index out of bounds !\n";
			}
	};
	Array()
	{
		std::cout << "Array created with default constructor\n";
		this->array = new T[0];
		this->len = 0;
	}
	Array(unsigned int n)
	{
		std::cout << "Array created with usigned int\n";
		this->array = new T[n];
		this->len = n;
	}
	Array& operator=(const Array &copy)
	{
		std::cout << "Array created by operator\n";
		if (this->array != NULL)
			delete [] this->array;
		this->len = copy.size();
		this->array = new T[copy.size()];
		for (int i = 0; (unsigned int)i < this->len; i++)
			this->array[i] = copy.array[i];
		return *this;
	}
	Array(const Array &copy) : array(NULL)
	{
		std::cout << "Array created by copy\n";
		*this = copy;
	}
	~Array()
	{
		std::cout << "Array destroyed\n";
		delete [] this->array;
	}
	T& operator[](unsigned int n)
	{
		if (n > this->len)
			throw Array::OOB();
		return this->array[n];
	}
	int size() const { return this->len; }
private:
	T *array;
	unsigned int len;
};


