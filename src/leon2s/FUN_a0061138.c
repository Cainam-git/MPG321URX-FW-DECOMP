/* FUN_a0061138 (leon2s 0xa0061138-0xa006119c, 100 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Clears bit 13 (0x2000) of word 0x9f100090, sets it in 0x9f120028, writes 0x2000 to 0x9f120034 and 0x9f10009c,
 * then clears it in 0x9f120028 and sets it again in 0x9f100090. Its address is the word at 0xa00b6070 (a table of
 * routine addresses).
 */
#define R90 (*(volatile unsigned int *)0x9f100090)
#define R9C (*(volatile unsigned int *)0x9f10009c)
#define S28 (*(volatile unsigned int *)0x9f120028)
#define S34 (*(volatile unsigned int *)0x9f120034)

void FUN_a0061138(void)
{
    R90 &= ~0x2000;
    S28 |= 0x2000;
    S34 = 0x2000;
    R9C = 0x2000;
    S28 &= ~0x2000;
    R90 |= 0x2000;
}
