/* reg_write_field_at  (FUN_a00df588)
 *
 * Write a value into the bit field between two bit positions of the word at an address.
 * Name basis: derived - positions in either order; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df588 @ 0xa00df588, flags -mcpu=v8 -O3 -g.
 * Source form: the mask is written (1 << high) - (1 << low) + (1 << high); after the mask the variable 'high'
 * is reused for the shift count ('high = low; value <<= high;'). A separate shift variable or 'value <<= low'
 * gives another register choice in the bit_a < bit_b branch. The write is a tail call.
 */
extern unsigned int reg_read32_copy(unsigned int address);
extern void reg_write32_copy(unsigned int address, unsigned int value);

/*
 * Write 'value' into the bit field of the word at 'address' that lies between bit positions 'bit_a' and
 * 'bit_b' (both included, given in either order). The other bits keep their value; bits of 'value' that do
 * not fit the field are dropped. Nothing calls it. Counterpart of reg_read_field_at.
 */
void reg_write_field_at(unsigned int address, unsigned char bit_a, unsigned char bit_b, unsigned int value)
{
    unsigned char low = bit_b, high = bit_a;
    unsigned int mask;

    if (bit_a < bit_b) {
        low = bit_a;
        high = bit_b;
    }
    mask = (1 << high) - (1 << low) + (1 << high);      /* bits low..high */
    high = low;
    value <<= high;
    reg_write32_copy(address, (reg_read32_copy(address) & ~mask) | (value & mask));
}
