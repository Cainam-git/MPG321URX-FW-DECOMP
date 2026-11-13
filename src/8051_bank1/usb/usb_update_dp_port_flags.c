/* usb_update_dp_port_flags  (FUN_CODE_ae1d)
 *
 * Set the DP receiver flags from the USB-C pin levels.
 * Name basis: descriptive - USB-C info 0xA69C (FillTypeCInfo) names two pins (gpio_read_port_bit); bits 4..5
 *   of 0xDCCF / 0xDCDF
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_ae1d, OPTIMIZE(8,SPEED) LARGE.
 * Bit-fields are allocated from bit 0 (Keil C51): b0 = bit 0, f2 = bits 2..3, f4 = bits 4..5, f6 = bits 6..7.
 * Source form: pins is declared with the initialiser 0, which is never read (pins is assigned before its first use).
 * With it, the firmware's copy of the first read of usb_c_port_info[0] is reproduced; without it the copy is absent.
 */
struct cbits { unsigned char b0 : 1; unsigned char b1 : 1; unsigned char f2 : 2; unsigned char f4 : 2; unsigned char f6 : 2; };
union cb { unsigned char v; struct cbits f; };
extern union cb xdata usb_c_port_info[6];
extern unsigned char xdata reg_dp_aux_request_ctrl_port1, reg_dp_aux_request_ctrl_port0;
extern bit gpio_read_port_bit(unsigned char n, unsigned char mask);

/*
 * usb_update_dp_port_flags - set or clear bits 4..5 (0x30) of one of two registers, from the levels of two pin pairs.
 * The record usb_c_port_info (6 bytes, XDATA 0xA69C) says what to do:
 *   [0] bits 2..3  non-zero: the register is 0xDCCF, zero: 0xDCDF
 *   [2],[3]        port number and pin mask of the first pin (gpio_read_port_bit arguments)
 *   [4],[5]        port number and pin mask of the second pin
 *   [1] bits 2..3, 4..5, 6..7  pin patterns (0..3 = second pin * 2 + first pin); bit 0 is the polarity
 * If the pins show the pattern in bits 2..3 or 4..5, bits 4..5 of the register are set (polarity bit 1) or cleared
 * (polarity bit 0); if they show the pattern in bits 6..7, the opposite is done. Otherwise the register keeps its value.
 * Called from sys_main.
 */
void usb_update_dp_port_flags(void)
{
    unsigned char pin_a_level, flags, pins = 0;

    if (usb_c_port_info[0].f.f2) flags = reg_dp_aux_request_ctrl_port1; else flags = reg_dp_aux_request_ctrl_port0;
    pin_a_level = gpio_read_port_bit(usb_c_port_info[2].v, usb_c_port_info[3].v);
    pins = ((unsigned char)gpio_read_port_bit(usb_c_port_info[4].v, usb_c_port_info[5].v) << 1) | pin_a_level;
    if (usb_c_port_info[1].f.f2 == pins || usb_c_port_info[1].f.f4 == pins) {
        if (usb_c_port_info[1].f.b0) flags |= 0x30; else flags &= 0xcf;
    } else if (usb_c_port_info[1].f.f6 == pins) {
        if (usb_c_port_info[1].f.b0) flags &= 0xcf; else flags |= 0x30;
    }
    if (usb_c_port_info[0].f.f2) reg_dp_aux_request_ctrl_port1 = flags; else reg_dp_aux_request_ctrl_port0 = flags;
}
