#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* Simulated flag updated asynchronously */
static volatile bool event_flag = false;

/* Simulated ISR */
static void simulated_isr(void)
{
    event_flag = true;
}

/* Main application */
int main(void)
{
    printf("Waiting for event...\n");

    /* Simulate an interrupt/event occurring */
    simulated_isr();

    /* Poll the volatile flag */
    if (event_flag)
    {
        printf("Event detected!\n");

        event_flag = false;
    }

    printf("Event flag cleared.\n");

    return 0;
}
