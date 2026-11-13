/* reg_read_field_at  (FUN_a00df540)
 *
 * Return the bit field between two bit positions of the word at an address.
 * Returns: field
 * Name basis: derived - positions in either order; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df540 @ 0xa00df540, flags -mcpu=v8 -O3 -g.
 * Source form: the mask is written (1 << high) - (1 << low) + (1 << high); after the mask the variable 'high'
 * is reused for the shift count ('high = low;'). Shifting by 'low' directly gives another register choice
 * for 'low'. The same form is used in reg_write_field_at.
 */
extern unsigned int reg_read32_copy(unsigned int address);

/*
 * Return the bit field of the word at 'address' that lies between bit positions 'bit_a' and 'bit_b'
 * (both included, given in either order), shifted down to bit 0. Nothing calls it.
 * Counterpart of reg_write_field_at.
 */
unsigned int reg_read_field_at(unsigned int address, unsigned char bit_a, unsigned char bit_b)
{
    unsigned char low = bit_b, high = bit_a;
    unsigned int mask;

    if (bit_a < bit_b) {
        low = bit_a;
        high = bit_b;
    }
    mask = (1 << high) - (1 << low) + (1 << high);      /* bits low..high */
    high = low;
    return (reg_read32_copy(address) & mask) >> high;
}
