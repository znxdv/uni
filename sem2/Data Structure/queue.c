#ifdef _WIN32
#include <windows.h>
#define clear "cls"
#else
#include <unistd.h>
#define clear "clear"
#endif

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main();

// Define a structure for a Node in a linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a structure for a Queue implemented using a linked list
typedef struct Queue {
    Node *front, *rear;
} Queue;

// Function to create a new Node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new empty Queue
Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

// Function to enqueue an element into the Queue
void enqueue(Queue* queue) {
    system(clear); 

    int data;
    printf("Insert a data into the queue: ");
    scanf("%d", &data);
    Node* newNode = createNode(data);

    // If the queue is empty, set both front and rear to the new node
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        printf("\n%d has been added to the queue. ");
        getch();
        return;
    }

    // Otherwise, add the new node to the rear of the queue
    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("\n%d has been added to the queue. ");
    getch();
}

// Function to check if the Queue is empty
void checkQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is still empty. ");
        getch();
    }
}

// Function to dequeue an element from the Queue
void dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return;  // If the queue is empty, there's nothing to dequeue
    }
    Node* temp = queue->front;
    queue->front = queue->front->next;

    // If the queue becomes empty after dequeue, update rear as well
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return;
}

// Function to display the elements in the Queue
void display(Queue* queue) {
    checkQueue(queue);
    system(clear);
    Node* temp = queue->front;
    puts("Current queue: \n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    getch();
    return;
}

// Function to display the front element of the Queue (peek)
void peek(Queue* queue) {
    checkQueue(queue);
    printf("The current Peek of the Queue is %d. ", queue->front->data);
    getch();
    return;
}


int main() {
    Queue* queue = createQueue(); // Create an empty Queue
    while (1) {
        system(clear);
        puts("Tugas Pertemuan 6 LAB Data Structure (Queue Implementation)");
        puts("2602225201 - Mhd. Fauzan Devinto\n");
        puts("[1] Enqueue");
        puts("[2] Dequeue");
        puts("[3] Display");
        puts("[4] Peek");
        puts("[5] Exit");
        printf("\nChoose: ");
        switch (getch()) {
            case '1':
                enqueue(queue);
                break;
            case '2':
                dequeue(queue);
                break;
            case '3':
                display(queue);
                break;
            case '4':
                peek(queue);
                break;
            case '5':
                exit(0);
            default:
                printf("Invalid input ! ");
                getch();
                main();
        }
    }
    return 0;
}