/* leon2m FUN_a00a0ff0 @ 0xa00a0ff0-0xa00a105c (27 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a00c9980.
 * Lowers the halfword 0xa802d02a (0xa802cff4 + 0x36) by 8 while it is above 0x3c0, otherwise sets it to 0x3c0.
 * Then calls FUN_a0146870(6, h36, 0, h36 + 4, h38, 0) with h36 = that halfword and h38 = the halfword at
 * 0xa802cff4 + 0x38, and prints "OSDPBPAdjustL %d, %d\r\n" with h36 and h38. FUN_a00a105c is the same with the
 * upper limit 0xb40 and + 8.
 */
struct Rcff4 { unsigned char pad[0x36]; unsigned short h36, h38; };
extern struct Rcff4 DAT_a802cff4;
extern char s_00108180[];
extern int FUN_a00df170();
extern void FUN_a0146870(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

void FUN_a00a0ff0(void)
{
    if (DAT_a802cff4.h36 > 0x3c0)
        DAT_a802cff4.h36 -= 8;
    else
        DAT_a802cff4.h36 = 0x3c0;
    FUN_a0146870(6, DAT_a802cff4.h36, 0, (unsigned short)(DAT_a802cff4.h36 + 4), DAT_a802cff4.h38, 0);
    FUN_a00df170(s_00108180, DAT_a802cff4.h36, DAT_a802cff4.h38);
}
