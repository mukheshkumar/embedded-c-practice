#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t value = 0x12345678U;
    uint8_t *byte_ptr = (uint8_t *)&value;

    printf("Variable value: 0x%08lX\n",
           (unsigned long)value);

    printf("Variable address: %p\n",
           (void *)&value);

    printf("Byte-wise memory representation:\n");

    for (size_t i = 0U; i < sizeof(value); i++)
    {
        printf("Address: %p | Data: 0x%02X\n",
               (void *)(byte_ptr + i),
               (unsigned int)byte_ptr[i]);
    }

    return 0;
}
