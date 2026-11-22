#include <stdio.h>
#include <stdint.h>

typedef union
{
    uint8_t byte;
    uint16_t half_word;
    uint32_t word;
} Data;

/* Display object representation byte by byte */
static void display_bytes(const Data *data, size_t size)
{
    const unsigned char *byte_ptr = (const unsigned char *)data;

    for (size_t i = 0U; i < size; i++)
    {
        printf("Byte %zu: 0x%02X\n",
               i,
               (unsigned int)byte_ptr[i]);
    }
}

int main(void)
{
    Data data;

    printf("Union size: %zu bytes\n", sizeof(data));

    /* Store byte */
    data.byte = 0xABU;
    printf("\nByte member: 0x%02X\n",
           (unsigned int)data.byte);

    /* Store half-word */
    data.half_word = 0x1234U;
    printf("\nHalf-word member: 0x%04X\n",
           (unsigned int)data.half_word);

    printf("Memory representation of half-word:\n");
    display_bytes(&data, sizeof(data));

    /* Store word */
    data.word = 0x12345678U;
    printf("\nWord member: 0x%08lX\n",
           (unsigned long)data.word);

    printf("Memory representation of word:\n");
    display_bytes(&data, sizeof(data));

    return 0;
}
