#include <stack_array/stack_array.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct stack_array 
{
    int32_t top;
    int32_t stack_size;
    uint32_t object_size;
    void *storage;
};

enum stack_state {stack_empty = -1};

Stack_Array *Stack_Array_init(int32_t stack_size, uint32_t object_size)
{
    Stack_Array *stack_array = (Stack_Array *)malloc(sizeof(Stack_Array));
    if(stack_array)
    {
        stack_array->storage = malloc(object_size * stack_size);
        if(!stack_array->storage)
        {
            free(stack_array);
        }
        else
        {
            stack_array->object_size = object_size;
            stack_array->stack_size = stack_size;
            stack_array->top = stack_empty;
        }
        
    }

    return stack_array;
}

bool Stack_Array_push(Stack_Array * const stack_array, void *object)
{
    bool status = false;
    if(stack_array->top < stack_array->stack_size - 1)
    {
        stack_array->top++;
        memcpy(stack_array->storage + (stack_array->top * stack_array->object_size), object, stack_array->object_size);
        status = true;
    }


    return status;
}

bool Stack_Array_pop(Stack_Array * const stack_array, void *object)
{
    bool status = false;
    if(stack_array->top != stack_empty)
    {
        memcpy(object, stack_array->storage + (stack_array->top * stack_array->object_size), stack_array->object_size);
        stack_array->top--;
        status = true;
    }

    return status;
}

bool Stack_Array_cleanup(Stack_Array *stack_array)
{
    bool status = false;
    if(stack_array)
    {
        if(stack_array->storage)
            free(stack_array->storage);

        free(stack_array);
        status = true;
    }

    return status;
}
