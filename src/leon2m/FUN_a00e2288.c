/* leon2m FUN_a00e2288 @ 0xa00e2288-0xa00e2340 (46 words).
 * Parameters dev, mode, delta. s = FUN_a00e0514(dev, 0, 0x10) is read first. The mask is 0x1f for mode 3 and 0x3f
 * otherwise; for mode 4 a second mask m2 = 0x1f is used below, else m2 = 0. Register 0xd5 is read with
 * FUN_a00e0514(dev, 0xd5, mask) and written back plus delta with FUN_a00e05d8(dev, 0xd5, mask, value + delta). Then,
 * when s is 0: FUN_a00e05d8(dev, 0xd6, m2, FUN_a00e0514(dev, 0xd5, 0x1f) + 0x10); when s is 0x10: nothing; any other
 * s: FUN_a00df80c(), FUN_a00e0bc0() and the log call FUN_a00df170(string 0x1996b8 "Error: NOT possible in this
 * case !!! ...").
 */
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern unsigned int FUN_a00e0514(unsigned int, unsigned int, unsigned int);
extern void FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);
extern const char s_001996b8[];

void FUN_a00e2288(unsigned int dev, unsigned int mode, unsigned int delta)
{
    unsigned int s = FUN_a00e0514(dev, 0, 0x10);
    unsigned int mask = 0x3f;
    unsigned int m2 = 0;

    if (mode == 4)
        m2 = 0x1f;
    else if (mode == 3)
        mask = 0x1f;
    FUN_a00e05d8(dev, 0xd5, mask, FUN_a00e0514(dev, 0xd5, mask) + delta);
    if (s == 0)
        FUN_a00e05d8(dev, 0xd6, m2, FUN_a00e0514(dev, 0xd5, 0x1f) + 0x10);
    else if (s != 0x10) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170(s_001996b8);
    }
}
