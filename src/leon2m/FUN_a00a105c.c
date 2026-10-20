/* leon2m FUN_a00a105c @ 0xa00a105c-0xa00a10c8 (27 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a00c9980.
 * Raises the halfword 0xa802d02a (0xa802cff4 + 0x36) by 8 while it is below 0xb40, otherwise sets it to 0xb40.
 * Then calls FUN_a0146870(6, h36, 0, h36 + 4, h38, 0) with h36 = that halfword and h38 = the halfword at
 * 0xa802cff4 + 0x38, and prints "OSDPBPAdjustR %d, %d\r\n" with h36 and h38. FUN_a00a0ff0 is the same with the
 * lower limit 0x3c0 and - 8.
 */
struct Rcff4 { unsigned char pad[0x36]; unsigned short h36, h38; };
extern struct Rcff4 DAT_a802cff4;
extern char s_00108198[];
extern int FUN_a00df170();
extern void FUN_a0146870(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

void FUN_a00a105c(void)
{
    if (DAT_a802cff4.h36 < 0xb40)
        DAT_a802cff4.h36 += 8;
    else
        DAT_a802cff4.h36 = 0xb40;
    FUN_a0146870(6, DAT_a802cff4.h36, 0, (unsigned short)(DAT_a802cff4.h36 + 4), DAT_a802cff4.h38, 0);
    FUN_a00df170(s_00108198, DAT_a802cff4.h36, DAT_a802cff4.h38);
}
