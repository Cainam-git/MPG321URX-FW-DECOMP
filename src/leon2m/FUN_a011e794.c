/* FUN_a011e794: two-bit fields in registers 0xcf016480..0xcf01648c selected by ch 0x10..0x17: register
 * 0xcf016480 + 4 * ((ch - 0x10) / 2), bits 6-7 for even ch, bits 2-3 for odd ch. sel == 1: both bits are
 * cleared; otherwise the lower bit is set and then the upper bit cleared. Other ch values write nothing.
 * Caller: FUN_a014fbf0. Written as if/else chains on ch (the firmware has a compare chain, no jump table).
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a011e794(unsigned char ch, unsigned char sel)
{
    if (sel == 1) {
        if (ch == 0x10) {
            R(0xcf016480) &= ~0xc0;
        } else if (ch == 0x11) {
            R(0xcf016480) &= ~0xc;
        } else if (ch == 0x12) {
            R(0xcf016484) &= ~0xc0;
        } else if (ch == 0x13) {
            R(0xcf016484) &= ~0xc;
        } else if (ch == 0x14) {
            R(0xcf016488) &= ~0xc0;
        } else if (ch == 0x15) {
            R(0xcf016488) &= ~0xc;
        } else if (ch == 0x16) {
            R(0xcf01648c) &= ~0xc0;
        } else if (ch == 0x17) {
            R(0xcf01648c) &= ~0xc;
        }
    } else {
        if (ch == 0x10) {
            R(0xcf016480) |= 0x40;
            R(0xcf016480) &= ~0x80;
        } else if (ch == 0x11) {
            R(0xcf016480) |= 4;
            R(0xcf016480) &= ~8;
        } else if (ch == 0x12) {
            R(0xcf016484) |= 0x40;
            R(0xcf016484) &= ~0x80;
        } else if (ch == 0x13) {
            R(0xcf016484) |= 4;
            R(0xcf016484) &= ~8;
        } else if (ch == 0x14) {
            R(0xcf016488) |= 0x40;
            R(0xcf016488) &= ~0x80;
        } else if (ch == 0x15) {
            R(0xcf016488) |= 4;
            R(0xcf016488) &= ~8;
        } else if (ch == 0x16) {
            R(0xcf01648c) |= 0x40;
            R(0xcf01648c) &= ~0x80;
        } else if (ch == 0x17) {
            R(0xcf01648c) |= 4;
            R(0xcf01648c) &= ~8;
        }
    }
}
