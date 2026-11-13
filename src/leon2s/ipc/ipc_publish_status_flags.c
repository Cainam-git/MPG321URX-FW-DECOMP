/* ipc_publish_status_flags  (FUN_a006fedc)
 *
 * Publish eight status flags (OSD unzip busy and others) to the main processor.
 * Name basis: derived - top byte of slot 0 word 3; bit 0 = OSD unzip busy flag
 *
 * Matching notes
 * --------------
 * FUN_a006fedc (leon2s 0xa006fedc, 216 bytes), flags -mcpu=v8 -Os -g.
 * The flag byte is built one statement per bit; the clear of the top byte of the word sits between the bit-1 and
 * bit-2 statements, which gives the firmware's load order.
 */
extern unsigned char osd_unzip_busy_flag;
extern unsigned char hdcp_rx_init_flag;
extern unsigned char sys_otp_shared_loaded_flag;
extern unsigned char hdmi_tx_sink_flags[];
extern unsigned char dp_tx_hpd_flag;
extern unsigned char ipc_status_flag_6;
extern void ipc_read_mailbox_slot(unsigned int slot, int word, unsigned int *buffer, unsigned int count);
extern void ipc_write_mailbox_slot(unsigned int slot, int word, unsigned int *buffer, unsigned int count);
extern unsigned int dp_tx_is_link_active(unsigned char port);

#define IPC_SLOT_STATE   0              /* slot 0: state words the input processor publishes */
#define IPC_STATUS_WORD  3              /* its word 3 */

/* Bit positions of the status flags, in the top byte (bits 24..31) of slot 0 word 3. */
#define STATUS_OSD_UNZIP_BUSY    0
#define STATUS_HDCP_RX_INIT      1
#define STATUS_OTP_SHARED_LOADED 2
#define STATUS_HDMI_TX_SINK_0    3
#define STATUS_HDMI_TX_SINK_1    4
#define STATUS_DP_TX_HPD         5
#define STATUS_FLAG_6            6
#define STATUS_DP_TX_LINK_ACTIVE 7

/*
 * Publish eight status flags to the main processor: read slot 0 word 3, replace its top byte by the flags and
 * write it back. The other 24 bits of the word are kept.
 * Called by ipc_publish_port_status.
 */
void ipc_publish_status_flags(void)
{
    unsigned int status = 0;
    unsigned int flags;

    ipc_read_mailbox_slot(IPC_SLOT_STATE, IPC_STATUS_WORD, &status, 1);
    flags = osd_unzip_busy_flag;
    flags |= hdcp_rx_init_flag << STATUS_HDCP_RX_INIT;
    status &= 0xffffff;
    flags |= sys_otp_shared_loaded_flag << STATUS_OTP_SHARED_LOADED;
    flags |= hdmi_tx_sink_flags[0] << STATUS_HDMI_TX_SINK_0;
    flags |= hdmi_tx_sink_flags[1] << STATUS_HDMI_TX_SINK_1;
    flags |= dp_tx_hpd_flag << STATUS_DP_TX_HPD;
    flags |= ipc_status_flag_6 << STATUS_FLAG_6;
    flags |= (unsigned char)dp_tx_is_link_active(0) << STATUS_DP_TX_LINK_ACTIVE;
    status |= flags << 24;
    ipc_write_mailbox_slot(IPC_SLOT_STATE, IPC_STATUS_WORD, &status, 1);
}
