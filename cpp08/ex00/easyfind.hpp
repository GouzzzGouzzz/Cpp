#pragma once
#include <iostream>
#include <algorithm>

template<typename T>
bool easyfind(T cntr, int n)
{
	return (std::find(cntr.begin(), cntr.end(), n) != cntr.end());
}
