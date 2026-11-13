/* reg_update_sync_meter_bits  (FUN_CODE_d61c)
 *
 * Set or clear mask bits in one register of the sync measurement block.
 *   reg: register
 *   mask: bits
 *   on: 1 set, else clear
 * Name basis: descriptive - read-modify-write on the block of reg_read_sync_meter_byte
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d61c @ 0xd61c  Options: OPTIMIZE(8,SPEED) LARGE.
 * 'on' is the LARGE parameter slot XDATA 0xA475. The write-back is a tail LJMP to ?C?CSTPTR.
 */
#define SYNC_METER_WINDOW 0x9ab0  /* XDATA base of the sync measurement register block */

/*
 * Set (on == 1) or clear (any other value) the bits of 'mask' in register 'reg' of the sync measurement block.
 * Twin of reg_update_wake_block_bits, which does the same on the wake detection block.
 */
void reg_update_sync_meter_bits(unsigned char reg, unsigned char mask, unsigned char on)
{
    unsigned char *reg_ptr;
    unsigned char value;

    reg_ptr = (unsigned char xdata *)SYNC_METER_WINDOW;
    reg_ptr += reg;
    value = *reg_ptr;
    if (on == 1) value |= mask; else value &= ~mask;
    *reg_ptr = value;
}
