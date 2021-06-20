#include <iostream> 

template <typename T>
void	iter(T *a, size_t size, void (*fn_ptr)(T &))
{
	if (!a)
		return;
	if (fn_ptr != NULL)
	{
		for (size_t i = 0; i < size ; i++)
		{
			fn_ptr(*(a + i));
		}
	}
}

template <typename T>
void	ft_set(T &ref)
{
	ref = 42;
}

template <typename T>
void	print(T &a)
{
	std::cout << a << std::endl; 
}

int		main(void)
{
	int array[3] = {150, -12, 254651};
	char s_array[3] = {'a', 'b', 'c'};

	iter<int>(NULL, 10, NULL);
	std::cout << "NULL TEST DONE" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << array[i] << std::endl;
	}
	iter<int>(array, 3, NULL);
	for (int i = 0; i < 3; i++)
	{
		std::cout << array[i] << std::endl;
	}
	iter<int>(array, 3, ft_set);
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
	std::cout << "last test with print" << std::endl;
	iter<char>(s_array, 3, print);
	return (1);
}
