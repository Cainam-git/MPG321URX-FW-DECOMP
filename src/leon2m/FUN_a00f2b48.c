/* leon2m FUN_a00f2b48 @ 0xa00f2b48-0xa00f2b8c (17 words), flags -mcpu=v8 -O3 -g.
 * What it does: reads one 8-bit register of a per-port register block. port >= 4 is clamped to 0
 * (fw: 'cmp 4; addx; neg; and' = port & -(port < 4)). The ROM table DAT_0019a2e4[4] = {0x4e00,
 * 0x4e40, 0x4e80, 0x4ec0} holds each port's word index, so the address is
 * 0xcf000000 | ((table[port] + reg) << 2) = 0xcf013800 / 0xcf013900 / 0xcf013a00 / 0xcf013b00 + reg * 4
 * (a real hardware register: volatile). The low byte of the 32-bit read is returned.
 * Caller FUN_a0118a28 reads reg 0x10 here, sets or clears bit 0 and writes it back with
 * FUN_a00f2b8c (the write twin). It only reads the register; the value
 * is whatever the hardware holds.
 * Fix vs the autoc draft (Ghidra's u16 'volatile' table read): the table is a plain const ROM
 * array symbol, u8 params, u8 return. Aids: none.
 */
extern const unsigned short DAT_0019a2e4[4];
unsigned char FUN_a00f2b48(unsigned char port, unsigned char reg)
{
    if (port >= 4)
        port = 0;
    return *(volatile unsigned int *)(((DAT_0019a2e4[port] + reg) << 2) | 0xcf000000);
}
