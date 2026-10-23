/* FUN_a00d649c (leon2s 0xa00d649c-0xa00d64ec, 80 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Writes 0xff to register 0xcf01301c, sets and then clears bits 0xc0 of 0xcf013008, sets and then clears bit 1
 * (value 2) of 0xcf013020. Hardware registers: volatile.
 */
#define R1C (*(volatile unsigned int *)0xcf01301c)
#define R08 (*(volatile unsigned int *)0xcf013008)
#define R20 (*(volatile unsigned int *)0xcf013020)

void FUN_a00d649c(void)
{
    R1C = 0xff;
    R08 |= 0xc0;
    R08 &= ~0xc0;
    R20 |= 2;
    R20 &= ~2;
}
