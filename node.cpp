#include <iostream>
#include "node.h"
using namespace std;

//get next node
Node* Node::getNext(){
  return next;
  
}

//set next node
void Node::setNext(Node* node){
  next = node;
  
}

void Node::setStudent(Student *inputStudent){
  studentPtr = inputStudent;

}

Student* Node::getStudent(){
  return studentPtr;
}


//constructor
Node::Node(Student* inputStudent){
  studentPtr = inputStudent;

}

//destructor
Node::~Node(){
  delete studentPtr;
}

