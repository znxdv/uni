#ifdef _WIN32
#include <windows.h>
#define clear "cls"
#else
#include <unistd.h>
#define clear "clear" 
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a person's ID information.
typedef struct Node{
    char name[50];
    int age;
    char sex[10];
    char occupation[50];
    char nationality[50];
    char address[100];
    char phoneNumber[20];
    struct Node *next;  // Pointer to the next person's ID.
} ID;

// Function to create a new node with ID information.
ID* createNode(char name[], int age, char sex[], char occupation[], char nationality[], char address[], char phoneNumber[]){
    ID *newNode = (ID*)malloc(sizeof(ID));
    
    strcpy(newNode->name, name);
    newNode->age = age;
    strcpy(newNode->sex, sex);
    strcpy(newNode->occupation, occupation);
    strcpy(newNode->nationality, nationality);
    strcpy(newNode->address, address);
    strcpy(newNode->phoneNumber, phoneNumber);
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node to the linked list.
ID* pushNode(ID *head, int position, char name[], int age, char sex[], char occupation[], char nationality[], char address[], char phoneNumber[]) {
    ID *newNode = createNode(name, age, sex, occupation, nationality, address, phoneNumber);
    
    if(position == 1){
        newNode->next = head;
        head = newNode;
    }
    else{
        ID *temp = head;
        int indexLinkedList = 1;
        while(indexLinkedList < position-1 && temp->next != NULL) {
            temp = temp->next;
            indexLinkedList++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

// Function to remove a node from the linked list.
ID* popNode(ID *head, int position){
    if(head == NULL){
        printf("Linked list is still empty. \n");
        return head;
    }
    if(position == 1){
        ID *temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
    else{
        ID *temp = head;
        int indexLinkedList = 1;
        while (indexLinkedList < position-1 && temp->next != NULL){
            temp = temp->next;
            indexLinkedList++;
        }
        if(temp->next == NULL){
            printf("Invalid position!\n");
            return head;
        }
        ID *pop = temp->next;
        temp->next = pop->next;
        free(pop);
        pop = NULL;
    }
    return head;
}

void printList(ID *head){
    if(head == NULL){
        printf("Linked list is still empty. \n");
        return;
    }
    printf("%-20s %-5s %-10s %-20s %-20s %-30s %-15s", "Name", "Age", "Gender", "Occupation", "Nationality", "Address", "Phone Number");
    ID *temp = head;
    putchar('\n');
    while (temp != NULL){
        printf("%-20s %-5d %-10s %-20s %-20s %-30s %-15s\n", temp->name, temp->age, temp->sex, temp->occupation, temp->nationality, temp->address, temp->phoneNumber);
        temp = temp->next;
    }
}

int main(){
    system(clear);

    ID *head = NULL;  // Initialize the head of the linked list.

    // Push nodes into the linked list.
    head = pushNode(head, 1, "John Doe", 35, "Male", "Engineer", "American", "123 Main St, Anytown USA", "555-1234");
    head = pushNode(head, 2, "Jane Smith", 27, "Female", "Designer", "British", "456 High St, London UK", "555-5678");
    head = pushNode(head, 3, "Ali Ahmad", 42, "Male", "Doctor", "Iranian", "789 Tehran St, Tehran Iran", "555-2468");
    head = pushNode(head, 4, "Maria Garcia", 29, "Female", "Programmer", "Mexican", "321 Juarez St, Mexico City Mexico", "555-3698");
    head = pushNode(head, 5, "Mohamed Abdi", 25, "Male", "Student", "Somalian", "987 Hargeisa St, Hargeisa Somalia", "555-1357");
    head = pushNode(head, 6, "Sara Chen", 33, "Female", "Manager", "Chinese", "654 Beijing St, Beijing China", "555-7890");
    head = pushNode(head, 7, "Ahmed Hassan", 48, "Male", "Businessman", "Egyptian", "012 Cairo St, Cairo Egypt", "555-8023");

    printf("Original Linked List:\n\n");
    printList(head);

    // Push more nodes into the linked list.
    head = pushNode(head, 2, "David Lee", 31, "Male", "Lawyer", "Canadian", "234 Main St, Toronto Canada", "555-1111");
    head = pushNode(head, 3, "Eva Kim", 26, "Female", "Teacher", "Korean", "567 Seoul St, Seoul Korea", "555-2222");

    printf("\n\nLinked list after push nodes:\n\n");
    printList(head);

    // Remove nodes from the linked list.
    head = popNode(head, 3);
    head = popNode(head, 5);

    printf("\n\nLinked list setelah pop nodes:\n\n");
    printList(head);
    puts("\n");
    return 0;
}