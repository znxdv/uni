#ifdef _WIN32
#include <windows.h>
#define clear "cls"
#else
#include <unistd.h>
#define clear "clear"
#endif

#include <conio.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[20];
    int age;
    struct Node* Next;
} Node;

Node* head = NULL;
Node* searchNode();

void menu();
void printList();
void sortList();

void pushNode();
void pushHead();
void pushMid();
void pushTail();

void popNode();
void popHead();
void popMid();
void popTail();

char nodesName[20];
int nodesAge;

void checkHead(){
    if(head == NULL){
        printf("Linked list is still empty. "); 
        getch();
        menu();
    }
}

void printList(){ 
    system(clear);
    checkHead();
    
    Node *temp = head;
    puts("Linked List : \n");
    while(temp != NULL){
        printf("|%s--%d Year| -> ", temp->name, temp->age);
        temp = temp->Next;
    }
    printf("NULL");
    puts("\n");
    printf("Press any key to continue."); 
    getch();
    menu();
}

void reversedList(){ 
    system(clear);
    checkHead();

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while(current != NULL){
        next = current->Next;
        current->Next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    Node* temp = head;
    puts("Reversed List : \n");
    while(temp != NULL){
        printf("|%s--%d Year| -> ", temp->name, temp->age);
        temp = temp->Next;
    }
    printf("NULL");
    puts("\n");
    printf("Press any key to continue."); 
    getch();
    menu();
}

int countNodes(){
    Node* current = head;
    int total = 0;
    while(current != NULL){
        total++;
        current = current->Next;
    }
    return total;
}

void popHead(){
    Node* deleted = head;
    head = head->Next;
    free(deleted);
    printf("\n\nThe head of the Linked List has been successfully removed."); getch();
    popNode();
}

void popMid(){ 
    system(clear);

    Node* temp = head;
    
    int input; 
    int nodesPosition = 1;
    int totalNodes = countNodes();
    
    printf("Enter the position of the node you want to delete (1-%d): ", totalNodes);
    scanf("%d", &input); 
    while(getchar() != '\n');   
    if(input < 1 || input > totalNodes){
        printf("Invalid Input! "); 
        getch();
        popNode();
    } 
    while(nodesPosition < input-1 && temp->Next != NULL){
        temp = temp->Next;
        nodesPosition++;
    }
    Node* delete = temp->Next;
    temp->Next = delete->Next;
    delete->Next = NULL;
    free(delete);
    puts("\n");
    printf("A node at position %d has been successfully deleted. ", input); 
    getch();
    popNode();
}

void popTail(){
    Node* deleted = head;
    Node* tail = NULL;
    while(deleted->Next != NULL){
        tail = deleted;
        deleted = deleted->Next;
    }
    if(tail == NULL){
        free(deleted);
        head = NULL;
    }
    else{
        free(deleted);
        tail->Next = NULL;
    }
    printf("\n\nThe tail of the Linked List has been successfully removed. ");
    getch();
    popNode();
}

void popAll() {
    while (head != NULL){
        Node* delete = head;
        head = head->Next;
        free(delete); 
    }
    printf("\n\nAll nodes has been succesfully removed ! ");
    getch();
    popNode();
}

void pushHead() { 
    system(clear);
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    puts("Insert a new node as the Head.");
    printf("\nName: ");
    scanf("%[^\n]", newNode->name);
    printf("\nAge: ");
    scanf("%d", &newNode->age); 
    while(getchar() != '\n');
    
    newNode->Next = NULL;
    if (head == NULL)
        head = newNode;
    else {
        newNode->Next = head;
        head = newNode;
    }
    printf("\nHead has already been updated! ");
    getch();
    pushNode();
}


void pushMid(){ 
    system(clear);

    int nodesPosition, totalNodes = countNodes();
    if(totalNodes == 0){
        pushHead();
    }
    printf("Enter the position for the node you want to add (1-%d): ", totalNodes+1);
    scanf("%d", &nodesPosition); 
    while(getchar() != '\n');
    while (nodesPosition < 1 || nodesPosition > totalNodes + 1){
        printf("Position is invalid. ", totalNodes+1); 
        getch();
        pushMid();
    }
    if(nodesPosition == 1){
        pushHead();
    }
    if (nodesPosition == totalNodes + 1){
        pushTail();
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    puts("\n");
    printf("Insert a new node at position %d: ", nodesPosition);
    puts("\n");
    printf("Name: ");
    scanf("%[^\n]", newNode->name);
    printf("\nAge: ");
    scanf("%d", &newNode->age); 
    while(getchar() != '\n');

    Node* current = head;
    int count = 1;
    while(count < nodesPosition-1 && current != NULL){
        current = current->Next;
        count++;
    }
    newNode->Next = current->Next;
    current->Next = newNode; 
    puts("");
    printf("A Node has been successfully added at position %d. ", nodesPosition);
    getch();
    pushNode();
}

void pushTail(){ 
    system(clear);
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    puts("Insert a new node as the tail.");
    printf("\nName: ");
    scanf(" %[^\n]", newNode->name);
    printf("\nAge: "); 
    scanf("%d", &newNode->age); 
    while(getchar() != '\n');
    
    newNode->Next = NULL;
    if (head == NULL){
        head = newNode;
    }
    else{
        while (head->Next != NULL){
            head = head->Next;
        }
        head->Next = newNode;
    }
    printf("\nTail has already been updated! "); 
    getch();
    pushNode();
}

void sortAscending(){ 
    system(clear);

    int choose;

    puts("Sort the data by: \n");
    puts("[1] Name");
    puts("[2] Age");
    puts("[3] Go back to the previous menu\n");
    printf("Choose: ");
    scanf("%d", &choose); 
    while(getchar() != '\n');

    if(choose < 1 || choose > 3){
        printf("Invalid Input! ");
        getch();
        sortAscending();
    }
    if(choose == 3){
        sortList();
    }

    Node *current = head;
    Node *index = current->Next;
    char tempName[50];
    int tempAge;
    while(index != NULL){
        if(choose == 1){
            if(strcmp(current->name, index->name) > 0){
                strcpy(tempName, current->name);
                strcpy(current->name, index->name);
                strcpy(index->name, tempName);
                tempAge = current->age;
                current->age = index->age;
                index->age = tempAge;
            }
        }
        else if (choose == 2){
            if(current->age > index->age){
                strcpy(tempName, current->name);
                strcpy(current->name, index->name);
                strcpy(index->name, tempName);
                tempAge = current->age;
                current->age = index->age;
                index->age = tempAge;
            }
        }
        index = index->Next;
        if(index == NULL && current->Next != NULL){
            current = current->Next;
            index = current->Next;
        }
    }
    printf("\nThe data has been sorted in ascending order. ");
    getch();
    menu();
}

void sortDescending(){ 
    system(clear);
    
    int choose;
    
    puts("Sort the data by: \n");
    puts("[1] Name");
    puts("[2] Age");
    puts("[3] Go back to the previous menu\n");
    printf("Choose: ");
    scanf("%d", &choose); 
    while(getchar() != '\n');

    if(choose < 1 || choose > 3){
        printf("Invalid Input! "); 
        getch();
        sortAscending();
    }
    if(choose == 3){
        sortList();
    }

    Node *current = head;
    Node *index = current->Next;
    char tempName[50];
    int tempAge;
    while(index != NULL){
        if(choose == 1){
            if(strcmp(current->name, index->name) < 0){
                strcpy(tempName, current->name);
                strcpy(current->name, index->name);
                strcpy(index->name, tempName);
                tempAge = current->age;
                current->age = index->age;
                index->age = tempAge;
            }
        }
        else if (choose == 2){
            if(current->age < index->age){
                strcpy(tempName, current->name);
                strcpy(current->name, index->name);
                strcpy(index->name, tempName);
                tempAge = current->age;
                current->age = index->age;
                index->age = tempAge;
            }
        }
        index = index->Next;
        if(index == NULL && current->Next != NULL){
            current = current->Next;
            index = current->Next;
        }
    }
    printf("\nThe data has been sorted in descending order."); 
    getch();
    menu();
}

Node* searchNode(){ 
    system(clear);
    checkHead();

    puts("Seatch the data by: ");
    puts("[1] Name");
    puts("[2] Age");
    puts("[3] Go back to the previous menu\n");
    char type[5];
    printf("Choose : "); 
    switch(getch()){
        case '1':
            strcpy(type, "name");
            break;
        case '2':
            strcpy(type, "age");
            break;
        case '3':
            menu();
            break;
        default:
            printf("Invalid input! ");
            getch();
            menu();
            return head;
    }

    Node* current = head;
    bool found = false;
    int num = 1, position = 1;
    if(strcmp(type, "name") == 0){ 
        system(clear);
        printf("Name you want to search for: ");
        scanf(" %[^\n]", nodesName);
        puts("\n");
        while(current != NULL){
            if(strcasecmp(current->name, nodesName) == 0){
                printf("%d. %s--%d Year\n", num, current->name, current->age);
                printf("   Found at Node %d.", position);
                puts("\n");
                found = true;
                num++;
            }
            position++;
            current = current->Next;
        }
    }
    else if(strcmp(type, "age") == 0){ system(clear);
        printf("Age you want to search for: ");
        scanf("%d", &nodesAge); 
        while(getchar() != '\n');
        while(current != NULL){
            if(current->age == nodesAge){
                printf("%d. %s--%d Year\n", num, current->name, current->age);
                printf("   Found at Node %d.", position);
                puts("\n");
                found = true;
                num++;
            }
            position++;
            current = current->Next;      
        }
    }
    if(!found){
        printf("Data is not found. "); 
        getch(); 
        searchNode();
    }
    printf("\nPress any key to continue."); 
    getch();
    menu();
    return head;
}

/*---------------------------------------------Yang dibawah ga penting---------------------------------------------*/

void popNode(){ 
    system(clear);
    checkHead();

    puts("Choose the type of Pop Node you want to use:\n");
    puts("[1] Pop Head");
    puts("[2] Pop Mid");
    puts("[3] Pop Tail");
    puts("[4] Pop All");
    puts("[5] Return to main menu");
    printf("\nPilih : ");
    switch(getch()){
        case '1': 
            popHead();
            break;
        case '2': 
            popMid();
            break;
        case '3': 
            popTail();
            break;
        case '4': 
            popAll();
            break;
        case '5': 
            menu();
            break;
        default :
            printf("Invalid Input! "); 
            getch();
            popNode();
    }
}

void pushNode(){ 
    system(clear);

    puts("Choose the type of Push Node you want to use: \n");
    puts("[1] Push Head");
    puts("[2] Push Mid");
    puts("[3] Push Tail");
    puts("[4] Return to main menu");
    printf("\nChoose: ");
    switch(getch()){
        case '1': 
            pushHead();
            break;
        case '2': 
            pushMid();
            break;
        case '3': 
            pushTail();
            break;
        case '4': 
            menu();
            break;
        default :
            printf("Invalid Input! "); 
            getch();
            pushNode();
    }
}

void sortList(){ 
    system(clear);
    checkHead();

    puts("Choose the type of sorting you want to use: \n");
    puts("[1] Ascending");
    puts("[2] Descending");
    puts("[3] Return to the main menu");
    printf("\nChoose: ");
    switch(getch()){
        case '1': 
            sortAscending();
            break;
        case '2': 
            sortDescending();
            break;
        case '3': 
            menu();
            break;
        default :
            printf("Invalid Input! "); 
            getch();
            popNode();
    }
}

void menu(){ 
    system(clear);

    puts("<<<Basic Singly Linked List>>>\n");
    puts("[1] Print Linked List");
    puts("[2] Sort Linked List");
    puts("[3] Reverse Linked List");
    puts("[4] Push Node");
    puts("[5] Pop Node");
    puts("[6] Cari Node");
    puts("[7] Exit");
    printf("\nChoose: ");
    switch(getch()){
        case '1':
            printList();
            break;
        case '2':
            sortList();
            break;
        case '3':
            reversedList();
            break;
        case '4':
            pushNode();
            break;
        case '5':
            popNode();
            break;
        case '6':
            searchNode();
            break;
        case '7':
            exit(0);
            break;
        default:
            printf("Invalid input! "); \
            getch();
            menu();
            break;
    }
}

int main(){
    menu();
    return 0;
}