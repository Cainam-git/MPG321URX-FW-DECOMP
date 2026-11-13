/* usb_cc_load_default_params  (FUN_CODE_d13a)
 *
 * Write five fixed parameter sets into the Type-C CC controller record.
 * Name basis: descriptive - called by the 'USB CC Initialize' routine; each set goes to bytes 0x38..0x3A of
 *   the CC register block
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d13a @ 0xd13a  OPTIMIZE(8,SPEED)
 */
extern void usb_cc_set_config_bytes(unsigned char, unsigned char, unsigned int);

/*
 * Call usb_cc_set_config_bytes five times with the fixed values (byte 0x38
 * bits, byte 0x39 bits, word): (0x00, 0x80, 0x01C2), (0x10, 0x00, 0x0640),
 * (0x20, 0x80, 0x0002), (0x30, 0x80, 0x001C), (0x50, 0x80, 0x0136).
 */
void usb_cc_load_default_params(void) 
{
    usb_cc_set_config_bytes(0x00, 0x80, 0x01c2);
    usb_cc_set_config_bytes(0x10, 0x00, 0x0640);
    usb_cc_set_config_bytes(0x20, 0x80, 0x0002);
    usb_cc_set_config_bytes(0x30, 0x80, 0x001c);
    usb_cc_set_config_bytes(0x50, 0x80, 0x0136);
}
