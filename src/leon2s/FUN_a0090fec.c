/* FUN_a0090fec (leon2s, 7 words, leaf). Flags -mcpu=v8 -Os -g.
 * Returns the u16 at byte offset 0x98 of the 0xb0-byte record (u8 param) of the table at 0xa807d3e4
 * (sethi/or base, smul 0xb0, add, lduh +0x98).
 * The base is ARR_a807d3e4 (the FUN_a0091078 form, u16 index param*0x58 + 0x4c).
 */
extern unsigned short ARR_a807d3e4[];

unsigned short FUN_a0090fec(unsigned int param_1)
{
    return ARR_a807d3e4[(param_1 & 0xff) * 0x58 + 0x4c];
}
