/* DRV_HDMI_Config_BCH  (DRV_HDMI_Config_BCH)
 *
 * Enable or disable BCH error correction of an HDMI receiver port.
 *   port: receiver
 *   en: 1 = enable
 * Name basis: proven - original name printed ('[EQ]: Port%c %s'); 'capture SCDC ERROR ==>Enable BCH'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_Config_BCH @ 0xa009c5b4, flags -mcpu=v8 -Os -g.
 * Source form: the clock value is read into an unsigned int before the print; the register pointer is a
 * block-local variable in each arm. The register block is volatile (hardware).
 */
#define HDMI_MSG_EQ_FLOW 2      /* debug message bit: '[EQ]' lines (dbg_hdmi_message_flags) */

#define BCH_MIN_CLOCK_MHZ 100   /* the BCH branch needs a PHY clock above this */

/* Entry of hdmi_phy_records: one per HDMI PHY (24 bytes). */
struct hdmi_phy_record {
    unsigned char bytes_0x0_to_0x7[8];
    unsigned short phy_clock_mhz;       /* +8 */
    unsigned char bytes_0xa_to_0x17[0x18 - 0xa];
};
/* Entry of hdmi_rx21_reg_blocks: register block bases of one receiver (0x34 bytes); block 0 is word 0. */
struct rx21_reg_blocks { volatile unsigned int *block0; unsigned char rest[0x34 - 4]; };
extern struct hdmi_phy_record hdmi_phy_records[];
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
static const char fn_[] = "DRV_HDMI_Config_BCH";

/* Programs three registers of register block 0 of the receiver. With en set and a PHY clock above
 * 100 MHz it writes the first value set (top byte of 0xc0 = 5, low byte of 0xc4 = 0, low 5 bits of
 * 0xbc = 0x1f) and prints "capture SCDC ERROR ==>Enable BCH"; otherwise the second set (top byte of
 * 0xc0 = 0x50, low byte of 0xc4 = 0, low 5 bits of 0xbc = 1).
 *   port: PHY / receiver index; also the letter ('A' + port) in the '[EQ]' prints
 *   en:   1 = enable */
void DRV_HDMI_Config_BCH(unsigned char port, unsigned char en)
{
    unsigned int clock_mhz = hdmi_phy_records[port].phy_clock_mhz;

    if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
        dbg_printf("[EQ]: Port%c %s \n", (char)(port + 'A'), fn_);
    if (en != 0 && clock_mhz > BCH_MIN_CLOCK_MHZ) {
        if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
            dbg_printf("[EQ]: \x1b[1mPort%c capture SCDC ERROR ==>Enable BCH \n\x1b[m", (char)(port + 'A'));
        volatile unsigned int *r = hdmi_rx21_reg_blocks[port].block0;

        r[0xc0 / 4] = (r[0xc0 / 4] & ~0xff000000) | 0x05000000;
        r[0xc4 / 4] &= ~0xff;
        r[0xbc / 4] |= 0x1f;
    } else {
        volatile unsigned int *r = hdmi_rx21_reg_blocks[port].block0;

        r[0xc0 / 4] = (r[0xc0 / 4] & ~0xff000000) | 0x50000000;
        r[0xc4 / 4] &= ~0xff;
        r[0xbc / 4] = (r[0xbc / 4] & ~0x1f) | 1;
    }
}
