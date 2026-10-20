/* leon2s FUN_a00b17e8 @ 0xa00b17e8-0xa00b18ac (49 words), flags -mcpu=v8 -Os -g.
 * Code facts: register init sequence: 0x9f100090 = 0; 0x9f120028, 0x9f10009c, 0x9f120034 = 0xffff;
 * then read-modify-write of 0x9f120038: clear bit 0 (and -2), set 0x10000, clear bit 2 (and -5),
 * set 0x40000, clear bit 3 (and -9), set 0x80000, clear bit 4 (and -17), set 0x100000; then
 * 0x9f120028 &= ~2 and 0x9f100090 |= 2. Leaf, no calls.
 * Fix vs the autoc draft: BEHAVIOUR bug, the first mask is ~1 (fw 'and %g1,-2'), the draft had ~2.
 * Aids: none.
 */
typedef unsigned int uint;

#define REG_9f100090 (*(volatile uint *)0x9f100090)
#define REG_9f10009c (*(volatile uint *)0x9f10009c)
#define REG_9f120028 (*(volatile uint *)0x9f120028)
#define REG_9f120034 (*(volatile uint *)0x9f120034)
#define REG_9f120038 (*(volatile uint *)0x9f120038)

void FUN_a00b17e8(void)
{
    REG_9f100090 = 0;
    REG_9f120028 = 0xffff;
    REG_9f10009c = 0xffff;
    REG_9f120034 = 0xffff;
    REG_9f120038 = REG_9f120038 & ~1;
    REG_9f120038 = REG_9f120038 | 0x10000;
    REG_9f120038 = REG_9f120038 & ~4;
    REG_9f120038 = REG_9f120038 | 0x40000;
    REG_9f120038 = REG_9f120038 & ~8;
    REG_9f120038 = REG_9f120038 | 0x80000;
    REG_9f120038 = REG_9f120038 & ~0x10;
    REG_9f120038 = REG_9f120038 | 0x100000;
    REG_9f120028 = REG_9f120028 & ~2;
    REG_9f100090 = REG_9f100090 | 2;
}
