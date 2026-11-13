/* panel_layer4_get_word0_bit0  (FUN_a0110084)
 *
 * Return bit 0 of word 0 of the fourth layer's first register set.
 * Returns: 0 or 1
 * Note: Nothing calls it.
 * Name basis: descriptive - register 0xD0032000 bit 0
 *
 * Matching notes
 * --------------
 * FUN_a0110084 (leon2m 0xa0110084-0xa01100a4, 32 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: result = 0; if (REG & 1) result = 1; return result & 1; (the and 1 sits in the retl delay slot).
 */
#define WORD0 (*(volatile unsigned int *)0xd0032000)

/* Return bit 0 of word 0 of the first register set (0xD0032000): 0 or 1. No routine in the image calls it. */
unsigned char panel_layer4_get_word0_bit0(void)
{
    unsigned char result = 0;

    if (WORD0 & 1)
        result = 1;
    return result & 1;
}
