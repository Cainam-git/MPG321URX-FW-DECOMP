/* leon2m FUN_a01439d8 @ 0xa01439d8..0xa0143bc4 (123 words)  start-up step 5 of FUN_a015266c, last call before WAIT 3,
 * called with (0, 1): turns an output group on or off by selector.
 * What it does (code facts): first FUN_a01356fc(3, 0); then by sel:
 *  - 0x00 / 0x01 / 0x02: FUN_a0151aa4(0xFF / 0x0F / 0xF0, on).
 *  - 0x10..0x1F: input port p = 1 / 2 / 3 for sel 0x11 / 0x12 / 0x13, else 0; k = FUN_a00fd820(bits 15..12 of word +0
 *    of the 120-byte port record DAT_a802df30[p]); k == 0xB1 -> k = FUN_a012fc20(); then k 0x31 / 0x41 / 0x51 / 0x61 /
 *    0x71 / 0x81 -> FUN_a0151aa4(1 / 2 / 4 / 8 / 0x10 / 0x20, on); any other k: nothing.
 *  - 0x20..0x27: FUN_a0151aa4(1 << (sel - 0x20), on); 0x40..0x45: FUN_a0151aa4(1 << (sel - 0x40), on) (two jump tables,
 *    CPU 0x000E3054 / 0x000E303C, sharing the same case blocks).
 *  - any other sel: nothing. FW.021 start-up call (0, 1): FUN_a01356fc(3, 0); FUN_a0151aa4(0xFF, 1) (all 8 bits on).
 * The function itself has no loop and no register access. Runs before WAIT 3 and FUN_a0106d64.
 * Exact form: if/else-if chain on sel & 0xF0 (fw compares 0x10, 0x20, 0x40 in order); sel 0 and 1 call FUN_a0151aa4
 * through a local function pointer: the fw makes those two plain calls ('call; nop; b ret', shared by crossjumping)
 * while every other call is a sibcall, and gcc 3.4 on SPARC refuses a sibcall only when the call has no known
 * function decl (sparc_function_ok_for_sibcall); cse then turns the pointer into the direct call. Default first in the
 * port switch and case 0x27 before 0x26 fix the block order.
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };
extern struct Chan DAT_a802df30[];
extern void FUN_a01356fc(unsigned char, unsigned char);
extern unsigned char FUN_a00fd820(unsigned char);
extern unsigned char FUN_a012fc20(void);
extern void FUN_a0151aa4(unsigned char, unsigned char);

void FUN_a01439d8(unsigned char sel, unsigned char on)
{
    unsigned char p, k;
    void (*fn)(unsigned char, unsigned char);

    FUN_a01356fc(3, 0);
    if ((sel & 0xf0) == 0x10) {
        switch (sel) {
        default: p = 0; break;
        case 0x11: p = 1; break;
        case 0x12: p = 2; break;
        case 0x13: p = 3; break;
        }
        k = FUN_a00fd820((DAT_a802df30[p].w0 >> 12) & 0xf);
        if (k == 0xb1)
            k = FUN_a012fc20();
        switch (k) {
        case 0x31: FUN_a0151aa4(1, on); break;
        case 0x41: FUN_a0151aa4(2, on); break;
        case 0x51: FUN_a0151aa4(4, on); break;
        case 0x61: FUN_a0151aa4(8, on); break;
        case 0x71: FUN_a0151aa4(0x10, on); break;
        case 0x81: FUN_a0151aa4(0x20, on); break;
        }
    } else if ((sel & 0xf0) == 0x20) {
        switch (sel) {
        case 0x20: FUN_a0151aa4(1, on); break;
        case 0x21: FUN_a0151aa4(2, on); break;
        case 0x22: FUN_a0151aa4(4, on); break;
        case 0x23: FUN_a0151aa4(8, on); break;
        case 0x24: FUN_a0151aa4(0x10, on); break;
        case 0x25: FUN_a0151aa4(0x20, on); break;
        case 0x27: FUN_a0151aa4(0x80, on); break;
        case 0x26: FUN_a0151aa4(0x40, on); break;
        }
    } else if ((sel & 0xf0) == 0x40) {
        switch (sel) {
        case 0x40: FUN_a0151aa4(1, on); break;
        case 0x41: FUN_a0151aa4(2, on); break;
        case 0x42: FUN_a0151aa4(4, on); break;
        case 0x43: FUN_a0151aa4(8, on); break;
        case 0x44: FUN_a0151aa4(0x10, on); break;
        case 0x45: FUN_a0151aa4(0x20, on); break;
        }
    } else if (sel == 0) {
        fn = FUN_a0151aa4;
        fn(0xff, on);
    } else if (sel == 1) {
        fn = FUN_a0151aa4;
        fn(0x0f, on);
    } else if (sel == 2) {
        FUN_a0151aa4(0xf0, on);
    }
}
