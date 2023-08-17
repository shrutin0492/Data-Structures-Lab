#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack implementation
struct Stack {
    char arr[MAX_SIZE];
    int top;
};

// Initialize a stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
bool isStackEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(struct Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

// Pop an element from the stack
char pop(struct Stack *stack) {
    if (isStackEmpty(stack)) {
        return '\0';
    }
    return stack->arr[stack->top--];
}

// Get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initializeStack(&stack);

    int len = strlen(infix);
    int postfixIndex = 0;

    for (int i = 0; i < len; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[postfixIndex++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!isStackEmpty(&stack) && stack.arr[stack.top] != '(') {
                postfix[postfixIndex++] = pop(&stack);
            }
            pop(&stack); // Pop '('
        } else {
            while (!isStackEmpty(&stack) && getPrecedence(ch) <= getPrecedence(stack.arr[stack.top])) {
                postfix[postfixIndex++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!isStackEmpty(&stack)) {
        postfix[postfixIndex++] = pop(&stack);
    }

    postfix[postfixIndex] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
