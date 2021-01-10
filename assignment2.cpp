//============================================================================
// Name        : LinkedStack.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <cstdlib>
#include <iostream>
#include <string>
using std::string;
using namespace std;



class StringNode {				        // a node in a list of strings
private:
  string elem;				                // element value
  StringNode* next;				        // next item in the list

  friend class StringLinkedList;		        // provide StringLinkedList access
};

class StringLinkedList {			        // a linked list of strings
public:
  StringLinkedList();				        // empty list constructor
  ~StringLinkedList();			                // destructor
  bool empty() const;				        // is list empty?
  const string& front() const;		                // get front element
  void addFront(const string& e);		        // add to front of list
  void removeFront();				        // remove front item list
private:
  StringNode* head;				        // pointer to the head of list
};

StringLinkedList::StringLinkedList()			// constructor
  : head(NULL) { }

StringLinkedList::~StringLinkedList()			// destructor
  { while (!empty()) removeFront(); }

bool StringLinkedList::empty() const			// is list empty?
  { return head == NULL; }

const string& StringLinkedList::front() const		// get front element
  { return head->elem; }



void StringLinkedList::addFront(const string& e) {	// add to front of list
  StringNode* v = new StringNode;			// create new node
  v->elem = e;					        // store data
  v->next = head;					// head now follows v
  head = v;						// v is now the head
}



void StringLinkedList::removeFront() {		        // remove front item
  StringNode* old = head;				// save current head
  head = old->next;					// skip over old head
  delete old;						// delete the old head
}


typedef string Elem;				        // stack element type
    class LinkedStack {				        // stack as a linked list
    public:
      LinkedStack();				        // constructor
      int size() const;				        // number of items in the stack
      bool empty() const;			        // is the stack empty?
      const Elem& top() const;	                        // the top element
      void push(const Elem& e);  		        // push element onto stack
      void pop();		                        // pop the stack
    private:                                	        // member data
      StringLinkedList S;			        // linked list of elements
      int n;					        // number of elements
};

LinkedStack::LinkedStack()
    : S(), n(0) { }				        // constructor

  bool LinkedStack::empty() const
    { return n == 0; }				        // is the stack empty?



const Elem& LinkedStack::top() const {
    return S.front();
}

void LinkedStack::push(const Elem& e) {	        // push element onto stack
    ++n;
    S.addFront(e);
}
						        // pop the stack
void LinkedStack::pop() {
	--n;
    S.removeFront();
}

int LinkedStack::size() const {
    return n;
}

int main() {
	cout << "Jeffrey Feng" << endl << "jzfeng" << endl << "301330473" << endl;

	StringLinkedList test;
	LinkedStack original;
	string input;
	string rever;
	bool flag = 1;
	while(flag){
        getline(cin, input);
        if(input == ""){
            flag = 0;
        }
        else{
            test.addFront(input);
        }
	}
	while(!test.empty()){
        rever += test.front();
        original.push(test.front());
        test.removeFront();
	}
	cout << "" << endl;
	cout << original.size() << endl;
	cout << rever << endl;
	cout << "" << endl;
	while(!original.empty()){
        cout << original.top() << endl;
        original.pop();
	}
	cout << "goodbye" << endl;
	return EXIT_SUCCESS;

  }
