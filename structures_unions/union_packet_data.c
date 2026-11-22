#include <stdio.h>
#include <stdint.h>

/* Union representing a 32-bit packet field */
typedef union
{
    uint32_t value;
} PacketData;

/* Extract bytes using explicit shifts */
static void extract_bytes(uint32_t value, uint8_t bytes[4])
{
    bytes[0] = (uint8_t)(value & 0xFFU);
    bytes[1] = (uint8_t)((value >> 8U) & 0xFFU);
    bytes[2] = (uint8_t)((value >> 16U) & 0xFFU);
    bytes[3] = (uint8_t)((value >> 24U) & 0xFFU);
}

static void display_packet_bytes(const uint8_t bytes[4])
{
    for (size_t i = 0U; i < 4U; i++)
    {
        printf("Byte[%zu] = 0x%02X\n",
               i,
               (unsigned int)bytes[i]);
    }
}

int main(void)
{
    PacketData packet;
    uint8_t bytes[4];

    packet.value = 0x12345678U;

    printf("Packet value: 0x%08lX\n",
           (unsigned long)packet.value);

    extract_bytes(packet.value, bytes);

    printf("\nExtracted bytes (LSB first):\n");
    display_packet_bytes(bytes);

    return 0;
}
