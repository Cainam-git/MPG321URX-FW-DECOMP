/* leon2m FUN_a0101984 @ 0xa0101984 (-mcpu=v8 -O2 -g)
 * Register 0xCF0160F4: keeps only bits 0..4 and 7 (& 0x9f), writes that back, reads it again and writes it with
 * (p & 0xff) << 5 ORed in.
 */
// FUN_a0101984 at 0xa0101984
#define _DAT_cf0160f4 (*(volatile unsigned int *)0xcf0160f4)

void FUN_a0101984(unsigned int param_1)
{
    unsigned int val;
    
    val = _DAT_cf0160f4 & 0x9f;
    _DAT_cf0160f4 = val;
    
    val = _DAT_cf0160f4;
    val |= (param_1 & 0xff) << 5;
    _DAT_cf0160f4 = val;
}
