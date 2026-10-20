/* leon2m FUN_a0111028 @ 0xa0111028-0xa0111088 (24 words).
 * Computes v = 0xc0 / n - 2 (signed division), sets bit 7 of hardware register 0xcf0115fc, then writes the low byte
 * of v to 0xcf0115f0 and bits 8-15 of v to 0xcf0115f4. Called from FUN_a014dc28. v is an unsigned short: the
 * high byte is taken with sll 16 / srl 24.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a0111028(unsigned char n)
{
    unsigned short v = 0xc0 / n - 2;

    R(0xcf0115fc) |= 0x80;
    R(0xcf0115f0) = v & 0xff;
    R(0xcf0115f4) = v >> 8;
}
