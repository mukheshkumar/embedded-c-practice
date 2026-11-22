#include <stdio.h>
#include <stdint.h>

/* Structure with inefficient member ordering */
typedef struct
{
    uint8_t  byte_value;
    uint32_t word_value;
    uint16_t half_word_value;
} Structure_1;

/* Structure with reordered members */
typedef struct
{
    uint32_t word_value;
    uint16_t half_word_value;
    uint8_t  byte_value;
} Structure_2;

int main(void)
{
    printf("--- Structure Padding and Alignment ---\n\n");

    printf("Structure 1 size: %zu bytes\n",
           sizeof(Structure_1));

    printf("Structure 2 size: %zu bytes\n",
           sizeof(Structure_2));

    printf("\nStructure 1 member sizes:\n");
    printf("uint8_t  : %zu bytes\n", sizeof(uint8_t));
    printf("uint32_t : %zu bytes\n", sizeof(uint32_t));
    printf("uint16_t : %zu bytes\n", sizeof(uint16_t));

    return 0;
}
