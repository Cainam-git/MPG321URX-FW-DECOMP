/* hdmi_eq_print_channel_values  (EQ_handler_2)
 *
 * Print the RVGA, RCT and CCT values of the three channels.
 *   port: PHY
 * Note: Ends with three empty counting loops (a short delay).
 * Name basis: proven - prints '[EQ]: Port%c <CH%d> RVGA=0x%02x, RCT=0x%02x, CCT=0x%04x'
 *
 * Matching notes
 * --------------
 * leon2s EQ_handler_2 @ 0xa0075ffc, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the first loop is written with labels ('goto test; loop: ...; ch++; test: if (ch < 3) goto loop;'),
 *    which keeps the firmware's jump to the test at entry;
 *  - p = (unsigned char)port is set after ch = 0;
 *  - the three values are read in print-argument order (rvga, rct, cct);
 *  - the three empty loops re-read byte 8 of the scan record at every test.
 */
#define HDMI_MSG_EQ_FLOW 2      /* debug message bit: '[EQ]' lines (dbg_hdmi_message_flags) */

/* Result of one channel (written by DRV_HDMI_EQScan_FSM_PHY_RunAEQ). */
struct rct_result { unsigned char rct; unsigned char byte_1; unsigned short cct; };
/* EQ scan data of one PHY (0x898 bytes, hdmi_eq_port_records); only the fields used here. */
struct eq_scan_channels {
    unsigned char bytes_0x0_to_0x883[0x884];
    struct rct_result result[3];        /* +0x884 */
    unsigned char best_rvga_index[3];   /* +0x890 */
    unsigned char bytes_0x893_to_0x897[5];
};
/* EQ scan record of one PHY (12 bytes, hdmi_eq_scan_records). */
struct eq_scan_record { unsigned int state; unsigned int word_0x4; unsigned char byte_0x8; unsigned char pad[3]; };
extern struct eq_scan_channels hdmi_eq_port_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];
extern const unsigned char hdmi_eq_rvga_values[];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);

/* Prints, for the three channels, the RVGA value (table hdmi_eq_rvga_values indexed by the channel's
 * best RVGA index), the RCT value and the CCT value of the PHY's scan data. Then it spends time in three
 * empty counting loops: j < 3 (1 when byte 8 of the scan record is clear), then i < 10 (14 when clear) with
 * the same j loop inside.
 *   port: PHY index (the letter in the print is 'A' + port) */
void hdmi_eq_print_channel_values(unsigned int port)
{
    unsigned int p;     /* PHY index, low 8 bits */
    unsigned char ch, i, j;
    unsigned char rvga, rct;
    unsigned short cct;

    ch = 0;
    p = (unsigned char)port;
    goto test;
loop:
    rvga = hdmi_eq_rvga_values[hdmi_eq_port_records[p].best_rvga_index[ch]];
    rct = hdmi_eq_port_records[p].result[ch].rct;
    cct = hdmi_eq_port_records[p].result[ch].cct;
    if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
        dbg_printf("[EQ]: Port%c <CH%d> RVGA=0x%02x, RCT=0x%02x, CCT=0x%04x\n", (char)(port + 'A'), ch,
                     rvga, rct, cct);
    ch++;
test:
    if (ch < 3)
        goto loop;
    for (j = 0; j < (hdmi_eq_scan_records[port & 0xff].byte_0x8 ? 3u : 1u); j++)
        ;
    for (i = 0; i < (hdmi_eq_scan_records[port & 0xff].byte_0x8 ? 10u : 14u); i++)
        for (j = 0; j < (hdmi_eq_scan_records[port & 0xff].byte_0x8 ? 3u : 1u); j++)
            ;
}
