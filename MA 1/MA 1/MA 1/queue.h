#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity of the queue
#define SIZE 10

class queue
{
private:
    int* arr;		// array to store queue elements
    int capacity;	// maximum capacity of the queue
    int front;		// front points to front element in the queue (if any)
    int rear;		// rear points to last element in the queue
    int count;		// current size of the queue

public:
    queue(); 	// constructor
    ~queue();   				// destructor

    void dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

// Constructor to initialize queue
queue::queue()
{
    arr = new int[SIZE];
    capacity = SIZE;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to the queue
queue::~queue()
{
    delete arr; // you are not required to test this function;
    // however, are there issues with it?
}

// Utility function to remove front element from the queue
void queue::dequeue()
{
    /* Test ID: check for front element remove - CFR
Unit: queue::dequeue ()
Description: check to see if dequeue removes front queue
Test steps:
1. Construct a non empty queue object
2. Invoke queue::dequeue ()
3. evaluate whether the front node is empty
Test data: arr[front]=arr[front+1]
Precondition: queue not empty
Postcondition: front of queue = second in queue
Expected result: front of queue destructed and replaced with second in queue
Actual result: front of queue destructed and replaced with second in queue
Status: passed
    */
    // check for queue underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        return;
    }
    else {
        cout << "Removing " << arr[front] << endl;

        front = (front + 1);
        count--;
    }
}

// Utility function to add an item to the queue
void queue::enqueue(int item)
{
    /* Test ID: check for element added at end - CEA
Unit: queue::enqueue ()
Description: check to see if enqueue adds to end of queue
Test steps:
1. Construct a queue object
2. Invoke queue::enqueue ()
3. evaluate whether the rear node is equal to int item 
Test data: arr[rear]=item
Precondition: queue not full
Postcondition: end of queue = item and count + 1
Expected result: item added to end of queue
Actual result: item added to end of queue
    */
    // check for queue overflow
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        return;
    }
    else 
    {
        cout << "Inserting " << item << '\n';

        rear = (rear + 1);
        arr[rear] = size();
        count++;
    }
}

// Utility function to return front element in the queue
int queue::peek()
{
    /* Test ID: check for returned front - CRF
Unit: queue::peek ()
Description: return front of queue
Test steps:
1. Construct a queue object
2. Invoke queue::peek ()
3. evaluate whether the node returned is the front node
Test data: front of queue has been returned
Precondition: queue not empty
Postcondition: front of queue returned
Expected result: front of queue peeked
Actual result: front of queue peeked
    */
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        return numeric_limits<int>::min();
    }
    return arr[front];
}

// Utility function to return the size of the queue
int queue::size()
{
    /* Test ID: check for correct size - CRF
Unit: queue::size ()
Description: return size of queue
Test steps:
1. Construct a queue object
2. Invoke queue::size ()
3. evaluate whether the node size returned is correct
Test data: size 10 has been returned
Precondition: queue size bigger than or equal to 0
Postcondition: size of queue returned
Expected result:  size 10 has been returned
Actual result: size 10 has been returned
*/
    return count;
}

// Utility function to check if the queue is empty or not
bool queue::isEmpty()
{
   /*Test ID : Empty queue check - EQC
        Unit : queue::isEmpty()
        Description : test to determine if queue::isEmpty() returns 1 if a queue object
        is empty.
        Test steps :
    1. Construct an empty queue object
        2. Invoke queue::isEmpty()
        3. Conditionally evaluate the value returned by queue::isEmpty()
        Test data : size = 0
        Precondition : queue object is empty
        Postcondition : queue object is still empty
        Expected result : queue is empty; 1 is returned
        Actual result : queue is empty; 1 is returned
        Status : passed
        */
    if (size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Utility function to check if the queue is full or not
bool queue::isFull()
{
    /*Test ID : full queue check - FQC
        Unit : queue::isFull()
        Description : test to determine if queue::isfull() returns 1 if a queue object
        is full.
        Test steps :
    1. Construct an empty queue object
        2. Invoke queue::isfull()
        3. Conditionally evaluate the value returned by queue::isfull()
        Test data : size = 10
        Precondition : queue object is full
        Postcondition : queue object is still full
        Expected result : queue is full; 1 is returned
        Actual result : queue is full; 1 is returned
        Status : passed
        */
    if ((size()) == capacity)
    {
        return true;
    }
    else
    {
        return false;
    }

}