#include <iostream>
#include <cstdio>

using namespace std;

char Front(char queue[], int front) {
    return queue[front];
}

bool isempty(int front, int rear){
	if(front>rear) return 1;
	return 0;
}
bool isfull(int rear, int size){
	if(rear = size-1) return 1;
	 return 0;
}
void enqueue(char queue[], char element, int& rear, int arraySize) {
    if(rear == arraySize)            // Queue is full
        printf("OverFlow\n");
    else {
        queue[rear] = element;    // Add the element to the back
        rear++;
    }
}


void dequeue(char queue[], int& front, int rear) {
    if(front == rear)            // Queue is empty
        printf("UnderFlow\n");
    else {
        queue[front] = 0;        // Delete the front element
        front++;
    }
}
int main() {
    char queue[20] = {'a', 'b', 'c'};
    int size = 3;
    int front = 0, rear = 3;
    int arraySize = 20;                // Size of the array
    int N = 3;                    // Number of steps
    char ch;
    enqueue(queue, 'd', rear, arraySize);
    enqueue(queue, 'e', rear, arraySize);
    enqueue(queue, 'f', rear, arraySize);
    enqueue(queue, 'g', rear, arraySize);
    enqueue(queue, 'h', rear, arraySize);
    dequeue(queue, front, rear);
    dequeue(queue, front, rear);
    for(int i = front;i <=rear;++i)
        printf("%c", queue[i]);
    printf("\n");
    return 0;
}
