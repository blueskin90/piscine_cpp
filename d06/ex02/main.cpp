#include <iostream>

class Base {
	public: 
		virtual ~Base(void) {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

void identify_from_pointer(Base *p)
{
	A	*castA = dynamic_cast<A*>(p);
	B	*castB = dynamic_cast<B*>(p);
	C	*castC = dynamic_cast<C*>(p);

	if (castA != NULL)
	{
		std::cout << "A" << std::endl;
		return;
	}
	if (castB != NULL)
	{
		std::cout << "B" << std::endl;
		return;
	}
	if (castC != NULL)
	{
		std::cout << "C" << std::endl;
		return;
	}
}

void identify_from_reference(Base &p)
{
	A	*castA = dynamic_cast<A*>(&p);
	B	*castB = dynamic_cast<B*>(&p);
	C	*castC = dynamic_cast<C*>(&p);

	if (castA != NULL)
	{
		std::cout << "A" << std::endl;
		return;
	}
	if (castB != NULL)
	{
		std::cout << "B" << std::endl;
		return;
	}
	if (castC != NULL)
	{
		std::cout << "C" << std::endl;
		return;
	}
}

int		main(void)
{
	Base *a = new A();
	Base *b = new B();
	Base *c = new C();
	
	identify_from_pointer(b);	
	identify_from_pointer(c);	
	identify_from_pointer(a);	

	identify_from_reference(*a);	
	identify_from_reference(*b);	
	identify_from_reference(*c);	


}
