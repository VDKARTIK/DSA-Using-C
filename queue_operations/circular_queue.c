#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int *arr;
    int front;
    int rear;
    int capacity;
} CircularQueue;

void initializeQueue(CircularQueue *cq, int capacity) {
    cq->arr = (int *)malloc(capacity * sizeof(int));
    cq->front = cq->rear = -1;
    cq->capacity = capacity;
}

int isFull(CircularQueue *cq) {
    return (cq->front == (cq->rear + 1) % cq->capacity);
}

int isEmpty(CircularQueue *cq) {
    return (cq->front == -1);
}

void enqueue(CircularQueue *cq, int element) {
    if (isFull(cq)) {
        printf("Queue Overflow: Cannot enqueue element %d, queue is full.\n", element);
        return;
    }
    if (isEmpty(cq)) {
        cq->front = cq->rear = 0;
    } else {
        cq->rear = (cq->rear + 1) % cq->capacity;
    }
    cq->arr[cq->rear] = element;
    printf("Enqueued element %d into the queue.\n", element);
}

int dequeue(CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue Underflow: Cannot dequeue from an empty queue.\n");
        return -1; // You may choose to return a special value to indicate an error.
    }
    int dequeuedElement = cq->arr[cq->front];
    if (cq->front == cq->rear) {
        // Reset front and rear when the queue becomes empty
        cq->front = cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % cq->capacity;
    }
    printf("Dequeued element %d from the queue.\n", dequeuedElement);
    return dequeuedElement;
}

int peek(CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty, cannot peek.\n");
        return -1; // You may choose to return a special value to indicate an error.
    }
    return cq->arr[cq->front];
}

void displayQueue(CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = cq->front;
    do {
        printf("%d ", cq->arr[i]);
        i = (i + 1) % cq->capacity;
    } while (i != (cq->rear + 1) % cq->capacity);
    printf("\n");
}

int main() {
    CircularQueue cq;
    initializeQueue(&cq, MAX_SIZE);

    int choice, element;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(&cq, element);
                break;

            case 2:
                dequeue(&cq);
                break;

            case 3:
                element = peek(&cq);
                if (element != -1) {
                    printf("Front element: %d\n", element);
                }
                break;

            case 4:
                displayQueue(&cq);
                break;

            case 5:
                free(cq.arr);
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
