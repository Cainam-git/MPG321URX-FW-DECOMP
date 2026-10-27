/* FUN_a0101904 (leon2m 0xa0101904-0xa010192c, 40 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears bit 6 (0x40) of the word register 0xcf016118, then writes 0xff to the word register 0xcf016114. Nothing in
 * the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a01018e8 and
 * FUN_a010192c.
 */
#define REG118 (*(volatile unsigned int *)0xcf016118)
#define REG114 (*(volatile unsigned int *)0xcf016114)

void FUN_a0101904(void)
{
    REG118 &= ~0x40u;
    REG114 = 0xff;
}
