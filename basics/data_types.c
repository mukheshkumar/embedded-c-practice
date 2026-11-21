
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(void)
{
    /* Standard C data types */
    char character = 'A';
    int integer = 100;
    float floating_point = 12.5f;
    double double_precision = 123.456;

    /* Fixed-width integer types */
    uint8_t uint8_value = 255U;
    uint16_t uint16_value = 65535U;
    uint32_t uint32_value = 100000U;
    int32_t int32_value = -1000;

    /* Boolean */
    bool status = true;

    printf("=== C Data Types ===\n");

    printf("Character       : %c\n", character);
    printf("Integer         : %d\n", integer);
    printf("Float           : %.2f\n", floating_point);
    printf("Double          : %.3f\n", double_precision);

    printf("\n=== Fixed Width Types ===\n");

    printf("uint8_t         : %u\n", (unsigned int)uint8_value);
    printf("uint16_t        : %u\n", (unsigned int)uint16_value);
    printf("uint32_t        : %lu\n", (unsigned long)uint32_value);
    printf("int32_t         : %ld\n", (long)int32_value);

    printf("\n=== Boolean ===\n");

    printf("Status          : %s\n", status ? "TRUE" : "FALSE");

    printf("\n=== Type Sizes ===\n");

    printf("Size of char    : %zu bytes\n", sizeof(char));
    printf("Size of int     : %zu bytes\n", sizeof(int));
    printf("Size of float   : %zu bytes\n", sizeof(float));
    printf("Size of double  : %zu bytes\n", sizeof(double));
    printf("Size of uint8_t : %zu bytes\n", sizeof(uint8_t));
    printf("Size of uint16_t: %zu bytes\n", sizeof(uint16_t));
    printf("Size of uint32_t: %zu bytes\n", sizeof(uint32_t));

    return 0;
}
