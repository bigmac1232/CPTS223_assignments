#include "node.h"




// Template class: the node in the linked list


// Define the linked list class
template <typename T1, typename T2>
class LinkedList {
public:
	
	void setpRoam(Node<T1, T2> npRoam);

	void setpHead(Node<T1, T2> npHead);
	Node<T1, T2>* getpHead(void);//getters
	Node<T1, T2>* getpRoam(void);//getters
	void createlist(ifstream& input);
	void outputtofile(ofstream& output);
private:

	Node<T1, T2>* pHead;
	Node<T1, T2>* pRoam;

	


};

template<typename T1, typename T2>
inline void LinkedList<T1, T2>::setpRoam(Node<T1, T2> npRoam)
{
	
	pRoam = &npRoam;
}

template<typename T1, typename T2>
inline void LinkedList<T1, T2>::setpHead(Node<T1, T2> npHead)
{
	
	
	pHead = &npHead;
}

template<typename T1, typename T2>
inline Node<T1, T2>* LinkedList<T1, T2>::getpHead(void)
{
	return pHead;
}

template<typename T1, typename T2>
inline Node<T1, T2>* LinkedList<T1, T2>::getpRoam(void)
{
	return pRoam;
}

template<typename T1, typename T2>
inline void LinkedList<T1, T2>::createlist(ifstream& input)
{
	Node<T1, T2> n = {};
	std::string p = "0000000000000";
	while (!input.eof)
	{
		std::getline(input, p, ',');
		n.setVar1(p);
		std::getline(input, p, ',');
		n.setVar2(p);
		this->setpRoam(n);
		if (this->getpHead == nullptr)
		{
			this->setpHead(this->getpRoam());
		}
		this->setpRoam(this->pRoam->getpNext());
	}
}

template<typename T1, typename T2>
inline void LinkedList<T1, T2>::outputtofile(ofstream& output)
{

	this->pRoam = this->pHead;

	while (this->pRoam->getpNext() != nullptr)
	{
		output << this->pRoam->getVar1()<<",";
		output << this->pRoam->getVar2() << endl;
		this->pRoam = this->pRoam->getpNext();
	}








}






