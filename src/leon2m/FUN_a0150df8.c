/* leon2m FUN_a0150df8 @ 0xa0150df8-0xa0150e80 (136 bytes incl. the trailing nop). Flags -mcpu=v8 -O3 -g.
 *
 * void FUN_a0150df8(void): FUN_a0115644(1), FUN_a011337c(3), then y = func_0x4008e46c(0x18) + 0x30 and for
 * i = 0..15: FUN_a01139c8(y, &DAT_a802ce90[o], &DAT_a802cd90[o], &DAT_a802cc90[o]) with o = 16 * i (unsigned short)
 * and y += 0x78; ends with a tail call FUN_a011337c(0x10). Called by FUN_a0153018.
 * Source form: the byte offset o is its own unsigned short loop variable, initialised and stepped before i
 *   ('for (o = 0, i = 0; i < 16; o += 16, i++)').
 */
extern unsigned char DAT_a802cc90[], DAT_a802cd90[], DAT_a802ce90[];
extern void FUN_a0115644(unsigned char);
extern void FUN_a011337c(unsigned char);
extern void FUN_a01139c8(unsigned int, unsigned char *, unsigned char *, unsigned char *);
extern unsigned int func_0x4008e46c(unsigned int);

void FUN_a0150df8(void)
{
    unsigned int y;
    unsigned short i, o;

    FUN_a0115644(1);
    FUN_a011337c(3);
    y = func_0x4008e46c(0x18) + 0x30;
    for (o = 0, i = 0; i < 16; o += 16, i++) {
        FUN_a01139c8(y, &DAT_a802ce90[o], &DAT_a802cd90[o], &DAT_a802cc90[o]);
        y += 0x78;
    }
    FUN_a011337c(0x10);
}
