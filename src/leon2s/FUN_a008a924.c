/* FUN_a008a924 (leon2s, 0xa008a924-0xa008a95c, 14 words, leaf). Flags -mcpu=v8 -Os -g.
 Code facts: void (u32 v): writes lo = v & 0xff and hi = (u16)v >> 8 to the hardware registers 0xcf011060/64 and again to 0xcf011068/6c.
 Fix vs draft: BEHAVIOUR the draft's u8 param made hi always 0; the fw takes bits 8..15 (sll 16, srl 24 = (unsigned short)v >> 8) of a full
 word argument. Aids: none.
 */
typedef unsigned int uint;

#define _DAT_cf011060 (*(volatile unsigned int *)0xcf011060)
#define _DAT_cf011064 (*(volatile unsigned int *)0xcf011064)
#define _DAT_cf011068 (*(volatile unsigned int *)0xcf011068)
#define _DAT_cf01106c (*(volatile unsigned int *)0xcf01106c)

void FUN_a008a924(unsigned int v)
{
    unsigned int lo = v & 0xff;
    unsigned int hi = (unsigned short)v >> 8;

    _DAT_cf011060 = lo;
    _DAT_cf011064 = hi;
    _DAT_cf011068 = lo;
    _DAT_cf01106c = hi;
}
