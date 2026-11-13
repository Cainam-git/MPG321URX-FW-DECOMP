/* dp_tx_get_link_state  (FUN_a0086bd8)
 *
 * Return the link state (0..4) from the DP output status registers.
 * Name basis: descriptive - 0 when bit 0 of 0xCF0189E0 is clear, else 1/2/3/4 from bits of 0xCF013000
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0086bd8 (0xa0086bd8-0xa0086c48, 28 words), flags -mcpu=v8 -Os -g. Leaf.
 * Source form: the firmware's 'and 7' in the retl slot is the unsigned char return extension narrowed by
 * combine (all values fit in 3 bits). 0xcf013000 is a constant address (low 10 bits 0: 'ld [%o5]'; an extern
 * symbol gives the simm13 form). volatile only on the two hardware registers, which are re-read for each test.
 */
#define REG_CF0189E0 (*(volatile unsigned int *)0xcf0189e0)
#define REG_CF013000 (*(volatile unsigned int *)0xcf013000)

/*
 * Return a state code from two registers: 0 when bit 0 of 0xcf0189e0 is clear; otherwise 1 when bit 7 of
 * 0xcf013000 is set, else 2 when its bit 1 is set, else 3 when its bit 4 is set, else 4.
 */
unsigned char dp_tx_get_link_state(void)
{
    unsigned char state = 4;
    if ((REG_CF0189E0 & 1) == 0)
        state = 0;
    else if (REG_CF013000 & 0x80)
        state = 1;
    else if (REG_CF013000 & 0x02)
        state = 2;
    else if (REG_CF013000 & 0x10)
        state = 3;
    return state;
}
