/* hdmi_tx_select_link_source  (FUN_a0094798)
 *
 * Select which input feeds an HDMI TX port.
 *   port: HDMI TX port 0/1
 * Name basis: proven - prints 'HDMITX_LINK_Source_Selection'; code into a nibble of 0xCF011634
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0094798 @ 0xa0094798-0xa009498c (500 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the cases 0x71, 0x81, 0xe1 and 0xf1 are listed with the default result 0 (they keep the firmware's
 *    compare tree, rooted at 0x61); the 0x91 case follows the port + 2 group;
 *  - the source code byte is read through a byte pointer to the record, after the three bit-field reads.
 */
/* Word 0 of the HDMI TX channel record (28 bytes per TX port, hdmi_tx_output_records); the source code is its byte +1. */
struct hdmi_tx_channel_record {
    unsigned int ctrl_bit31 : 1, ctrl_bit30 : 1, : 26,
                 dsc_enable : 1,        /* bit 3 */
                 : 1,
                 bit1 : 1,
                 : 1;
    unsigned int words[6];
};
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern int dbg_printf(const char *, ...);
#define R(a) (*(volatile unsigned int *)(a))

#define HDMITX_LINK_SOURCE_REG  0xcf011634  /* bits 0..3: TX port 0, bits 4..7: TX port 1 */

/* Source codes (channel record byte +1). */
enum {
    INPUT_CODE_HDMI20_0 = 0x31,     /* HDMI 2.0 receiver 0 */
    INPUT_CODE_HDMI20_1 = 0x41,     /* HDMI 2.0 receiver 1 */
    INPUT_CODE_HDMI21_0 = 0x51,     /* HDMI 2.1 receiver 0 */
    INPUT_CODE_HDMI21_1 = 0x61,     /* HDMI 2.1 receiver 1 */
    INPUT_CODE_DP_0     = 0x71,     /* DisplayPort receiver 0 */
    INPUT_CODE_DP_1     = 0x81,     /* DisplayPort receiver 1 */
    SOURCE_CODE_E1      = 0xe1
};

/* Link source values written to the register. */
enum {
    LINK_SOURCE_NONE      = 0,
    LINK_SOURCE_HDMI20_0  = 4,      /* 4..7: the four HDMI receivers in input code order */
    LINK_SOURCE_HDMI20_1  = 5,
    LINK_SOURCE_HDMI21_0  = 6,
    LINK_SOURCE_HDMI21_1  = 7,
    LINK_SOURCE_CODE_91   = 0xa,
    LINK_SOURCE_CODE_C1   = 0xb,
    LINK_SOURCE_DSC       = 0xc,
    LINK_SOURCE_BIT1      = 0xe
};

/*
 * Set the 4-bit link source of an HDMI TX port (TX_STEP_SELECT_SOURCE of hdmi_tx_run_step) from the source
 * code in its channel record, and print the code ('HDMITX_LINK_Source_Selection : 0x..').
 *
 *   port   HDMI TX port; 0 writes the low nibble of HDMITX_LINK_SOURCE_REG, any other value the high nibble
 *
 * The value, in the order it is decided:
 *   source code 0x11..0x13 or 0x21          port + 2
 *   source code 0x91 / 0xC1                 0xA / 0xB
 *   one of the four HDMI receivers          4..7, only when ctrl_bit30 is set (else 0)
 *   any other code (DisplayPort, 0xE1 ...)  0
 *   then: 0xE when bit 1 of word 0 is set and nothing was chosen; 0xC whenever dsc_enable is set.
 */
void hdmi_tx_select_link_source(unsigned int port)
{
    unsigned char tx = port;
    unsigned char *record_bytes = (unsigned char *)&hdmi_tx_output_records[tx];
    unsigned char ctrl_bit30 = hdmi_tx_output_records[tx].ctrl_bit30;
    unsigned char dsc_enable = hdmi_tx_output_records[tx].dsc_enable;
    unsigned char bit1 = hdmi_tx_output_records[tx].bit1;
    unsigned char source_code = record_bytes[1];
    unsigned char link_source = LINK_SOURCE_NONE;

    dbg_printf("\x1b[0m\t\t - HDMITX_LINK_Source_Selection : 0x%x\r\n", source_code);
    switch (source_code) {
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x21:
        link_source = port + 2;
        break;
    case 0x91:
        link_source = LINK_SOURCE_CODE_91;
        break;
    case INPUT_CODE_HDMI20_0:
        if (ctrl_bit30)
            link_source = LINK_SOURCE_HDMI20_0;
        break;
    case INPUT_CODE_HDMI20_1:
        if (ctrl_bit30)
            link_source = LINK_SOURCE_HDMI20_1;
        break;
    case INPUT_CODE_HDMI21_0:
        if (ctrl_bit30)
            link_source = LINK_SOURCE_HDMI21_0;
        break;
    case INPUT_CODE_HDMI21_1:
        if (ctrl_bit30)
            link_source = LINK_SOURCE_HDMI21_1;
        break;
    case INPUT_CODE_DP_0:
    case INPUT_CODE_DP_1:
        link_source = LINK_SOURCE_NONE;
        break;
    case 0xc1:
        link_source = LINK_SOURCE_CODE_C1;
        break;
    case SOURCE_CODE_E1:
        link_source = LINK_SOURCE_NONE;
        break;
    case 0xf1:
        link_source = LINK_SOURCE_NONE;
        break;
    }
    if (bit1 && link_source == LINK_SOURCE_NONE)
        link_source = LINK_SOURCE_BIT1;
    /* DSC overrides every other choice. */
    if (dsc_enable)
        link_source = LINK_SOURCE_DSC;
    if (tx)
        R(HDMITX_LINK_SOURCE_REG) = (R(HDMITX_LINK_SOURCE_REG) & 0xf) | (link_source << 4);
    else
        R(HDMITX_LINK_SOURCE_REG) = (R(HDMITX_LINK_SOURCE_REG) & 0xf0) | link_source;
}
