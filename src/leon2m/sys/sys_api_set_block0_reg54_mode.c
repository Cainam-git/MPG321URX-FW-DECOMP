/* sys_api_set_block0_reg54_mode  (FUN_a014e0a4)
 *
 * Write mode 2, 1 or 0 to register 0x54 of register block 0.
 * Name basis: descriptive - value 2/1/0 chosen from the argument; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e0a4 @ 0xa014e0a4-0xa014e0d4 (12 words), flags -mcpu=v8 -O2 -g (the section default).
 * Source form: three separate tail calls; v == 2 is tested first, then v == 1.
 */
extern void pq_block0_set_blank_mode(unsigned char);

/*
 * Pass the mode to register 0x54 of picture block 0 (pq_block0_set_blank_mode): 2 for 2, 1 for 1, 0 for any
 * other value.
 *
 *   mode  0, 1 or 2
 *
 * Nothing in the firmware calls it.
 */
void sys_api_set_block0_reg54_mode(unsigned char mode)
{
    if (mode == 2)
        pq_block0_set_blank_mode(2);
    else if (mode == 1)
        pq_block0_set_blank_mode(1);
    else
        pq_block0_set_blank_mode(0);
}
