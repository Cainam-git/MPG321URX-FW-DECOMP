/* leon2m FUN_a00976f8 @ 0xa00976f8-0xa0097814 (71 words), flags -mcpu=v8 -O3 -g. Called from FUN_a0097814,
 * FUN_a00978c8, FUN_a00979ec and FUN_a00db1ac.
 * When byte 0x1f of DAT_a802d290 differs from DAT_a8025c56: if bit 15 of the halfword at 0xa802cff4 + 4 is set,
 * sets its bit 10 and calls FUN_a00808ac(4, 0); clears word 0xa802afec, calls FUN_a00b5080 and sets bits 14 and 13
 * of the halfword at 0xa802cff4 + 0x18. Tests the two bytes again; when they still differ it calls FUN_a00d91fc(0),
 * FUN_a0148268(0, 1), FUN_a0148268(1, 1), FUN_a00da254, FUN_a00830f4(0), FUN_a00d8c1c, FUN_a00d4998,
 * FUN_a00d5cd8 when bit 14 of word DAT_a802d290 + 0xa8 is set, then FUN_a00808ac(0, 0) and FUN_a00808ac(1, 0).
 * The halfword flags are single-bit bit-fields (the form of FUN_a0096b54).
 */
struct R290 { unsigned char pad[0x1f]; unsigned char b1f; unsigned char pad2[0xa8 - 0x20]; unsigned int wa8; };
struct Rcff4 {
    unsigned char pad[4];
    unsigned short b15 : 1, b14 : 4, b10 : 1, rest : 10;
    unsigned char pad2[0x18 - 6];
    unsigned short f15 : 1, f14 : 1, f13 : 1, frest : 13;
};
extern struct R290 DAT_a802d290;
extern struct Rcff4 DAT_a802cff4;
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00808ac(unsigned char, unsigned char);
extern void FUN_a00b5080(void);
extern void FUN_a00d91fc(int);
extern void FUN_a0148268(int, int);
extern void FUN_a00da254(void);
extern void FUN_a00830f4(int);
extern void FUN_a00d8c1c(void);
extern void FUN_a00d4998(void);
extern void FUN_a00d5cd8(void);

void FUN_a00976f8(void)
{
    if (DAT_a802d290.b1f != DAT_a8025c56) {
        if (DAT_a802cff4.b15) {
            DAT_a802cff4.b10 = 1;
            FUN_a00808ac(4, 0);
        }
        _DAT_a802afec = 0;
        FUN_a00b5080();
        DAT_a802cff4.f14 = 1;
        DAT_a802cff4.f13 = 1;
    }
    if (DAT_a802d290.b1f != DAT_a8025c56) {
        FUN_a00d91fc(0);
        FUN_a0148268(0, 1);
        FUN_a0148268(1, 1);
        FUN_a00da254();
        FUN_a00830f4(0);
        FUN_a00d8c1c();
        FUN_a00d4998();
        if (DAT_a802d290.wa8 & 0x4000)
            FUN_a00d5cd8();
        FUN_a00808ac(0, 0);
        FUN_a00808ac(1, 0);
    }
}
