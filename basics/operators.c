
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    /* Arithmetic operators */
    uint32_t a = 20U;
    uint32_t b = 6U;

    printf("=== Arithmetic Operators ===\n");
    printf("Addition       : %lu\n", (unsigned long)(a + b));
    printf("Subtraction    : %lu\n", (unsigned long)(a - b));
    printf("Multiplication : %lu\n", (unsigned long)(a * b));
    printf("Division       : %lu\n", (unsigned long)(a / b));
    printf("Modulus        : %lu\n", (unsigned long)(a % b));

    /* Relational operators */
    printf("\n=== Relational Operators ===\n");
    printf("a > b          : %d\n", (a > b));
    printf("a < b          : %d\n", (a < b));
    printf("a == b         : %d\n", (a == b));
    printf("a != b          : %d\n", (a != b));

    /* Logical operators */
    uint8_t ignition_status = 1U;
    uint8_t sensor_status = 1U;

    printf("\n=== Logical Operators ===\n");
    printf("Ignition AND Sensor : %d\n",
           (ignition_status != 0U) && (sensor_status != 0U));

    printf("Ignition OR Sensor  : %d\n",
           (ignition_status != 0U) || (sensor_status != 0U));

    printf("NOT Ignition        : %d\n",
           !(ignition_status != 0U));

    /* Bitwise operators */
    uint8_t x = 0x0AU; /* 00001010 */
    uint8_t y = 0x03U; /* 00000011 */

    printf("\n=== Bitwise Operators ===\n");
    printf("AND : 0x%02X\n", (unsigned int)(x & y));
    printf("OR  : 0x%02X\n", (unsigned int)(x | y));
    printf("XOR : 0x%02X\n", (unsigned int)(x ^ y));
    printf("NOT : 0x%02X\n", (unsigned int)(uint8_t)(~x));
    printf("Left Shift  : 0x%02X\n", (unsigned int)(uint8_t)(x << 1U));
    printf("Right Shift : 0x%02X\n", (unsigned int)(x >> 1U));

    /* Embedded register-style bit operations */
    uint8_t register_value = 0x00U;
    uint8_t bit_position = 3U;

    printf("\n=== Embedded Bit Operations ===\n");

    /* Set bit */
    register_value |= (uint8_t)(1U << bit_position);
    printf("Set Bit 3    : 0x%02X\n", (unsigned int)register_value);

    /* Clear bit */
    register_value &= (uint8_t)~(1U << bit_position);
    printf("Clear Bit 3   : 0x%02X\n", (unsigned int)register_value);

    /* Toggle bit */
    register_value ^= (uint8_t)(1U << bit_position);
    printf("Toggle Bit 3   : 0x%02X\n", (unsigned int)register_value);

    /* Test bit */
    printf("Test Bit 3     : %d\n",
           (register_value & (uint8_t)(1U << bit_position)) != 0U);

    return 0;
}
