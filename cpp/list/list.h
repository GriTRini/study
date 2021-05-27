#ifndef LIST_H
#define LIST_H
#include <iostream>

class Node {
friend class List;			//list의 멤버 함수가 Node의 private 함수에 접근 할 수 있다.
								// Node class는 linked list 만 쓸수 있다.
private:
   int data;
   Node *next;
   
   Node();
   Node(int data, Node *next);
   Node(const Node& );
};

class List {
friend std::ostream& operator<<(std::ostream& out, const List& rhs);

private:
   Node *ptr;
   
   void printList(std::ostream& out) const;
   
public:
   List();
   List(const List& rhs);
   ~List();
   
   List& operator=(const List& rhs);
   
   bool operator==(const List& rhs) const;
   
   void insertFirstNode(int data);
   void insertNode(int prevData, int data);
   void deleteNode(int data);

};

#endif
