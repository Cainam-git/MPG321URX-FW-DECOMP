/* reg_test_table_reg_bits  (FUN_CODE_d56d)
 *
 * Test mask bits of the register picked from the 28-entry pointer table.
 *   index: table index
 *   mask: bits
 * Returns: 1 when a bit is set
 * Note: Not called anywhere.
 * Name basis: descriptive - pointer table CODE 0xB13E; reads twice and writes back; no caller
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d56d @ 0xd56d..0xd59b (46 B)
 * The pointed-to byte is volatile: the code reads it twice and writes it (register access through the table).
 */
extern unsigned char volatile * code edid_port_reg_ptr_table[28];

/*
 * Read the register that entry 'index' of edid_port_reg_ptr_table points to, then write the value read back to it.
 * Returns 1 when a second read has at least one bit of 'mask' set, else 0. Nothing in the image calls this
 * routine; reg_set_table_reg_to_7 uses the same table.
 */
bit reg_test_table_reg_bits(unsigned char index, unsigned char mask)
{
    bit hit;
    unsigned char value;
    unsigned char volatile *reg;

    hit = 0;
    reg = edid_port_reg_ptr_table[index];
    value = *reg;
    if (*reg & mask) hit = 1;
    *reg = value;
    return hit;
}
