#include "dynamic_stack.h"
#include <stdlib.h>
#include <stdio.h>

int StackIsEmpty(const Stack_t *stack_obj){
    return (stack_obj->ElementCount == 0);

}
int StackIsFull(const Stack_t *stack_obj) {
    return (stack_obj->StackMaxsize == stack_obj->ElementCount);
}

Stack_t *CreateStack(const int maxsize, StackStatue_t *ret_status){
    Stack_t *myStack = NULL;
    if(ret_status == NULL) {
        #ifdef DEBUG
            printf("[ ERROR ] : NULL POINTER DETECTED\n");
        #endif

        *ret_status = STACK_NULL_POINTER;
    }else {
        myStack = (Stack_t *) malloc(sizeof(Stack_t));
        #ifdef DEBUG
                printf("=== [ STACK CREATED ] ===\n");
        #endif
        if(!myStack) {
            #ifdef DEBUG
                printf("[ ERROR ] : STACK ALLOCATION FIELD\n");
            #endif
            *ret_status = STACK_NOK;
            myStack = NULL;
        }
        myStack->StackTop = -1;
        myStack->ElementCount = 0;
        myStack->StackMaxsize = maxsize;
        myStack->StackArray = (void **)calloc(myStack->StackMaxsize, sizeof(void *));
        if(!myStack->StackArray) {
            free(myStack);
            myStack = NULL;
            *ret_status = STACK_NOK;
        }else {
            *ret_status = STACK_OK;
        }
    }
    return myStack;
}
Stack_t *DestroyStack(Stack_t *stack_obj, StackStatue_t *ret_status){
    if(ret_status == NULL && stack_obj == NULL) {
        #ifdef DEBUG
                printf("[ ERROR ] : NULL POINTER DETECTED\n");
        #endif
        *ret_status = STACK_NULL_POINTER;
    }else {
        free(stack_obj->StackArray);
        free(stack_obj);
        *ret_status = STACK_OK;
        #ifdef DEBUG
                printf("=== [ STACK DESTROYED ]=== \n");
        #endif
    }
    return NULL;
}
StackStatue_t PushStack(Stack_t *stack_obj, void *itemPtr){
    StackStatue_t ret_status = STACK_NOK;
    if(stack_obj == NULL && itemPtr==NULL) {
        #ifdef DEBUG
                printf("[ ERROR ] : NULL POINTER DETECTED\n");
        #endif
        ret_status = STACK_NULL_POINTER;
    }else {
        if(StackIsFull(stack_obj)) {
            #ifdef DEBUG
                printf("[ ERROR ] : STACK OVERFLOW\n");
            #endif
            ret_status = STACK_FULL;
        }else {
            (stack_obj->StackTop)++;
            stack_obj->StackArray[stack_obj->StackTop] = itemPtr;
            stack_obj->ElementCount++;
            #ifdef DEBUG
                printf("[ OK ] : DATA: [%p] => (%i) is PUSHED SUCCESSFULLY\n", (void*)itemPtr, *(char*)itemPtr);
            #endif
        }
        ret_status = STACK_OK;
    }

    return ret_status;
}

void* PopStack(Stack_t *stack_obj, StackStatue_t *ret_status){
    void *popedData = NULL;
    if(ret_status == NULL && stack_obj == NULL) {
        #ifdef DEBUG
                printf("[ ERROR ] : NULL POINTER DETECTED\n");
        #endif
        *ret_status = STACK_NULL_POINTER;
    } else {
        if(StackIsEmpty(stack_obj)) {
            #ifdef DEBUG
                printf("[ ERROR ] : STACK IS EMPTY\n");
            #endif
            *ret_status = STACK_EMPTY;
            popedData = NULL;
        }
        popedData = stack_obj->StackArray[stack_obj->StackTop];
        stack_obj->StackTop--;
        stack_obj->ElementCount--;
        *ret_status = STACK_OK;
        #ifdef DEBUG
                printf("[ OK ] : Data: (%i) is POPED\n", *(int*)popedData);
        #endif
    }
    return popedData;
}

void *StackTop(const Stack_t *stack_obj, StackStatue_t *ret_status){
    void *popedData = NULL;
    if(ret_status == NULL && stack_obj == NULL) {
        #ifdef DEBUG
                printf("[ ERROR ] : NULL POINTER DETECTED\n");
        #endif
        *ret_status = STACK_NULL_POINTER;
    } else {
        if(StackIsEmpty(stack_obj)) {
            #ifdef DEBUG
                        printf("[ ERROR ] : STACK IS EMPTY\n");
            #endif
            *ret_status = STACK_EMPTY;
            popedData = NULL;
        }
        popedData = stack_obj->StackArray[stack_obj->StackTop];
        *ret_status = STACK_OK;
    }
    return popedData;
}

StackStatue_t StackCount(const Stack_t *stack_obj, int *stack_count){
    StackStatue_t ret_status = STACK_NOK;
    if(stack_obj == NULL && stack_count) {
        #ifdef DEBUG
                printf("[ ERROR ] : NULL POINTER DETECTED\n");
        #endif
        ret_status = STACK_NULL_POINTER;
    }else {
        *stack_count = stack_obj->ElementCount;
        #ifdef DEBUG
                printf("[ OK ] : STACK COUNT IS : %i\n", *(int*)stack_count);
        #endif
        ret_status = STACK_OK;
    }
    return ret_status;
}


