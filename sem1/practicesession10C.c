#ifdef _WIN32
#include <windows.h>
#define clear "cls"
#else
#include <unistd.h>
#define clear "clear"
#endif

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#define FILE_MAX_WORDS 26413

FILE *fp; // Declare a file pointer.

// This function performs a binary search on an array of words to find a match.
int binary_search(char dictionaryWords[][37], int max, char *input){
    int low = 0, high = max-1;
    
    while(low <= high){
        int mid = (low + high) /2;
        if(strcmp(dictionaryWords[mid], input) == 0){ 
            return mid + 1;  // Match found, return the line number.
        }
        else if (strcmp(dictionaryWords[mid], input) < 0){
            low = mid+1;
        }
        else{ 
            high = mid-1;
        }
    }
    return -1;  // Match not found, return -1.
}

int main(){
    system(clear);  // Clear the console screen.

    clock_t start, finish;
    char input[37], dictionaryWords[FILE_MAX_WORDS][37];

    scanf("%s", input);
    start = clock();  // Start measuring time.

    // Check if the first character of the input is within a certain range.
    if(!(/*(input[0] > 64 && input[0] <74) || */ (input[0] > 96 && input[0] < 106))){
        puts("Found at line -1"); 
        return 0;
    }
    
    // Opening and reading a file.
    fp = fopen("words.txt", "r");
    if(fp == NULL){
        perror("");  // Print an error message if the file couldn't be opened.
        return 1;
    }

    // Read words from the file and store them in an array.
    for(int i = 0; i < FILE_MAX_WORDS; i++){
        fscanf(fp, "%s", dictionaryWords[i]);
    }
    fclose(fp);  // Close the file.

    // Perform a binary search and display the result.
    binary_search(dictionaryWords, FILE_MAX_WORDS, input) > 0 ? printf("Found at line %d", binary_search(dictionaryWords, FILE_MAX_WORDS, input)) : puts("Found at line -1");
    finish = clock();  // Stop measuring time.
    printf("\nruntime : %lf seconds",(double)(finish - start) / CLOCKS_PER_SEC);  // Print the program's runtime.
    return 0;
}

/*
If the input accepts uppercase letters, uncomment everything.
If you want to use a different file, remove the if statement on lines 21-23, 
and adjust the size of the 'dictionaryWords' array accordingly.
*/
