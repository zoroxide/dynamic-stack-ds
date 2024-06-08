#include <stdio.h>
#include "dynamic_stack.h"


int main() {

    StackStatus_t status;

    // Create a stack with a maximum size of 5
    struct Stack_t *myStack = CreateStack(5, &status);

    if(status != STACK_OK) {
        printf("Failed to create stack\n");
        return -1;
    }

    // Push elements onto the stack
    for (int i = 1; i <= 5; ++i) {
        int data = i;
        PushStack(myStack, &data);
    }

    if (status == STACK_FULL) {
        printf("Stack is full\n");
    }

    // Pop elements from the stack
    for (int i = 0; i < 5; ++i) {
        PopStack(myStack, &status);
    }

    // Check if the stack is empty
    if (StackIsEmpty(myStack)) {
        printf("Stack is empty\n");
    }

    // Destroy the stack
    DestroyStack(myStack, &status);

    if (status != STACK_OK) {
        printf("Failed to destroy stack\n");
        return -1;
    }

    return 0;
}
