/* hdcp_tx_hdmi_state_check_v  (FUN_a00c90b4)
 *
 * State handler: read the repeater's 20-byte check value and compare it with the engine's.
 * Name basis: derived - one state handler of the per-output copy-protection state machine; called from
 *   hdcp_tx_hdmi_run_state; 20 bytes compared in reversed groups; prints
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c90b4 @ 0xa00c90b4, flags -mcpu=v8 -Os -g (the section default).
 * Source form: word 0 of the record is one 32-bit group of bit-fields (a:3, bit 28, 4-bit count, bit 23, a
 * 5-bit field, the 2-bit field st in bits 16..17, then a 16-bit field for bytes +2 and +3); it is kept as
 * one group. The two messages are passed as raw ROM
 * addresses cast to const char *. The comparison loops use unsigned char counters with <= bounds.
 */
/* Protection record of an output (24 bytes); only the bits this routine uses are named. Word 0 is one group of
   bit-fields, bit 31 first. */
struct hdcp_tx_record {
    unsigned int bits_29_31 : 3;
    unsigned int f28 : 1;               /* bit 28 */
    unsigned int cnt : 4;               /* bits 24..27 */
    unsigned int b23 : 1;
    unsigned int bits_18_22 : 5;
    unsigned int st : 2;                /* bits 16..17: 0, 1 or 3 */
    unsigned int state_and_count : 16;  /* bytes +2 (state) and +3 (device_count) */
    unsigned char bytes_4_23[20];
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_tx_repeater_v[];
extern int dbg_printf(const char *, ...);
extern unsigned int hdmi_tx_ddc_start(unsigned char, unsigned char, unsigned char, unsigned char);
extern unsigned int hdmi_tx_ddc_read(unsigned char, unsigned char *, unsigned char);

#define DDC_DEVICE      0x74    /* device address passed to hdmi_tx_ddc_start */
#define DDC_OFFSET      0x20    /* offset of the 20 bytes in that device */
#define VALUE_LENGTH    0x14    /* bytes compared */
#define GROUP_LENGTH    4       /* the comparison runs over 5 groups of 4 bytes, each group reversed */

/*
 * State handler of an HDMI output's handshake: read the 20-byte value from the receiver on the output's DDC
 * channel and compare it with hdcp_tx_repeater_v.
 *
 *   port  the HDMI output, 0 or 1
 *
 * Called by hdcp_tx_hdmi_run_state. The 2-bit field st of the output's record (bits 16..17 of word 0) is set
 * to 1 first and ends as:
 *   0  bit 28 of the record is clear (a message is printed and nothing is read), or the value read differs
 *      from hdcp_tx_repeater_v (a second message is printed);
 *   3  hdmi_tx_ddc_start or hdmi_tx_ddc_read reports an error;
 *   1  the value matches.
 * The value read is compared with hdcp_tx_repeater_v group by group: byte j of group i of the stored value
 * against byte 3 - j of group i of the value read, so each group of four is compared in reversed byte order.
 */
void hdcp_tx_hdmi_state_check_v(unsigned char port)
{
    unsigned char value[VALUE_LENGTH];
    unsigned char i, j;

    hdcp_tx_records[port].st = 1;
    if (hdcp_tx_records[port].f28 == 0) {
        hdcp_tx_records[port].st = 0;
        dbg_printf((const char *)0x9f1c2098);
        return;
    }
    if ((unsigned char)hdmi_tx_ddc_start(port, DDC_DEVICE, DDC_OFFSET, VALUE_LENGTH) != 0) {
        hdcp_tx_records[port].st = 3;
        return;
    }
    if ((unsigned char)hdmi_tx_ddc_read(port, value, VALUE_LENGTH) != 0) {
        hdcp_tx_records[port].st = 3;
        return;
    }
    for (i = 0; i <= 4; i++) {
        for (j = 0; j <= GROUP_LENGTH - 1; j++) {
            if (hdcp_tx_repeater_v[i * GROUP_LENGTH + j] != value[i * GROUP_LENGTH + GROUP_LENGTH - 1 - j]) {
                dbg_printf((const char *)0x9f1c20a8);
                hdcp_tx_records[port].st = 0;
                return;
            }
        }
    }
}
