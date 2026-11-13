/* hdmi_get_saved_hback_porch  (FUN_a0091094)
 *
 * Return the saved horizontal back porch of an HDMI receiver.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: derived - htotal - hactive - hsync width - front porch from the record; caller
 *   input_read_port_timing
 *
 * Matching notes
 * --------------
 * FUN_a0091094 (leon2s, 0xa0091094-0xa00910d0, 60 bytes, 15 words, leaf), flags -mcpu=v8 -Os -g.
 * Source form: the record is reached through an unsigned short pointer (index times 0xb0 added to the table
 * address); the four fields are subtracted one after the other in the order htotal, hactive, hsync_width,
 * hfront_porch and the sum is cast to unsigned short on return.
 */

extern unsigned short hdmi_rx_records[];  /* table of 0xB0-byte receiver records, see hdmi_save_link_timing */

#define HDMI_RX_RECORD_SIZE   0xb0
/* Halfword indexes of the saved timing fields in a record (byte offset / 2). */
#define REC_HTOTAL       0x4b           /* +0x96 */
#define REC_HACTIVE      0x4c           /* +0x98 */
#define REC_HFRONT_PORCH 0x4d           /* +0x9A */
#define REC_HSYNC_WIDTH  0x4e           /* +0x9C */

/* The horizontal back porch of receiver "port" is not measured: it is the saved line length minus the saved
   active width, the saved sync width and the saved front porch. Called by input_read_port_timing. */
unsigned int hdmi_get_saved_hback_porch(unsigned char port) {
    unsigned short *rec = (unsigned short *)((unsigned int)port * HDMI_RX_RECORD_SIZE + (unsigned int)hdmi_rx_records);
    unsigned int result = rec[REC_HTOTAL];
    result -= rec[REC_HACTIVE];
    result -= rec[REC_HSYNC_WIDTH];
    result -= rec[REC_HFRONT_PORCH];
    return (unsigned short)result;
}
