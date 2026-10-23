/* leon2m FUN_a0142ed0 @ 0xa0142ed0-0xa0142fcc (63 words).
 * Port record p of DAT_a802e224 (0x2a bytes each): when byte +0x0a differs from m or force != 0:
 * FUN_a00fde94(p) if the old value is 0x11..0x13 or 0x21; then +0x0a = m, +0x02 = 2, FUN_a00fd594(p, m),
 * FUN_a00fd9a0(p, m); halfword +0x10 = 1000 when the re-read +0x0a is 0x11..0x13 or 0x21, else 100; byte
 * +0x0e = 5. Called by FUN_a012f43c.
 * Source form: each pair of conditions is held in int locals and combined with '|' (the firmware computes both
 * flags with addx/subx and tests them with orcc).
 */
struct Port {
    unsigned char b00, b01, b02;
    unsigned char p03[7];
    unsigned char b0a;
    unsigned char p0b[3];
    unsigned char b0e;
    unsigned char p0f;
    unsigned short h10;
    unsigned char rest[0x2a - 0x12];
};
extern struct Port DAT_a802e224[];
extern void FUN_a00fde94(unsigned char);
extern void FUN_a00fd594(unsigned char, unsigned char);
extern void FUN_a00fd9a0(unsigned char, unsigned char);

void FUN_a0142ed0(unsigned char p, unsigned char m, unsigned char force)
{
    unsigned char v = DAT_a802e224[p].b0a;
    int chg = v != m, f = force != 0;

    if (chg | f) {
        int x = (unsigned char)(v - 0x11) < 3, y = v == 0x21;
        if (x | y)
            FUN_a00fde94(p);
        DAT_a802e224[p].b0a = m;
        DAT_a802e224[p].b02 = 2;
        FUN_a00fd594(p, m);
        FUN_a00fd9a0(p, m);
        v = DAT_a802e224[p].b0a;
        x = (unsigned char)(v - 0x11) < 3;
        y = v == 0x21;
        if (x | y)
            DAT_a802e224[p].h10 = 1000;
        else
            DAT_a802e224[p].h10 = 100;
        DAT_a802e224[p].b0e = 5;
    }
}
