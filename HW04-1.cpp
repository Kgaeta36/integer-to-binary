#include <iostream>
using namespace std;
/***
Title: HW04-1.cpp
Abstract: This program will take in a positive integer and convert it into
binary. Author: Kimberly Gaeta Email: Kgaeta@csumb.edu Date: 2/19/2023 Estimate:
1 hour
  ***/
const int STACK_CAPACITY = 128;
typedef int StackElement;
class Stack {
public:
  Stack() { 
    myTop = -1;
    }
  bool empty() const { 
    return (myTop == -1); 
    }
  void reset(){
    myTop = -1;
  }
  void push(StackElement value);
  void display() const;
  void converter(int value);
private:
  StackElement myArray[STACK_CAPACITY];
  int myTop;
};
int main() { 
  Stack s;
  int input;
  do {
    s.reset();
    cout << "Enter a number: ";
    cin >> input;
    if (input <= 0){
      break;
    }
    s.converter(input);
    cout << input << " => ";
    s.display();
    cout << "\n";
    
  } while (input > 0);
  cout << "Exiting";
}
void Stack::push (StackElement value){
  if (myTop < STACK_CAPACITY - 1){
    ++myTop;
    myArray[myTop] = value;
  } else {
    cerr << "***Stack Full!!!***\n";
    return;
  }
}
void Stack::display() const{
  for (int i = myTop; i >= 0; i--){
   cout << myArray[i] ;
  }
}
void Stack::converter(int value){
  while (value != 0){
    if (value%2 == 1){
      push(1);
    } else {
      push(0);
    }
    value = value/2;
  }
}