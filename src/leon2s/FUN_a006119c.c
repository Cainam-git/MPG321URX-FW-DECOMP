/* FUN_a006119c (leon2s 0xa006119c-0xa0061200, 100 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Same sequence as FUN_a0061138 with bit 14 (0x4000): clears it in 0x9f100090, sets it in 0x9f120028, writes 0x4000
 * to 0x9f120034 and 0x9f10009c, clears it in 0x9f120028, sets it in 0x9f100090. Address word at 0xa00b6074.
 */
#define R90 (*(volatile unsigned int *)0x9f100090)
#define R9C (*(volatile unsigned int *)0x9f10009c)
#define S28 (*(volatile unsigned int *)0x9f120028)
#define S34 (*(volatile unsigned int *)0x9f120034)

void FUN_a006119c(void)
{
    R90 &= ~0x4000;
    S28 |= 0x4000;
    S34 = 0x4000;
    R9C = 0x4000;
    S28 &= ~0x4000;
    R90 |= 0x4000;
}
