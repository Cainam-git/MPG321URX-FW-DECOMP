/* leon2m FUN_a0129edc @ 0xa0129edc-0xa012a128 (147 words), flags -mcpu=v8 -O3 -g. No direct callers.
 * Calls FUN_a0101c64(0), FUN_a010192c(0), FUN_a0101868(0, 0). Byte 0xa802a449 = ((b * k + 50) / 100 + 126) / 4
 * with b = byte 8 of 0xa802e3d0 and k = 607 when word 0x38 of that structure is 1 or 2, else 897; byte 0xa802a448
 * gets the same value, byte 0xa802ca03 = 0x7e, FUN_a0101a28(0x7e, that value). Then FUN_a0101b48(0x40),
 * FUN_a0101b60(0x40), FUN_a0101950(8), FUN_a0101984(1), FUN_a01019b4(1), FUN_a0101884(0, 1). r = FUN_a0101cb4().
 * When r is above byte 0xa802a44b, index i counts up from byte 0xa802a44a to 0x3f and the first i whose entry in
 * the byte table 0x1a3128 is >= r is stored in 0xa802a44a; otherwise i counts down from 0xa802a44a to 0x18 and
 * for the first entry below r, i + 1 is stored. When the final i is at most 0x18, 0xa802a44a = 0x18. Then
 * FUN_a0101b48 and FUN_a0101b60 get the low byte of 0xa802a44a * 4, byte 0xa802a44b = r, func_0x4008e2a4() runs
 * when FUN_a0104c34(8) returns 0, then FUN_a01016cc(), FUN_a0101858(7, 0xd), FUN_a01018e8(), FUN_a011e438(7, 1)
 * and byte 0xa802ca02 = 0x81.
 * Source form: the 0xa802a449 assignment is written out in each of the three arms (word 0x38 == 1, == 2, other).
 */
struct E3d0 { unsigned char p00[8]; unsigned char b08; unsigned char p09[0x38 - 9]; unsigned int w38; };
extern struct E3d0 DAT_a802e3d0;
extern unsigned char DAT_a802a448, DAT_a802a449, DAT_a802a44a, DAT_a802a44b;
extern unsigned char DAT_a802ca02, DAT_a802ca03;
extern const unsigned char DAT_001a3128[];
extern void FUN_a0101c64(unsigned char);
extern void FUN_a010192c(unsigned int);
extern void FUN_a0101868(unsigned int, int);
extern void FUN_a0101a28(unsigned int, unsigned int);
extern void FUN_a0101b48(unsigned int);
extern void FUN_a0101b60(unsigned int);
extern void FUN_a0101950(unsigned int);
extern void FUN_a0101984(unsigned int);
extern void FUN_a01019b4(unsigned int);
extern void FUN_a0101884(unsigned int, unsigned int);
extern unsigned int FUN_a0101cb4(void);
extern unsigned char FUN_a0104c34(unsigned char blk);
extern void func_0x4008e2a4(void);
extern void FUN_a01016cc(void);
extern void FUN_a0101858();
extern void FUN_a01018e8(void);
extern void FUN_a011e438(unsigned char ch, unsigned char b);

void FUN_a0129edc(void)
{
    unsigned char r, i;

    FUN_a0101c64(0);
    FUN_a010192c(0);
    FUN_a0101868(0, 0);
    if (DAT_a802e3d0.w38 == 1)
        DAT_a802a449 = ((DAT_a802e3d0.b08 * 607u + 50) / 100 + 126) / 4;
    else if (DAT_a802e3d0.w38 == 2)
        DAT_a802a449 = ((DAT_a802e3d0.b08 * 607u + 50) / 100 + 126) / 4;
    else
        DAT_a802a449 = ((DAT_a802e3d0.b08 * 897u + 50) / 100 + 126) / 4;
    DAT_a802a448 = DAT_a802a449;
    DAT_a802ca03 = 0x7e;
    FUN_a0101a28(DAT_a802ca03, DAT_a802a448);
    FUN_a0101b48(0x40);
    FUN_a0101b60(0x40);
    FUN_a0101950(8);
    FUN_a0101984(1);
    FUN_a01019b4(1);
    FUN_a0101884(0, 1);
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
    if (FUN_a0104c34(8) == 0)
        func_0x4008e2a4();
    FUN_a01016cc();
    FUN_a0101858(7, 0xd);
    FUN_a01018e8();
    FUN_a011e438(7, 1);
    DAT_a802ca02 = 0x81;
}
