/* usb_cc_init_phy  (FUN_CODE_9522)
 *
 * Load the USB-C CC detector's start values and set its line mode.
 * Name basis: proven - prints 'Initial CC PHY!!'; then usb_cc_set_mode_ch0 or _ch1 by 0xA6A6
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_9522 @ 0x9522..0x960f (237 bytes), OPTIMIZE(8,SPEED).
 * Source form: the pointee of usb_cc_block_ptr is volatile (as in usb_cc_set_mode_ch0); the stores go through
 * ?C?CSTOPTR / ?C?CSTPTR and both branches share the final 'LCALL ?C?CSTOPTR' for byte 0x0B.
 */
extern unsigned char volatile * xdata usb_cc_block_ptr;
extern unsigned char xdata reg_chip_id;
extern unsigned char xdata usb_cc_channel_select;
extern unsigned char xdata usb_cc_mode_ch0;
extern unsigned char xdata usb_cc_mode_ch1;
extern unsigned char xdata DAT_EXTMEM_a782;
extern bit usb_cc_ch0_mode_on_flag;
extern bit usb_cc_ch1_mode_on_flag;
extern void lib_printf517(void *fmt, ...) large;
extern void usb_cc_set_mode_ch0(void);
extern void usb_cc_set_mode_ch1(void);

#define CHIP_VARIANT_20      0x20  /* reg_chip_id value with its own set of start values */
#define CC_SELECT_CHANNEL_0  1     /* usb_cc_channel_select: 1 = channel 0, anything else = channel 1 */
#define CC_MODE_2            2     /* stored mode applied by usb_cc_set_mode_ch0 / _ch1 */

/*
 * usb_cc_init_phy - load the start values of the Type-C CC register block and switch one CC channel on.
 * Called from usb_cc_initialize, before the other CC set-up routines.
 * 1. Clears XDATA 0xA782 and prints "Initial CC PHY!!".
 * 2. Writes the start values into the register block that usb_cc_block_ptr points to. Chip variant 0x20 and the
 *    other variants get different values and different bytes: 0x20 writes bytes 1..8, 0x0A and 0x0B; the others
 *    bytes 0..6, 8, 0x0A and 0x0B. Byte 9 is never written here.
 * 3. Switches one channel on in mode 2: channel 0 when usb_cc_channel_select is 1, channel 1 otherwise. The
 *    flag and the stored mode are set first, then usb_cc_set_mode_ch0 / _ch1 writes them to the block.
 */
void usb_cc_init_phy(void)
{
    DAT_EXTMEM_a782 = 0;
    lib_printf517((void code *)0xdd1c /* "Initial CC PHY!!\r\n" */);
    if (reg_chip_id == CHIP_VARIANT_20) {
        usb_cc_block_ptr[1] = 0x01;
        usb_cc_block_ptr[2] = 0x0d;
        usb_cc_block_ptr[3] = 0xf6;
        usb_cc_block_ptr[4] = 0xf6;
        usb_cc_block_ptr[5] = 0xf3;
        usb_cc_block_ptr[6] = 0xb0;
        usb_cc_block_ptr[7] = 0x00;
        usb_cc_block_ptr[8] = 0x88;
        usb_cc_block_ptr[0x0a] = 0x1c;
        usb_cc_block_ptr[0x0b] = 0xd1;
    } else {
        usb_cc_block_ptr[0] = 0x43;
        usb_cc_block_ptr[1] = 0x7d;
        usb_cc_block_ptr[2] = 0x0f;
        usb_cc_block_ptr[3] = 0xc5;
        usb_cc_block_ptr[4] = 0xc5;
        usb_cc_block_ptr[5] = 0x03;
        usb_cc_block_ptr[6] = 0x80;
        usb_cc_block_ptr[8] = 0x66;
        usb_cc_block_ptr[0x0a] = 0x1d;
        usb_cc_block_ptr[0x0b] = 0xa0;
    }
    if (usb_cc_channel_select == CC_SELECT_CHANNEL_0) {
        usb_cc_ch0_mode_on_flag = 1;
        usb_cc_mode_ch0 = CC_MODE_2;
        usb_cc_set_mode_ch0();
    } else {
        usb_cc_ch1_mode_on_flag = 1;
        usb_cc_mode_ch1 = CC_MODE_2;
        usb_cc_set_mode_ch1();
    }
}
