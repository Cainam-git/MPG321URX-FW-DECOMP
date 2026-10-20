/* leon2m FUN_a0113138 @ 0xa0113138-0xa01131d4 (39 words).
 * For each bit i = 0..4 set in mask: calls func_0x4008e3c4(i, 0), then sets bit i of hardware register 0xcf011800
 * and bit i of 0xcf011a00. When bit 5 of mask is set it ends with a tail call to FUN_a01185d4. No direct callers
 * (address taken).
 */
#define R(a) (*(volatile unsigned int *)(a))
extern void func_0x4008e3c4(unsigned int, unsigned int);
extern void FUN_a01185d4(void);

void FUN_a0113138(unsigned char mask)
{
    unsigned char i;

    for (i = 0; i <= 4; i++) {
        if ((mask >> i) & 1) {
            func_0x4008e3c4(i, 0);
            R(0xcf011800) |= 1 << i;
            R(0xcf011a00) |= 1 << i;
        }
    }
    if (mask & 0x20)
        FUN_a01185d4();
}
