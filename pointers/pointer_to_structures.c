#include <stdio.h>
#include <stdint.h>

/* Structure representing an embedded device */
typedef struct
{
    uint32_t device_id;
    uint16_t voltage_mv;
    uint8_t status;
} Device;

/* Function accepting a pointer to structure */
static void update_device_status(Device *device, uint8_t new_status)
{
    if (device != NULL)
    {
        device->status = new_status;
    }
}

/* Function to display device information */
static void display_device(const Device *device)
{
    if (device != NULL)
    {
        printf("Device ID    : %lu\n",
               (unsigned long)device->device_id);

        printf("Voltage      : %u mV\n",
               (unsigned int)device->voltage_mv);

        printf("Status       : %u\n",
               (unsigned int)device->status);
    }
}

int main(void)
{
    Device device = {
        .device_id = 1001U,
        .voltage_mv = 12000U,
        .status = 0U
    };

    Device *device_ptr = &device;

    /* Access members through pointer */
    printf("Device ID using pointer: %lu\n",
           (unsigned long)device_ptr->device_id);

    printf("Voltage using pointer: %u mV\n",
           (unsigned int)device_ptr->voltage_mv);

    /* Modify structure through pointer */
    device_ptr->voltage_mv = 12500U;

    /* Pass structure pointer to function */
    update_device_status(device_ptr, 1U);

    /* Display updated structure */
    display_device(device_ptr);

    return 0;
}
