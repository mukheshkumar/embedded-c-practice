
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t data[5] = {10U, 20U, 30U, 40U, 50U};
    uint8_t *ptr = data;

    printf("=== Pointer Arithmetic ===\n");

    /* Access first element */
    printf("First Element    : %u\n", (unsigned int)*ptr);

    /* Increment pointer */
    ptr++;

    printf("Second Element   : %u\n", (unsigned int)*ptr);

    /* Pointer offset */
    ptr = data + 2U;

    printf("Third Element    : %u\n", (unsigned int)*ptr);

    /* Pointer decrement */
    ptr--;

    printf("After Decrement  : %u\n", (unsigned int)*ptr);

    /* Array traversal using pointer */
    printf("\n=== Array Traversal ===\n");

    ptr = data;

    for (uint8_t index = 0U; index < 5U; index++)
    {
        printf("Element %u : %u\n",
               (unsigned int)index,
               (unsigned int)*(ptr + index));
    }

    /* Pointer difference */
    printf("\n=== Pointer Difference ===\n");

    uint8_t *start_ptr = &data[0];
    uint8_t *end_ptr = &data[4];

    printf("Element distance : %td\n", end_ptr - start_ptr);

    /* Pointer movement */
    printf("\n=== Pointer Movement ===\n");

    ptr = &data[0];

    printf("Current Element  : %u\n", (unsigned int)*ptr);

    ptr += 2;

    printf("After ptr += 2   : %u\n", (unsigned int)*ptr);

    ptr -= 1;

    printf("After ptr -= 1   : %u\n", (unsigned int)*ptr);

    /* Pointer traversal with a boundary */
    printf("\n=== Boundary-Aware Traversal ===\n");

    uint8_t *array_end = data + 5U;

    for (ptr = data; ptr < array_end; ptr++)
    {
        printf("Value : %u\n", (unsigned int)*ptr);
    }

    return 0;
}
