#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void push(int stack[], int *top, int capacity, int element) {
    if (*top == capacity - 1) {
        printf("Stack Overflow: Cannot push element %d, stack is full.\n", element);
        return;
    }
    stack[++(*top)] = element;
    printf("Pushed element %d onto the stack.\n", element);
}

int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow: Cannot pop from an empty stack.\n");
        return -1; // You may choose to return a special value to indicate an error.
    }
    int poppedElement = stack[(*top)--];
    printf("Popped element %d from the stack.\n", poppedElement);
    return poppedElement;
}

int peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty, cannot peek.\n");
        return -1; // You may choose to return a special value to indicate an error.
    }
    return stack[top];
}

int isEmpty(int top) {
    return (top == -1);
}

int main() {
    int stack[MAX_SIZE];
    int top = -1; // Initialize top to -1 to indicate an empty stack

    int choice, element;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(stack, &top, MAX_SIZE, element);
                break;

            case 2:
                pop(stack, &top);
                break;

            case 3:
                element = peek(stack, top);
                if (element != -1) {
                    printf("Top element: %d\n", element);
                }
                break;

            case 4:
                if (isEmpty(top)) {
                    printf("The stack is empty.\n");
                } else {
                    printf("The stack is not empty.\n");
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
