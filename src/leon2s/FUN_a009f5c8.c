/* leon2s FUN_a009f5c8 @ 0xa009f5c8 (-mcpu=v8 -Os -g)
 * Stores 1 in byte p1 of the array 0xA80790D0 when all of these hold: bits 24-27 of word +0x90 of the block whose
 * address is word +0x18 of record p1 of the 0x34-byte records at 0xA807DB00 differ from byte +2 of record p1 of
 * the 0xB0-byte records at 0xA807D680; byte p1 of the array 0xA80790D8 is nonzero; word p1 of the array 0xA807D648
 * is above 4 and not 7.
 * Source form: the block behind the +0x18 pointer is read through a volatile pointer; a plain pointer narrows
 * the word load and shift to a byte load.
 */
struct port_regs {
    unsigned char _00[0x18];
    volatile unsigned int *cfg;
    unsigned char _1c[0x34 - 0x1c];
};
extern struct port_regs DAT_a807db00[];
extern unsigned char DAT_a807d680[];
extern unsigned char ARR_a80790d8[];
extern unsigned char ARR_a80790d0[];
extern unsigned int ARR_a807d648[];

void FUN_a009f5c8(unsigned char port)
{
    if (((DAT_a807db00[port].cfg[0x24] >> 24) & 0xf) != DAT_a807d680[port * 0xb0 + 2]
        && ARR_a80790d8[port] != 0
        && ARR_a807d648[port] > 4
        && ARR_a807d648[port] != 7)
        ARR_a80790d0[port] = 1;
}
