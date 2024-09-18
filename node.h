#include <iostream>
#include <string>
#include <fstream>
using std::ifstream;
using std::ofstream;
using namespace std;
template <typename T1, typename T2>
class Node
{
public: // Member functions
	Node(T1 Var1, T2 Var2);
	void setVar1(T1 Var1);
	void setVar2(T2 Var2);
	void setpNext(Node<T1, T2>* npNext);//set next node after current node
	T1 getVar1(void);//getters
	T2 getVar2(void);//getters
	Node<T1, T2>* getpNext(void);
	~Node();
private:
	T1 Var1;
	T2 Var2;
	bool correct;
	Node<T1, T2>* pNext;
};

template<typename T1, typename T2>
inline Node<T1, T2>::Node(T1 Var1, T2 Var2)
{
	this->Var1 = Var1;
	this->Var2 = Var2;
}

template<typename T1, typename T2>
inline void Node<T1, T2>::setVar1(T1 Var1)
{
	this->Var1 = Var1;
}

template<typename T1, typename T2>
inline void Node<T1, T2>::setVar2(T2 Var2)
{
	this->Var2 = Var2;
}

template<typename T1, typename T2>
inline void Node<T1, T2>::setpNext(Node<T1, T2>* npNext)
{
	Node<T1, T2>* pMem = new Node<T1, T2>(*npNext);
	this->pNext = pMem;
}

template<typename T1, typename T2>
inline T1 Node<T1, T2>::getVar1(void)
{
	return Var1;
}

template<typename T1, typename T2>
inline T2 Node<T1, T2>::getVar2(void)
{
	return Var2;
}

template<typename T1, typename T2>
inline Node<T1, T2>* Node<T1, T2>::getpNext(void)
{
	return pNext;
}

template<typename T1, typename T2>
inline Node<T1, T2>::~Node()
{
}
