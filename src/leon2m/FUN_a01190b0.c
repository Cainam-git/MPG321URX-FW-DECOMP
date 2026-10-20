/* FUN_a01190b0: when the chip version code (FUN_a011cf88) is above 0x83, sets bit 5 of registers
 * 0xcf011800 and 0xcf011a00, bit 0 of 0xcf012e00 and bit 1 of 0xcf012f74; otherwise it writes nothing.
 * No direct callers were found (the address may be reached through a pointer). The bits are the ones that
 * FUN_a011855c clears.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern unsigned char FUN_a011cf88(void);

void FUN_a01190b0(void)
{
    if (FUN_a011cf88() > 0x83) {
        R(0xcf011800) |= 0x20;
        R(0xcf011a00) |= 0x20;
        R(0xcf012e00) |= 1;
        R(0xcf012f74) |= 2;
    }
}
