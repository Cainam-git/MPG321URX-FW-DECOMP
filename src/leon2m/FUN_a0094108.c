/* leon2m FUN_a0094108 @ 0xa0094108-0xa0094368 (152 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Uses the halfword time stamps 0xa802d034 and 0xa802d03a (FUN_a0147724 returns the current count,
 * func_0x4008d594(t) the count elapsed since t) and byte 0xa802cffc (0xa802cff4 + 8). When more than 100 have passed
 * since 0xa802d034, the byte is set to 0x48 and 0xa802d03a restarted; 0xa802d034 is restarted; when the high nibble
 * of the byte is not 4, the byte is set to 0x48 and 0xa802d03a restarted. When more than 2000 and when more than 5000
 * have passed since 0xa802d03a, the byte is set to 0x48 unless more than 99 have passed since 0xa802d034. Then, for
 * byte 0xa802d2c1 (0xa802d290 + 0x31) 0, 1 or 2, with the limit FUN_a014837c(1) - 972, - 756 or - 540: the
 * halfword 0xa802d2e6 (+0x56) is raised by the low nibble of the byte when the sum stays within the limit, else by
 * 1 when it is below the limit (signed compares). Ends with FUN_a00d7a70(0) and sets bit 1 (0x02) of byte
 * 0xa802b08e. Same time stamp handling as FUN_a0093bac; FUN_a0093d30 is the same for the halfword +0x54.
 */
struct Rcff4 { unsigned char pad[8]; unsigned char b8; };
struct R290 { unsigned char pad[0x31]; unsigned char b31; unsigned char pad32[0x22]; unsigned short h54, h56; };
extern struct Rcff4 DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned short DAT_a802d034, DAT_a802d03a;
extern unsigned char DAT_a802b08e;
extern unsigned short FUN_a0147724(void);
extern unsigned short func_0x4008d594(unsigned short start);
extern void FUN_a00d7a70(int);
extern unsigned short FUN_a014837c(unsigned char p);

void FUN_a0094108(void)
{
    if (func_0x4008d594(DAT_a802d034) > 100) {
        DAT_a802cff4.b8 = 0x48;
        DAT_a802d03a = FUN_a0147724();
    }
    DAT_a802d034 = FUN_a0147724();
    if ((DAT_a802cff4.b8 >> 4) != 4) {
        DAT_a802cff4.b8 = 0x48;
        DAT_a802d03a = FUN_a0147724();
    }
    if (func_0x4008d594(DAT_a802d03a) > 2000)
        if (func_0x4008d594(DAT_a802d034) <= 99)
            DAT_a802cff4.b8 = 0x48;
    if (func_0x4008d594(DAT_a802d03a) > 5000)
        if (func_0x4008d594(DAT_a802d034) <= 99)
            DAT_a802cff4.b8 = 0x48;
    if (DAT_a802d290.b31 == 0) {
        if (DAT_a802d290.h56 + (DAT_a802cff4.b8 & 0xf) <= FUN_a014837c(1) - 972)
            DAT_a802d290.h56 += (DAT_a802cff4.b8 & 0xf);
        else if (DAT_a802d290.h56 < FUN_a014837c(1) - 972)
            DAT_a802d290.h56 += 1;
    } else if (DAT_a802d290.b31 == 1) {
        if (DAT_a802d290.h56 + (DAT_a802cff4.b8 & 0xf) <= FUN_a014837c(1) - 756)
            DAT_a802d290.h56 += (DAT_a802cff4.b8 & 0xf);
        else if (DAT_a802d290.h56 < FUN_a014837c(1) - 756)
            DAT_a802d290.h56 += 1;
    } else if (DAT_a802d290.b31 == 2) {
        if (DAT_a802d290.h56 + (DAT_a802cff4.b8 & 0xf) <= FUN_a014837c(1) - 540)
            DAT_a802d290.h56 += (DAT_a802cff4.b8 & 0xf);
        else if (DAT_a802d290.h56 < FUN_a014837c(1) - 540)
            DAT_a802d290.h56 += 1;
    }
    FUN_a00d7a70(0);
    DAT_a802b08e |= 2;
}
