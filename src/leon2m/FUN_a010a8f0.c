/* leon2m FUN_a010a8f0 @ 0xa010a8f0-0xa010a9e8 (62 words). -mcpu=v8 -O3 -g.
 * What it does (output path set-up FUN_a01062e0 callee): returns a 16-bit value read with FUN_a00f3078
 * (the hardware register pair p[0] | p[1] << 8):
 *   bit 7 of hw 0xcf011a80 clear: the pair at 0xcf011c30;
 *   bit 7 set: the pair at 0xcf011af8, shifted left by
 *     1 when FUN_a011cf88() > 0x82 and bit 3 of hw 0xcf011e40 is set, else
 *     2 when the code > 0x83 and bit 2 of 0xcf011e40 is set, else
 *     3 when the code > 0x83 and bit 1 of 0xcf011e40 is set, else 0
 *   (FUN_a011cf88 is called again for each test); the result is cut to 16 bits.
 * The multiplier depends on the code FUN_a011cf88() (0x80..0x84 from register
 * 0xcf011444) and the 0xcf011e40 bits, not on the input rate itself.
 * Form: early returns per test (an if/else chain into one u16 local gives 88.89).
 * Prototypes from src/leon2m (FUN_a00f3078 takes the register address). volatile only on real hardware
 * registers. Aids: none.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned int FUN_a00f3078(volatile unsigned int *p);
extern unsigned char FUN_a011cf88(void);
unsigned short FUN_a010a8f0(void)
{
    if (!(R(0xcf011a80) & 0x80))
        return FUN_a00f3078((volatile unsigned int *)0xcf011c30);
    if (FUN_a011cf88() > 0x82 && (R(0xcf011e40) & 8))
        return FUN_a00f3078((volatile unsigned int *)0xcf011af8) << 1;
    if (FUN_a011cf88() > 0x83 && (R(0xcf011e40) & 4))
        return FUN_a00f3078((volatile unsigned int *)0xcf011af8) << 2;
    if (FUN_a011cf88() > 0x83 && (R(0xcf011e40) & 2))
        return FUN_a00f3078((volatile unsigned int *)0xcf011af8) << 3;
    return FUN_a00f3078((volatile unsigned int *)0xcf011af8);
}
