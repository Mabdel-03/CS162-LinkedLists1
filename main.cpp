/* Code Written By Mahmoud Abdelmoneum
 * Code Written On 4/11/2021
 * Linked Lists 1 replicates the student list project, but uses a linear linked list to store data
 */

#include <iostream>
#include "node.h"
#include <cstring>
using namespace std;

//add and print function prototypes
void addStudent(Node* &head);
void print(Node* &head);


//add a new student to linked list
void addStudent(Node* &head){
  char firstName[50];
  char lastName[50];
  int id = 0;
  float gpa = 0.00;
  Student* student = new Student();
  
  cout << "Enter the first name of student. " << endl;
  cout << " > "; //prompt input
  cin.get(firstName, 50);
  cin.get();
  student->setFirstName(firstName);
  cout << "Enter the last name of student. " << endl;
  cout << " > "; //prompt input
  cin.get(lastName, 50);
  cin.get();
  student->setLastName(lastName);
  cout << "Enter the student ID of the student. " << endl;
  cout << " > "; //prompt input
  cin >> id;
  cin.get();
  student->setID(id);
  cout << "Enter the GPA of the student. " << endl;
  cout << " > "; //prompt input
  cin >> gpa;
  cin.get();
  student->setGPA(gpa);
  
  //add into node
  Node* current = head;

  //first pass thru, no nodes yet
  if(current == NULL){
    head = new Node(student);
    head->setStudent(student);
    head->setNext(NULL); 
  }
  else {
    current = head;
    while(current->getNext() != NULL){
      current = current->getNext(); //traverse through by setting current to next
    }
    current->setNext(new Node(student));
    current->getNext()->setNext(NULL);
  }
}

//print out list
void print(Node* &head){
  Node *ptr = head;
  Student *studentPtr = NULL;

  if(ptr != NULL){
    studentPtr = ptr->getStudent();
    cout << studentPtr->getFirstName() << " " << studentPtr->getLastName()
	 << ", " << studentPtr->getID() << ", " << studentPtr->getGPA() << endl;
    ptr = ptr->getNext();
    print(ptr);
  }
}


int main(){

  Node* head = NULL; //beginning of list
  char input[10]; //holds either add or print currently
  cout << "Welcome to (Linked) StudentList. " << endl;
  cout << "To add a student, type 'ADD'." << endl;
  cout << "To print out list, type 'PRINT'." << endl;
  cout << "To quit, type 'QUIT'." << endl;

  //while they havent quit..
  while(strcmp(input, "QUIT") != 0){
    cout << "Enter a command (ADD/PRINT/QUIT)" << endl;
    cout << " > "; //prompt user again
    cin.get(input, 10);
    cin.get();

    //make to uppercase
    for(int i = 0; i < strlen(input); i++){
      input[i] = toupper(input[i]);
    }

    //call respective functions
    if(strcmp(input, "ADD") == 0){
      addStudent(head);
    }
    else if(strcmp(input, "PRINT") == 0){
      print(head);
      
    }
  }
  cout << "Now quitting. Goodbye! " << endl;
}

