/* leon2s FUN_a009c4a4 @ 0xa009c4a4-0xa009c558 (180 bytes, 45 words)
 * BYTE-EXACT with -mcpu=v8 -Os -g (gcc 3.4.4): jf 100.00 match=True, rawcmp_l2s 0/45.
 * Code facts: u8 (u8 port). FUN_a009c434 takes ONE arg (the draft passed 2). Its u8 result picks bits 16..19
 * (non-zero) or 24..27 (zero) of the MMIO word at ARR_a807db00[port].regs, the +4 register pointer of the
 * 0x34-byte port record. AID (MMIO class): that pointer target is volatile, because the fw does a
 * full-word ld and then extracts the field. The nibble is mapped by a switch (jump table, 15 entries):
 * 0, 8, 12, 10, 14 and 3 map to themselves, anything else to 2. The cases set a u8 result that is returned
 * at the end (fw 'mov 2' in the bgu delay slot plus the final 'and 0xf' = u8 nonzero-bits narrowing).
 * Note: the fw jump table is the 60 bytes 0xa009c468-0xa009c4a4, between the end of
 * FUN_a009c434 (0xa009c468) and this function. Ours references a .rodata table by relocation.
 */
struct Port34 { unsigned int w0; volatile unsigned int *regs; unsigned char rest[0x34 - 8]; };
extern struct Port34 ARR_a807db00[];
extern unsigned int FUN_a009c434(unsigned char);

unsigned char FUN_a009c4a4(unsigned char port)
{
    unsigned int v;
    unsigned char r;

    if ((unsigned char)FUN_a009c434(port) != 0)
        v = *ARR_a807db00[port].regs >> 16;
    else
        v = *ARR_a807db00[port].regs >> 24;
    switch (v & 0xf) {
    case 0: r = 0; break;
    case 8: r = 8; break;
    case 12: r = 12; break;
    case 10: r = 10; break;
    case 14: r = 14; break;
    case 3: r = 3; break;
    default: r = 2; break;
    }
    return r;
}
