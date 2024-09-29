// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn

#include "queue.h"
// Class for queue


// main function
int main()
{
    queue p = {};
    p.enqueue(4);
    p.isEmpty();
    p.isFull();
    p.size();
    p.peek();
    p.dequeue();
        
    return 0;
}

