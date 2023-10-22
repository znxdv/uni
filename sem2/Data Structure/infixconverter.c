#ifdef _WIN32
#include <windows.h>
#define clear "cls"
#else
#include <unistd.h>
#define clear "clear"
#endif

#include <conio.h> 
#include <ctype.h> 
#include <stdio.h> 
#include <stdbool.h> 
#include <stdlib.h> 
#include <string.h> 

char infixExpression[100], postfixExpression[100], prefixExpression[100], stack[100]; 

int main(); 

bool isOperator(char character) { 
    if (character == '^' || character == '*' || character == '/' || character == '+' || character == '-'){
        return true;
    }
    else {
        return false;
    }
} 

int precedence(char operator) { 
    if (operator == '^'){
        return 3;
    }
    else if (operator == '*' || operator == '/'){
        return 2; 
    }
    else if (operator == '+' || operator == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

char* infixToPostfix(char *infixExpression, char *postfixExpression) {
    int top = -1, i = 0, j = 0, num = 1; 
    while (infixExpression[i] != '\0') { 
        if (infixExpression[i] == '(') { 
            printf("[%d] Push %c onto Stack\n", num++, infixExpression[i]); 
            stack[++top] = infixExpression[i++]; 
        }
        if (infixExpression[i] == ')'){ 
            printf("[%d] Encountered closing parenthesis.\n", num++); 
            while (stack[top] != '(') { 
                postfixExpression[j++] = stack[top]; 
                printf("[%d] Pop %c from Stack and push it onto Output: %s\n", num++, stack[top--], postfixExpression); 
            } 
            printf("[%d] Pop %c from Stack\n", num++, stack[top--]); 
            i++; 
        } 
        if (isalnum(infixExpression[i])){ 
            postfixExpression[j++] = infixExpression[i]; 
            printf("[%d] Append %c to Output: %s\n", num++, infixExpression[i++], postfixExpression); 
        } 
        if (isOperator(infixExpression[i])) { 
            while (isOperator(stack[top]) && precedence(stack[top]) >= precedence(infixExpression[i])){ 
                postfixExpression[j++] = stack[top]; 
                printf("[%d] Pop %c from Stack and push it onto Output: %s\n", num++, stack[top--], postfixExpression); 
            } 
            printf("[%d] Push %c onto Stack\n", num++, infixExpression[i]); 
            stack[++top] = infixExpression[i++]; 
        } 
    } 
    while (top > -1){ 
        postfixExpression[j++] = stack[top]; 
        printf("[%d] Pop %c from Stack\n", num++, stack[top--]); 
    } 
    postfixExpression[j] = '\0'; 
    return postfixExpression; 
} 

char* infixToPrefix(char *infixExpression, char *prefixExpression) { 
    for (int i = 0; infixExpression[i] != '\0'; i++) { 
        if (infixExpression[i] == '('){
            infixExpression[i] = ')';
        }
        else if (infixExpression[i] == ')'){ 
            infixExpression[i] = '(';
        }
    } 
    printf("Reverse the infix to: %s\n\n", strrev(infixExpression)); 
    prefixExpression = infixToPostfix(infixExpression, prefixExpression); 
    printf("\nReverse the output to: %s\n", strrev(prefixExpression)); 
    return prefixExpression; 
} 

void prefixConversion() { 
    system(clear); 

    char temp[100];

    printf("Infix Expression: "); 
    scanf("%s", infixExpression);
    strcpy(temp, infixExpression);
    putchar('\n'); 
    printf("\nPrefix of %s = %s\n\n", infixExpression, infixToPrefix(infixExpression, prefixExpression)); 

    stack[0] = '\0'; 
    infixExpression[0] = '\0';
    prefixExpression[0] = '\0';
    temp[0] = '\0';	

    printf("Press any key to continue."); 
    getch(); 
    main(); 
} 

void postfixConversion() { 
    system(clear); 

    printf("Infix Expression: "); 
    scanf("%s", infixExpression); 
    putchar('\n'); 
    printf("\nPostfix of %s = %s\n\n", infixExpression, infixToPostfix(infixExpression, postfixExpression)); 

    stack[0] = '\0'; 
    infixExpression[0] = '\0'; 
    postfixExpression[0] = '\0'; 

    printf("Press any key to continue."); 
    getch(); 
    main(); 
} 

int main() { 
    system(clear); 

    puts("<< Infix to Prefix/Postfix Converter >>\n"); 
    puts("[1] Infix to Prefix"); 
    puts("[2] Infix to Postfix"); 
    puts("[3] Exit"); 
    printf("\nChoose: "); 
    switch (getch()){ 
        case '1' : 
            prefixConversion(); 
            break; 
        case '2' : 
            postfixConversion(); 
            break; 
        case '3' :
            exit(1);
            break;
        default: 
            printf("Invalid Input!"); 
            getch(); 
            main(); 
    } 
    return 0; 
}