#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Function demonstrating stack allocation */
static void stack_example(void)
{
    uint32_t local_array[5] = {10U, 20U, 30U, 40U, 50U};

    printf("\n--- Stack Example ---\n");

    for (size_t i = 0U; i < 5U; i++)
    {
        printf("local_array[%zu] = %u\n",
               i,
               (unsigned int)local_array[i]);
    }

    printf("Array size: %zu bytes\n", sizeof(local_array));
}

/* Function demonstrating heap allocation */
static void heap_example(void)
{
    uint32_t *heap_array;
    size_t array_count = 5U;

    printf("\n--- Heap Example ---\n");

    heap_array = malloc(array_count * sizeof(*heap_array));

    if (heap_array == NULL)
    {
        printf("Heap allocation failed\n");
        return;
    }

    for (size_t i = 0U; i < array_count; i++)
    {
        heap_array[i] = (uint32_t)((i + 1U) * 100U);
    }

    for (size_t i = 0U; i < array_count; i++)
    {
        printf("heap_array[%zu] = %u\n",
               i,
               (unsigned int)heap_array[i]);
    }

    printf("Allocated size: %zu bytes\n",
           array_count * sizeof(*heap_array));

    free(heap_array);
    heap_array = NULL;

    printf("Heap memory released.\n");
}

int main(void)
{
    printf("--- Stack vs Heap ---\n");

    stack_example();
    heap_example();

    return 0;
}
