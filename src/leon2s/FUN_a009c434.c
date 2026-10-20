/* leon2s FUN_a009c434 @ 0xa009c434-0xa009c468 (13 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s 0 mismatches / 13 words.
 * Code facts: returns FUN_a00a7408(1, word +4 of the 52-byte port record DAT_a807db00[port]) != 0.
 * Fix vs the autoc draft (76.92): real base DAT_a807db00 as a 52-byte struct (the draft named mid-record
 * ARR_a807db04), u8 param. Aids: none.
 */
struct port_rec { unsigned int w0; unsigned int w4; unsigned char rest[0x2c]; };
extern struct port_rec DAT_a807db00[];
extern unsigned int FUN_a00a7408(unsigned int, unsigned int);

int FUN_a009c434(unsigned char port)
{
    return FUN_a00a7408(1, DAT_a807db00[port].w4) != 0;
}
