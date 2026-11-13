/* reg_set_table_reg_to_7  (FUN_CODE_d9ff)
 *
 * Write 7 into the register picked from the 28-entry pointer table.
 *   index: table index
 * Note: Not called anywhere.
 * Name basis: descriptive - pointer table CODE 0xB13E (as reg_test_table_reg_bits); no caller
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d9ff @ 0xd9ff..0xda1d (30 B)
 * The write is a tail jump to ?C?CSTPTR. The bytes after the routine (0xDA1D..0xDA3A) are a string.
 */
extern unsigned char volatile * code edid_port_reg_ptr_table[28];

/*
 * Write 7 to the register that entry 'index' of edid_port_reg_ptr_table points to. Nothing in the image calls
 * this routine; reg_test_table_reg_bits uses the same table.
 */
void reg_set_table_reg_to_7(unsigned char index)
{
    *edid_port_reg_ptr_table[index] = 7;
}
