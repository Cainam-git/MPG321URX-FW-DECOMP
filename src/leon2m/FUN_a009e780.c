/* leon2m FUN_a009e780 @ 0xa009e780-0xa009e820 (40 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Calls FUN_a0080bd8(0), clears bits 7 and 15 of the halfword 0xa802cff8 (0xa802cff4 + 4, & 0x7f7f), clears word
 * 0xa802afec and calls FUN_a00b5080. Then, when byte 0xa802d465 is not 0 and FUN_a0143c14(0) does not return 10,
 * calls FUN_a00808ac(4, 0). Finally, when FUN_a0143c14(0) does not return 10, tail-calls FUN_a014512c(0, 0). The
 * start is the same as FUN_a009e820.
 * Exact form: the two bits are 1-bit bit-fields cleared bit 7 first, then bit 15 (GCC merges them into one
 * and with 0x7f7f; the mask form or the other order schedules the halfword store after the word store).
 */
struct Rcff4 { unsigned char pad[4]; unsigned short b15 : 1, m : 7, b7 : 1, l : 7; };
extern struct Rcff4 DAT_a802cff4;
extern unsigned int DAT_a802afec;
extern unsigned char DAT_a802d465;
extern void FUN_a0080bd8(int);
extern void FUN_a00b5080(void);
extern unsigned char FUN_a0143c14(unsigned char);
extern void FUN_a00808ac(int, int);
extern void FUN_a014512c(int, int);

void FUN_a009e780(void)
{
    FUN_a0080bd8(0);
    DAT_a802cff4.b7 = 0;
    DAT_a802cff4.b15 = 0;
    DAT_a802afec = 0;
    FUN_a00b5080();
    if (DAT_a802d465 != 0 && FUN_a0143c14(0) != 10)
        FUN_a00808ac(4, 0);
    if (FUN_a0143c14(0) != 10)
        FUN_a014512c(0, 0);
}
