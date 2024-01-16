#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int *arr;
    int front;
    int rear;
    int capacity;
} Deque;

void initializeDeque(Deque *dq, int capacity) {
    dq->arr = (int *)malloc(capacity * sizeof(int));
    dq->front = dq->rear = -1;
    dq->capacity = capacity;
}

int isFull(Deque *dq) {
    return ((dq->front == 0 && dq->rear == dq->capacity - 1) || (dq->front == dq->rear + 1));
}

int isEmpty(Deque *dq) {
    return (dq->front == -1);
}

void insertFront(Deque *dq, int element) {
    if (isFull(dq)) {
        printf("Deque Overflow: Cannot insert at the front, deque is full.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = dq->capacity - 1;
    } else {
        dq->front--;
    }

    dq->arr[dq->front] = element;
    printf("Inserted element %d at the front of the deque.\n", element);
}

void insertRear(Deque *dq, int element) {
    if (isFull(dq)) {
        printf("Deque Overflow: Cannot insert at the rear, deque is full.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == dq->capacity - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->arr[dq->rear] = element;
    printf("Inserted element %d at the rear of the deque.\n", element);
}

int deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow: Cannot delete from the front, deque is empty.\n");
        return -1; // You may choose to return a special value to indicate an error.
    }

    int deletedElement = dq->arr[dq->front];

    if (dq->front == dq->rear) {
        // Reset front and rear when the deque becomes empty
        dq->front = dq->rear = -1;
    } else if (dq->front == dq->capacity - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }

    printf("Deleted element %d from the front of the deque.\n", deletedElement);
    return deletedElement;
}

int deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow: Cannot delete from the rear, deque is empty.\n");
        return -1; // You may choose to return a special value to indicate an error.
    }

    int deletedElement = dq->arr[dq->rear];

    if (dq->front == dq->rear) {
        // Reset front and rear when the deque becomes empty
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = dq->capacity - 1;
    } else {
        dq->rear--;
    }

    printf("Deleted element %d from the rear of the deque.\n", deletedElement);
    return deletedElement;
}

void displayDeque(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = dq->front;
    do {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % dq->capacity;
    } while (i != (dq->rear + 1) % dq->capacity);
    printf("\n");
}

int main() {
    Deque dq;
    initializeDeque(&dq, MAX_SIZE);

    int choice, element;

    while (1) {
        printf("\nDouble Ended Queue (Deque) Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at the front: ");
                scanf("%d", &element);
                insertFront(&dq, element);
                break;

            case 2:
                printf("Enter element to insert at the rear: ");
                scanf("%d", &element);
                insertRear(&dq, element);
                break;

            case 3:
                deleteFront(&dq);
                break;

            case 4:
                deleteRear(&dq);
                break;

            case 5:
                displayDeque(&dq);
                break;

            case 6:
                free(dq.arr);
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
