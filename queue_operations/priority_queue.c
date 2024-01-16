#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int *arr;
    int front;
    int rear;
    int capacity;
} PriorityQueue;

void initializeQueue(PriorityQueue *pq, int capacity) {
    pq->arr = (int *)malloc(capacity * sizeof(int));
    pq->front = pq->rear = -1;
    pq->capacity = capacity;
}

int isFull(PriorityQueue *pq) {
    return (pq->rear == pq->capacity - 1);
}

int isEmpty(PriorityQueue *pq) {
    return (pq->front == -1);
}

void enqueue(PriorityQueue *pq, int element) {
    if (isFull(pq)) {
        printf("Queue Overflow: Cannot enqueue element %d, priority queue is full.\n", element);
        return;
    }

    int i;
    for (i = pq->rear; i >= pq->front && element > pq->arr[i]; i--) {
        pq->arr[i + 1] = pq->arr[i];
    }

    pq->arr[i + 1] = element;
    pq->rear++;

    if (pq->front == -1) {
        pq->front++;
    }

    printf("Enqueued element %d into the priority queue.\n", element);
}

int dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue Underflow: Cannot dequeue from an empty priority queue.\n");
        return -1; // You may choose to return a special value to indicate an error.
    }

    int dequeuedElement = pq->arr[pq->front];
    if (pq->front == pq->rear) {
        // Reset front and rear when the priority queue becomes empty
        pq->front = pq->rear = -1;
    } else {
        pq->front++;
    }

    printf("Dequeued element %d from the priority queue.\n", dequeuedElement);
    return dequeuedElement;
}

void displayQueue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue elements: ");
    for (int i = pq->front; i <= pq->rear; i++) {
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

int main() {
    PriorityQueue pq;
    initializeQueue(&pq, MAX_SIZE);

    int choice, element;

    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(&pq, element);
                break;

            case 2:
                dequeue(&pq);
                break;

            case 3:
                displayQueue(&pq);
                break;

            case 4:
                free(pq.arr);
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
