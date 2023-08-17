#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack implementation
struct Stack {
    int arr[MAX_SIZE];
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
void push(struct Stack *stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

// Pop an element from the stack
int pop(struct Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initializeStack(&stack);

    int len = strlen(postfix);

    for (int i = 0; i < len; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(&stack, ch - '0'); // Convert character to integer
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (ch) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator!\n");
                    return -1;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    if (result != -1) {
        printf("Result of the postfix expression: %d\n", result);
    }

    return 0;
}
