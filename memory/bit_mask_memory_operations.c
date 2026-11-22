#include <stdio.h>
#include <stdint.h>

/* Set a bit */
static uint8_t set_bit(uint8_t value, uint8_t bit_position)
{
    return (uint8_t)(value | (uint8_t)(1U << bit_position));
}

/* Clear a bit */
static uint8_t clear_bit(uint8_t value, uint8_t bit_position)
{
    return (uint8_t)(value & (uint8_t)~(1U << bit_position));
}

/* Toggle a bit */
static uint8_t toggle_bit(uint8_t value, uint8_t bit_position)
{
    return (uint8_t)(value ^ (uint8_t)(1U << bit_position));
}

/* Read a bit */
static uint8_t read_bit(uint8_t value, uint8_t bit_position)
{
    return (uint8_t)((value >> bit_position) & 1U);
}

int main(void)
{
    uint8_t register_value = 0x00U;

    printf("Initial value : 0x%02X\n", (unsigned int)register_value);

    /* Set bit 3 */
    register_value = set_bit(register_value, 3U);
    printf("Set bit 3     : 0x%02X\n", (unsigned int)register_value);

    /* Set bit 5 */
    register_value = set_bit(register_value, 5U);
    printf("Set bit 5     : 0x%02X\n", (unsigned int)register_value);

    /* Clear bit 3 */
    register_value = clear_bit(register_value, 3U);
    printf("Clear bit 3    : 0x%02X\n", (unsigned int)register_value);

    /* Toggle bit 5 */
    register_value = toggle_bit(register_value, 5U);
    printf("Toggle bit 5    : 0x%02X\n", (unsigned int)register_value);

    /* Read bit 2 */
    printf("Bit 2 status   : %u\n",
           (unsigned int)read_bit(register_value, 2U));

    /* Read bit 5 */
    printf("Bit 5 status   : %u\n",
           (unsigned int)read_bit(register_value, 5U));

    return 0;
}
