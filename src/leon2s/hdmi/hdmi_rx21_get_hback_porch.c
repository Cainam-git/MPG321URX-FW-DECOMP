/* hdmi_rx21_get_hback_porch  (FUN_a00a2868)
 *
 * Return the horizontal back porch of an HDMI 2.1 input.
 *   receiver: HDMI 2.1 receiver 0/1
 * Returns: pixels
 * Name basis: derived - htotal - hactive - front porch - sync width; same slot as hdmi_get_saved_hback_porch
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2868 @ 0xa00a2868, flags -mcpu=v8 -Os -g.
 * The four reads and subtractions keep this order; the record is addressed as a halfword pointer computed from
 * the byte offset receiver * 400, and the result is truncated to 16 bits only at the return.
 */

/* Halfword indexes of the fields in one HDMI 2.1 input record (400 bytes per receiver, table at 0xA807D7E0). */
#define RX21_HTOTAL       13    /* +0x1A */
#define RX21_HACTIVE      15    /* +0x1E */
#define RX21_HSYNC_WIDTH  18    /* +0x24 */
#define RX21_HFRONT_PORCH 20    /* +0x28 */

extern unsigned short hdmi_rx21_input_records[];

/*
 * Horizontal back porch in pixels: the line is not stored with it, so it is the total line length minus the
 * active width, the front porch and the sync width. receiver is 0 or 1.
 */
unsigned int hdmi_rx21_get_hback_porch(unsigned char receiver) {
    unsigned short *rec = (unsigned short *)((unsigned int)receiver * 400 + (unsigned int)hdmi_rx21_input_records);
    unsigned int result = rec[RX21_HTOTAL];
    result -= rec[RX21_HACTIVE];
    result -= rec[RX21_HFRONT_PORCH];
    result -= rec[RX21_HSYNC_WIDTH];
    return (unsigned short)result;
}
