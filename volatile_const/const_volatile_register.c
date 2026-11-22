#include <stdio.h>
#include <stdint.h>

/* Simulated read-only hardware status register */
static const volatile uint8_t simulated_status_register = 0x05U;

/* Read hardware status register */
static uint8_t read_status_register(void)
{
    return simulated_status_register;
}

int main(void)
{
    uint8_t status;

    status = read_status_register();

    printf("Status Register: 0x%02X\n",
           (unsigned int)status);

    /* Check status bit 0 */
    if ((status & 0x01U) != 0U)
    {
        printf("Status Bit 0: SET\n");
    }
    else
    {
        printf("Status Bit 0: CLEAR\n");
    }

    /* Check status bit 2 */
    if ((status & 0x04U) != 0U)
    {
        printf("Status Bit 2: SET\n");
    }
    else
    {
        printf("Status Bit 2: CLEAR\n");
    }

    return 0;
}
