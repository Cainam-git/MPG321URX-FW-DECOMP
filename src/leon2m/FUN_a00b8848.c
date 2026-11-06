/* leon2m FUN_a00b8848 @ 0xa00b8848-0xa00b88b8 (28 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a0146b6c(0, 0); FUN_a0090fd8(); FUN_a00dc3dc(); flag byte 0xa802b08e |= 6; FUN_a0142e8c(0) &
 * 0xff != 5 -> if (u16)FUN_a0145660(0, 0x16) != 0 then flag byte |= 1. void. FUN_a0090fd8 takes no argument (the
 * fw sets no %o0 for it; its own asm never reads %i0).
 * Source form: FUN_a0145660 returns unsigned short; both tests are written directly on the call results.
 */
extern unsigned char DAT_a802b08e;

extern void FUN_a0146b6c(unsigned int, unsigned int);
extern void FUN_a0090fd8(void);
extern void FUN_a00dc3dc(void);
extern unsigned char FUN_a0142e8c(unsigned int);
extern unsigned short FUN_a0145660(unsigned int, unsigned int);

void FUN_a00b8848(void)
{
    FUN_a0146b6c(0, 0);
    FUN_a0090fd8();
    FUN_a00dc3dc();
    DAT_a802b08e |= 6;
    if (FUN_a0142e8c(0) != 5) {
        if (FUN_a0145660(0, 0x16) != 0)
            DAT_a802b08e |= 1;
    }
}
