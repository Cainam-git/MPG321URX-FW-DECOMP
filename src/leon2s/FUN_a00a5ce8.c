/* leon2s FUN_a00a5ce8 @ 0xa00a5ce8-0xa00a5d8c (41 words).
 * FUN_a00a4ec4(1, 0) and FUN_a00b15ac(0xa807db74, 0, 0x90), then for entry 0 of the 12-byte records at 0xa807dc04:
 * clears bit 0 of the registers at word offsets 0xb0 and 0xbc of the entry's register pointer, calls FUN_a00a5cb4(0)
 * and sets bit 13 of the register at offset 0xc0. The mask 1 is a volatile local: the firmware stores it to the stack
 * and loads it back before each of the two clears.
 */
struct rec12 { volatile unsigned int *a; unsigned int b; unsigned int c; };
extern struct rec12 DAT_a807dc04[];
extern unsigned char DAT_a807db74[];
extern void FUN_a00a4ec4(unsigned int, unsigned short);
extern void FUN_a00b15ac(void *, int, int);
extern void FUN_a00a5cb4(unsigned char);

void FUN_a00a5ce8(void)
{
    unsigned char i;
    volatile unsigned int m;

    FUN_a00a4ec4(1, 0);
    FUN_a00b15ac(DAT_a807db74, 0, 0x90);
    for (i = 0; i < 1; i++) {
        m = 1;
        DAT_a807dc04[i].a[0xb0 / 4] &= ~m;
        m = 1;
        DAT_a807dc04[i].a[0xbc / 4] &= ~m;
        FUN_a00a5cb4(i);
        DAT_a807dc04[i].a[0xc0 / 4] |= 0x2000;
    }
}
