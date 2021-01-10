/*  301330473 jzfeng Jeffrey Feng
**  a4.cpp
**  Assignment 4, CMPT-225
**
**  Reads a sequence of integers (in the range of int's) from standard in;
**  It is interpreted as two lists, separated by a single 0
**/
#include <iostream>
#include "heap.h"
#include "binary.h"

using namespace std;

int main(){
	
  int x;
  int y;
  cout << "301330473 jzfeng Jeffrey Feng" << endl;

  //READS INPUTS FOR FIRST LIST
  Heap List1;
  while(!cin.eof()){
    cin >> x;
    if(x == 0){
      break;
    }
	else{
      List1.insert(x,x);
    }
  }

  //READS INPUTS FOR SECOND LIST
  btree List2;
  while(!cin.eof()){
    cin >> y;
    List2.insert(y);
  }

  //SEARCHES IF A LARGEST ELEMENT IN LIST1 EXISTS IN LIST2
  while(!List1.empty()){
    int temp1 = List1.extractMax();
    node* temp2 = List2.search(temp1);
    if(temp2 == NULL){
      cout << temp1 << endl;
      return 0;
    }
  }

  //PRINTS NONE IF EMPTY/L1 IS DONE
  if(List1.empty()){
    cout << "NONE" << endl;
  }

  return 0;
}