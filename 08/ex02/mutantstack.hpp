#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>

template<typename T>
class MutantStack : public std::stack<T> {

public:
	MutantStack();
	virtual ~MutantStack();
	MutantStack(const MutantStack &copy);
	MutantStack &operator= (const MutantStack &operand);

	class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
	private:
		T *ptr;
	public:
		iterator() : ptr(NULL) {};
		iterator(T *new_ptr) : ptr(new_ptr) {};
		iterator(const iterator& copy) : ptr(copy.ptr) {};
		iterator& operator=(const iterator &operand) {this->ptr = operand.ptr; return *this;};
		iterator& operator--() {--ptr;return *this;}
		iterator& operator++() {++ptr;return *this;}
		iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
		iterator operator--(int) {iterator tmp(*this); operator--(); return tmp;}
		bool operator==(const iterator& rhs) const {return ptr==rhs.ptr;}
		bool operator!=(const iterator& rhs) const {return ptr!=rhs.ptr;}
		T& operator*() {return *ptr;}
	};

	iterator begin();
	iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) :
	std::stack<T>(copy)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator= (const MutantStack &operand)
{
	std::stack<T>::operator=(operand);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() 
{
	return iterator(&(this->c.front()));
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() 
{
	iterator tmp(&this->c.back());
	tmp++;
	return tmp;
}

#endif