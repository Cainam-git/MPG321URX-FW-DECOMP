/* FUN_a0092f2c (leon2m 0xa0092f2c-0xa0092fd4, 168 bytes), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a00a8ee8(DAT_a802afec - 52) and FUN_a00b0034(8); for DAT_a802afec = 0x3b stores 0xff to the byte
 * DAT_a802d419 and calls FUN_a00ab4bc(), FUN_a00a9468(2, 5), FUN_a00a9468(0, 0); for 0x3b and 0x35 calls
 * FUN_a00a9468(1, 2) and FUN_a00b34d4(0, 1); then stores 10 to DAT_a802afec and calls FUN_a00b4144(8, 1) as a tail
 * call. Source form: an if/else chain with the shared calls written in both arms (GCC merges the tails).
 */
extern unsigned int DAT_a802afec;
extern unsigned char DAT_a802d419;
extern void FUN_a00a8ee8(unsigned char);
extern void FUN_a00b0034(unsigned char id);
extern void FUN_a00ab4bc(void);
extern void FUN_a00a9468(unsigned char sel, unsigned char mode);
extern void FUN_a00b34d4(unsigned char hi, unsigned char lo);
extern void FUN_a00b4144(unsigned char, int);
void FUN_a0092f2c(void)
{
    FUN_a00a8ee8(DAT_a802afec - 52);
    FUN_a00b0034(8);
    if (DAT_a802afec == 0x3b) {
        DAT_a802d419 = 0xff;
        FUN_a00ab4bc();
        FUN_a00a9468(2, 5);
        FUN_a00a9468(0, 0);
        FUN_a00a9468(1, 2);
        FUN_a00b34d4(0, 1);
    } else if (DAT_a802afec == 0x35) {
        FUN_a00a9468(1, 2);
        FUN_a00b34d4(0, 1);
    }
    DAT_a802afec = 10;
    FUN_a00b4144(8, 1);
}
