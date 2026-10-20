/* leon2s FUN_a0091078 @ 0xa0091078-0xa0091094 (7 words), flags -mcpu=v8 -Os -g.
 * Returns the u16 at byte offset 0xa4 of 176-byte record n (n = low byte of the argument, smul 0xb0) in the
 * table at 0xa807d3e4 (sethi/or base = 0xa807d3e4, lduh +0xa4), i.e. u16 index n*0x58 + 0x52. Sibling
 * getters FUN_a009105c (+0x51) etc. use the same table. The base is the table start, not the mid-record
 * address 0xa807d488.
 */
extern unsigned short ARR_a807d3e4[];

unsigned short FUN_a0091078(unsigned char param_1)
{
    return ARR_a807d3e4[param_1 * 0x58 + 0x52];
}
