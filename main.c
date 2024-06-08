//
// Created by loay on 6/2/2024.
//
#include "dynamic_stack.h"

StackStatue_t ret;
Stack_t *mystack = 0;
int val = 1;

// go to the header file and remove the DEBUG defenetion (at line 4) to disable debugging...
int main(void) {
    mystack = CreateStack(5, &ret);


    // int desitred_val_to_push_1 = 3;PushStack(mystack, &desitred_val_to_push_1);
    // char desitred_val_to_push_2 = "test";PushStack(mystack, &desitred_val_to_push_2);
    // double desitred_val_to_push_3 = 3.14;PushStack(mystack, &desitred_val_to_push_3);
    // long long desitred_val_to_push_4 = 88;PushStack(mystack, &desitred_val_to_push_4);

    // for(int i = 0; i<5; i++) {
    //     PushStack(mystack, &val);
    // }

    // for(int i = 0; i<5; i++) {
    //     PopStack(mystack, &ret);
    // }
    DestroyStack(mystack, &ret);
    return 0;
}

