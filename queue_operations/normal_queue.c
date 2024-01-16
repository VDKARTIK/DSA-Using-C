#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void enqueue(int queue[], int *front, int *rear, int capacity, int element) {
    if (*rear == capacity - 1) {
        printf("Queue Overflow: Cannot enqueue element %d, queue is full.\n", element);
        return;
    }
    if (*front == -1) {
        *front = 0;
    }
    queue[++(*rear)] = element;
    printf("Enqueued element %d into the queue.\n", element);
}

int dequeue(int queue[], int *front, int *rear) {
    if (*front == -1) {
        printf("Queue Underflow: Cannot dequeue from an empty queue.\n");
        return -1; // You may choose to return a special value to indicate an error.
    }
    int dequeuedElement = queue[(*front)++];
    if (*front > *rear) {
        // Reset front and rear when the queue becomes empty
        *front = *rear = -1;
    }
    printf("Dequeued element %d from the queue.\n", dequeuedElement);
    return dequeuedElement;
}

int peek(int queue[], int front) {
    if (front == -1) {
        printf("Queue is empty, cannot peek.\n");
        return -1; // You may choose to return a special value to indicate an error.
    }
    return queue[front];
}

int isEmpty(int front) {
    return (front == -1);
}

int main() {
    int queue[MAX_SIZE];
    int front = -1, rear = -1; // Initialize front and rear to -1 to indicate an empty queue

    int choice, element;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(queue, &front, &rear, MAX_SIZE, element);
                break;

            case 2:
                dequeue(queue, &front, &rear);
                break;

            case 3:
                element = peek(queue, front);
                if (element != -1) {
                    printf("Front element: %d\n", element);
                }
                break;

            case 4:
                if (isEmpty(front)) {
                    printf("The queue is empty.\n");
                } else {
                    printf("The queue is not empty.\n");
                }
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
