#ifndef PONY_HPP
# define PONY_HPP

class Pony {
	private:
		static int	destructor_called;
		static int	constructor_called;
	public:
		int	legs;
		Pony(void);
		~Pony(void);
		static void show_alloc(void);
};

#endif
