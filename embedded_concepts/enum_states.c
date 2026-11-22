#include <stdio.h>
#include <stdint.h>

/* Define system states */
typedef enum
{
    SYSTEM_OFF = 0,
    SYSTEM_INIT,
    SYSTEM_IDLE,
    SYSTEM_ACTIVE,
    SYSTEM_ERROR
} SystemState;

/* Function to display system state */
static void display_state(SystemState state)
{
    switch (state)
    {
        case SYSTEM_OFF:
            printf("System State: OFF\n");
            break;

        case SYSTEM_INIT:
            printf("System State: INIT\n");
            break;

        case SYSTEM_IDLE:
            printf("System State: IDLE\n");
            break;

        case SYSTEM_ACTIVE:
            printf("System State: ACTIVE\n");
            break;

        case SYSTEM_ERROR:
            printf("System State: ERROR\n");
            break;

        default:
            printf("System State: INVALID\n");
            break;
    }
}

int main(void)
{
    SystemState current_state = SYSTEM_INIT;

    display_state(current_state);

    current_state = SYSTEM_IDLE;
    display_state(current_state);

    current_state = SYSTEM_ACTIVE;
    display_state(current_state);

    current_state = SYSTEM_ERROR;
    display_state(current_state);

    return 0;
}
