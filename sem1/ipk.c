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
#include <string.h>

FILE* fp;
int main();

// This function allows users to input data (NIM, assignment, mid-exam, final exam scores) and stores it in a file.
void inputData() {
    system(clear);

    int assignment, midExam, finalExam;
    unsigned long long nim;
    char dataUser[20];

    printf("Register your NIM: ");
    scanf("%llu", &nim);

    // Create a file with a filename based on the user's NIM.
    snprintf(dataUser, sizeof(dataUser), "data-%llu.txt", nim);
    fp = fopen(dataUser, "a+");

    printf("\nPlease enter your Assignment score: ");
    scanf("%d", &assignment);

    printf("Please enter your Mid Exam score: ");
    scanf("%d", &midExam);

    printf("Please enter your Final Exam score: ");
    scanf("%d", &finalExam);

    // Write the scores to the user's file.
    fprintf(fp, "%d %d %d\n", assignment, midExam, finalExam);
    printf("\nInput completed! ");
    fclose(fp);

    printf("Press any key to continue...");
    getch();
    main();
}

// This function allows users to view and calculate their IPK (GPA) based on their scores in stored files.
void showData() {
    system(clear);

    char dataUser[20], line[200];
    int assignment, midExam, finalExam;
    unsigned long long nim;

    printf("Please enter your NIM to view your data: ");
    scanf("%llu", &nim);

    // Open the user's file based on their NIM.
    snprintf(dataUser, sizeof(dataUser), "data-%llu.txt", nim);
    fp = fopen(dataUser, "r");

    if (fp == NULL) {
        printf("Your NIM is not registered.");
        printf("Press any key to continue...");
        getch();
        main();
    }

    float sum = 0;
    int count = 0;

    // Read the scores from the file and calculate the IPK.
    while (fgets(line, 200, fp) != NULL) {
        sscanf(line, "%d %d %d", &assignment, &midExam, &finalExam);
        sum += (assignment + midExam + finalExam);
    }

    printf("IPK : %.2f", sum / 300);
    fprintf(fp, "\nIPK : %.2f", sum / 300);
    fclose(fp);

    printf("Press any key to continue...");
    getch();
    main();
}

// This is the main function that provides a menu for the user to input data, show data, or exit the program.
int main() {
    system(clear);

    puts("IPK\n");
    puts("[1] Input data");
    puts("[2] Show data");
    puts("[3] Exit");
    printf("\nChoose: ");

    switch (getch()) {
        case '1':
            inputData();
            break;
        case '2':
            showData();
            break;
        case '3':
            return 0;
        default:
            puts("\n\nInvalid Input! ");
            printf("Press any key to continue...");
            getch();
            main();
    }

    return 0;
}