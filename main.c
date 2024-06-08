//
// Created by loay on 6/2/2024.
//
#include "dynamic_stack.h"

StackStatue_t ret;
Stack_t *mystack = 0;

int main(void) {
    // go to the header file and remove the DEBUG defenetion (at line 4) to disable debugging...
    int desitred_val_to_push_1 = 3;
    char desitred_val_to_push_2 = "test";
    double desitred_val_to_push_3 = 3.14;
    long long desitred_val_to_push_4 = 88;
    int stackC;


    mystack = CreateStack(5, &ret);


    PushStack(mystack, &desitred_val_to_push_4);
    PushStack(mystack, &desitred_val_to_push_1);
    PushStack(mystack, &desitred_val_to_push_3);
    PushStack(mystack, &desitred_val_to_push_2);
    PopStack(mystack, &ret);
    StackCount(mystack, &stackC);

    DestroyStack(mystack, &ret);
    return 0;
}

