#include <iostream>

template <typename T>
class Array{
	public:
		class IndexOutOfBoundsException: public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return ("Array index out of bounds.");
				}
		};

		Array<T>(unsigned int n = 0): _size(n), _array(new T[n]())
		{
		}

		Array<T>(Array<T> const &src) : _size(src.size()), _array(new T[_size]())
		{
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src[i];
		}

		Array<T> & operator=(Array<T> const & rhs)
		{
			if (this != &rhs)
			{
				delete [] this->_array;
				this->_size = rhs.size();
				this->_array = new T[rhs.size()]();
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = rhs[i];
			}
			return (*this);
		}

		~Array<T>()
		{
			delete [] this->_array;
		}

		T &operator[](unsigned int i) const 
		{
			if (i >= this->_size)
				throw (IndexOutOfBoundsException());
			return (this->_array[i]);
		}

		unsigned int size() const
		{
			return (this->_size);
		}	

	private:
		unsigned int	_size;
		T				*_array;
};
