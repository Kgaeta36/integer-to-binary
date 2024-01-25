/**********************************************************
 * Queue implementation with a static array.
 * Original code: https://cs.calvin.edu/activities/books/c++/ds/2e/SourcePrograms/Chap08/Figure8.2/
 * Updated by Dr. Byun for CST238.
 * Basic operations:
 *   Constructor: Constructs an empty queue
 *   empty:       Checks if a queue is empty
 *   enqueue:     Modifies a queue by adding a value at the back
 *   front:       Accesses the front queue value; leaves queue unchanged
 *   dequeue:     Modifies a queue by removing the value at the front
 *   display:     Displays the queue elements from front to back
 *
 **********************************************************/ 

/*** 
Title: HW04-2.cpp
Abstract: This program will be practice for adding methods into a queue.
Author: Kimberly Gaeta
Email: Kgaeta@csumb.edu
Date: 2/20/23
Estimate: 3 hours
  ****/
#include <iostream>
using namespace std;

const int QUEUE_CAPACITY = 7;
typedef char QueueElement;

class Queue
{
public:
    Queue();
    bool empty() const;
    void enqueue(QueueElement value);
    void display() const;
    QueueElement front() const;
    void dequeue();
    void printPrivateInfo();
/****
  -----HW04-2 Methods Below-----
****/
    bool isSorted() const;
    bool drop(QueueElement value);
    bool indexUsed(int index) const;
    void dump() const;

private:
    int myFront;
    int myBack;
    QueueElement myArray[QUEUE_CAPACITY];
}; // end of class declaration


//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}


//--- Definition of empty()
bool Queue::empty() const
{ 
    return (myFront == myBack); 
}

void Queue::printPrivateInfo() {
    cout << "myFront: " << myFront << endl;
    cout << "myBack: " << myBack << endl;
    cout << "Elements: " << endl;
    for (int i = 0; i < QUEUE_CAPACITY; i++) {
        cout << "\t" << i << ": " << myArray[i] << endl;
    }
}


//--- Definition of enqueue()
void Queue::enqueue(QueueElement value)
{
    int newBack = (myBack + 1) % QUEUE_CAPACITY;
    if (newBack != myFront)     // queue isn't full
    { 
        myArray[myBack] = value;
        myBack = newBack;
    }
    else
    {
        cerr << "*** Queue full -- can't add new value ***\n"
            "Must increase value of QUEUE_CAPACITY.\n";
    }
}


//--- Definition of display()
void Queue::display() const
{
    for (int i = myFront; i != myBack; i = (i + 1)%QUEUE_CAPACITY) 
    {
        cout << myArray[i] << "  ";
    }
    cout << endl;
}


//--- Definition of front()
QueueElement Queue::front() const
{
    if ( !empty() ) 
    {
        return (myArray[myFront]);
    }
    else
    {
        cerr << "*** Queue is empty -- returning garbage value ***\n";
        QueueElement garbage;
        return garbage;
    }
}


//--- Definition of dequeue()
void Queue::dequeue()
{
    if ( !empty() )
    {
        myFront = (myFront + 1) % QUEUE_CAPACITY;
    }
    else
    {
        cerr << "*** Queue is empty -- "
            "can't remove a value ***\n";
    }
}
/****
    -----HW04-2 Definitions Below-----
  ****/

// definition of is sorted :(((
bool Queue::isSorted() const{
  if (empty()){
    return true;
    }
  if (myArray[myFront] < myArray[(myFront+1)%QUEUE_CAPACITY]){
     //cout << int(myArray[myFront]) << " " << int(myArray[(myFront+1)%QUEUE_CAPACITY]) << "\n";
      for (int i = myFront; i != myBack - 1; i = (i+1)%QUEUE_CAPACITY){
      if (int(myArray[i]) > int(myArray[i+1])){
        cout << "Queue is not sorted in any order!\n";
        return false;
     }
   } 
    cout << "Queue is sorted is ascending order!\n";
    return true;
   } else if (myArray[myFront] > myArray[(myFront+1)%QUEUE_CAPACITY]){
      //cout << int(myArray[myFront]) << " " << int(myArray[(myFront+1)%QUEUE_CAPACITY]) << "\n";
      for (int i = myFront; i != myBack - 1; i = (i+1)%QUEUE_CAPACITY){
      if (int(myArray[i]) < int(myArray[i+1])){
        cout << "Queue is not sorted in any order!\n";
        return false;
     }
   } 
    cout << "Queue is sorted is decending order!\n";
    return true;
  }
}
// Definition of drop() WORKS!!
bool Queue::drop(QueueElement value){
  Queue temp;
  for (int i = myFront; i != myBack; i = (i + 1)%QUEUE_CAPACITY){
    temp.myArray[i] = myArray[i];
  }
  for (int i = myFront; i != myBack; i = (i + 1)%QUEUE_CAPACITY){
    if (myArray[i] == value){
      for (int k = i; k != myBack; k = (k+1)%QUEUE_CAPACITY){
        myArray[k] = temp.myArray[(k+1)%QUEUE_CAPACITY];
      }
      myBack = (myBack-1)%QUEUE_CAPACITY;
      return true;
    }
  }
  cout << "Value was not found in the Queue!\n";
  return false;
}
// Definition of indexUsed WORKS!!!
bool Queue::indexUsed (int index) const{
  if (myFront > myBack){
    if ((myBack - 1)%QUEUE_CAPACITY >= index || myFront <= index){
      return true;
    } else {
      return false;
    }
  } else {
    if (myFront <= index && index < myBack){
      return true;
    } else {
      return false;
    }
  }
}
// Definition of dump WORKS!!
void Queue::dump() const{
  cout << "myFront: " << myFront << "\n";
  cout << "myBack: " << myBack << "\n";
  for (int i = 0; i < QUEUE_CAPACITY; i++){
    if (indexUsed(i)){
      cout << myArray[i] << " ";
    } else {
      cout << "_ ";
    }
  }
}

int main()
{
    // Queue q1;
    // cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;

    // cout << "How many elements to add to the queue? ";
    // int numItems;
    // cin >> numItems;
    // for (int i = 1; i <= numItems; i++) 
    //     q1.enqueue(100*i);

    // cout << "Contents of queue:\n";
    // q1.display(); 
    // cout << "Queue q1 empty? " << q1.empty() << endl;

    // cout << "\nFront value in q1: " << q1.front() << endl << endl;

    // while (!q1.empty())
    // {
    //     cout << "Remove front -- Queue contents: ";
    //     q1.dequeue();
    //     q1.display();
    // }
    // cout << "\nQueue q1 empty? " << q1.empty() << endl;
    // cout << "Now try to retrieve front value in q1" << endl;
    // cout << "Front value in q1?" << endl << q1.front() << endl;
    // cout << "\nNow Try to remove front of q1: " << endl;
    // q1.dequeue();
    Queue myQueue;
    myQueue.enqueue('H');
    myQueue.enqueue('F');
    myQueue.enqueue('D');
    myQueue.enqueue('C');
    myQueue.enqueue('B');
    myQueue.enqueue('A');
    myQueue.display();
    cout << "Checking if queue is sorted in order!\n\t";
    myQueue.isSorted();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.enqueue('A');
    myQueue.enqueue('B');
    myQueue.enqueue('C');
    myQueue.display();
    cout << "Checking if queue is sorted in order!\n\t";
    myQueue.isSorted();
    myQueue.printPrivateInfo();
    cout << "Dropping the value D from the queue!\n\t";
    myQueue.drop('D');
    cout << "Dropping the value B from the queue!\n\t";
    myQueue.drop('B');
    myQueue.display();
    myQueue.printPrivateInfo();
    cout << "Checking if index 5 is in use!\n\t" << boolalpha
      << myQueue.indexUsed(5) << "\n";
    myQueue.dump();
  
}

