/* irq_record_ir_pulse  (FUN_CODE_bc3d)
 *
 * Measure one infrared pulse and append its length to the IR ring.
 * Name basis: derived - capture count 0xF027/0xF028, (0xFFFF - count) / 75 into ring 0xA566 read by
 *   sys_ring_read_byte; 'Reload IR' report type 5
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_bc3d, OPTIMIZE(7,SPEED), register bank 3 ('using 3').
 * irq_ir_pulse_length and the byte at IDATA 0x5B are volatile (written in interrupt context): the firmware reads
 * the length back right after storing it, and stores the result into 0x5B twice, which is the chained assignment
 * 'x = x = value' on a volatile byte.
 */
extern unsigned char xdata reg_ir_capture_low, reg_ir_capture_high, sys_ir_ring_write_index;
extern unsigned char xdata sys_ir_ring_buffer[];
extern unsigned int volatile idata irq_ir_pulse_length;
extern unsigned char volatile idata irq_ext1_loop_counters;
unsigned char sys_ir_ring_is_full(void);

/*
 * irq_record_ir_pulse - take the 16-bit capture count from 0xF028 (high) / 0xF027 (low) and keep it in
 * irq_ir_pulse_length. The pulse value is (0xFFFF - count) / 75 (0xFF when the count is 0); it is left in IDATA 0x5B
 * (irq_ext1_loop_counters). Both capture registers are then set to 0xFF. Unless sys_ir_ring_is_full says the ring is
 * full, the value is appended to the 128-byte IR ring (sys_ir_ring_buffer, write index sys_ir_ring_write_index,
 * wraps at 0x80); sys_ring_read_byte reads it from the other end.
 * Only caller: the interrupt handler irq_ext1_peripherals.
 */
void irq_record_ir_pulse(void) using 3
{
    unsigned int count;

    irq_ir_pulse_length = ((unsigned int)reg_ir_capture_high << 8) + reg_ir_capture_low;
    count = irq_ir_pulse_length;
    if (count > 0)
        irq_ext1_loop_counters = irq_ext1_loop_counters = (0xffff - count) / 75;
    else
        irq_ext1_loop_counters = 0xff;
    reg_ir_capture_low = 0xff;
    reg_ir_capture_high = 0xff;
    if (sys_ir_ring_is_full() == 0) {
        sys_ir_ring_buffer[sys_ir_ring_write_index] = irq_ext1_loop_counters;
        sys_ir_ring_write_index++;
        if (sys_ir_ring_write_index == 0x80) sys_ir_ring_write_index = 0;
    }
}
