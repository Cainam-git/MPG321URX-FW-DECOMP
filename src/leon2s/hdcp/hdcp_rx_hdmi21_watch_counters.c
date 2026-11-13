/* hdcp_rx_hdmi21_watch_counters  (FUN_a00c2f58)
 *
 * Check two 16-bit counters of an HDMI 2.1 input at a limited rate.
 * Name basis: descriptive - steps the counter at 0xA8078C88; prints
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c2f58 @ 0xa00c2f58-0xa00c30e4, flags -mcpu=v8 -Os -g.
 * Source form as hdcp_rx_hdmi_watch_counters (second record pointer cur before the bit test). The print format is
 * the program-image address 0x9f1b7580, passed as a pointer constant.
 */
/* The first 16 bytes of a record of hdcp_rx_record_hdmi21, seen as words. */
struct hdcp_rx_record { unsigned int word0; unsigned int word_0x4; unsigned int time_stamp; unsigned int word_0xc; };
extern struct hdcp_rx_record hdcp_rx_record_hdmi21[];
extern unsigned char hdcp_rx_hdmi21_watch_bytes[];
extern unsigned int timer_get_ticks(void);
extern void hdmi_rx21_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern int dbg_printf(const char *, ...);
extern unsigned int hdmi_rx21_reg_read8(unsigned char, unsigned short);

#define WATCH_INTERVAL_TICKS 100                /* least time between two checks of one input */
#define WATCH_HOLD_BITS      0x1f0000           /* word 0, bits 16..20 of the record */

/*
 * The HDMI 2.1 twin of hdcp_rx_hdmi_watch_counters: check two 16-bit counters (registers 0xC9/0xCA as a and
 * 0xCD/0xCE as b) of HDMI 2.1 receiver `port` with the same rules, counting in hdcp_rx_hdmi21_watch_bytes and
 * using the records of hdcp_rx_record_hdmi21. The differences: register 0xBB is set by setting its bit 0
 * (not by writing 1), and when the count is about to be reset the routine first prints a message with port and b.
 *
 * Called from the HDMI 2.1 protection task (hdcp_rx_hdmi21_task); a return of 1 makes it print "Re-auth".
 */
unsigned char hdcp_rx_hdmi21_watch_counters(unsigned char port)
{
    struct hdcp_rx_record *rec = &hdcp_rx_record_hdmi21[port];
    struct hdcp_rx_record *cur;
    unsigned char bad = 0;
    unsigned short a, b;

    if (timer_get_ticks() - rec->time_stamp > WATCH_INTERVAL_TICKS) {
        hdmi_rx21_reg_update_bits(port, 0xbb, 1, 1);
        a = ((hdmi_rx21_reg_read8(port, 0xca) & 0xff) << 8) + (hdmi_rx21_reg_read8(port, 0xc9) & 0xff);
        b = ((hdmi_rx21_reg_read8(port, 0xce) & 0xff) << 8) + (hdmi_rx21_reg_read8(port, 0xcd) & 0xff);
        cur = &hdcp_rx_record_hdmi21[port];
        if (a < 0x10 && b > 5 && (cur->word0 & WATCH_HOLD_BITS) == 0) {
            if (hdcp_rx_hdmi21_watch_bytes[port] > 4) {
                dbg_printf((const char *)0x9f1b7580, port, b);
                hdcp_rx_hdmi21_watch_bytes[port] = 0;
                bad = 1;
            }
            hdcp_rx_hdmi21_watch_bytes[port]++;
            if (b > 0x400 || (b > 0x300 && a < 8))
                hdcp_rx_hdmi21_watch_bytes[port]++;
        } else {
            hdcp_rx_hdmi21_watch_bytes[port] = 0;
        }
        rec->word0 &= ~WATCH_HOLD_BITS;
        rec->time_stamp = timer_get_ticks();
    }
    return bad & 1;
}
