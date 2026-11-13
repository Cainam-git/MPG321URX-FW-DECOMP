/* pq_port_read8  (FUN_a00f2b48)
 *
 * Read an 8-bit register of one of the four port blocks.
 * Returns: byte
 * Name basis: derived - block base addresses from the ROM table at 0x19A2E4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f2b48 @ 0xa00f2b48-0xa00f2b8c (17 words), flags -mcpu=v8 -O3 -g.
 */
#define PORT_COUNT 4
#define PORT_REG_BASE 0xcf000000

/* Word index of each port's register block. */
extern const unsigned short pq_port_reg_bases[4];

/*
 * Read an 8-bit register of one of the four port blocks.
 * port_index selects the port (0-3); values >= 4 are clamped to 0.
 * register_offset is the register number within the port's block (registers are words 4 bytes apart).
 * Returns the low byte of the 32-bit value read from the hardware register.
 * Callers: pq_port_set_reg10_bit0, pq_load_block8_config.
 */
unsigned char pq_port_read8(unsigned char port_index, unsigned char register_offset)
{
    /* Clamp out-of-range port index to 0. */
    if (port_index >= PORT_COUNT)
        port_index = 0;
    return *(volatile unsigned int *)(((pq_port_reg_bases[port_index] + register_offset) << 2) | PORT_REG_BASE);
}
