#ifdef _WIN32
#include <windows.h>
#define clear "cls"
#else
#include <unistd.h>
#define clear "clear"
#endif

#include <stdio.h>
#define MAX_INPUT_LENGTH 256

FILE* fp;  // Declare a file pointer.

int main(){ 
    int character, line = 1;
    char input[MAX_INPUT_LENGTH];  // Declare an array to store user input.

    fp = fopen("testdata.out", "a+");  // Open the file "testdata.out" in append mode.

    system(clear);

    if(fp == NULL){
        perror("");  // Check if the file couldn't be opened and print an error message.
        return 1;  // Return with an error code.
    }

    // Count the number of lines in the file.
    while ((character = fgetc(fp)) != EOF) {
        if (character == '\n') {
            line++;
        }
    }

    fseek(fp, 0, SEEK_END);  // Move the file pointer to the end.

    // Continue to input text and append it to the file until "0" followed by a newline is entered.
    while (input[0] != '0' || input[1] != '\n') {
        printf("Enter text [input 0 to finish] : ");
        fgets(input, sizeof(input), stdin);
        fprintf(fp, "%d#%s", line, input);  // Append the line number and input text to the file.
        line++;
    }

    fclose(fp);  // Close the file.
    return 0;
}