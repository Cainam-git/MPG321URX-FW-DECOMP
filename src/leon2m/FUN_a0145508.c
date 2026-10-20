/* leon2m FUN_a0145508 @ 0xa0145508-0xa0145644 (79 words).
 * mode 0 tail-calls FUN_a01544cc. mode 1 visits display channels 0..3: for each channel i where FUN_a013ce6c(i)
 * returns 0xc and the 0x2a-byte entry at 0xa802e224 selected by bits 12..15 of word 0 of record i (0x78-byte records
 * at 0xa802df30, through the channel check that reports "SYS remapping channel OOR") does not hold 5 in byte 9, record
 * i gets byte 0x26 = 0x20 and the halfwords at 0x28, 0x2a and 0x2c are copied to 0x0e, 0x1e and 0x20. Other modes do
 * nothing. The __builtin_expect hint (copy is the unlikely case) gives the firmware's annulled loop increment in
 * the delay slot of the kind test.
 */
struct Rec {
    unsigned int top : 16;
    unsigned int f12 : 4;
    unsigned int low : 12;
    unsigned char p04[0x0a];
    unsigned short h0e;
    unsigned char p10[0x0e];
    unsigned short h1e;
    unsigned short h20;
    unsigned char p22[4];
    unsigned char b26;
    unsigned char p27;
    unsigned short h28, h2a, h2c;
    unsigned char tail[0x4a];
};
struct Src { unsigned char p[9]; unsigned char kind; unsigned char rest[0x20]; };
extern struct Rec DAT_a802df30[4];
extern struct Src DAT_a802e224[];
extern int FUN_a00df170();
extern char s_001a6dd8[];
extern unsigned char FUN_a013ce6c(unsigned char);
extern void FUN_a01544cc(void);

static int remap(int ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

void FUN_a0145508(unsigned char mode)
{
    unsigned char i, k;

    if (mode == 0) {
        FUN_a01544cc();
        return;
    }
    if (mode != 1)
        return;
    for (i = 0; i < 4; i++) {
        if (FUN_a013ce6c(i) != 0xc)
            continue;
        k = remap(i);
        if (k > 3) { FUN_a00df170(s_001a6dd8); k = 0; }
        if (__builtin_expect(DAT_a802e224[DAT_a802df30[k].f12].kind != 5, 0)) {
            DAT_a802df30[i].h0e = DAT_a802df30[i].h28;
            DAT_a802df30[i].h1e = DAT_a802df30[i].h2a;
            DAT_a802df30[i].h20 = DAT_a802df30[i].h2c;
            DAT_a802df30[i].b26 = 0x20;
        }
    }
}
