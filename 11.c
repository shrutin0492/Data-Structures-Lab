#include <stdio.h>
#include <stdbool.h>

struct CircularQueue {
    char *arr;
    int front, rear, size;
};

void initializeQueue(struct CircularQueue *queue, int size) {
    queue->arr = (char *)malloc(size * sizeof(char));
    queue->front = queue->rear = -1;
    queue->size = size;
}

bool isQueueEmpty(struct CircularQueue *queue) {
    return queue->front == -1;
}

bool isQueueFull(struct CircularQueue *queue) {
    return (queue->rear + 1) % queue->size == queue->front;
}

void enqueue(struct CircularQueue *queue, char item) {
    if (isQueueFull(queue)) {
        printf("Queue overflow!\n");
        return;
    }
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->size;
    }
    queue->arr[queue->rear] = item;
}

char dequeue(struct CircularQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue underflow!\n");
        return '\0';
    }
    char item = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->size;
    }
    return item;
}

int main() {
    int size;
    printf("Enter the size of the circular queue: ");
    scanf("%d", &size);

    struct CircularQueue queue;
    initializeQueue(&queue, size);

    int choice;
    char item;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!isQueueFull(&queue)) {
                    printf("Enter a character to enqueue: ");
                    scanf(" %c", &item);
                    enqueue(&queue, item);
                } else {
                    printf("Queue is full. Cannot enqueue.\n");
                }
                break;
            case 2:
                item = dequeue(&queue);
                if (item != '\0') {
                    printf("Dequeued: %c\n", item);
                }
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    free(queue.arr); // Free allocated memory

    return 0;
}
