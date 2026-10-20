/* leon2s FUN_a009f5c8 @ 0xa009f5c8-0xa009f654 (35 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/35 mismatches.
 * Code facts: leaf, u8 port. If the FRL rate field (bits 24..27 of word +0x90 of the register block that
 * the 0x34-byte port record DAT_a807db00[port] points to at +0x18) differs from byte +2 of the 0xb0-byte
 * state record DAT_a807d680[port], and ARR_a80790d8[port] != 0, and the state word ARR_a807d648[port] is
 * > 4 and != 7: ARR_a80790d0[port] = 1. void.
 * Fixes vs the autoc draft: real record bases DAT_a807db00 (draft: a negative constant) and
 * DAT_a807d680 + 2 (draft: mid-record ARR_a807d682). volatile only on the register block reached through
 * the +0x18 pointer (MMIO, the port-record convention): a plain pointer narrows the full-word 'ld' +
 * srl/and to a byte load (77.14). Aids: none.
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
