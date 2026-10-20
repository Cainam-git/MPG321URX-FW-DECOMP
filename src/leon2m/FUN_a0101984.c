/* leon2m FUN_a0101984 @ 0xa0101984  MATCH (-mcpu=v8 -O2 -g)
 * 
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
