/* leon2m FUN_a010a2cc @ 0xa010a2cc-0xa010a3a8 (55 words).
 * mode 1 or 2: sets bit 4 of hardware register 0xcf01e400, waits 200 (func_0x4008d1a0), sets bit 4 of 0xcf01e600,
 * writes bits 6-7 of 0xcf01ea40 as 10 (mode 1) or 11 (mode 2) together with bit 0, keeping bits 0-5 otherwise, and
 * prints "PIVOT_Enable". Any other mode: clears bits 6-7 of 0xcf01ea40 and bit 4 of 0xcf01e400 and 0xcf01e600, and
 * prints "PIVOT_Disable". The print through FUN_a00df170 is a tail call. No direct callers were found.
 */
#define REG_cf01e400 (*(volatile unsigned int *)0xcf01e400)
#define REG_cf01e600 (*(volatile unsigned int *)0xcf01e600)
#define REG_cf01ea40 (*(volatile unsigned int *)0xcf01ea40)

extern int FUN_a00df170(const char *fmt, ...);
extern void func_0x4008d1a0(int ms);

void FUN_a010a2cc(unsigned char mode)
{
    if ((unsigned char)(mode - 1) <= 1) {
        REG_cf01e400 |= 0x10;
        func_0x4008d1a0(200);
        REG_cf01e600 |= 0x10;
        if (mode == 1)
            REG_cf01ea40 = (REG_cf01ea40 & 0x3f) | 0x81;
        else
            REG_cf01ea40 = (REG_cf01ea40 & 0x3f) | 0xc1;
        FUN_a00df170("\nPIVOT_Enable\r\n");
    } else {
        REG_cf01ea40 &= ~0xc0;
        REG_cf01e400 &= ~0x10;
        REG_cf01e600 &= ~0x10;
        FUN_a00df170("\nPIVOT_Disable\r\n");
    }
}
