
#include <stdio.h>

int main(void)
{
    int value = 100;
    int *ptr = &value;

    printf("=== Pointer Basics ===\n");

    /* Original variable */
    printf("Value             : %d\n", value);

    /* Address of variable */
    printf("Address of value  : %p\n", (void *)&value);

    /* Pointer stores the address */
    printf("Pointer address   : %p\n", (void *)ptr);

    /* Dereferencing pointer */
    printf("Pointer value     : %d\n", *ptr);

    /* Modify variable through pointer */
    *ptr = 200;

    printf("\n=== After Pointer Modification ===\n");
    printf("Updated value     : %d\n", value);
    printf("Updated via ptr   : %d\n", *ptr);

    /* Pointer reassignment */
    int another_value = 500;
    ptr = &another_value;

    printf("\n=== Pointer Reassignment ===\n");
    printf("Another value     : %d\n", another_value);
    printf("Pointer address   : %p\n", (void *)ptr);
    printf("Pointer value     : %d\n", *ptr);

    /* NULL pointer example */
    int *null_ptr = NULL;

    printf("\n=== NULL Pointer ===\n");

    if (null_ptr == NULL)
    {
        printf("Pointer is NULL\n");
    }

    return 0;
}
