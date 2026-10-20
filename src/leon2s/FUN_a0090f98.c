/* FUN_a0090f98 (leon2s, 7 words, leaf). Flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 Code facts: returns the u16 at byte offset 0x92 of the 0xb0-byte record (u8 param) of the table at 0xa807d3e4 (sethi/or base, smul 0xb0, add, lduh +0x92).
 Fixes vs draft: real base ARR_a807d3e4 (FUN_a0091078 form, u16 index param*0x58 + 0x49); the draft used a mid-record symbol and a stride
 of 0xb0 u16 elements (smul 0x160). Aids: none.
 */
extern unsigned short ARR_a807d3e4[];

unsigned short FUN_a0090f98(unsigned int param_1)
{
    return ARR_a807d3e4[(param_1 & 0xff) * 0x58 + 0x49];
}
