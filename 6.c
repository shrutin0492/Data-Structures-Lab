#include <stdio.h>
#include <stdbool.h>

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

// Check if the stack is full
bool isStackFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(struct Stack *stack, int item) {
    if (isStackFull(stack)) {
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

// Queue implementation
struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

// Initialize a queue
void initializeQueue(struct Queue *queue) {
    queue->front = queue->rear = -1;
}

// Check if the queue is empty
bool isQueueEmpty(struct Queue *queue) {
    return queue->front == -1;
}

// Check if the queue is full
bool isQueueFull(struct Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Enqueue an element into the queue
void enqueue(struct Queue *queue, int item) {
    if (isQueueFull(queue)) {
        printf("Queue overflow!\n");
        return;
    }
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->arr[queue->rear] = item;
}

// Dequeue an element from the queue
int dequeue(struct Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue underflow!\n");
        return -1;
    }
    int item = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        initializeQueue(queue);
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return item;
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    struct Queue queue;
    initializeQueue(&queue);

    int choice, item;

    do {
        printf("1. Push to Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Enqueue to Queue\n");
        printf("4. Dequeue from Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(&stack, item);
                break;
            case 2:
                item = pop(&stack);
                if (item != -1) {
                    printf("Popped from stack: %d\n", item);
                }
                break;
            case 3:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;
            case 4:
                item = dequeue(&queue);
                if (item != -1) {
                    printf("Dequeued from queue: %d\n", item);
                }
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
