#include <stdio.h>
#include <stdint.h>

/* Basic functions */
static void operation_start(void)
{
    printf("Operation started\n");
}

static void operation_stop(void)
{
    printf("Operation stopped\n");
}

/* Function pointer declaration */
typedef void (*OperationHandler)(void);

/* Function accepting a function pointer */
static void execute_operation(OperationHandler handler)
{
    if (handler != NULL)
    {
        handler();
    }
}

/* Callback example */
static void sensor_callback(uint16_t sensor_value)
{
    printf("Sensor callback: Value = %u\n", (unsigned int)sensor_value);
}

/* Callback function pointer type */
typedef void (*SensorCallback)(uint16_t);

/* Simulated sensor driver */
static void sensor_read(SensorCallback callback)
{
    uint16_t simulated_sensor_value = 250U;

    printf("Reading sensor...\n");

    if (callback != NULL)
    {
        callback(simulated_sensor_value);
    }
}

int main(void)
{
    OperationHandler operation = operation_start;

    /* Calling function through function pointer */
    operation();

    /* Reassign function pointer */
    operation = operation_stop;
    operation();

    /* Passing function pointer as an argument */
    execute_operation(operation_start);
    execute_operation(operation_stop);

    /* Simulated callback mechanism */
    sensor_read(sensor_callback);

    return 0;
}
