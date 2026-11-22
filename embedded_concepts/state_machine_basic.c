#include <stdio.h>
#include <stddef.h>

/* Define system states */
typedef enum
{
    STATE_INIT = 0,
    STATE_IDLE,
    STATE_RUNNING,
    STATE_ERROR
} SystemState;

/* State machine handler */
static void system_state_handler(SystemState *state)
{
    if (state == NULL)
    {
        return;
    }

    switch (*state)
    {
        case STATE_INIT:
            printf("Initializing system...\n");
            *state = STATE_IDLE;
            break;

        case STATE_IDLE:
            printf("System is idle. Starting operation...\n");
            *state = STATE_RUNNING;
            break;

        case STATE_RUNNING:
            printf("System is running.\n");
            *state = STATE_IDLE;
            break;

        case STATE_ERROR:
            printf("System error detected!\n");
            break;

        default:
            printf("Invalid state!\n");
            *state = STATE_ERROR;
            break;
    }
}

int main(void)
{
    SystemState current_state = STATE_INIT;

    for (unsigned int cycle = 0U; cycle < 5U; cycle++)
    {
        printf("\nCycle %u:\n", cycle + 1U);
        system_state_handler(&current_state);
    }

    return 0;
}
