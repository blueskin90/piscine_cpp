#include <iostream> 

	template <typename T>
void	iter(T *a, size_t size, void (*fn_ptr)(T *))
{
	if (fn_ptr != NULL)
	{
		for (size_t i = 0; i < size ; i++)
		{
			fn_ptr(a + i);
		}
	}
}

void	testfunc(int *ptr)
{
	*ptr = 42;
}

void	s_testfunc(char *a)
{
	*a += 1;
}

int		main(void)
{
	int array[3] = {150, -12, 254651};
	char s_array[3] = {'a', 'b', 'c'};

	for (int i = 0; i < 3; i++)
	{
		std::cout << array[i] << std::endl;
	}
	iter<int>(array, 3, NULL);
	for (int i = 0; i < 3; i++)
	{
		std::cout << array[i] << std::endl;
	}
	iter<int>(array, 3, testfunc);
	for (int i = 0; i < 3; i++)
	{
		std::cout << array[i] << std::endl;
	}


	for (int i = 0; i < 3; i++)
	{
		std::cout << s_array[i] << std::endl;
	}
	iter<char>(s_array, 3, NULL);
	for (int i = 0; i < 3; i++)
	{
		std::cout << s_array[i] << std::endl;
	}
	iter<char>(s_array, 3, s_testfunc);
	for (int i = 0; i < 3; i++)
	{
		std::cout << s_array[i] << std::endl;
	}
	return (1);
}
