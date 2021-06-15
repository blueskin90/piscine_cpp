#include <iostream>

template <typename T>
void swap(T &a, T&b){
	T tmp = b;

	b = a;
	a = tmp;
}

template <typename T>
T const &min(T const &a, T const &b){
	return ((a < b) ? a : b);
}

template <typename T>
T const &max(T const &a, T const &b){
	return ((a > b) ? a : b);
}

int		main(void)
{
	int	a = 2;
	int b = 4;
	char c = 'c';
	char d = 'd';
	std::string hello = "Hello";
	std::string world = "World";

	std::string hella = "Hella";

	std::cout << " MAIN 42 " << std::endl;
int e = 2;
int f = 3;
::swap( e, f );
std::cout << "e = " << e << ", f = " << f << std::endl;
std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
std::string g = "chaine1";
std::string h = "chaine2";
::swap(g, h);
std::cout << "g = " << g << ", h = " << h << std::endl;
std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;


	std::cout << "SWAP TEST" << std::endl;
	std::cout << a << " " << b << std::endl;
	swap<int>(a, b);
	std::cout << a << " " << b << std::endl;

	std::cout << c << " " << d << std::endl;
	swap<char>(c, d);
	std::cout << c << " " << d << std::endl;


	std::cout << hello << " " << world << std::endl;
	swap<char>(hello, world);
	std::cout << hello << " " << world << std::endl;

	std::cout << "MIN TEST" << std::endl;
	std::cout << ::min<int>(a, b) << std::endl;
	std::cout << ::min<char>(c, d) << std::endl;
	std::cout << ::min<std::string>(hello, world) << std::endl;
	std::cout << ::min<std::string>(hello, hella) << std::endl;

	std::cout << "MAX TEST" << std::endl;
	std::cout << ::max<int>(a, b) << std::endl;
	std::cout << ::max<char>(c, d) << std::endl;
	std::cout << ::max<std::string>(hello, world) << std::endl;
	std::cout << ::max<std::string>(hello, hella) << std::endl;

	return (1);
}
