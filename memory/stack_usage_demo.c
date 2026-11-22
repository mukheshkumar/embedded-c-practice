#include <stdio.h>
#include <stdint.h>

/* Function with a local buffer */
static void function_c(void)
{
    volatile uint8_t local_buffer[128];

    for (size_t i = 0U; i < sizeof(local_buffer); i++)
    {
        local_buffer[i] = (uint8_t)i;
    }

    printf("Function C: Local buffer = %zu bytes, first value = %u\n",
           sizeof(local_buffer),
           (unsigned int)local_buffer[0]);
}

/* Nested function call */
static void function_b(void)
{
    volatile uint8_t local_buffer[256];

    local_buffer[0] = 0xAAU;

    printf("Function B: Local buffer = %zu bytes\n",
           sizeof(local_buffer));

    function_c();
}

/* Entry into call chain */
static void function_a(void)
{
    volatile uint8_t local_buffer[512];

    local_buffer[0] = 0x55U;

    printf("Function A: Local buffer = %zu bytes\n",
           sizeof(local_buffer));

    function_b();
}

int main(void)
{
    printf("Stack Usage Demonstration\n");
    printf("------------------------\n");

    function_a();

    printf("\nFunction call chain completed.\n");

    return 0;
}
