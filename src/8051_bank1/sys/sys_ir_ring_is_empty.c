/* sys_ir_ring_is_empty  (FUN_CODE_dce3)
 *
 * Report whether the 128-byte IR ring holds no data.
 * Returns: 1 when empty
 * Name basis: derived - compares the write and read indexes of the ring read by sys_ir_ring_read_byte
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dce3 @ 0xdce3
 * Byte-exact with OPTIMIZE(7,SPEED) ONLY (level 8 gives 18 B).
 */
extern unsigned char xdata sys_ir_ring_write_index, sys_ir_ring_read_index;

/* Return 1 when the write and read positions of the 128-byte infrared
 * pulse ring are equal, else 0. */
unsigned char sys_ir_ring_is_empty(void)
{
    return sys_ir_ring_write_index == sys_ir_ring_read_index;
}
