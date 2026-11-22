#include <stdio.h>
#include <stdint.h>

/* Simulated hardware register */
static volatile uint8_t simulated_control_register = 0U;

/* Register bit positions */
#define BIT0    (1U << 0U)
#define BIT1    (1U << 1U)
#define BIT2    (1U << 2U)

/* Enable simulated peripheral */
static void peripheral_enable(void)
{
    simulated_control_register |= (uint8_t)BIT0;
}

/* Configure simulated peripheral mode */
static void peripheral_configure(void)
{
    simulated_control_register |= (uint8_t)BIT1;
}

/* Disable simulated peripheral */
static void peripheral_disable(void)
{
    simulated_control_register &= (uint8_t)~BIT0;
}

/* Read simulated register */
static uint8_t peripheral_read_register(void)
{
    return simulated_control_register;
}

int main(void)
{
    printf("Initial Register: 0x%02X\n",
           (unsigned int)peripheral_read_register());

    /* Enable peripheral */
    peripheral_enable();

    printf("After Enable   : 0x%02X\n",
           (unsigned int)peripheral_read_register());

    /* Configure peripheral */
    peripheral_configure();

    printf("After Configure: 0x%02X\n",
           (unsigned int)peripheral_read_register());

    /* Disable peripheral */
    peripheral_disable();

    printf("After Disable  : 0x%02X\n",
           (unsigned int)peripheral_read_register());

    /* Check bit 2 */
    if ((peripheral_read_register() & (uint8_t)BIT2) != 0U)
    {
        printf("Bit 2 is SET\n");
    }
    else
    {
        printf("Bit 2 is CLEAR\n");
    }

    return 0;
}
