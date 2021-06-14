#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

struct RealData {
	char s1[8];
	int n;
	char s2[8];
};

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void* serialize(void)
{
	RealData *data = new RealData();

	strcpy(data->s1, "1111111");
	for (int i = 0; i < 8; i++)
	{
		data->s1[i] = static_cast<char>(rand() % ('~' - ' ') + ' ');
		data->s2[i] = static_cast<char>(rand() % ('~' - ' ') + ' ');
	}
	data->n = rand();
	return (static_cast<void*>(data));
}


Data* deserialize(void *raw)
{
	Data *data = new Data();
	RealData *realData = reinterpret_cast<RealData*>(raw);

	data->s1.assign(realData->s1, 8);
	data->n = realData->n;
	data->s2.assign(realData->s2, 8);
	return (data);
}


int		main(void)
{
	srand(time(NULL));
	void* test = serialize();
	Data *result  = deserialize(test);

	
	std::cout <<"'"<< result->s1 <<"'"<< std::endl; 
	std::cout.write(static_cast<const char*>(test), 8);
	std::cout << std::endl;
	std::cout << result->n << std::endl;
	std::cout << *reinterpret_cast<int*>(static_cast<char*>(test) + 8) << std::endl;
	std::cout << "'" << result->s2 <<"'" << std::endl;
	std::cout.write(static_cast<const char*>(test) + 8 * sizeof(char) + 1 * sizeof(int), 8);
	std::cout << std::endl;
	return (0);
}
