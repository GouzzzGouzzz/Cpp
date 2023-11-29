template <typename T>
void iter(T addr[], T& len, T *func)
{
	for (int i = 0; i < len; i++)
		func(addr[i]);
}

