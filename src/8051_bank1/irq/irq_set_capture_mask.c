/* irq_set_capture_mask  (FUN_CODE_c03f)
 *
 * Set which sources of the capture interrupt are enabled.
 *   sources: source bits 0..3
 * Name basis: descriptive - bits 0..3 into 0xA1E7 and the low nibble of 0xF021/0xF022; irq_ext1_peripherals
 *   tests 0xF021 & 0xA1E7 before irq_record_ir_pulse; commands 0x09 / 0x0A
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c03f, OPTIMIZE(8,SPEED) LARGE. One C function: the else branch of bit 3 runs straight into the
 * 0xF021 / 0xF022 update. The mask is copied to a register at entry.
 */
extern unsigned char xdata irq_capture_enable_mask, reg_capture_irq_flags, reg_capture_irq_enable;

/*
 * irq_set_capture_mask - copy bits 0..3 of sources into irq_capture_enable_mask, then write that mask into the low
 * nibble of 0xF021 and 0xF022 (the upper nibbles keep their values).
 *   sources: bits 0..3, one per source
 * Only caller: the command switch ipc_run_command (command 0x09 with its byte 1, command 0x0A with 0).
 */
void irq_set_capture_mask(unsigned char sources)
{
    if (sources & 0x01) irq_capture_enable_mask |= 0x01; else irq_capture_enable_mask &= ~0x01;
    if (sources & 0x02) irq_capture_enable_mask |= 0x02; else irq_capture_enable_mask &= ~0x02;
    if (sources & 0x04) irq_capture_enable_mask |= 0x04; else irq_capture_enable_mask &= ~0x04;
    if (sources & 0x08) irq_capture_enable_mask |= 0x08; else irq_capture_enable_mask &= ~0x08;
    reg_capture_irq_flags = (reg_capture_irq_flags & 0xf0) | irq_capture_enable_mask;
    reg_capture_irq_enable = (reg_capture_irq_enable & 0xf0) | irq_capture_enable_mask;
}
