/* FUN_a008a040 (leon2s 0xa008a040-0xa008a110, 208 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns a 2-bit status field selected by sel (jump table): bits 6..7 or 2..3 of one of the registers
 * 0xcf0111c0..0xcf0111d4 (sel 1/0x11 and 2: 0x11c0; 4/5: 0x11c4; 6/7: 0x11c8; 8/10: 0x11cc; 12/14: 0x11d0;
 * 3/0x13: bits 6..7 of 0x11d4). Any other sel returns 0xff.
 * Source form: every case stores into one unsigned int result that is returned as unsigned char.
 */
#define R11C0 (*(volatile unsigned int *)0xcf0111c0)
#define R11C4 (*(volatile unsigned int *)0xcf0111c4)
#define R11C8 (*(volatile unsigned int *)0xcf0111c8)
#define R11CC (*(volatile unsigned int *)0xcf0111cc)
#define R11D0 (*(volatile unsigned int *)0xcf0111d0)
#define R11D4 (*(volatile unsigned int *)0xcf0111d4)

unsigned char FUN_a008a040(unsigned char sel)
{
    unsigned int r;

    switch (sel) {
    case 1:
    case 0x11:
        r = (R11C0 >> 6) & 3;
        break;
    case 2:
        r = (R11C0 >> 2) & 3;
        break;
    case 3:
    case 0x13:
        r = (R11D4 >> 6) & 3;
        break;
    case 4:
        r = (R11C4 >> 6) & 3;
        break;
    case 5:
        r = (R11C4 >> 2) & 3;
        break;
    case 6:
        r = (R11C8 >> 6) & 3;
        break;
    case 7:
        r = (R11C8 >> 2) & 3;
        break;
    case 8:
        r = (R11CC >> 6) & 3;
        break;
    case 10:
        r = (R11CC >> 2) & 3;
        break;
    case 12:
        r = (R11D0 >> 6) & 3;
        break;
    case 14:
        r = (R11D0 >> 2) & 3;
        break;
    default:
        r = -1;
        break;
    }
    return r;
}
