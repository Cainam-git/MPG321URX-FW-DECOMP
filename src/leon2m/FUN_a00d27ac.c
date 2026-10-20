/* FUN_a00d27ac (leon2m 0xa00d27ac-0xa00d2884, 216 bytes), flags -mcpu=v8 -O3 -g.
 * Takes a pointer p to a received frame. For p[7] = 0, 1 or 2: byte 0xa802d290+9 and byte +0x59 = 0x19 (for 0)
 * or 0x46 (for 1 and 2), byte 0xa802e1ab = p[7], bit 11 of the word 0xa802d290+0xa8 cleared, byte +0x182 = 1,
 * byte +0x181 = 0; then FUN_a00d8cd4(), FUN_a00dbcf0(), FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc) and
 * FUN_a0145360(1) run and 0xe0 is returned. Any other p[7] returns 0xe4.
 * Source form: each value has its own full arm (GCC merges the common tails); bit 11 of word +0xa8 is a 1-bit
 * bit-field; byte +0x181 is cleared before the FUN_a00d8cd4 call.
 */
struct R290 { unsigned char p000[9]; unsigned char b009; unsigned char p00a[0x59 - 0xa]; unsigned char b059;
              unsigned char p05a[0xa8 - 0x5a]; unsigned int w0a8_hi : 20, b11 : 1, w0a8_lo : 11; unsigned char p0ac[0x181 - 0xac];
              unsigned char b181; unsigned char b182; unsigned char p183[0x1fc - 0x183]; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802e1ab;
extern void FUN_a00d8cd4(void);
extern void FUN_a00dbcf0(void);
extern int FUN_a014aed0(int, void *, int, int);
extern void FUN_a0145360(int);

int FUN_a00d27ac(unsigned char *p)
{
    if (p[7] == 0) {
        DAT_a802d290.b009 = 0x19;
        DAT_a802e1ab = 0;
        DAT_a802d290.b059 = 0x19;
        DAT_a802d290.b11 = 0;
        DAT_a802d290.b182 = 1;
        DAT_a802d290.b181 = 0;
        FUN_a00d8cd4();
        FUN_a00dbcf0();
        FUN_a014aed0(0x30, &DAT_a802d290, 0, sizeof DAT_a802d290);
        FUN_a0145360(1);
        return 0xe0;
    } else if (p[7] == 1) {
        DAT_a802d290.b009 = 0x46;
        DAT_a802e1ab = 1;
        DAT_a802d290.b059 = 0x46;
        DAT_a802d290.b11 = 0;
        DAT_a802d290.b182 = 1;
        DAT_a802d290.b181 = 0;
        FUN_a00d8cd4();
        FUN_a00dbcf0();
        FUN_a014aed0(0x30, &DAT_a802d290, 0, sizeof DAT_a802d290);
        FUN_a0145360(1);
        return 0xe0;
    } else if (p[7] == 2) {
        DAT_a802d290.b009 = 0x46;
        DAT_a802e1ab = 2;
        DAT_a802d290.b059 = 0x46;
        DAT_a802d290.b11 = 0;
        DAT_a802d290.b182 = 1;
        DAT_a802d290.b181 = 0;
        FUN_a00d8cd4();
        FUN_a00dbcf0();
        FUN_a014aed0(0x30, &DAT_a802d290, 0, sizeof DAT_a802d290);
        FUN_a0145360(1);
        return 0xe0;
    }
    return 0xe4;
}
