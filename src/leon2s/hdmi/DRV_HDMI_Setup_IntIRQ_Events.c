/* DRV_HDMI_Setup_IntIRQ_Events  (DRV_HDMI_Setup_IntIRQ_Events)
 *
 * Switch on the interrupt events of an HDMI 2.1 receiver and load its record; acts only on enable = 1.
 *   receiver: HDMI 2.1 receiver
 *   enable: 1 = on
 * Note: Any other enable value only prints.
 * Name basis: proven - original name printed ('DRV_HDMI_Setup_IntIRQ_Events Enable = %d')
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_Setup_IntIRQ_Events @ 0xa0096344, flags -mcpu=v8 -Os -g.
 * Source form: a local record pointer r for the [r+4] load; the stores come in source order 0x16, 0x14, 8
 * (0x14, 0x16, 8 builds the same code).
 */
#define RX21_RECORD_SIZE 0x190      /* bytes per entry of hdmi_rx21_input_records */
#define HDMI_MSG_MODEDET_FLOW 4 /* debug message bit: '[MODEDET]' lines (dbg_hdmi_message_flags) */

extern unsigned int dbg_hdmi_message_flags;
extern unsigned char hdmi_rx21_reg_blocks[];
extern unsigned char hdmi_rx21_input_records[];
extern int dbg_printf(const char *, ...);
extern void hdmi_rx21_set_event_reg78_bit(unsigned int, unsigned int, unsigned int);

/* With enable == 1: sets bits 0x10, 0x15, 0x12, 0xd and 0x11 of event register 0x78 of the receiver
 * (hdmi_rx21_set_event_reg78_bit), copies registers 0x40 and 0x44 of its register block 1 into the
 * receiver record (+0xc and +0x10), and sets record bytes +0x16 = 0, +0x14 = 4 and +8 = 0. With any
 * other value it only prints (when enabled).
 *   receiver: receiver index (the letter in the print is 'A' + receiver)
 *   enable:   1 = enable */
void DRV_HDMI_Setup_IntIRQ_Events(unsigned int receiver, unsigned int enable)
{
    unsigned int port;
    unsigned char *r;       /* register-block row of the receiver */
    unsigned char *q;       /* register block 1 */
    unsigned char *rec;     /* receiver record */

    port = receiver & 0xff;
    if ((dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW) != 0) {
        dbg_printf("[MODEDET]: Port%c DRV_HDMI_Setup_IntIRQ_Events Enable = %d\n",
                     (char)(receiver + 0x41), enable & 0xff);
    }
    if (((unsigned char)enable) == 1) {
        hdmi_rx21_set_event_reg78_bit(port, 0x10, 1);
        hdmi_rx21_set_event_reg78_bit(port, 0x15, 1);
        hdmi_rx21_set_event_reg78_bit(port, 0x12, 1);
        hdmi_rx21_set_event_reg78_bit(port, 0xd, 1);
        hdmi_rx21_set_event_reg78_bit(port, 0x11, 1);
        r = hdmi_rx21_reg_blocks + port * 0x34;
        q = *(unsigned char **)(r + 4);
        rec = hdmi_rx21_input_records + port * RX21_RECORD_SIZE;
        *(unsigned int *)(rec + 0xc) = *(unsigned int *)(q + 0x40);
        *(unsigned int *)(rec + 0x10) = *(unsigned int *)(q + 0x44);
        rec[0x16] = 0;
        rec[0x14] = 4;
        rec[8] = 0;
    }
}
