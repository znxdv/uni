#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("\033[2J\033[1;1H"); // Clear the console screen.
    int length;
    char password[100];

    puts("<<Password Generation>>\n");

    printf("Desired password length: ");
    scanf("%d", &length);
    puts("");

    if (length < 6){
        printf("Password must be at least 6 characters long! ");
        getch();
        main();
    }

    // Seed the random number generator with the current time.
    srand(time(NULL));

    // Generate the password character by character.
    for (int i = 0; i < length; i++) {
        int random_char = rand() % 3;
        if (random_char == 0){
            password[i] = 'a' + (rand() % 26);
        } 
        else if (random_char == 1){
            password[i] = 'A' + (rand() % 26);
        }
        else{
            password[i] = '0' + (rand() % 10);
        }
    }

    printf("Recommended Password: ");
    for (int i = 0; i < length; i++) {
        printf("%c", password[i]);
    }
    puts("\n");

    return 0;
}
