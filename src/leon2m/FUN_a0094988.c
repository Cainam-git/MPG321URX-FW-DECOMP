/* leon2m FUN_a0094988 @ 0xa0094988-0xa0094b6c (121 words), flags -mcpu=v8 -O3 -g. No direct callers (reached through
 * a table). Selected by byte 0xa802d433 (0xa802d290 + 0x1a3). 0: when byte +0x1a6 is not 0x1c, FUN_a00a6b98(0, 0,
 * 1), the byte is raised by 1 and FUN_a00a6b98(0, 0, 0) is tail-called. 1: the same with byte +0x1a8 and first
 * argument 1. 2: uses the halfwords 0xa802d034 and 0xa802d03a ('restarted' = set to FUN_a0147724(); 'more than n
 * have passed since t' = func_0x4008d594(t) > n) and byte 0xa802cffc (0xa802cff4 + 8): when more than 100 have
 * passed since 0xa802d034, the byte is set to 0x11 and 0xa802d03a restarted; 0xa802d034 is restarted; when the high
 * nibble of the byte is not 1, the byte is set to 0x11 and 0xa802d03a restarted; when more than 2000 (5000) have
 * passed since 0xa802d03a and at most 99 since 0xa802d034, the byte is set to 0x15 (0x1a). The halfword +0x1ae is
 * raised by the low nibble of the byte while the sum stays at most 0x7f2, else by 1 while it is at most 0x803, and
 * FUN_a014654c(halfword +0x1ac, halfword +0x1ae, 1) is tail-called. Same form as FUN_a00945a8.
 * Exact form: the step is (byte & 0xf) in an unsigned short local and the limit test is written h + step; the three
 * selector values are an if/else chain. (FUN_a00945a8 reads the step through a 4-bit bit-field.)
 */
union U8 { unsigned char b; struct { unsigned char hi : 4, lo : 4; } f; };
struct Rcff4 { unsigned char pad[8]; union U8 u; };
struct R290 {
    unsigned char pad[0x1a3];
    unsigned char b1a3, b1a4, b1a5, b1a6, b1a7, b1a8;
    unsigned char pad1a9[3];
    unsigned short h1ac, h1ae;
};
extern struct Rcff4 DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned short DAT_a802d034, DAT_a802d03a;
extern unsigned short FUN_a0147724(void);
extern unsigned short func_0x4008d594(unsigned short start);
extern void FUN_a00a6b98(int, int, int);
extern void FUN_a014654c(int, int, int);

void FUN_a0094988(void)
{
    unsigned short step;

    if (DAT_a802d290.b1a3 == 0) {
        if (DAT_a802d290.b1a6 != 0x1c) {
            FUN_a00a6b98(0, 0, 1);
            DAT_a802d290.b1a6++;
            FUN_a00a6b98(0, 0, 0);
        }
    } else if (DAT_a802d290.b1a3 == 1) {
        if (DAT_a802d290.b1a8 != 0x1c) {
            FUN_a00a6b98(1, 0, 1);
            DAT_a802d290.b1a8++;
            FUN_a00a6b98(1, 0, 0);
        }
    } else if (DAT_a802d290.b1a3 == 2) {
        if (func_0x4008d594(DAT_a802d034) > 100) {
            DAT_a802cff4.u.b = 0x11;
            DAT_a802d03a = FUN_a0147724();
        }
        DAT_a802d034 = FUN_a0147724();
        if ((DAT_a802cff4.u.b >> 4) != 1) {
            DAT_a802cff4.u.b = 0x11;
            DAT_a802d03a = FUN_a0147724();
        }
        if (func_0x4008d594(DAT_a802d03a) > 2000)
            if (func_0x4008d594(DAT_a802d034) <= 99)
                DAT_a802cff4.u.b = 0x15;
        if (func_0x4008d594(DAT_a802d03a) > 5000)
            if (func_0x4008d594(DAT_a802d034) <= 99)
                DAT_a802cff4.u.b = 0x1a;
        step = DAT_a802cff4.u.b & 0xf;
        if (DAT_a802d290.h1ae + step <= 0x7f2)
            DAT_a802d290.h1ae += step;
        else if (DAT_a802d290.h1ae <= 0x803)
            DAT_a802d290.h1ae++;
        FUN_a014654c(DAT_a802d290.h1ac, DAT_a802d290.h1ae, 1);
    }
}
