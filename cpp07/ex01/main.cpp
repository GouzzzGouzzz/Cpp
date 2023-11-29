#include "iter.hpp"

int main()
{
	int tab[10] = {0,1,2,3,4,5,6,7,8,9};
	int len = 10;
	iter(tab,len,&add);
}
