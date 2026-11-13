/* usb_phy_tune_ctrl52  (FUN_CODE_da02)
 *
 * Adjust the USB PHY control register 0x5052 from the stored setting.
 * Name basis: derived - prints 'USB_PHY0_CTRL52= %X' before and after; value 0x09CC
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. Source form the bytes depend on: usb_phy_tune_value is named twice in C and
 * read once by Keil (kept in R5); a local copy makes Keil compute the OR the other way round (98 B). Each register is
 * read once per statement, so no volatile. The second printf is a tail jump (LJMP).
 */
extern unsigned char xdata DAT_EXTMEM_5050, DAT_EXTMEM_5051, reg_usb_phy_ctrl52;
extern unsigned char xdata usb_phy_tune_value;
extern void lib_printf517(void *fmt, ...) large;
void timer_delay_units(unsigned char t);

#define PHY_TUNE_LIMIT     0x20     /* usb_phy_tune_value from here up is not written into the register */
#define PHY_CTRL52_DEFAULT 0x10     /* the value written instead */

/* usb_phy_tune_ctrl52: print register 0x5052 ("USB_PHY0_CTRL52= %X\r\n", CODE 0xE48E), set it from
 * usb_phy_tune_value and print it again.
 *
 * usb_phy_tune_value below PHY_TUNE_LIMIT: bit 5 of register 0x5050 is set; register 0x5052 gets bits 5 and 6 set,
 * bit 7 kept and the value in bits 0..4; then register 0x5051 is set to 0x20 for one timer_delay_units(1) and
 * cleared again. Any other value: bit 5 of 0x5050 is cleared and 0x5052 is set to PHY_CTRL52_DEFAULT.
 * usb_phy_tune_value is the mailbox byte 0xF199 of command MBOX_CMD_SET_MEM_BASE (fwupd_run_mailbox_command).
 * Callers: usb_device_mode_init and usb_host_init_controller. */
void usb_phy_tune_ctrl52(void)
{
    lib_printf517((void code *)0xe48e, (unsigned int)reg_usb_phy_ctrl52);
    if (usb_phy_tune_value < PHY_TUNE_LIMIT) {
        DAT_EXTMEM_5050 |= 0x20;
        reg_usb_phy_ctrl52 = ((reg_usb_phy_ctrl52 | 0x60) & 0xe0) | usb_phy_tune_value;
        DAT_EXTMEM_5051 = 0x20;
        timer_delay_units(1);
        DAT_EXTMEM_5051 = 0;
    } else {
        DAT_EXTMEM_5050 &= ~0x20;
        reg_usb_phy_ctrl52 = PHY_CTRL52_DEFAULT;
    }
    lib_printf517((void code *)0xe48e, (unsigned int)reg_usb_phy_ctrl52);
}
