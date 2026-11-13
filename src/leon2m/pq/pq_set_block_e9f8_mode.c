/* pq_set_block_e9f8_mode  (FUN_a010740c)
 *
 * Write the mode values of the block at 0xCF00E9F8 and its twin for a selector.
 * Name basis: descriptive - values 0x10, 0x90, 0 or 0xF4; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010740c @ 0xa010740c-0xa0107554, flags -mcpu=v8 -O3 -g.
 * Source form: in selector 2, (field_a & 3) << 4 is computed into its own variable before the two stores of 0.
 */

/*
 * Two sets of three registers 0xC0 apart; every write goes to both. startup_reset_output_blocks starts them
 * at 0x33, 0x90 and 0.
 */
#define UNIT_E9E8      (*(volatile unsigned int *)0xcf00e9e8)
#define UNIT_E9F8      (*(volatile unsigned int *)0xcf00e9f8)
#define UNIT_E9FC      (*(volatile unsigned int *)0xcf00e9fc)
#define UNIT_E9E8_TWIN (*(volatile unsigned int *)0xcf00eaa8)   /* gets a copy of UNIT_E9E8 */
#define UNIT_E9F8_TWIN (*(volatile unsigned int *)0xcf00eab8)
#define UNIT_E9FC_TWIN (*(volatile unsigned int *)0xcf00eabc)

#define E9E8_BIT0 1u
#define E9E8_BIT3 8u

/*
 * Write a mode value chosen by selector to UNIT_E9F8 and its twin, update bits 0 and 3 of UNIT_E9E8, and copy
 * UNIT_E9E8 to its twin.
 *
 *   selector  0: 0x10, bit 3 cleared, bit 0 set
 *             1: 0x90, bit 3 cleared, bit 0 set
 *             2: 0, UNIT_E9FC and its twin get ((field_a & 3) << 4) | (field_b & 7), bit 3 set
 *             3: 0xF4, field_a & 0xF goes to bits 4..7 of UNIT_E9E8, bit 3 cleared, bit 0 set
 *             other: only bits 0 and 3 cleared
 *   field_a   used by selectors 2 and 3
 *   field_b   used by selector 2
 *
 * Nothing in the firmware calls this routine.
 */
void pq_set_block_e9f8_mode(unsigned int selector, unsigned int field_a, unsigned int field_b)
{
    unsigned int e9fc_value;
    unsigned int field_a_bits;

    switch (selector) {
    case 0:
        UNIT_E9F8 = 0x10;
        UNIT_E9F8_TWIN = 0x10;
        UNIT_E9E8 &= ~E9E8_BIT3;
        UNIT_E9E8 |= E9E8_BIT0;
        UNIT_E9E8_TWIN = UNIT_E9E8;
        break;
    case 1:
        UNIT_E9F8 = 0x90;
        UNIT_E9F8_TWIN = 0x90;
        UNIT_E9E8 &= ~E9E8_BIT3;
        UNIT_E9E8 |= E9E8_BIT0;
        UNIT_E9E8_TWIN = UNIT_E9E8;
        break;
    case 2:
        field_a_bits = (field_a & 3) << 4;
        UNIT_E9F8 = 0;
        UNIT_E9F8_TWIN = 0;
        e9fc_value = field_a_bits | (field_b & 7);
        UNIT_E9FC = e9fc_value;
        UNIT_E9FC_TWIN = e9fc_value;
        UNIT_E9E8 |= E9E8_BIT3;
        UNIT_E9E8_TWIN = UNIT_E9E8;
        break;
    case 3:
        UNIT_E9F8 = 0xf4;
        UNIT_E9F8_TWIN = 0xf4;
        /* Bits 4..7 of UNIT_E9E8 are replaced by field_a. */
        UNIT_E9E8 &= 0xf;
        UNIT_E9E8 |= (field_a & 0xf) << 4;
        UNIT_E9E8 &= ~E9E8_BIT3;
        UNIT_E9E8 |= E9E8_BIT0;
        UNIT_E9E8_TWIN = UNIT_E9E8;
        break;
    default:
        UNIT_E9E8 &= ~(E9E8_BIT0 | E9E8_BIT3);
        UNIT_E9E8_TWIN = UNIT_E9E8;
        break;
    }
}
