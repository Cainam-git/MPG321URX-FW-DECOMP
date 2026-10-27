/* FUN_a0092bb4 (leon2m 0xa0092bb4-0xa0092c58, 164 bytes), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a00a8ee8(DAT_a802afec - 42) and FUN_a00aa33c(DAT_a802afec - 42, 0); calls FUN_a00b0034(7) when
 * DAT_a802afec - 42 is above 6 (unsigned); then calls FUN_a00af44c(0x2a, 0) and FUN_a00a900c(0, 0), stores 9 to
 * DAT_a802afec and calls FUN_a00b4144(7, 1) as a tail call. Source form: the common tail after the if is duplicated
 * by GCC into both paths.
 */
extern unsigned int DAT_a802afec;
extern void FUN_a00a8ee8(unsigned char);
extern void FUN_a00aa33c(unsigned char, int);
extern void FUN_a00af44c(unsigned short page, unsigned char sel);
extern void FUN_a00b0034(unsigned char id);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00b4144(unsigned char, int);

void FUN_a0092bb4(void)
{
    FUN_a00a8ee8(DAT_a802afec - 42);
    FUN_a00aa33c(DAT_a802afec - 42, 0);
    if (DAT_a802afec - 42 > 6)
        FUN_a00b0034(7);
    FUN_a00af44c(0x2a, 0);
    FUN_a00a900c(0, 0);
    DAT_a802afec = 9;
    FUN_a00b4144(7, 1);
}
