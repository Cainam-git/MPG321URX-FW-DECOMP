/* sys_ir_ring_is_full  (FUN_CODE_d862)
 *
 * Report whether the 128-byte IR ring has no free slot.
 * Returns: 1 when full
 * Name basis: derived - write index one behind the read index (wrap at 0x7F); used by the ring writer
 *   irq_record_ir_pulse
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d862 @ 0xd862  OPTIMIZE(7,SPEED)
 * Source form: the read index is copied to a local and tested for 0 first, then the subtraction compare in the
 * else branch; this order gives the firmware's JNZ to the else path.
 */
#define IR_RING_LAST_INDEX 0x7f  /* last entry of the 128-byte ring */

extern unsigned char xdata sys_ir_ring_write_index;
extern unsigned char xdata sys_ir_ring_read_index;

/*
 * Return 1 when the 128-byte infrared pulse ring has no free entry: the write index is one behind the read index
 * (0x7F when the read index is 0). The ring writer is irq_record_ir_pulse.
 */
unsigned char sys_ir_ring_is_full(void)
{
    unsigned char result = 0;
    unsigned char read_index;
    
    read_index = sys_ir_ring_read_index;
    if (read_index == 0) {
        if (sys_ir_ring_write_index == IR_RING_LAST_INDEX) {
            result = 1;
        }
    } else {
        if ((read_index - sys_ir_ring_write_index) == 1) {
            result = 1;
        }
    }
    return result;
}
