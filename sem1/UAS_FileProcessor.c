#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to store psychotest participant data
struct Psychotest {
    char name[50];
    char gender[20];
    int age;
    int duration;
};
struct Psychotest participants[100];

// Function to clear the console screen
void clearScreen() {
    getch();
    fflush(stdin);
    printf("\033[1A\033[K");
    printf("\033[1A\033[2K");
}

FILE* fp;
int count = 0;

// Input participant data
void inputParticipant() {
    system("cls");
    
    fp = fopen("psychotest201.dat", "a");
    if (fp == NULL) {
        perror("");
        exit(1);
    }
    puts("Enter psychotest participant data\n");
    printf("Name          : ");
    scanf("%[^\n]", participants[count].name);
    getchar();
    puts("");
    
    while (1) {
        printf("Gender        : ");
        scanf(" %[^\n]", &participants[count].gender);
        getchar();
        if (strcasecmp(participants[count].gender, "Male") == 0 ||
            strcasecmp(participants[count].gender, "Female") == 0) {
            break;
        } else {
            printf("Invalid gender input, please enter 'Male' or 'Female'.\n");
            clearScreen();
        }
    }
    
    if (strcasecmp(participants[count].gender, "Female") == 0) {
        strcpy(participants[count].gender, "Female");
    } else {
        strcpy(participants[count].gender, "Male");
    }

    puts("");
    
    while (1) {
        printf("Age           : ");
        scanf("%d", &participants[count].age);
        while (getchar() != '\n');
        if (participants[count].age >= 25 && participants[count].age <= 35) {
            break;
        } else {
            printf("Invalid age, age should be between 25 and 35.\n");
            clearScreen();
        }
    }
    
    puts("");
    
    while (1) {
        printf("Duration      : ");
        scanf("%d", &participants[count].duration);
        while (getchar() != '\n');
        if (participants[count].duration >= 120 && participants[count].duration <= 240) {
            break;
        } else {
            printf("Invalid duration, duration should be between 120 and 240 minutes.\n");
            clearScreen();
        }
    }
    
    fwrite(&participants[count], sizeof(struct Psychotest), 1, fp);
    fclose(fp);
    count++;
    printf("\nData has been successfully saved! ");
    getch();
    menu();
}

// List all participants
void listParticipants() {
    system("cls");
    fp = fopen("psychotest201.dat", "r");
    if (fp == NULL) {
        perror("");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    
    if (ftell(fp) == 0) {
        printf("There are no registered participants. ");
        getch();
        fclose(fp);
        menu();
    }
    rewind(fp);
    puts("\t<<<Participant List>>>");
    puts("\n\nName\tGender\t   Age\t   Duration\n\n");
    
    for (int i = 0; i < count; i++) {
        fread(&participants[i], sizeof(struct Psychotest), 1, fp);
        printf("%s\t  %s\t %d Years\t %d Minutes\n\n", participants[i].name, participants[i].gender, participants[i].age, participants[i].duration);
    }
    
    fclose(fp);
    printf("\nPress any key to return to the main menu. ");
    getch();
    menu();
}

// Search for a participant by name
void searchParticipant() {
    system("cls");
    char searchName[50];
    int found = 0, foundIndex;
    fp = fopen("psychotest201.dat", "r");
    fseek(fp, 0, SEEK_END);
    
    if (ftell(fp) == 0) {
        printf("There are no registered participants. ");
        getch();
        fclose(fp);
        menu();
    }
    
    fclose(fp);
    printf("Enter the name you want to search for: ");
    scanf("%[^\n]", searchName);
    getchar();
    
    for (int i = 0; i < count; i++) {
        if (strcasecmp(participants[i].name, searchName) == 0) {
            found = 1;
            foundIndex = i;
            break;
        }
    }
    
    if (found) {
        puts("\n<<<Participant Data>>>\n");
        printf("Name              : %s\n", participants[foundIndex].name);
        printf("Gender            : %s\n", participants[foundIndex].gender);
        printf("Age               : %d Years\n", participants[foundIndex].age);
        printf("Duration          : %d Minutes\n", participants[foundIndex].duration);
        puts("");
        printf("Press any key to return to the main menu. ");
        getch();
        menu();
    } else {
        printf("\n\nParticipant with the name %s is not registered! ", searchName);
        getch();
        menu();
    }
}

// Sort participants data based on name
void sortData() {
    system("cls");
    fp = fopen("psychotest201.dat", "r");
    fseek(fp, 0, SEEK_END);
    
    if (ftell(fp) == 0) {
        printf("There are no registered participants. ");
        getch();
        fclose(fp);
        menu();
    }
    
    fclose(fp);
    struct Psychotest temp;
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(participants[i].name, participants[j].name) > 0) {
                temp = participants[i];
                participants[i] = participants[j];
                participants[j] = temp;
            }
        }
    }
    
    puts("<<<List Sorted by Name>>>\n");
    puts("Name\tGender\t   Age\t   Duration\n\n");
    
    for (int i = 0; i < count; i++) {
        printf("%s\t  %s\t %d Years\t    %d Minutes\n\n", participants[i].name, participants[i].gender, participants[i].age, participants[i].duration);
    }
    
    printf("\nPress any key to return to the main menu. ");
    getch();
    menu();
}

// Main menu
void menu() {
    system("cls");
    
    puts("<<<Psychotest>>>\n");
    puts("[1] Daftarkan Peserta");
    puts("[2] List Peserta");
    puts("[3] Cari Peserta");
    puts("[4] Sort Data");
    puts("[5] Exit");
    printf("\nPilih menu : ");

    switch(getch()){
        case '1':
            input_peserta();
            break;
        case '2':
            list_peserta();
            break;
        case '3':
            cari_peserta();
            break;
        case '4':
            sortData();
            break;
        case '5':
            return;
            break;
        default:
            printf("Invalid input ! "); getch(); menu();
            break;
    }
}

int main(){
    fp = fopen("psikotest201.dat", "a+");
    if(fp!=NULL){
        while(fread(&participants[count], sizeof(struct Psychotest), 1, fp)){
            count++;
        }
        fclose(fp);
    }
    fclose(fp);
    menu();
}


