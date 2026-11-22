#include <stdio.h>

/* Status structure using bit-fields */
typedef struct
{
    unsigned int power_on : 1;
    unsigned int error    : 1;
    unsigned int mode     : 2;
    unsigned int reserved : 4;
} StatusFlags;

int main(void)
{
    StatusFlags status = {0};

    status.power_on = 1U;
    status.error = 0U;
    status.mode = 2U;
    status.reserved = 0U;

    printf("Power ON : %u\n", status.power_on);
    printf("Error    : %u\n", status.error);
    printf("Mode     : %u\n", status.mode);
    printf("Reserved : %u\n", status.reserved);

    return 0;
}
