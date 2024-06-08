# dynamic Stacke Data Structure using C

### initializing

 - ``` c++
    #include <stdio.h>
    #include "dynamic_stack.h"

    int main() {
    StackStatus_t status;
    int *data;

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
    StackStatus_t status;
    int *data;


    // Create a stack with a maximum size of 5
    struct Stack_t *myStack = CreateStack(5, &status);
    if (status != STACK_OK) {
        printf("Failed to create stack\n");
        return -1;
    }

    // Push elements onto the stack
    for (int i = 0; i < 5; ++i) {
        data = (int *)malloc(sizeof(int));
        *data = i;
        status = PushStack(myStack, data);
        if (status != STACK_OK) {
            printf("Failed to push data onto stack\n");
            return -1;
        }
    }

    // Try pushing one more element to check for stack overflow
    data = (int *)malloc(sizeof(int));
    *data = 5;
    status = PushStack(myStack, data);
    if (status == STACK_FULL) {
        printf("Stack is full\n");
    }

    // Pop elements from the stack
    for (int i = 0; i < 5; ++i) {
        data = (int *)PopStack(myStack, &status);
        if (status == STACK_OK) {
            printf("Popped data: %d\n", *data);
            free(data); // Free the memory allocated for the popped element
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