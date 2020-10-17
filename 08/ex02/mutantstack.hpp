#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T> {

public:
	MutantStack();
	virtual ~MutantStack();
	MutantStack(const MutantStack &copy);
	MutantStack &operator= (const MutantStack &operand);

private:

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

// template <typename T>
// class MutantStackIterator {

// public:
// 	MutantStackIterator();
// 	~MutantStackIterator();
// 	MutantStackIterator(const MutantStackIterator &copy);
// 	MutantStackIterator &operator= (const MutantStackIterator &operand);

// private:
// 	MutantStack<T> &ms;

// };


#include <iterator>     // std::iterator, std::input_iterator_tag
template <typename T>
class MutantStackIterator : public std::iterator<std::input_iterator_tag, T>
{
  int* p;
public:
  MutantStackIterator();
  MutantStackIterator(const MutantStackIterator& copy);
  MutantStackIterator& operator++() {++p;return *this;}
  MutantStackIterator operator++(int) {MutantStackIterator tmp(*this); operator++(); return tmp;}
  bool operator==(const MutantStackIterator& rhs) const {return p==rhs.p;}
  bool operator!=(const MutantStackIterator& rhs) const {return p!=rhs.p;}
  int& operator*() {return *p;}
};

#endif