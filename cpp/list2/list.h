#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cassert>

template<typename T>
class Node {

template<typename U>
friend class List;			//list의 멤버 함수가 Node의 private 함수에 접근 할 수 있다.
								// Node class는 linked list 만 쓸수 있다.
private:
   T data;
   Node<T> *next;

   Node(const T& data, Node<T> *next);
   
   // not used
   Node();
   Node(const Node<T>& );
};

template<typename T>
class List {

template<typename U>
friend std::ostream& operator<<(std::ostream& out, const List<U>& rhs);

private:
   Node<T> *ptr;
   
   void printList(std::ostream& out) const;
   
public:
   List();
   List(const List& rhs);
   ~List();
   
   List<T>& operator=(const List<T>& rhs);
   
   bool operator==(const List<T>& rhs) const;
   
   void insertFirstNode(const T& data);
   void insertNode(const T& prevData, const T& data);
   void deleteNode(const T& data);

};

template<typename T>
Node<T>::Node(const T& data, Node<T> *n)
: data(data), next(n)
{

}

template<typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& rhs)
{
	rhs.printList(out);
	
	return out;
	
}

template<typename T>
void List<T>::printList(std::ostream& out) const
{
	Node<T> *ptr = this->ptr->next;
	
	out << "[";
	while (ptr) {
		out << ptr->data;
		out << ( (ptr->next) ? "," : "");
		
		ptr = ptr->next;
	}
	out << "]";
}

template<typename T>
List<T>::List()
{
   this->ptr = new Node<T>(-1, NULL);
   assert(this->ptr);
}

template<typename T>
List<T>::List(const List<T>& rhs)
{
	this->ptr = new Node<T>(-1, NULL);
	assert(this->ptr);
   
   Node<T> *p = rhs.ptr->next;
   Node<T> *p2 = this->ptr;
	
	while (p) {
		p2->next = new Node<T>(p->data, NULL);
      assert(p2->next );
		p = p->next;
      p2 = p2->next;
	}
}

template<typename T>
List<T>::~List()
{
   Node<T> *p;
   p = this->ptr;
   
   while (p ) {
      Node<T> *tmp = p;
      p = p->next;
      
      delete tmp;
   }
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& rhs)
{
   if (this != &rhs){
   		Node<T> *p = this->ptr;
   		while (p) {
      		Node<T> *tmp = p;
      		p = p->next;

      		delete tmp;
      	}
   		this->ptr = new Node<T>(-1, NULL);			// dummy Node여서 의미없는 -1을 넣
		assert(this->ptr);
   
   		 p = rhs.ptr->next;
  		 Node<T> *p2 = this->ptr;
	
		while (p) {
			p2->next = new Node<T>(p->data, NULL);
      		assert(p2->next );
			p = p->next;
      		p2 = p2->next;
		}
  	}
}

template<typename T>
bool List<T>::operator==(const List<T>& rhs) const
{
	Node<T> *p = this->ptr->next;
	Node<T> *p2 = rhs.ptr->next;
	
	while(p) {
		if(p->data != p2->data) {
			break;
		}
		
		p = p->next;
		p2 = p2->next;
	}
	
	return (p == NULL);
}

template<typename T>
void List<T>::insertFirstNode(const T& data)
{
   Node<T> *tmp = new Node<T>(data, this->ptr->next);
   assert(tmp );
   this->ptr->next = tmp;   
}

template<typename T>
void List<T>::insertNode(const T& prevData, const T& data)
{
   Node<T> *p = this->ptr->next;
   while (p ) {
      if (p->data == prevData) 
         break;
      
      p = p->next;
   }
   
   if (p ) { //found
      Node<T> *tmp = new Node<T>(data, p->next);
      assert(tmp );
      p->next = tmp;
   }
}

template<typename T>
void List<T>::deleteNode(const T& data)
{
   Node<T> *p1 = this->ptr->next;
   Node<T> *p2 = this->ptr;
   
   while (p1 ) {
      if (p1->data == data)
         break;
         
      p1 = p1->next;
      p2 = p2->next;   
   }
   
   if (p1 ) {
      p2->next = p1->next;
      delete p1;
   }
}   
#endif
