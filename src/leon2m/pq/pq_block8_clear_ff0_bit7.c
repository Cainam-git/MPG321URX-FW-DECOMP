/* pq_block8_clear_ff0_bit7  (FUN_a0118ad4)
 *
 * Clear bit 7 of register 0xCF012FF0.
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0118ad4 @ 0xa0118ad4-0xa0118af0 (28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: one read-modify-write of the volatile register.
 */
#define BLOCK8_FF0 (*(volatile unsigned int *)0xcf012ff0)   /* bit 7 also cleared by pq_block8_setup_ff0 */
#define FF0_BIT7   0x80u

/*
 * Clear bit 7 of BLOCK8_FF0. Nothing in the firmware refers to this routine (no call and no stored address).
 */
void pq_block8_clear_ff0_bit7(void)
{
    BLOCK8_FF0 &= ~FF0_BIT7;
}
