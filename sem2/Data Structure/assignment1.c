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

typedef struct Node {
    char brand[20];
    char model[20];
    int year;
    float machine;
    double price;
    struct Node* next; // Pointer to the next car in the linked list.
} Car;

int main() {
    system(clear);

    // Create nodes for four cars and initialize them.
    Car* head = (Car*)malloc(sizeof(Car));
    Car* second = (Car*)malloc(sizeof(Car));
    Car* third = (Car*)malloc(sizeof(Car));
    Car* fourth = (Car*)malloc(sizeof(Car));

    // Initialize the attributes of the first car.
    strcpy(head->brand, "Toyota");
    strcpy(head->model, "Corolla");
    head->year = 2010;
    head->machine = 1.8f;
    head->price = 5000.0;
    head->next = second; // Link this car to the second car.

    // Initialize the attributes of the second car.
    strcpy(second->brand, "Honda");
    strcpy(second->model, "Civic");
    second->year = 2015;
    second->machine = 1.5f;
    second->price = 8000.0;
    second->next = third; // Link this car to the third car.

    // Initialize the attributes of the third car.
    strcpy(third->brand, "Ford");
    strcpy(third->model, "Mustang");
    third->year = 2018;
    third->machine = 5.0f;
    third->price = 20000.0;
    third->next = fourth; // Link this car to the fourth car.

    // Initialize the attributes of the fourth car.
    strcpy(fourth->brand, "Tesla");
    strcpy(fourth->model, "Model 3");
    fourth->year = 2020;
    fourth->machine = 0.0f;
    fourth->price = 40000.0;
    fourth->next = NULL; // The last car has no next car.

    // Print the original linked list of cars.
    puts("Original Linked List:\n");
    Car* original = head;
    while (original != NULL) {
        printf("%d %s %s with a %.1f engine size for Rp%.2f\n",
            original->year, original->brand, original->model,
            original->machine, original->price);
        original = original->next;
    }

    // Create a new car and add it to the end of the linked list.
    Car* newCar = malloc(sizeof(Car));
    strcpy(newCar->brand, "BMW");
    strcpy(newCar->model, "X5");
    newCar->year = 2021;
    newCar->machine = 2.0f;
    newCar->price = 50000.0;
    newCar->next = NULL;
    fourth->next = newCar; // Link the last car to the new car.

    puts("\n\nLinked List after Adding Nodes:\n");
    Car* afterPush = head;
    while (afterPush != NULL) {
        printf("%d %s %s with a %.1f engine size for Rp%.2f\n",
            afterPush->year, afterPush->brand, afterPush->model,
            afterPush->machine, afterPush->price);
        afterPush = afterPush->next;
    }

    // Remove the first car (pop operation).
    Car* temp = head;
    head = head->next;
    free(temp);
    temp = NULL;

    puts("\n\nLinked List after Removing Nodes:\n");
    Car* afterPop = head;
    while (afterPop != NULL) {
        printf("%d %s %s with a %.1f engine size for Rp%.2f\n",
            afterPop->year, afterPop->brand, afterPop->model,
            afterPop->machine, afterPop->price);
        afterPop = afterPop->next;
    }
    puts("\n");

    // Free memory allocated for the linked list nodes.
    free(head);
    free(third);
    free(fourth);
    free(newCar);

    return 0;
}