/* reg_window_write_reg114_bit0  (FUN_CODE_e004)
 *
 * Clear bit 0 of the 32-bit register 0x114 when the flag bit is set, else set it.
 * Name basis: descriptive - reads 0x114, clears bit 0 when bit variable 0 is set and sets it otherwise, writes
 *   the register back
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. Local value in XDATA (0x08EA). The bit test is JNB 20h.0, then ANL #0FEh or
 * ORL #01h on the low byte; the stray MOV A,R4 before the second ?C?LSTXDATA is Keil's own. The write is a tail
 * jump (LJMP).
 */
extern bit usb_reg114_bit0_clear_flag;        /* set: clear bit 0 of register 0x114; clear: set it */
unsigned long reg_window_read32(unsigned int reg);
void reg_window_write32(unsigned int reg, unsigned long v);

#define REG_114       0x0114
#define REG114_BIT0   1UL

/* reg_window_write_reg114_bit0: clear bit 0 of the selected USB controller's register 0x114 when bit
 * usb_reg114_bit0_clear_flag is set, else set it; the other bits are written back as read. The bit of the register itself does not
 * decide anything.
 * Caller: usb_device_mode_init, once with usb_reg114_bit0_clear_flag = 0 (bit 0 set) at its start and once with usb_reg114_bit0_clear_flag = 1
 * (bit 0 cleared) later. */
void reg_window_write_reg114_bit0(void)
{
    unsigned long value;
    value = reg_window_read32(REG_114);
    if (usb_reg114_bit0_clear_flag) value &= ~REG114_BIT0; else value |= 1;
    reg_window_write32(REG_114, value);
}
