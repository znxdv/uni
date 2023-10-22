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

#define RED 0
#define BLACK 1

int main();

typedef struct Node {
    int data;
    int color;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
} rb;

rb* root = NULL;

rb* createNode(int data) {
    rb* newNode = (rb*)malloc(sizeof(rb));
    newNode->data = data;
    newNode->color = RED;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void leftRotate(rb** root, rb* x) {
    rb* y = x->right;
    x->right = y->left;

    if (y->left != NULL){
        y->left->parent = x;
    }

    y->parent = x->parent;
    if (x->parent == NULL){
        *root = y;
    }
    else if (x == x->parent->left){
        x->parent->left = y;
    }
    else{
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(rb** root, rb* y) {
    rb* x = y->left;
    y->left = x->right;

    if (x->right != NULL){
        x->right->parent = y;
    }
    
    x->parent = y->parent;
    if (y->parent == NULL){
        *root = x;
    }
    else if (y == y->parent->left){
        y->parent->left = x;
    }
    else{
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

void fixRedBlackTree(rb** root, rb* newNode) {
    rb* parent = NULL;
    rb* grandparent = NULL;
    while (newNode != *root && newNode->color != BLACK && newNode->parent->color == RED) {
        parent = newNode->parent;
        grandparent = newNode->parent->parent;
        if (parent == grandparent->left) {
            rb* uncle = grandparent->right;
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grandparent;
            } 
            else {
                if (newNode == parent->right) {
                    leftRotate(root, parent);
                    newNode = parent;
                    parent = newNode->parent;
                }
                rightRotate(root, grandparent);
                int tempColor = parent->color;
                parent->color = grandparent->color;
                grandparent->color = tempColor;
                newNode = parent;
            }
        }
        else {
            rb* uncle = grandparent->left;
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grandparent;
            }
            else {
                if (newNode == parent->left) {
                    rightRotate(root, parent);
                    newNode = parent;
                    parent = newNode->parent;
                }
                leftRotate(root, grandparent);
                int tempColor = parent->color;
                parent->color = grandparent->color;
                grandparent->color = tempColor;
                newNode = parent;
            }
        }
    }
    (*root)->color = BLACK;
}

rb* insertNode(rb* root) {
    system(clear);

    int value;
    printf("Enter the value of the node you want to insert: ");
    scanf("%d", &value);

    rb* newNode = createNode(value);
    if (root == NULL) {
        root = newNode;
        root->color = BLACK;
        printf("\nNode has been succefully added.");
        getch();
        return root;
    }

    rb* current = root;
    rb* parent = NULL;
    while (current != NULL) {
        parent = current;
        if (newNode->data < current->data){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    newNode->parent = parent;
    if (newNode->data < parent->data){
        parent->left = newNode;
    }
    else{
        parent->right = newNode;
    }
    fixRedBlackTree(&root, newNode);
    printf("\nNode has been succefully added. ");
    getch();
    return root;
}

void inOrderTraversal(rb* root) {
    if (root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main() {
    while(1) {
        system(clear);

        puts("<<Red-Black Tree>>\n");
        puts("[1] Insert Node");
        puts("[2] In-order Traversal");
        puts("[3] Exit");
        printf("\nChoose: ");
        switch (getch()) {
            case '1':
                root = insertNode(root);
                break;
            case '2':
                system(clear);
                puts("In-order Traversal : \n");
                inOrderTraversal(root);
                getch();
                break;
            case '3':
                printf("Bye guys..");
                return 0;
            default:
                printf("Invalid input! ");
                getch();
                main();
        }
    }
    return 0;
}