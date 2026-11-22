#include <stdio.h>
#include <stdint.h>

/* Define system states */
typedef enum
{
    SYSTEM_STATE_IDLE = 0,
    SYSTEM_STATE_RUNNING,
    SYSTEM_STATE_ERROR
} SystemState;

/* Define system events */
typedef enum
{
    EVENT_NONE = 0,
    EVENT_START,
    EVENT_STOP,
    EVENT_ERROR
} SystemEvent;

/* State machine processing function */
static void state_machine_process(SystemState *state,
                                 SystemEvent event)
{
    if (state == NULL)
    {
        return;
    }

    switch (*state)
    {
        case SYSTEM_STATE_IDLE:
            if (event == EVENT_START)
            {
                *state = SYSTEM_STATE_RUNNING;
                printf("Transition: IDLE -> RUNNING\n");
            }
            break;

        case SYSTEM_STATE_RUNNING:
            if (event == EVENT_STOP)
            {
                *state = SYSTEM_STATE_IDLE;
                printf("Transition: RUNNING -> IDLE\n");
            }
            else if (event == EVENT_ERROR)
            {
                *state = SYSTEM_STATE_ERROR;
                printf("Transition: RUNNING -> ERROR\n");
            }
            break;

        case SYSTEM_STATE_ERROR:
            printf("System is in ERROR state.\n");
            break;

        default:
            *state = SYSTEM_STATE_ERROR;
            printf("Invalid state detected.\n");
            break;
    }
}

int main(void)
{
    SystemState current_state = SYSTEM_STATE_IDLE;

    SystemEvent events[] =
    {
        EVENT_START,
        EVENT_NONE,
        EVENT_STOP,
        EVENT_START,
        EVENT_ERROR
    };

    const uint32_t event_count =
        (uint32_t)(sizeof(events) / sizeof(events[0]));

    for (uint32_t i = 0U; i < event_count; i++)
    {
        printf("\nProcessing event %u\n", (unsigned int)events[i]);

        state_machine_process(&current_state, events[i]);
    }

    return 0;
}
