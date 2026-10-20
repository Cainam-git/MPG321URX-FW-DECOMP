/* leon2m FUN_a00b5080 @ 0xa00b5080-0xa00b50d8 (22 words), flags -mcpu=v8 -O3 -g. Called from many functions
 * (FUN_a0090fd8, FUN_a0094368, FUN_a00943a4, FUN_a0097190 and others).
 * Calls FUN_a0146dc0(0, 0) and FUN_a0146c40(8, 0, 0), stores 0x24 into byte 0xa802b08f, calls FUN_a0146dc0(0, 1)
 * and clears bit 15 of the halfword 0xa802d032 (0xa802cff4 + 0x3e). The bit is a 1-bit bit-field.
 */
struct Rcff4 { unsigned char pad[0x3e]; unsigned short b15 : 1, rest : 15; };
extern struct Rcff4 DAT_a802cff4;
extern unsigned char DAT_a802b08f;
extern void FUN_a0146dc0(int, int);
extern void FUN_a0146c40(int, int, int);

void FUN_a00b5080(void)
{
    FUN_a0146dc0(0, 0);
    FUN_a0146c40(8, 0, 0);
    DAT_a802b08f = 0x24;
    FUN_a0146dc0(0, 1);
    DAT_a802cff4.b15 = 0;
}
