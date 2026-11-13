/* i2c_sw_select_pins  (FUN_CODE_c32e)
 *
 * Choose the clock and data pins of the software I2C bus.
 * Name basis: derived - stores the pin register pointers and masks 0xA6FE/0xA701/0xA704.. used by the i2c_sw_*
 *   routines; caller i2c_sw_match_device_id
 *
 * Matching notes
 * --------------
 * FUN_CODE_c32e, 8051_bank1. OPTIMIZE(8,SPEED) (also with REGFILE(R.ORC) added).
 * The areas 0xA6FE..0xA70B and 0xA71E..0xA728 are declared byte by byte or pointer by pointer, as the code only shows
 * these scalar copies (the byte pair 0xA728 -> 0xA704 and 0xA727 -> 0xA705 is in swapped order).
 */
extern unsigned char * xdata i2c_sw_scl_ctrl_ptr;
extern unsigned char * xdata i2c_sw_scl_port_ptr;
extern unsigned char * xdata i2c_sw_sda_ctrl_ptr;
extern unsigned char * xdata i2c_sw_sda_port_ptr;
extern unsigned char xdata i2c_sw_sda_mask;
extern unsigned char xdata i2c_sw_scl_mask;
extern unsigned char * xdata DAT_EXTMEM_a721;
extern unsigned char * xdata DAT_EXTMEM_a71e;
extern unsigned char * xdata DAT_EXTMEM_a724;
extern unsigned char xdata DAT_EXTMEM_a727;
extern unsigned char xdata DAT_EXTMEM_a728;
/*
 * i2c_sw_select_pins - set up the pins of the software I2C bus. The clock control pointer is the argument; the other
 * five values are copied from the staging variables at XDATA 0xA721 (clock port pointer), 0xA71E (data control
 * pointer), 0xA724 (data port pointer), 0xA728 (data pin mask) and 0xA727 (clock pin mask) into the i2c_sw_*
 * variables the bit-banging routines use.
 *   scl_ctrl: clock control pointer
 * Caller: code at 0x7FC7 (i2c_sw_match_device_id).
 */
void i2c_sw_select_pins(unsigned char *scl_ctrl)
{
    i2c_sw_scl_ctrl_ptr = scl_ctrl;
    i2c_sw_scl_port_ptr = DAT_EXTMEM_a721;
    i2c_sw_sda_ctrl_ptr = DAT_EXTMEM_a71e;
    i2c_sw_sda_port_ptr = DAT_EXTMEM_a724;
    i2c_sw_sda_mask = DAT_EXTMEM_a728;
    i2c_sw_scl_mask = DAT_EXTMEM_a727;
}
