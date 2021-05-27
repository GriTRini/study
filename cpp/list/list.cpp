#include <cassert>
#include "list.h"

Node::Node(int d, Node *n)
: data(d), next(n)
{

}

std::ostream& operator<<(std::ostream& out, const List& rhs)
{
	rhs.printList(out);
	
	return out;
	
}

void List::printList(std::ostream& out) const
{
	Node *ptr = this->ptr->next;
	
	out << "[";
	while (ptr) {
		out << ptr->data;
		out << ( (ptr->next) ? "," : "");
		
		ptr = ptr->next;
	}
	out << "]";
}

List::List()
{
   this->ptr = new Node(-1, NULL);
   assert(this->ptr);
}

List::List(const List& rhs)
{
	this->ptr = new Node(-1, NULL);
	assert(this->ptr);
   
   Node *p = rhs.ptr->next;
   Node *p2 = this->ptr;
	
	while (p) {
		p2->next = new Node(p->data, NULL);
      assert(p2->next );
		p = p->next;
      p2 = p2->next;
	}
}

List::~List()
{
   Node *p;
   p = this->ptr;
   
   while (p ) {
      Node *tmp = p;
      p = p->next;
      
      delete tmp;
   }
}

List& List::operator=(const List& rhs)
{
   if (this != &rhs){
   		Node *p = this->ptr;
   		while (p) {
      		Node *tmp = p;
      		p = p->next;

      		delete tmp;
      	}
   		this->ptr = new Node(-1, NULL);			// dummy Node여서 의미없는 -1을 넣
		assert(this->ptr);
   
   		 p = rhs.ptr->next;
  		 Node *p2 = this->ptr;
	
		while (p) {
			p2->next = new Node(p->data, NULL);
      		assert(p2->next );
			p = p->next;
      		p2 = p2->next;
		}
  	}
}

bool List::operator==(const List& rhs) const
{
	Node *p = this->ptr->next;
	Node *p2 = rhs.ptr->next;
	
	while(p) {
		if(p->data != p2->data) {
			break;
		}
		
		p = p->next;
		p2 = p2->next;
	}
	
	return (p == NULL);
}

void List::insertFirstNode(int data)
{
   Node *tmp = new Node(data, this->ptr->next);
   assert(tmp );
   this->ptr->next = tmp;   
}

void List::insertNode(int prevData, int data)
{
   Node *p = this->ptr->next;
   while (p ) {
      if (p->data == prevData) 
         break;
      
      p = p->next;
   }
   
   if (p ) { //found
      Node *tmp = new Node(data, p->next);
      assert(tmp );
      p->next = tmp;
   }
}

void List::deleteNode(int data)
{
   Node *p1 = this->ptr->next;
   Node *p2 = this->ptr;
   
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
