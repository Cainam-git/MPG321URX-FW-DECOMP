/* leon2s FUN_a0086bd8 @ 0xa0086bd8-0xa0086c48 (28 words), flags -mcpu=v8 -Os -g.
 * Leaf, returns a u8 status: 0 when bit 0 of hardware word 0xcf0189e0 is clear; otherwise 1 / 2 / 3 for
 * bit 7 / bit 1 / bit 4 of hardware word 0xcf013000 (re-read for each test), else 4. The firmware 'and 7' in
 * the retl slot is the u8 return extension narrowed by combine (all values fit in 3 bits).
 * 0xcf013000 is a constant hardware address (low 10 bits 0: ld [%o5]; an extern symbol gives the simm13
 * form). volatile only on the two hardware registers.
 */
#define REG_CF0189E0 (*(volatile unsigned int *)0xcf0189e0)
#define REG_CF013000 (*(volatile unsigned int *)0xcf013000)

unsigned char FUN_a0086bd8(void)
{
    unsigned char r = 4;

    if ((REG_CF0189E0 & 1) == 0)
        r = 0;
    else if (REG_CF013000 & 0x80)
        r = 1;
    else if (REG_CF013000 & 0x02)
        r = 2;
    else if (REG_CF013000 & 0x10)
        r = 3;
    return r;
}
