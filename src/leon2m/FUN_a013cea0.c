/* leon2m FUN_a013cea0 @ 0xa013cea0-0xa013cecc (11 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf; ch is a u8 param (and 0xff at entry); returns bits 14..15 of word +0x70 of the
 * port record DAT_a802df30[ch] (0x78-byte records, index ch*15*8: sll 4 / sub / sll 3), i.e.
 * (w70 >> 14) & 3 (srl 0xe; and 3). Caller: FUN_a0143d14 (channel-checked wrapper, row-1e events).
 * Fixes vs the autoc draft (36.36): the real base DAT_a802df30 as a 0x78-byte struct array with the
 * word at +0x70 (the draft used a wrong DAT_a802dfa0 base), u8 param and return. Aids: none.
 */
struct Port { unsigned char pad[0x70]; unsigned int w70; unsigned int pad74; };
extern struct Port DAT_a802df30[];

unsigned char FUN_a013cea0(unsigned char ch)
{
    return (DAT_a802df30[ch].w70 >> 14) & 3;
}
