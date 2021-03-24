#include <stack_array/stack_array.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    Stack_Array *stack_array = Stack_Array_init(3, sizeof(int));
    assert(stack_array != NULL);

    /* Testing is empty */
    int value;
    assert(Stack_Array_pop(stack_array, &value) == false);

    /* Adding first item */
    value = 10;
    assert(Stack_Array_push(stack_array, &value) == true);

    /* Adding second item */
    value = 20;
    assert(Stack_Array_push(stack_array, &value) == true);

    /* Retrieving a data */
    assert(Stack_Array_pop(stack_array, &value) == true);

    /* Verifying the last pushed value */
    assert(value == 20);

    value = 30;
    assert(Stack_Array_push(stack_array, &value) == true);

    value = 35;
    assert(Stack_Array_push(stack_array, &value) == true);

    /* Verifying stack limit */
    value = 40;
    assert(Stack_Array_push(stack_array, &value) == false);

    while(Stack_Array_pop(stack_array, &value))
    {
        printf("value: %d.\n", value);
    }

    /* Cleaning up stack */
    assert(Stack_Array_cleanup(stack_array) == true);
    
    return 0;
}