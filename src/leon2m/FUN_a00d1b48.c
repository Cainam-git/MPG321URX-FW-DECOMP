/* leon2m FUN_a00d1b48 @ 0xa00d1b48-0xa00d1ce4 (103 words).
 * When bits 8..23 of word DAT_a802d290+8 are 0x102: halfword 0xa802e1da += 1 and FUN_a0145360(1); when they are
 * 0x104: the same and FUN_a0149254(0). Byte DAT_a802d274+0x10 = 0xf6; when halfword DAT_a802d290+0x1f6 is 0x55aa,
 * FUN_a0145c5c(n, 0) for n = 0xb, 0xa, 0xd, 0xc, 0x10, 0xe, 0xf and FUN_a0145360(1). Then FUN_a00dc3dc(), writes
 * DAT_a802d290 with FUN_a014aed0(0x30, DAT_a802d290, 0, 0x1fc), clears byte +0x10 of DAT_a802d274, calls
 * FUN_a00cea44(), stores 0xbb99 to halfword +0x1f6 and writes DAT_a802d274 with FUN_a014aed0(0x30, DAT_a802d274,
 * 0x2e0, 0x1c). Returns 0xe0.
 */
struct S290 {
    unsigned char pad0[8];
    unsigned int w08;
    unsigned char pad0c[0x1f6 - 0xc];
    unsigned short h1f6;
};
struct S274 {
    unsigned char pad[0x10];
    unsigned char b10;
};
struct Se1a0 {
    unsigned char pad[0x3a];
    unsigned short h3a;
};
extern struct S290 DAT_a802d290;
extern struct S274 DAT_a802d274;
extern struct Se1a0 DAT_a802e1a0;
extern void FUN_a0145360(int);
extern void FUN_a0149254(unsigned char);
extern void FUN_a0145c5c(int, int);
extern void FUN_a00dc3dc(void);
extern void FUN_a00cea44(void);
extern int FUN_a014aed0(int, void *, int, int);

unsigned char FUN_a00d1b48(void)
{
    if ((DAT_a802d290.w08 & 0xffff00) == 0x10200) {
        DAT_a802e1a0.h3a++;
        FUN_a0145360(1);
    }
    if ((DAT_a802d290.w08 & 0xffff00) == 0x10400) {
        DAT_a802e1a0.h3a++;
        FUN_a0145360(1);
        FUN_a0149254(0);
    }
    DAT_a802d274.b10 = 0xf6;
    if (DAT_a802d290.h1f6 == 0x55aa) {
        FUN_a0145c5c(0xb, 0);
        FUN_a0145c5c(0xa, 0);
        FUN_a0145c5c(0xd, 0);
        FUN_a0145c5c(0xc, 0);
        FUN_a0145c5c(0x10, 0);
        FUN_a0145c5c(0xe, 0);
        FUN_a0145c5c(0xf, 0);
        FUN_a0145360(1);
    }
    FUN_a00dc3dc();
    FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
    DAT_a802d274.b10 = 0;
    FUN_a00cea44();
    DAT_a802d290.h1f6 = 0xbb99;
    FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c);
    return 0xe0;
}
