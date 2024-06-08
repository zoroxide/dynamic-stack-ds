#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H
#include <stdlib.h>
#include <stdio.h>

#define DEBUG

/*
 * @brief: Enum to define stack status
 * @types:
 *       - (STACK_NOK) : stack is not ok or an error happened
 *       - (STACK_OK) : stack is ok and no errors happened
 *       - (STACK_FULL) : stack is full of elements
 *       - (STACK_EMPTY) : stack is empty, no data in it
 *       - (STACK_NULL_POINTER) : the user has passed a null pointer to any of the stack functions
 */
typedef enum {
    STACK_NOK = 0,
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL_POINTER
} StackStatus_t;

/*
 * @brief: Stack Data Structure with dynamic size
 * @types:
 *       - (StackArray) : array of pointers that each element in it holds the address of the first element
 *       - (ElementCount) : how many elements are located in the data array
 *       - (StackMaxsize) : max size of the stack
 *       - (StackTop) : the index of the top element of the stack
 */
struct Stack_t {
    void **StackArray;
    int ElementCount;
    int StackMaxsize;
    int StackTop;
};

/*
 * @brief: checks if the stack is empty
 * @param: (stack_obj) an address of the desired stack
 * @retval: "0" if the stack is not empty, "1" if it is empty
 */
static int StackIsEmpty(const struct Stack_t* stack_obj) {
    return (stack_obj->ElementCount == 0);
}

/*
 * @brief: checks if the stack is full
 * @param: (stack_obj) an address of the desired stack
 * @retval: "0" if the stack is not full, "1" if it is full
 */
static int StackIsFull(const struct Stack_t* stack_obj) {
    return (stack_obj->StackMaxsize == stack_obj->ElementCount);
}

// Core Functions

/*
 * @brief: creates the stack and allocates it and its array of elements in the memory
 * @param: (maxsize) is the max size that stack could hold
 * @param: (ret_status) is an address of an existing StackStatus_t variable, used to return the status of the stack
 * @retval: returns the address of the Stack in the memory
 */
struct Stack_t* CreateStack(const int maxsize, StackStatus_t *ret_status) {
    struct Stack_t *myStack = NULL;
    if(ret_status == NULL) {
    #ifdef DEBUG
            printf("[ ERROR ] : NULL POINTER DETECTED\n");
    #endif
        return NULL;
    }

    myStack = (struct Stack_t *) malloc(sizeof(struct Stack_t));
    if(!myStack) {
    #ifdef DEBUG
            printf("[ ERROR ] : STACK ALLOCATION FAILED\n");
    #endif
        *ret_status = STACK_NOK;
        return NULL;
    }

    myStack->StackTop = -1;
    myStack->ElementCount = 0;
    myStack->StackMaxsize = maxsize;
    myStack->StackArray = (void **)calloc(myStack->StackMaxsize, sizeof(void *));
    if(!myStack->StackArray) {
        free(myStack);
        *ret_status = STACK_NOK;
        return NULL;
    } else {
        *ret_status = STACK_OK;
    }

    #ifdef DEBUG
        printf("[ INFO ] STACK CREATED\n");
    #endif
    return myStack;
}

/*
 * @brief: Destroys an existing Stack
 * @param: (stack_obj) the address of stack itself
 * @param:(ret_status) is an address of an existing StackStatus_t variable, used to return the status of the stack
 * @retval: returns NULL if the process is done
 */
struct Stack_t* DestroyStack(struct Stack_t* stack_obj, StackStatus_t *ret_status) {
    if(ret_status == NULL || stack_obj == NULL) {
    #ifdef DEBUG
            printf("[ ERROR ] : NULL POINTER DETECTED\n");
    #endif
        if (ret_status != NULL) {
            *ret_status = STACK_NULL_POINTER;
        }
        return NULL;
    }

    free(stack_obj->StackArray);
    free(stack_obj);
    *ret_status = STACK_OK;

    #ifdef DEBUG
        printf("[ INFO ] STACK DELETED \n");
    #endif

    return NULL;
}

/*
 * @brief: Function to push an element to the stack
 * @param: (stack_obj) the address of stack itself
 * @param: (itemPtr) is an address of the data you want to push
 * @retval: STACK_OK if everything is good, STACK_NOK if any error happened, STACK_NULL_POINTER if null pointer is passed to the function arguments
 */
StackStatus_t PushStack(struct Stack_t* stack_obj, void* itemPtr) {
    if(stack_obj == NULL || itemPtr == NULL) {
        #ifdef DEBUG
                printf("[ ERROR ] : NULL POINTER DETECTED\n");
        #endif
        return STACK_NULL_POINTER;
    }

    if(StackIsFull(stack_obj)) {
        #ifdef DEBUG
                printf("[ ERROR ] : STACK OVERFLOW\n");
        #endif
        return STACK_FULL;
    }

    stack_obj->StackTop++;
    stack_obj->StackArray[stack_obj->StackTop] = itemPtr;
    stack_obj->ElementCount++;

        #ifdef DEBUG
            printf("[ OK ] : DATA: [%p] => (%i) is PUSHED SUCCESSFULLY\n", (void*)itemPtr, *(char*)itemPtr);
        #endif

    return STACK_OK;
}

/*
 * @brief: removes the Stack Top Value
 * @param: (stack_obj) the address of stack itself
 * @param:(ret_status) is an address of an existing StackStatus_t variable, used to return the status of the stack
 * @retval: an address of the variable that will hold the output data from the function (save this function in a pointer)
 */
void* PopStack(struct Stack_t *stack_obj, StackStatus_t *ret_status) {
    if(ret_status == NULL || stack_obj == NULL) {
        #ifdef DEBUG
                printf("[ ERROR ] : NULL POINTER DETECTED\n");
        #endif
        if (ret_status != NULL) {
            *ret_status = STACK_NULL_POINTER;
        }
        return NULL;
    }

    if(StackIsEmpty(stack_obj)) {
        #ifdef DEBUG
                printf("[ ERROR ] : STACK IS EMPTY\n");
        #endif
        *ret_status = STACK_EMPTY;
        return NULL;
    }

    void *poppedData = stack_obj->StackArray[stack_obj->StackTop];
    stack_obj->StackTop--;
    stack_obj->ElementCount--;
    *ret_status = STACK_OK;

    #ifdef DEBUG
        printf("[ OK ] : Data: (%i) is POPPED\n", *(int*)poppedData);
    #endif

    return poppedData;
}

/*
 * @brief: Copies the stack top element
 * @param: (stack_obj) the address of stack itself
 * @param:(ret_status) is an address of an existing StackStatus_t variable, used to return the status of the stack
 * @retval: an address of the variable that will hold the output data from the function (save this function in a pointer)
 */
void* StackTop(const struct Stack_t* stack_obj, StackStatus_t* ret_status) {
    if(ret_status == NULL || stack_obj == NULL) {
        #ifdef DEBUG
                printf("[ ERROR ] : NULL POINTER DETECTED\n");
        #endif
        if (ret_status != NULL) {
            *ret_status = STACK_NULL_POINTER;
        }
        return NULL;
    }

    if(StackIsEmpty(stack_obj)) {
        #ifdef DEBUG
                printf("[ ERROR ] : STACK IS EMPTY\n");
        #endif
        *ret_status = STACK_EMPTY;
        return NULL;
    }

    void *topData = stack_obj->StackArray[stack_obj->StackTop];
    *ret_status = STACK_OK;

    return topData;
}

/*
 * @brief: Gets the count of elements in the stack
 * @param: (stack_obj) the address of stack itself
 * @param: (stack_count) is the address of an existing variable to hold the output of the function
 * @retval: STACK_OK if everything is good, STACK_NOK if any error happened, STACK_NULL_POINTER if null pointer is passed to the function arguments
 */
StackStatus_t StackCount(const struct Stack_t* stack_obj, int *stack_count) {
    if(stack_obj == NULL || stack_count == NULL) {
#ifdef DEBUG
        printf("[ ERROR ] : NULL POINTER DETECTED\n");
#endif
        return STACK_NULL_POINTER;
    }

    *stack_count = stack_obj->ElementCount;

#ifdef DEBUG
    printf("[ OK ] : STACK COUNT IS : %i\n", *(int*)stack_count);
#endif

    return STACK_OK;
}

#endif //DYNAMIC_STACK_H
