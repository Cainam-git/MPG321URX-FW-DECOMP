/* reg_window_set_bits32  (FUN_CODE_dfbe)
 *
 * Set bits of a 32-bit register reached through the register window.
 * Name basis: derived - read, OR, write through the window routines
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. LARGE parameters reg (0x0986) and mask (0x098A); the new value goes into
 * reg_window_write32's parameter home 0x0992 with ?C?LSTXDATA, and that call is a tail jump (LJMP).
 * Operand order matters: 'value | mask'; 'mask | value' loads value first and is 72 B.
 */
unsigned long reg_window_read32(unsigned int reg);
void reg_window_write32(unsigned int reg, unsigned long v);

/* reg_window_set_bits32: set the bits of mask in a 32-bit register of the selected USB controller (read, OR, write
 * back through the register window).
 * Callers: usb_host_run_transfer, usb_read_port_status_record (which writes register 0x14 back with its own bits),
 * usb_device_answer_setup and usb_host_init_controller. */
void reg_window_set_bits32(unsigned int reg, unsigned long mask)
{
    unsigned long value;
    value = reg_window_read32(reg);
    reg_window_write32(reg, value | mask);
}
