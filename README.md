# dynamic Stacke Data Structure using C

### initializing

 - ``` c++
    #include "dynamic_stack.h"
    StackStatue_t ret;
    Stack_t *mystack = 0;

    // go to the header file and remove the DEBUG defenetion (at line 4) to disable debugging...
    int main(void) {
    mystack = CreateStack(5, &ret);
    // playgroung
    DestroyStack(mystack, &ret);
    return 0;
   } 
   ```
### Playground

 - ``` c++
    /* manually add data */
    int desitred_val_to_push_1 = 3;PushStack(mystack, &desitred_val_to_push_1);
    char desitred_val_to_push_2 = "test";PushStack(mystack, &desitred_val_to_push_2);
    double desitred_val_to_push_3 = 3.14;PushStack(mystack, &desitred_val_to_push_3);
    long long desitred_val_to_push_4 = 88;PushStack(mystack, &desitred_val_to_push_4);

    /* add data using for loop*/
    for(int i = 0; i<5; i++) {
        PushStack(mystack, &val);
    }
    
    /* remove data using for loop */
    for(int i = 0; i<5; i++) {
        PopStack(mystack, &ret);
    }

    /* adding data using while loop */
    while(!StackIsFull(mystack)) {
        PushStack(mystack, &val);
    }

    /*removing data using while loop*/
    while(!StackIsEmpty(mystack)) {
        PopStack(mystack, &ret);
    } 
   ``` 