/* leon2m FUN_a0094b6c @ 0xa0094b6c-0xa0094df0 (161 words), flags -mcpu=v8 -O3 -g. No direct callers (reached through
 * a table). Selected by byte 0xa802d433 (0xa802d290 + 0x1a3). 0: when byte +0x1a5 differs from (FUN_a014837c(0) -
 * 192) / 72 (signed), FUN_a00a6b98(0, 0, 1), the byte is raised by 1 and FUN_a00a6b98(0, 0, 0) is tail-called. 1:
 * the same with byte +0x1a7, (FUN_a014837c(0) - 288) / 72 and first argument 1. 2: uses the halfwords 0xa802d034 and
 * 0xa802d03a ('restarted' = set to FUN_a0147724(); 'more than n have passed since t' = func_0x4008d594(t) > n) and
 * byte 0xa802cffc (0xa802cff4 + 8): when more than 100 have passed since 0xa802d034, the byte is set to 0x42 and
 * 0xa802d03a restarted; 0xa802d034 is restarted; when the high nibble of the byte is not 4, the byte is set to 0x42
 * and 0xa802d03a restarted; when more than 2000 (5000) have passed since 0xa802d03a and at most 99 since 0xa802d034,
 * the byte is set to 0x46 (0x4a). The halfword +0x1ac is raised by the low nibble of the byte when the sum stays
 * within FUN_a014837c(0) - 120, else by 2 when it is below FUN_a014837c(0) - 96 (signed compares), and
 * FUN_a014654c(halfword +0x1ac, halfword +0x1ae, 1) is tail-called. Same form as FUN_a00945a8 and FUN_a0093d30.
 */
struct Rcff4 { unsigned char pad[8]; unsigned char b8; };
struct R290 {
    unsigned char pad[0x1a3];
    unsigned char b1a3, b1a4, b1a5, b1a6, b1a7;
    unsigned char pad1a8[4];
    unsigned short h1ac, h1ae;
};
extern struct Rcff4 DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned short DAT_a802d034, DAT_a802d03a;
extern unsigned short FUN_a0147724(void);
extern unsigned short func_0x4008d594(unsigned short start);
extern void FUN_a00a6b98(int, int, int);
extern void FUN_a014654c(int, int, int);
extern unsigned short FUN_a014837c(unsigned char p);

void FUN_a0094b6c(void)
{
    if (DAT_a802d290.b1a3 == 0) {
        if (DAT_a802d290.b1a5 != (FUN_a014837c(0) - 192) / 72) {
            FUN_a00a6b98(0, 0, 1);
            DAT_a802d290.b1a5++;
            FUN_a00a6b98(0, 0, 0);
        }
    } else if (DAT_a802d290.b1a3 == 1) {
        if (DAT_a802d290.b1a7 != (FUN_a014837c(0) - 288) / 72) {
            FUN_a00a6b98(1, 0, 1);
            DAT_a802d290.b1a7++;
            FUN_a00a6b98(1, 0, 0);
        }
    } else if (DAT_a802d290.b1a3 == 2) {
        if (func_0x4008d594(DAT_a802d034) > 100) {
            DAT_a802cff4.b8 = 0x42;
            DAT_a802d03a = FUN_a0147724();
        }
        DAT_a802d034 = FUN_a0147724();
        if ((DAT_a802cff4.b8 >> 4) != 4) {
            DAT_a802cff4.b8 = 0x42;
            DAT_a802d03a = FUN_a0147724();
        }
        if (func_0x4008d594(DAT_a802d03a) > 2000)
            if (func_0x4008d594(DAT_a802d034) <= 99)
                DAT_a802cff4.b8 = 0x46;
        if (func_0x4008d594(DAT_a802d03a) > 5000)
            if (func_0x4008d594(DAT_a802d034) <= 99)
                DAT_a802cff4.b8 = 0x4a;
        if (DAT_a802d290.h1ac + (DAT_a802cff4.b8 & 0xf) <= FUN_a014837c(0) - 120)
            DAT_a802d290.h1ac += DAT_a802cff4.b8 & 0xf;
        else if (DAT_a802d290.h1ac < FUN_a014837c(0) - 96)
            DAT_a802d290.h1ac += 2;
        FUN_a014654c(DAT_a802d290.h1ac, DAT_a802d290.h1ae, 1);
    }
}
