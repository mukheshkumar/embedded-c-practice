
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    /* Example 1: if / else - Battery voltage monitoring */
    float battery_voltage = 11.8f;

    printf("=== Battery Voltage Monitoring ===\n");

    if (battery_voltage >= 12.5f)
    {
        printf("Battery Status: NORMAL\n");
    }
    else if (battery_voltage >= 11.5f)
    {
        printf("Battery Status: LOW\n");
    }
    else
    {
        printf("Battery Status: CRITICAL\n");
    }

    /* Example 2: switch - Operating mode selection */
    uint8_t operating_mode = 2U;

    printf("\n=== Operating Mode ===\n");

    switch (operating_mode)
    {
        case 0U:
            printf("Mode: SLEEP\n");
            break;

        case 1U:
            printf("Mode: IDLE\n");
            break;

        case 2U:
            printf("Mode: ACTIVE\n");
            break;

        default:
            printf("Mode: INVALID\n");
            break;
    }

    /* Example 3: for loop - Periodic sampling simulation */
    printf("\n=== Sensor Sampling ===\n");

    for (uint8_t sample = 1U; sample <= 5U; sample++)
    {
        printf("Sensor Sample %u\n", (unsigned int)sample);
    }

    /* Example 4: while loop - Alive counter */
    printf("\n=== Alive Counter ===\n");

    uint8_t alive_counter = 0U;

    while (alive_counter < 5U)
    {
        printf("Alive Counter: %u\n", (unsigned int)alive_counter);
        alive_counter++;
    }

    /* Example 5: do-while - Initialization sequence */
    printf("\n=== Initialization Sequence ===\n");

    uint8_t initialization_step = 1U;

    do
    {
        printf("Initialization Step: %u\n",
               (unsigned int)initialization_step);

        initialization_step++;

    } while (initialization_step <= 3U);

    /* Example 6: break - Fault detection simulation */
    printf("\n=== Fault Detection ===\n");

    uint8_t sensor_values[5] = {10U, 20U, 30U, 255U, 40U};

    for (uint8_t index = 0U; index < 5U; index++)
    {
        if (sensor_values[index] == 255U)
        {
            printf("Sensor Fault Detected at Index %u\n",
                   (unsigned int)index);
            break;
        }

        printf("Sensor Value: %u\n",
               (unsigned int)sensor_values[index]);
    }

    return 0;
}
