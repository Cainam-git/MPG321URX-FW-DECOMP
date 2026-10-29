/* leon2m FUN_a00f42b8 @ 0xa00f42b8-0xa00f4434 (380 bytes), flags -mcpu=v8 -O3 -g.
 * Steps a 16-bit value from start = FUN_a00f3528() towards target in steps of 4 (up when target is above start,
 * down otherwise; the last step is clamped to target). For each step: func_0x4008e2a4(), FUN_a00f36b8(blk, cur);
 * lim = FUN_a00f8dd4(blk) + 0x14 (second call) when the low halfword of FUN_a00f8dd4(blk) is above cur, else
 * cur; then FUN_a011ff28(0, lim) when blk is 0 and FUN_a01207ac(0) returns nonzero, otherwise
 * FUN_a011ff28(1, lim) when FUN_a0120638() equals blk and FUN_a01207ac(1) returns nonzero. The loop body only
 * runs while target differs from start, and the loop repeats while cur differs from target. Afterwards, for blk 0
 * with bit 4 of the register 0xcf011800 set, the function pointer at 0xa802b7a8 is called when it is not 0.
 * Source form: a do-while loop whose body is wrapped in 'if (target != start)' (the code tests target == start at
 * the top of every pass); the FUN_a00f8dd4 result is compared through an unsigned short local.
 */
#define REG_CF011800 (*(volatile unsigned int *)0xcf011800)

extern unsigned short FUN_a00f3528(void);
extern void func_0x4008e2a4(void);
extern void FUN_a00f36b8(unsigned char blk, unsigned short val);
extern unsigned int FUN_a00f8dd4(unsigned int blk);
extern unsigned char FUN_a01207ac(unsigned int blk);
extern void FUN_a011ff28(unsigned int blk, unsigned short v);
extern unsigned char FUN_a0120638(void);
extern void (*DAT_a802b7a8)(void);

void FUN_a00f42b8(unsigned char blk, unsigned short target)
{
    unsigned short start;
    unsigned short cur, lim;
    unsigned short m;

    start = FUN_a00f3528();
    cur = start;
    do {
        if (target != start) {
            if (target > start) {
                cur += 4;
                if (cur > target)
                    cur = target;
            } else {
                cur -= 4;
                if (cur < target)
                    cur = target;
            }
            func_0x4008e2a4();
            FUN_a00f36b8(blk, cur);
            m = FUN_a00f8dd4(blk);
            if (m > cur)
                lim = FUN_a00f8dd4(blk) + 0x14;
            else
                lim = cur;
            if (blk == 0 && FUN_a01207ac(0))
                FUN_a011ff28(0, lim);
            else if (FUN_a0120638() == blk && FUN_a01207ac(1))
                FUN_a011ff28(1, lim);
        }
    } while (cur != target);
    if (blk == 0 && (REG_CF011800 & 0x10) && DAT_a802b7a8 != 0)
        DAT_a802b7a8();
}
