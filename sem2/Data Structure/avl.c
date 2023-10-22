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

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

Node* root = NULL;

int main();

int maxValue(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* node) {
    if (node == NULL){
        return 0;
    }
    return node->height;
}

Node* newNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = maxValue(height(y->left), height(y->right)) + 1;
    x->height = maxValue(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = maxValue(height(x->left), height(x->right)) + 1;
    y->height = maxValue(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(Node* node) {
    if (node == NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node* insertNode(Node* node, int value) {
    if (node == NULL){
        return newNode(value);
    }
    if (value < node->value){
        node->left = insertNode(node->left, value);
    }
    else if (value > node->value){
        node->right = insertNode(node->right, value);
    }
    else {
        printf("\n%d is already in the Tree. Enter a different Value. ");
        getch();
        main();
    }

    node->height = 1 + maxValue(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && value < node->left->value){
        return rightRotate(node);
    }
    if (balance < -1 && value > node->right->value){
        return leftRotate(node);
    }
    if (balance > 1 && value > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && value < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL){
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) {
        printf("%d is not in the Tree. ", value);
        getch();
        main();
    }
    if (value < root->value){
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->value){
        root->right = deleteNode(root->right, value);
    }
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } 
            else{
                *root = *temp;
            }
            free(temp);
        } 
        else {
            Node* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, value);
        }
    }
    if (root == NULL){
        return root;
    }

    root->height = 1 + maxValue(height(root->left), height(root->right));
    int balance = getBalance(root);
    
    if (balance > 1 && getBalance(root->left) >= 0){
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorderTraversal(Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->value);
        inorderTraversal(node->right);
    }
}

int main() {
    while (1) {
        int insertValue, deleteValue;
        system(clear); 
        puts("AVL Tree\n");
        puts("1. Insert Node");
        puts("2. Delete Node");
        puts("3. Print Tree");
        puts("4. Exit\n");
        printf("Choose: ");
        switch (getch()) {
            case '1':
                system(clear);
                printf("Enter the Value of the Node you want to add: ");
                scanf("%d", &insertValue);
                root = insertNode(root, insertValue);
                printf("\nAnode has been succesfully added. ");
                getch();
                break;
            case '2':
                if (root == NULL){
                    printf("Tree is still empty. ");
                    getch();
                    main();
                }
                system(clear);       
                printf("Enter the Value of the Node you want to delete: ");
                scanf("%d", &deleteValue);
                root = deleteNode(root, deleteValue);
                printf("\nNode has been succesfully deleted. ");
                getch();
                break;
            case '3':
                system(clear);
                printf("Tree [In-Order] : ");
                inorderTraversal(root);
                getch();
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid input! ");
                getch();
                main();
        }
    }
    return 0;
}