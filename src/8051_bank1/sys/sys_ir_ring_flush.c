/* sys_ir_ring_flush  (FUN_CODE_deb9)
 *
 * Discard everything in the IR ring.
 * Name basis: derived - sets the write index to the read index; only call in sys_main at the end of a wake-up,
 *   right after the run state becomes 'running'
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_deb9 @ 0xdeb9  OPTIMIZE(7,SPEED)
 */
extern unsigned char xdata sys_ir_ring_read_index;
extern unsigned char xdata sys_ir_ring_write_index;

/*
 * Empty the infrared pulse ring by setting the write index to the read index; sys_ir_ring_is_empty then reports
 * it empty. Only caller: sys_main, at the end of a wake-up, just after the run state becomes RUN_STATE_RUNNING.
 */
void sys_ir_ring_flush(void) {
    sys_ir_ring_write_index = sys_ir_ring_read_index;
}
