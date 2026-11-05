/* leon2m FUN_a00d7bc0 @ 0xa00d7bc0-0xa00d7d48 (98 words), flags -mcpu=v8 -O3 -g.
 * v = byte DAT_a802d290+0x44; v = 1 when bits 18..19 of word +0xac are not both clear and the FUN_a00d7b60 test
 * (inlined as chk()) is true; otherwise, when byte +0x11 is 1, byte +0x181 is 5 or 6 and bit 11 of word +0xa8 is
 * set, v = 3 (with bit 11 clear v keeps byte +0x44). v is limited to 7 and mapped to r by a switch (jump table at
 * 0x00073ac0 for 0..5): 1 -> 0x1a (bits 18..19 set and the test true), 0x18 (bit 11 set and byte +0x181 == 4)
 * or 0x13, 2 -> 0x11, 3 -> 0x13, 4 -> 0x19, 5 -> 0x18, 0, 6 and 7 -> 0. Ends with FUN_a014c794(r) (tail call).
 * Callers: FUN_a0086ae8, FUN_a0088724, FUN_a008f354, FUN_a00db738, FUN_a00dbcf0, FUN_a00dc3dc.
 * Source form: byte +0x181 read once into an unsigned int k for the 5..6 range test; 'r = 0;' as a statement right
 * before the switch (no default case).
 */
struct R290 {
    unsigned char pad0[0x11];
    unsigned char b11;
    unsigned char pad12[0x44 - 0x12];
    unsigned char b44;
    unsigned char pad45[0xa8 - 0x45];
    unsigned int wa8;
    unsigned int wac;
    unsigned char padb0[0x181 - 0xb0];
    unsigned char b181;
};
extern struct R290 DAT_a802d290;
extern unsigned char FUN_a014ba68(void);
extern unsigned char FUN_a014bd70(unsigned char ch);
extern void FUN_a014c794(unsigned char);

static int chk(void)
{
    unsigned char r = 0;

    if (FUN_a014ba68() == 2)
        r = 1;
    if (FUN_a014bd70(0) == 1)
        r = 1;
    return r & 1;
}

void FUN_a00d7bc0(void)
{
    unsigned char v = DAT_a802d290.b44;
    unsigned char r;
    unsigned int k;

    if ((DAT_a802d290.wac & 0xc0000) && chk())
        v = 1;
    else if (DAT_a802d290.b11 == 1 && (k = DAT_a802d290.b181) >= 5 && k <= 6) {
        if (DAT_a802d290.wa8 & 0x800)
            v = 3;
    }
    if (v > 7)
        v = 7;
    r = 0;
    switch (v) {
    case 1:
        if ((DAT_a802d290.wac & 0xc0000) && chk())
            r = 0x1a;
        else if ((DAT_a802d290.wa8 & 0x800) && DAT_a802d290.b181 == 4)
            r = 0x18;
        else
            r = 0x13;
        break;
    case 2:
        r = 0x11;
        break;
    case 3:
        r = 0x13;
        break;
    case 4:
        r = 0x19;
        break;
    case 5:
        r = 0x18;
        break;
    }
    FUN_a014c794(r);
}
