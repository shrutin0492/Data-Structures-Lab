#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a binary expression tree node
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(char data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to build a binary expression tree from a postfix expression
struct Node *buildExpressionTree(char postfix[]) {
    struct Node *stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            struct Node *operand = createNode(postfix[i]);
            stack[++top] = operand;
        } else {
            struct Node *operator = createNode(postfix[i]);
            operator->right = stack[top--];
            operator->left = stack[top--];
            stack[++top] = operator;
        }
    }

    return stack[top];
}

// In-order traversal of the expression tree
void inorder(struct Node *root) {
    if (root != NULL) {
        if (root->left != NULL || root->right != NULL) {
            printf("(");
        }
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if (root->left != NULL || root->right != NULL) {
            printf(")");
        }
    }
}

// Pre-order traversal of the expression tree
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal of the expression tree
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main() {
    char postfix[100];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    struct Node *root = buildExpressionTree(postfix);

    printf("\nIn-order traversal: ");
    inorder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preorder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
