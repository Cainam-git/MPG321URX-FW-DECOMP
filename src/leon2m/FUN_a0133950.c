/* leon2m FUN_a0133950 @ 0xa0133950  UART ring-buffer read (hand; BYTE-EXACT at -mcpu=v8 -O3 -g,
 * jf 100 % + rawcmp 0/48 words).
 *
 * Copies up to len bytes from the receive ring of UART port (0..4) into buf and counts them in *pn. Each ring is 35
 * bytes at 0xA802DD90 + 35 * port: write index, read index, 32 data bytes, overflow byte; the read index wraps at 32.
 * Stops early when the ring is empty (read index == write index). port > 4 prints the error string at 0x001A53E0 and
 * returns without touching *pn.
 * Update tool input (code fact): the command framer FUN_a00baef8 reads the update tool's bytes through
 * FUN_a01487cc -> this function before dispatching them to the command switch FUN_a00bfcc4.
 */
struct UartRing { unsigned char wr, rd, data[32], ovf; };
extern struct UartRing DAT_a802dd90[];
extern int FUN_a00df170();
extern char s_001a53e0[];

void FUN_a0133950(unsigned char port, unsigned short len, unsigned char *buf, unsigned short *pn)
{
    unsigned short i;
    struct UartRing *r;

    if (port > 4) {
        FUN_a00df170(s_001a53e0);
        return;
    }
    *pn = 0;
    for (i = 0; i < len; i++) {
        if (DAT_a802dd90[port].wr == DAT_a802dd90[port].rd) return;
        buf[i] = DAT_a802dd90[port].data[DAT_a802dd90[port].rd];
        (*pn)++;
        DAT_a802dd90[port].rd = (DAT_a802dd90[port].rd + 1) & 0x1f;
    }
}
