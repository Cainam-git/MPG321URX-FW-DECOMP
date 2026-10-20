/* leon2m FUN_a00d4108 @ 0xa00d4108-0xa00d4164 (23 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/23 mismatches.
 * Code facts: id = FUN_a0144414() (u8); level (u8 param) clamped to 100; sibcall
 * FUN_a0145808(id, 0x14, (u16)(level * 63 / 100), 1) (signed division by 100 via the 0x51eb851f
 * magic multiply). Fixes vs the autoc draft (52.17): real prototypes (u8 return of a0144414,
 * a0145808(u8, u32, u16, int) from the accepted users), void. Aids: none.
 */
extern unsigned char FUN_a0144414(void);
extern void FUN_a0145808(unsigned char, unsigned int, unsigned short, int);

void FUN_a00d4108(unsigned char level)
{
    unsigned char id;

    id = FUN_a0144414();
    if (level > 100)
        level = 100;
    FUN_a0145808(id, 0x14, level * 63 / 100, 1);
}
