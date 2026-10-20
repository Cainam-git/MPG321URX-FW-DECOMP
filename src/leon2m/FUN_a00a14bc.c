/* leon2m FUN_a00a14bc @ 0xa00a14bc-0xa00a15d0 (69 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Fills five values a..e (all 0 at first) from the word _DAT_a802afec: 0xc0: a = DAT_a802d478, c = 4; 0xc2:
 * a = DAT_a802d47c, c = 6; 0xf7: b = DAT_a802d479, d = 1, e = 2; 0xc1: a = record byte 0x1ea, c = 5, then the
 * 0xf8 case: b = record byte 0x1eb, d = 1, e = 3; 0xf9: b = DAT_a802d47d, d = 1, e = 3 (record DAT_a802d290).
 * Any other value returns 0. Then returns the value chosen by sel (1 = a ... 5 = e, others 0) as a byte.
 * Both are switches with jump tables (0x2f400, 0xc0..0xf9; 0x2f3e8, 0..5). Case 0xc1 falls through into case 0xf8;
 * this case order gives the firmware's block layout.
 */
extern unsigned int _DAT_a802afec;   // 0xa802afec
extern unsigned char DAT_a802d290[]; // base 0xa802d290
extern unsigned char DAT_a802d478;   // 0xa802d478
extern unsigned char DAT_a802d479;   // 0xa802d479
extern unsigned char DAT_a802d47c;   // 0xa802d47c
extern unsigned char DAT_a802d47d;   // 0xa802d47d

unsigned char FUN_a00a14bc(unsigned char sel)
{
    unsigned int a = 0, b = 0, c = 0, d = 0, e = 0;

    switch (_DAT_a802afec) {
    case 0xc0:
        a = DAT_a802d478;
        c = 4;
        break;
    case 0xc2:
        a = DAT_a802d47c;
        c = 6;
        break;
    case 0xf7:
        b = DAT_a802d479;
        d = 1;
        e = 2;
        break;
    case 0xc1:
        a = DAT_a802d290[0x1ea];
        c = 5;
    case 0xf8:
        b = DAT_a802d290[0x1eb];
        d = 1;
        e = 3;
        break;
    case 0xf9:
        b = DAT_a802d47d;
        d = 1;
        e = 3;
        break;
    default:
        return 0;
    }
    switch (sel) {
    case 1: return a;
    case 2: return b;
    case 3: return c;
    case 4: return d;
    case 5: return e;
    default: return 0;
    }
}
