#ifdef _WIN32
#include <windows.h>
#define clear "cls"
#else
#include <unistd.h>
#define clear "clear"
#endif

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct item { // Define a struct for items
    char name[100];
    int quantity;
    double price;
};
struct item brg[10]; // Declare an array of struct to store items

// Function to handle payment and order details
void pay(char name[], char address[], double totalPrice, int quantity) {
    while (1) { 
        system(clear);

        double money;
        printf("You are buying: ");
        for (int i = 0; i < quantity; i++) {
            printf("%d %s", brg[i].quantity, brg[i].name);
        }
        printf("\nThe items will be sent to %s, under the name of %s", address, name);
        printf("\nWith a total cost of Rp%.02lf.", totalPrice);
        printf("\n\nEnter the amount of money for payment: ");
        scanf("%lf", &money);
        if (money < totalPrice) {
            printf("\n\nPayment failed, the money you entered is not enough!");
            getch();
        }
        else if (money > totalPrice) {
            printf("\nPayment successful, please wait for the items to arrive :)");
            printf("\nYour change is Rp%.02lf\n\n", money - totalPrice);
            exit(1);
        }
        else if (money == totalPrice) {
            printf("\nPayment successful, please wait for the items to arrive :)");
            exit(1);
        }
    }
}

int main() {
    system(clear);

    // Define a local struct to store order information
    struct pesan_item_belanja {
        char name[100];
        struct item brg; // Nested struct for an individual item
        char address[100];
    } itm;

    int quantity;
    double price[10] = {0}, totalPrice = 0;

    printf("Please enter the buyer's name: ");
    scanf("%[^\n]", itm.name);
    printf("How many types of items do you want to buy? ");
    scanf("%d", &quantity);

    for (int i = 0; i < quantity; i++) {
        printf("\nName of the %d item you want to buy: ", (i+1));
        while (getchar() != '\n');
        scanf("%[^\n]", brg[i].name);
        
        printf("How many %s do you want to buy? ", brg[i].name);
        scanf("%d", &brg[i].quantity);
        
        printf("What's the price for 1 %s? ", brg[i].name);
        scanf("%lf", &brg[i].price);
        
        price[i] = (double)brg[i].quantity * brg[i].price;
        totalPrice += price[i];
    }
    while (getchar() != '\n');

    printf("\nEnter the recipient's address: ");
    scanf("%[^\n]", itm.address);
    printf("\n\nPlease make the payment");
    
    getch();
    // Call the pay function to handle payment details
    pay(itm.name, itm.address, totalPrice, quantity);
}