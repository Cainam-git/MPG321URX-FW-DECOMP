/* leon2m FUN_a0129c64 @ 0xa0129c64-0xa0129edc (158 words), flags -mcpu=v8 -O3 -g. No direct callers.
 * Byte 0xa802a449 = ((b * k + 50) / 100 + 126) / 4 with b = byte 8 of 0xa802e3d0 and k = 607 when word 0x38 of
 * that structure is 1 or 2, else 897; byte 0xa802ca03 = 0x7e. Target t = that value when bit 0 of byte 0xa802ca02
 * is set, else value * 85 / 100; t is raised to byte 0xa802ca03 when below it. When byte 0xa802a448 equals t the
 * function returns; otherwise 0xa802a448 steps one towards t and FUN_a0101a28(byte 0xa802ca03, byte 0xa802a448)
 * runs. Then the same index update as FUN_a0129edc: r = FUN_a0101cb4(); above byte 0xa802a44b, index i counts up
 * from byte 0xa802a44a to 0x3f and the first i whose entry in the byte table 0x1a3128 is >= r is stored; otherwise
 * i counts down to 0x18 and for the first entry below r, i + 1 is stored; a final i of at most 0x18 stores 0x18.
 * FUN_a0101b48 and FUN_a0101b60 get the low byte of 0xa802a44a * 4, byte 0xa802a44b = r, and func_0x4008e2a4()
 * is tail-called.
 * Source form: the 0xa802a449 assignment is written out in each of the three arms (word 0x38 == 1, == 2, other).
 */
struct E3d0 { unsigned char p00[8]; unsigned char b08; unsigned char p09[0x38 - 9]; unsigned int w38; };
extern struct E3d0 DAT_a802e3d0;
extern unsigned char DAT_a802a448, DAT_a802a449, DAT_a802a44a, DAT_a802a44b;
extern unsigned char DAT_a802ca02, DAT_a802ca03;
extern const unsigned char DAT_001a3128[];
extern void FUN_a0101a28(unsigned int, unsigned int);
extern void FUN_a0101b48(unsigned int);
extern void FUN_a0101b60(unsigned int);
extern unsigned int FUN_a0101cb4(void);
extern void func_0x4008e2a4(void);

void FUN_a0129c64(void)
{
    unsigned char r, i, t;

    if (DAT_a802e3d0.w38 == 1)
        DAT_a802a449 = ((DAT_a802e3d0.b08 * 607u + 50) / 100 + 126) / 4;
    else if (DAT_a802e3d0.w38 == 2)
        DAT_a802a449 = ((DAT_a802e3d0.b08 * 607u + 50) / 100 + 126) / 4;
    else
        DAT_a802a449 = ((DAT_a802e3d0.b08 * 897u + 50) / 100 + 126) / 4;
    DAT_a802ca03 = 0x7e;
    if (DAT_a802ca02 & 1)
        t = DAT_a802a449;
    else
        t = DAT_a802a449 * 85 / 100;
    if (t < DAT_a802ca03)
        t = DAT_a802ca03;
    if (DAT_a802a448 == t)
        return;
    if (DAT_a802a448 > t)
        DAT_a802a448--;
    else
        DAT_a802a448++;
    FUN_a0101a28(DAT_a802ca03, DAT_a802a448);
    r = FUN_a0101cb4();
    if (r > DAT_a802a44b) {
        for (i = DAT_a802a44a; i <= 0x3f; i++)
            if (DAT_001a3128[i] >= r) {
                DAT_a802a44a = i;
                break;
            }
    } else {
        for (i = DAT_a802a44a; i > 0x17; i--)
            if (DAT_001a3128[i] < r) {
                DAT_a802a44a = i + 1;
                break;
            }
    }
    if (i <= 0x18)
        DAT_a802a44a = 0x18;
    FUN_a0101b48((unsigned char)(DAT_a802a44a << 2));
    FUN_a0101b60((unsigned char)(DAT_a802a44a << 2));
    DAT_a802a44b = r;
    func_0x4008e2a4();
}
