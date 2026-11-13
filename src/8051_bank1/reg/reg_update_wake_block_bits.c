/* reg_update_wake_block_bits  (FUN_CODE_d645)
 *
 * Set or clear mask bits in one register of the wake detection block.
 *   reg: register
 *   mask: bits
 *   on: 1 set
 * Name basis: descriptive - block written per wake-source type by power_set_wake_block_mode
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d645 @ 0xd645  OPTIMIZE(8,SPEED) LARGE
 * Source form: the base is the array symbol reg_wake_block_window.
 */
extern unsigned char xdata reg_wake_block_window[];

/*
 * Set (on == 1) or clear (any other value) the bits of 'mask' in register 'reg' of the wake detection block.
 * Twin of reg_update_sync_meter_bits, which does the same on the sync measurement block.
 */
void reg_update_wake_block_bits(unsigned char reg, unsigned char mask, unsigned char on)
{
    unsigned char *reg_ptr;
    unsigned char value;

    reg_ptr = reg_wake_block_window;
    reg_ptr += reg;
    value = *reg_ptr;
    if (on == 1) value |= mask; else value &= ~mask;
    *reg_ptr = value;
}
