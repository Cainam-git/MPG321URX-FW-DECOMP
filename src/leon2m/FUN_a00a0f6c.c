/* leon2m FUN_a00a0f6c @ 0xa00a0f6c-0xa00a0ff0 (33 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Only when byte 0xa802d028 (0xa802cff4 + 0x34) is above 2: sets the halfword 0xa802d02c (0xa802cff4 + 0x38) to
 * 0x870 when it is at least 0x870 and raises it by 8 otherwise, calls FUN_a0146870(6, 0, h38, h36, h38 + 4, 0) with
 * h38 = that halfword and h36 = the halfword at 0xa802cff4 + 0x36, and prints "OSDPBPAdjustD %d, %d\r\n" with h36
 * and h38. FUN_a00a0ee8 is the same with the lower limit 0x870 and - 8 ("OSDPBPAdjustU").
 */
struct Rcff4 { unsigned char pad[0x34]; unsigned char b34, pad35; unsigned short h36, h38; };
extern struct Rcff4 DAT_a802cff4;
extern char s_00108168[];
extern int FUN_a00df170();
extern void FUN_a0146870(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

void FUN_a00a0f6c(void)
{
    if (DAT_a802cff4.b34 > 2) {
        if (DAT_a802cff4.h38 < 0x870)
            DAT_a802cff4.h38 += 8;
        else
            DAT_a802cff4.h38 = 0x870;
        FUN_a0146870(6, 0, DAT_a802cff4.h38, DAT_a802cff4.h36, (unsigned short)(DAT_a802cff4.h38 + 4), 0);
        FUN_a00df170(s_00108168, DAT_a802cff4.h36, DAT_a802cff4.h38);
    }
}
