# dynamic Stacke Data Structure using C

### initializing

 - ``` c++
    #include <stdio.h>
    #include "dynamic_stack.h"

    int main() {
    StackStatus_t status;

    // Create a stack with a maximum size of 5
    struct Stack_t *myStack = CreateStack(5, &status);
    if (status != STACK_OK) {
        printf("Failed to create stack\n");
        return -1;
    }
   
    return 0;
   }
   ```
### Playground

 - ``` c++
    // Push elements onto the stack
    for (int i = 0; i < 5; ++i) {
        int data = i;
        status = PushStack(myStack, &data);
        if (status != STACK_OK) {
            printf("Failed to push data onto stack\n");
            return -1;
        }
    }

    if (status == STACK_FULL) {
        printf("Stack is full\n");
    }

    // Pop elements from the stack
    for (int i = 0; i < 5; ++i) {
        const int *data = (int *)PopStack(myStack, &status);
        if (status == STACK_OK) {
            printf("Popped data: %d\n", *data);
        } else {
            printf("Failed to pop data from stack\n");
        }
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
   ``` 