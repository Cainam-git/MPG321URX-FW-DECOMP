/* FillTypeCInfo  (FUN_CODE_74af)
 *
 * Store the ten-byte USB-C port description sent by the main processor.
 *   info: ten bytes
 * Name basis: proven - prints 'FillTypeCInfo : %02X, ...' (original name); message type 11 (main side
 *   ipc_8051_send_usb_c_info)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_74af @ 0x74AF..0x760C (349 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Source form: Keil bit-fields (allocated from bit 0 up); each field is stored from a shifted message byte, so the
 * compiler masks and merges every field on its own. The adc_channel value '(info[0] >> 4) & 0xF0' gives the
 * firmware's 'SWAP A / ANL A,#00H' (the field always gets 0).
 */
/* The USB-C port record at XDATA 0xA69C..0xA6A5, as its readers use it. */
struct usb_c_info_record {
    unsigned char bits_0_1:2;      /* 0xA69C bits 1..0: no reader in this program */
    unsigned char dp_port:2;       /*        bits 3..2: usb_update_dp_port_flags: 0 = 0xDCDF, else 0xDCCF */
    unsigned char adc_channel:4;   /*        bits 7..4: usb_cc_read_line_levels passes them to gpio_read_adc */
    unsigned char invert:1;        /* 0xA69D bit 0: usb_update_dp_port_flags swaps set and clear of its bits */
    unsigned char bit_1:1;         /*        bit 1: no reader in this program */
    unsigned char level_match_1:2; /*        bits 3..2: pin levels that clear bits 4..5 of that byte (set them when invert = 1) */
    unsigned char level_match_2:2; /*        bits 5..4: likewise */
    unsigned char level_match_3:2; /*        bits 7..6: pin levels that set bits 4..5 (clear them when invert = 1) */
    unsigned char bytes[7];        /* 0xA69E..0xA6A4: [0]/[1] and [2]/[3] = GPIO port and bit mask of the two
                                      pins usb_update_dp_port_flags reads; [4..6] no reader in this program */
    unsigned char port_select:2;   /* 0xA6A5 bits 1..0: 0 or 1, chooses the CC block and ADC channels
                                      (usb_cc_select_port_block, usb_cc_read_line_levels) */
};
extern struct usb_c_info_record xdata usb_c_port_info;
extern void lib_printf517(void *fmt, ...) large;

/*
 * FillTypeCInfo - store the ten-byte USB-C port description the main processor sends (message type
 * IPC_8051_TX_MSG_USB_C_INFO 11, from ipc_8051_send_usb_c_info) in usb_c_port_info.
 *   info  the ten message bytes
 * Prints bytes 0..3 and 9, then unpacks bytes 0 and 1 into bit groups and copies bytes 2..9.
 * Only caller: ipc_run_message, for message type 11.
 */
void FillTypeCInfo(unsigned char *info)
{
    lib_printf517((void code *)0xb4e0, (unsigned int)info[0], (unsigned int)info[1], (unsigned int)info[2],
                  (unsigned int)info[3], (unsigned int)info[9]);   /* "FillTypeCInfo : %02X, ..." */
    usb_c_port_info.bits_0_1 = info[0];
    usb_c_port_info.dp_port = info[0] >> 2;
    usb_c_port_info.adc_channel = (info[0] >> 4) & 0xf0;
    usb_c_port_info.invert = info[1];
    usb_c_port_info.bit_1 = info[1] >> 1;
    usb_c_port_info.level_match_1 = info[1] >> 2;
    usb_c_port_info.level_match_2 = info[1] >> 4;
    usb_c_port_info.level_match_3 = info[1] >> 6;
    usb_c_port_info.bytes[0] = info[2];
    usb_c_port_info.bytes[1] = info[3];
    usb_c_port_info.bytes[2] = info[4];
    usb_c_port_info.bytes[3] = info[5];
    usb_c_port_info.bytes[4] = info[6];
    usb_c_port_info.bytes[5] = info[7];
    usb_c_port_info.bytes[6] = info[8];
    usb_c_port_info.port_select = info[9];
}
