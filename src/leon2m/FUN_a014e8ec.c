/* FUN_a014e8ec: on != 0: writes the low / high bytes of a to registers 0xcf00ef84 / 0xcf00ef88 and of b to
 * 0xcf00ef8c / 0xcf00ef90, then sets bits 0-1 of 0xcf00ef80. on == 0: clears bit 1 of 0xcf00ef80.
 * No direct callers were found (the address may be reached through a pointer).
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a014e8ec(unsigned char on, unsigned short a, unsigned short b)
{
    if (on) {
        R(0xcf00ef84) = a & 0xff;
        R(0xcf00ef88) = a >> 8;
        R(0xcf00ef8c) = b & 0xff;
        R(0xcf00ef90) = b >> 8;
        R(0xcf00ef80) |= 3;
    } else {
        R(0xcf00ef80) &= ~2;
    }
}
