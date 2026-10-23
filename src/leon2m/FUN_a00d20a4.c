/* leon2m FUN_a00d20a4 @ 0xa00d20a4-0xa00d2334 (164 words).
 * Maps byte 7 of the record p (0..0x1f) to a value stored in byte DAT_a802d290+8 (jump table 0x6ecb0; codes 0xa,
 * 0xb, 0xf and codes above 0x1f leave it unchanged), then writes DAT_a802d290 with FUN_a014aed0(0x30,
 * DAT_a802d290, 0, 0x1fc), calls FUN_a0145360(1) and returns 0xe0.
 */
struct St {
    unsigned char pad[8];
    unsigned char b08;
};
extern struct St DAT_a802d290;
extern int FUN_a014aed0(int, void *, int, int);
extern void FUN_a0145360(int);

unsigned char FUN_a00d20a4(unsigned char *p)
{
    switch (p[7]) {
    case 0x0:
        DAT_a802d290.b08 = 0x1;
        break;
    case 0x1:
        DAT_a802d290.b08 = 0x3;
        break;
    case 0x2:
        DAT_a802d290.b08 = 0x2;
        break;
    case 0x3:
        DAT_a802d290.b08 = 0x5;
        break;
    case 0x4:
        DAT_a802d290.b08 = 0x4;
        break;
    case 0x5:
        DAT_a802d290.b08 = 0x19;
        break;
    case 0x6:
        DAT_a802d290.b08 = 0x16;
        break;
    case 0x7:
        DAT_a802d290.b08 = 0x9;
        break;
    case 0x8:
        DAT_a802d290.b08 = 0x18;
        break;
    case 0x9:
        DAT_a802d290.b08 = 0x8;
        break;
    case 0xc:
        DAT_a802d290.b08 = 0x0;
        break;
    case 0xd:
        DAT_a802d290.b08 = 0x7;
        break;
    case 0xe:
        DAT_a802d290.b08 = 0x6;
        break;
    case 0x10:
        DAT_a802d290.b08 = 0xd;
        break;
    case 0x11:
        DAT_a802d290.b08 = 0xa;
        break;
    case 0x12:
        DAT_a802d290.b08 = 0xb;
        break;
    case 0x13:
        DAT_a802d290.b08 = 0xc;
        break;
    case 0x14:
        DAT_a802d290.b08 = 0xe;
        break;
    case 0x15:
        DAT_a802d290.b08 = 0xf;
        break;
    case 0x16:
        DAT_a802d290.b08 = 0x10;
        break;
    case 0x17:
        DAT_a802d290.b08 = 0x11;
        break;
    case 0x18:
        DAT_a802d290.b08 = 0x12;
        break;
    case 0x19:
        DAT_a802d290.b08 = 0x13;
        break;
    case 0x1a:
        DAT_a802d290.b08 = 0x14;
        break;
    case 0x1b:
        DAT_a802d290.b08 = 0x15;
        break;
    case 0x1c:
        DAT_a802d290.b08 = 0x17;
        break;
    case 0x1d:
        DAT_a802d290.b08 = 0x1a;
        break;
    case 0x1e:
        DAT_a802d290.b08 = 0x1b;
        break;
    case 0x1f:
        DAT_a802d290.b08 = 0x1c;
        break;
    }
    FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
    FUN_a0145360(1);
    return 0xe0;
}
