/* sys_set_ef80_block  (FUN_a014e8ec)
 *
 * Write two 16-bit values as low and high bytes to block 0xCF00EF80 and switch it on, or switch it off.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * FUN_a014e8ec (leon2m 0xa014e8ec, flags -mcpu=v8 -O3 -g, the section default).
 * Source form: the registers as a volatile fixed-address macro; the shifted byte is the 16-bit value >> 8.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define EF80_CTRL     0xcf00ef80        /* bit 0 and bit 1 are set to switch the block on; bit 1 is cleared to switch off */
#define EF80_A_LOW    0xcf00ef84
#define EF80_A_HIGH   0xcf00ef88
#define EF80_B_LOW    0xcf00ef8c
#define EF80_B_HIGH   0xcf00ef90

/*
 * With 'on' non-zero: write the low and high byte of each of the two values to the four registers
 * 0xCF00EF84..90 and set bits 0 and 1 of 0xCF00EF80. With 'on' 0: clear bit 1 of 0xCF00EF80.
 *
 *   on  non-zero programs the block and switches it on, 0 switches it off
 *   a   first value (low byte to 0xCF00EF84, high byte to 0xCF00EF88)
 *   b   second value (low byte to 0xCF00EF8C, high byte to 0xCF00EF90)
 *
 * No direct caller was found.
 */
void sys_set_ef80_block(unsigned char on, unsigned short a, unsigned short b)
{
    if (on) {
        R(EF80_A_LOW) = a & 0xff;
        R(EF80_A_HIGH) = a >> 8;
        R(EF80_B_LOW) = b & 0xff;
        R(EF80_B_HIGH) = b >> 8;
        R(EF80_CTRL) |= 3;
    } else {
        R(EF80_CTRL) &= ~2;
    }
}
