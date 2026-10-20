/* FUN_a011855c: reads the chip version code (FUN_a011cf88). When the code is at most 0x83, or bit 1 of
 * register 0xcf012f74 is clear, it clears bit 0 of 0xcf012e00 and bit 5 of 0xcf011a00 and 0xcf011800.
 * In every case it writes 0 to 0xcf012e80. Callers include FUN_a0113064, FUN_a014913c and FUN_a014c7bc.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern unsigned char FUN_a011cf88(void);

void FUN_a011855c(void)
{
    if (FUN_a011cf88() <= 0x83 || !(R(0xcf012f74) & 2)) {
        R(0xcf012e80) = 0;
        R(0xcf012e00) &= ~1;
        R(0xcf011a00) &= ~0x20;
        R(0xcf011800) &= ~0x20;
    } else {
        R(0xcf012e80) = 0;
    }
}
