#pragma once
#include <iostream>
template <typename T> //template <typename T, typename FUNCTION>
void iter(T *array, int len, void (*func)(T &)) //void iter(T *array, int len, FUNCTION func) 
{
	for (int i = 0; i < len; i++)
		func(array[i]);
}

template <typename T>
void print(T &truc)
{
	std::cout << truc << " ";
}
