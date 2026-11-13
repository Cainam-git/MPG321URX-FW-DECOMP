/* hdcp_rx_hdmi_watch_counters  (FUN_a00c2de4)
 *
 * Check two 16-bit counters of an HDMI 2.0 input at a limited rate.
 * Name basis: descriptive - steps the counter at 0xA8078C80
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c2de4 @ 0xa00c2de4-0xa00c2f58, flags -mcpu=v8 -Os -g.
 * Source form: a second record pointer (cur) is taken right before the bit test (address operand order).
 */
/* The first 16 bytes of a record of hdcp_rx_record_hdmi20, seen as words. */
struct hdcp_rx_record { unsigned int word0; unsigned int word_0x4; unsigned int time_stamp; unsigned int word_0xc; };
extern struct hdcp_rx_record hdcp_rx_record_hdmi20[];
extern unsigned char hdcp_rx_hdmi_watch_bytes[];
extern unsigned int timer_get_ticks(void);
extern void hdmi_reg_write8(unsigned char, unsigned short, unsigned char);
extern unsigned int hdmi_reg_read8(unsigned char, unsigned short);

#define WATCH_INTERVAL_TICKS 100                /* least time between two checks of one input */
#define WATCH_HOLD_BITS      0x1f0000           /* word 0, bits 16..20 of the record */

/*
 * Check two 16-bit counters (registers 0xC9/0xCA and 0xCD/0xCE) of HDMI 2.0 receiver `port`. Returns 1 when the
 * check has given a bad reading more than 4 times in a row, 0 otherwise (0 without a check when the last check is
 * not more than 100 ticks old).
 *
 * A check writes 1 to register 0xBB, reads the counters as a (0xC9/0xCA) and b (0xCD/0xCE) and then
 *   - with a < 0x10, b > 5 and the hold bits of the record clear: raises hdcp_rx_hdmi_watch_bytes[port] by 1
 *     (by 2 when b > 0x400 or b > 0x300 with a < 8); when it was already above 4 it is reset to 0 and 1 is returned;
 *   - otherwise: clears hdcp_rx_hdmi_watch_bytes[port].
 * The hold bits are cleared and the time stamp of the record is renewed at every check.
 *
 * Called from the HDMI 2.0 protection task (hdcp_rx_hdmi_task); a return of 1 makes it set bit 3 of register 0x303.
 */
unsigned char hdcp_rx_hdmi_watch_counters(unsigned char port)
{
    struct hdcp_rx_record *rec = &hdcp_rx_record_hdmi20[port];
    struct hdcp_rx_record *cur;
    unsigned char bad = 0;
    unsigned short a, b;

    if (timer_get_ticks() - rec->time_stamp > WATCH_INTERVAL_TICKS) {
        hdmi_reg_write8(port, 0xbb, 1);
        a = ((hdmi_reg_read8(port, 0xca) & 0xff) << 8) + (hdmi_reg_read8(port, 0xc9) & 0xff);
        b = ((hdmi_reg_read8(port, 0xce) & 0xff) << 8) + (hdmi_reg_read8(port, 0xcd) & 0xff);
        cur = &hdcp_rx_record_hdmi20[port];
        if (a < 0x10 && b > 5 && (cur->word0 & WATCH_HOLD_BITS) == 0) {
            if (hdcp_rx_hdmi_watch_bytes[port] > 4) {
                hdcp_rx_hdmi_watch_bytes[port] = 0;
                bad = 1;
            }
            hdcp_rx_hdmi_watch_bytes[port]++;
            if (b > 0x400 || (b > 0x300 && a < 8))
                hdcp_rx_hdmi_watch_bytes[port]++;
        } else {
            hdcp_rx_hdmi_watch_bytes[port] = 0;
        }
        rec->word0 &= ~WATCH_HOLD_BITS;
        rec->time_stamp = timer_get_ticks();
    }
    return bad & 1;
}
