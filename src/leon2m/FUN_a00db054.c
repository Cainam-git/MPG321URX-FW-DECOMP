/* leon2m FUN_a00db054 @ 0xa00db054-0xa00db12c (54 words), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a0124a08(), FUN_a01248ac(), FUN_a014512c(0, 0), FUN_a00d99f8(2, 0), FUN_a0148268(0, 1),
 * FUN_a0148268(1, 1) and FUN_a014a8d4(4, 1, 1000). Then by bits 18..19 of the word at 0xa802d290 + 0xac:
 * 0x40000 -> halfword 0xa802e1f0 + 0x24 = 0x3f7 and FUN_a014e050(0); 0x80000 -> 0x3f7 and FUN_a014e050(1);
 * otherwise 0x1c2 and FUN_a014e050(0). Ends with the tail call FUN_a014e024(halfword 0xa802e1f0 + 0x24).
 * Callers: FUN_a0087020, FUN_a0096ce4, FUN_a00c9be0, FUN_a00db1ac, FUN_a00dc3dc.
 * Source form: both globals are named directly in every arm of the if/else-if chain (no pointer local), so each
 * arm computes the address of 0xa802e1f0 itself, as the firmware does.
 */
struct R290 {
    unsigned char pad[0xac];
    unsigned int wac;
};
struct E1f0 {
    unsigned char pad[0x24];
    unsigned short h24;
};
extern struct R290 DAT_a802d290;
extern struct E1f0 DAT_a802e1f0;
extern void FUN_a0124a08(void);
extern void FUN_a01248ac(void);
extern void FUN_a014512c(unsigned int, unsigned int);
extern void FUN_a00d99f8(unsigned char how, unsigned char sel);
extern void FUN_a0148268(unsigned char, unsigned char);
extern void FUN_a014a8d4(unsigned char ch, unsigned int on, unsigned short v);
extern void FUN_a014e050(unsigned char mode);
extern void FUN_a014e024(unsigned short);

void FUN_a00db054(void)
{
    FUN_a0124a08();
    FUN_a01248ac();
    FUN_a014512c(0, 0);
    FUN_a00d99f8(2, 0);
    FUN_a0148268(0, 1);
    FUN_a0148268(1, 1);
    FUN_a014a8d4(4, 1, 1000);
    if ((DAT_a802d290.wac & 0xc0000) == 0x40000) {
        DAT_a802e1f0.h24 = 0x3f7;
        FUN_a014e050(0);
    } else if ((DAT_a802d290.wac & 0xc0000) == 0x80000) {
        DAT_a802e1f0.h24 = 0x3f7;
        FUN_a014e050(1);
    } else {
        DAT_a802e1f0.h24 = 0x1c2;
        FUN_a014e050(0);
    }
    FUN_a014e024(DAT_a802e1f0.h24);
}
