#include <stdio.h>
#include <stdint.h>

/* Pointer to constant data */
static void display_value(const uint32_t *ptr)
{
    if (ptr != NULL)
    {
        printf("Value: %lu\n", (unsigned long)*ptr);

        /* *ptr = 20U;  Not allowed */
    }
}

/* Constant pointer */
static void increment_value(uint32_t *const ptr)
{
    if (ptr != NULL)
    {
        (*ptr)++;

        /* ptr = NULL;  Not allowed */
    }
}

/* Constant pointer to constant data */
static void display_read_only(const uint32_t *const ptr)
{
    if (ptr != NULL)
    {
        printf("Read-only value: %lu\n",
               (unsigned long)*ptr);
    }
}

int main(void)
{
    uint32_t value = 10U;
    uint32_t another_value = 50U;

    /* Pointer to constant data */
    const uint32_t *ptr1 = &value;

    ptr1 = &another_value; /* Allowed */
    /* *ptr1 = 100U;       Not allowed */

    /* Constant pointer */
    uint32_t *const ptr2 = &value;

    *ptr2 = 20U; /* Allowed */
    /* ptr2 = &another_value; Not allowed */

    /* Constant pointer to constant data */
    const uint32_t *const ptr3 = &value;

    /* *ptr3 = 100U; Not allowed */
    /* ptr3 = &another_value; Not allowed */

    display_value(&value);
    increment_value(&value);
    display_read_only(&value);

    printf("Final value: %lu\n", (unsigned long)value);

    return 0;
}
