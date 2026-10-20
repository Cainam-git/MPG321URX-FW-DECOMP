/* leon2m FUN_a010b610 @ 0xa010b610-0xa010b6e4 (53 words).
 * When FUN_a011cf88() returns more than 0x81, sets bit 6 of hardware register 0xcf00b844 and bit 7 of 0xcf00b870.
 * Then on 0xd00300f0: clears bit 26, calls func_0x4008d1a0(1), sets bit 26, sets bit 4, calls func_0x4008d1a0(2), clears bit 4,
 * sets bit 10, sets bit 14; finally sets bits 10 and 14 of 0xd00380f0 (one read-modify-write per bit).
 * Called from FUN_a015209c.
 */
#define REG_cf00b844 (*(volatile unsigned int *)0xcf00b844)
#define REG_cf00b870 (*(volatile unsigned int *)0xcf00b870)
#define REG_d00300f0 (*(volatile unsigned int *)0xd00300f0)
#define REG_d00380f0 (*(volatile unsigned int *)0xd00380f0)

extern unsigned char FUN_a011cf88(void);
extern void func_0x4008d1a0(int ms);

void FUN_a010b610(void)
{
    if (FUN_a011cf88() > 0x81) {
        REG_cf00b844 |= 0x40;
        REG_cf00b870 |= 0x80;
    }
    REG_d00300f0 &= ~0x4000000;
    func_0x4008d1a0(1);
    REG_d00300f0 |= 0x4000000;
    REG_d00300f0 |= 0x10;
    func_0x4008d1a0(2);
    REG_d00300f0 &= ~0x10;
    REG_d00300f0 |= 0x400;
    REG_d00300f0 |= 0x4000;
    REG_d00380f0 |= 0x400;
    REG_d00380f0 |= 0x4000;
}
