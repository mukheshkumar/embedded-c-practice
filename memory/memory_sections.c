#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Typically placed in .data */
uint32_t initialized_global = 100U;

/* Typically placed in .bss */
uint32_t uninitialized_global;

/* Typically placed in .rodata */
const uint32_t constant_global = 500U;

/* Typically placed in .bss */
static uint32_t static_uninitialized;

/* Typically placed in .data */
static uint32_t static_initialized = 25U;

/* Function code: typically .text */
static void display_memory_info(void)
{
    /* Local variable: typically stack */
    uint32_t local_variable = 10U;

    printf("Local variable (stack): %u\n",
           (unsigned int)local_variable);
}

int main(void)
{
    /* Local variables: typically stack */
    uint32_t stack_variable = 200U;
    uint8_t *heap_ptr;

    /* Dynamically allocated memory: heap */
    heap_ptr = malloc(sizeof(uint8_t));

    if (heap_ptr == NULL)
    {
        printf("Heap allocation failed\n");
        return 1;
    }

    *heap_ptr = 50U;

    printf("Initialized global (.data): %u\n",
           (unsigned int)initialized_global);

    printf("Uninitialized global (.bss): %u\n",
           (unsigned int)uninitialized_global);

    printf("Constant global (.rodata): %u\n",
           (unsigned int)constant_global);

    printf("Static uninitialized (.bss): %u\n",
           (unsigned int)static_uninitialized);

    printf("Static initialized (.data): %u\n",
           (unsigned int)static_initialized);

    printf("Local variable (stack): %u\n",
           (unsigned int)stack_variable);

    printf("Heap variable: %u\n",
           (unsigned int)*heap_ptr);

    display_memory_info();

    free(heap_ptr);
    heap_ptr = NULL;

    return 0;
}
