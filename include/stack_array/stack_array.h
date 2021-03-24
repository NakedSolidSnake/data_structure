#ifndef STACK_ARRAY_H_
#define STACK_ARRAY_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct stack_array Stack_Array;

Stack_Array *Stack_Array_init(int32_t stack_size, uint32_t object_size);
bool Stack_Array_push(Stack_Array * const stack_array, void *object);
bool Stack_Array_pop(Stack_Array * const stack_array, void *object);
bool Stack_Array_cleanup(Stack_Array *stack_array);


#endif /* STACK_H_ */
