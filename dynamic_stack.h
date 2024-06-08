#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#define DEBUG


/*
 * @brief: Stack Data Structure with dynamic size
 * @types:
 *       - (StackArray) : array of pointers that each element in it holds the adress of the first element
 *       - (ElementCount) : how many elements are located in the data array
 *       - (StackMaxsize) : max size of the stack
 *       - (StackTop) : the index of the top element of the stack
 */
typedef struct {
    void **StackArray;
    int ElementCount;
    int StackMaxsize;
    int StackTop;
} Stack_t;


/*
 * @brief:
 * @types:
 *       - (STACK_NOK) : stack is not ok or error happend
 *       - (STACK_OK) : stack is ok and no errors happend
 *       - (STACK_FULL) : stack is full of elements
 *       - (STACK_EMPTY) : stack is empty, no data in it
 *       - (STACK_NULL_POINTER) : the user have passed a null pointer to any of the stack functions
 */
typedef enum {
    STACK_NOK = 0,
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL_POINTER
} StackStatue_t;


//Helper Functions


/*
 * @brief: checks if the stack is empty
 * @param: (stack_obj) an adress of the desired stack
 * @retval: "0" if the stack is not empty, "1" if it is empty
 */
static int StackIsEmpty(const Stack_t* stack_obj);

/*
 * @brief: checks if the stack is Full
 * @param: (stack_obj) an adress of the desired stack
 * @retval: "0" if the stack is not Full, "1" if it is Full
 */
static int StackIsFull(const Stack_t* stack_obj);


//Core Functions

/*
 * @brief: creates the stack and allocates it and its array of elements in the memorey
 * @param: (maxsize) is the max size that stack could hold
 * @param: (ret_status) is a adress of an excesting StackStatue_t variable, used to return the status of the stack
 * @retval: returns the adress of the Stack in the memorey
 */
Stack_t* CreateStack(const int maxsize, StackStatue_t *ret_status);

/*
 * @brief: Destroeys an excesing Stack
 * @param: (stack_obj) the adress of stack it self
 * @param:(ret_status) is a adress of an excesting StackStatue_t variable, used to return the status of the stack
 * @retval: returns NULL if the process is Done
 */
Stack_t* DestroyStack(Stack_t* stack_obj, StackStatue_t *ret_status);

/*
 * @brief: Function stack push element to the stack
 * @param: (stack_obj) the adress of stack it self
 * @param: (itemPtr) is an adress of the data you want to push
 * @retval: STACK_OK if everyting is good, STACK_NOK is any error happend, STACK_NULL_POINTER is null pointer is passed to the function arguments
 */
StackStatue_t PushStack(Stack_t* stack_obj, void* itemPtr);

/*
 * @brief:
 * @param: (stack_obj) the adress of stack it self
 * @param: (stack_count) is the adress of an excesting variable to hold the output of the function
 * @retval: STACK_OK if everyting is good, STACK_NOK is any error happend, STACK_NULL_POINTER is null pointer is passed to the function arguments
 */
StackStatue_t StackCount(const Stack_t* stack_obj, int *stack_count);;

/*
 * @brief: removes the Stack Top Value
 * @param: (stack_obj) the adress of stack it self
 * @param:(ret_status) is a adress of an excesting StackStatue_t variable, used to return the status of the stack
 * @retval: an adress of the of the variable the will hold the output data from the function (save this funtction in a pointer)
 */
void* PopStack(Stack_t *stack_obj, StackStatue_t *ret_status);

/*
 * @brief: Copies the stack top element
 * @param: (stack_obj) the adress of stack it self
 * @param:(ret_status) is a adress of an excesting StackStatue_t variable, used to return the status of the stack
 * @retval: an adress of the of the variable the will hold the output data from the function (save this funtction in a pointer)
 */
void* StackTop(const Stack_t* stack_obj, StackStatue_t* ret_status);


#endif //DYNAMIC_STACK_H
