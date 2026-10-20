/* leon2m FUN_a010b77c @ 0xa010b77c-0xa010b884 (66 words).
 * Sets bit 4 of hardware register 0xcf00b800. On 0xd00300f0: clears bit 26, calls func_0x4008d1a0(1), sets bit 26,
 * sets bit 4, calls func_0x4008d1a0(2), clears bit 4. When FUN_a011cf88() returns at most 0x81, sets bits 10 and 14
 * of 0xd00300f0 and of 0xd00380f0; when a second FUN_a011cf88() call returns more than 0x81, sets bit 6 of
 * 0xcf00b844 and bit 7 of 0xcf00b870. Finally writes 0x100 to 0xd0030008 and 0xd0038008. No direct callers were
 * found (same register sequence as FUN_a010b610).
 */
#define REG_cf00b800 (*(volatile unsigned int *)0xcf00b800)
#define REG_cf00b844 (*(volatile unsigned int *)0xcf00b844)
#define REG_cf00b870 (*(volatile unsigned int *)0xcf00b870)
#define REG_d00300f0 (*(volatile unsigned int *)0xd00300f0)
#define REG_d00380f0 (*(volatile unsigned int *)0xd00380f0)
#define REG_d0030008 (*(volatile unsigned int *)0xd0030008)
#define REG_d0038008 (*(volatile unsigned int *)0xd0038008)

extern unsigned char FUN_a011cf88(void);
extern void func_0x4008d1a0(int ms);

void FUN_a010b77c(void)
{
    REG_cf00b800 |= 0x10;
    REG_d00300f0 &= ~0x4000000;
    func_0x4008d1a0(1);
    REG_d00300f0 |= 0x4000000;
    REG_d00300f0 |= 0x10;
    func_0x4008d1a0(2);
    REG_d00300f0 &= ~0x10;
    if (FUN_a011cf88() <= 0x81) {
        REG_d00300f0 |= 0x400;
        REG_d00300f0 |= 0x4000;
        REG_d00380f0 |= 0x400;
        REG_d00380f0 |= 0x4000;
    }
    if (FUN_a011cf88() > 0x81) {
        REG_cf00b844 |= 0x40;
        REG_cf00b870 |= 0x80;
    }
    REG_d0030008 = 0x100;
    REG_d0038008 = 0x100;
}
