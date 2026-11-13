/* hdmi_rx21_update_port_status_flags  (FUN_a006e0e4)
 *
 * Refresh the status flags of an HDMI 2.1 port record.
 * Name basis: derived - same flag layout as hdmi_update_port_status_flags from the 400-byte HDMI 2.1 record;
 *   callers HDMI 2.1 link code
 *
 * Matching notes
 * --------------
 * leon2s hdmi_rx21_update_port_status_flags (FUN_a006e0e4) @ 0xa006e0e4-0xa006e2c4 (480 bytes), flags
 * -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - st and rec are plain byte pointers; the flag byte is changed with byte read-modify-writes (set with
 *    '|=', cleared with '&= ~bit', bit 7 with '&= 0x7f') and the halfwords at +0xe and +0x12 through
 *    unsigned short pointers, each bit in its own if/else;
 *  - p is assigned just before the bit-7 test;
 *  - the last call takes 'port & 0xff' (a fresh mask) while the others take p.
 */
extern unsigned char hdr_source_active_flag;
extern unsigned char hdcp_rx_status_mask;
extern unsigned char hdmi_rx21_get_status_byte7(unsigned int);
extern unsigned char hdmi_rx21_get_hdmi_mode_copy(unsigned int);
extern unsigned char hdmi_rx21_is_frl_mode(unsigned char port);
extern unsigned int audio_check_hdmi21_rate_valid(unsigned char reset, unsigned int param_2);

/* Byte offsets in the 20-byte port record (input_port_records[2 + receiver]). */
#define PORT_LINK_STATE         0       /* 5 = LINK_READY */
#define PORT_PUBLISHED_FLAGS    0xd     /* printed 'ucPHYStatus'; sent to the main processor */
#define PORT_STATUS_0XE         0xe     /* halfword: bits 13..15 set here */
#define PORT_FLAGS_0X12         0x12    /* halfword: bit 6 set here */
#define LINK_READY              5

/* Byte offsets in the 400-byte HDMI 2.1 receiver record (hdmi_rx21_input_records). */
#define RX_VRR_FLAGS            6       /* set by hdmi_rx21_detect_vrr_signalling */
#define RX_CVTEM_PRESENT        0x2d

/* Bits of the published flag byte. */
#define FLAG_CVTEM              0x02    /* the receiver record's cvtem_present is set */
#define FLAG_VRR_BIT0_OR_2      0x04    /* VRR flags bit 0 or bit 2 */
#define FLAG_VRR_BIT1           0x08
#define FLAG_VRR_BIT4           0x10
#define FLAG_HDCP_STATUS        0x20    /* bit (input) of hdcp_rx_status_mask */
#define FLAG_HDR_SOURCE         0x40    /* bit (input) of hdr_source_active_flag */
#define FLAG_VRR_BIT3           0x80
/* Bits of the status halfword at +0xe. */
#define STATUS_BYTE7            0x4000  /* hdmi_rx21_get_status_byte7 */
#define STATUS_HDMI_MODE        0x8000  /* hdmi_rx21_get_hdmi_mode_copy */
#define STATUS_FRL_MODE         0x2000  /* hdmi_rx21_is_frl_mode */
#define FLAGS12_AUDIO_RATE_OK   0x40    /* audio_check_hdmi21_rate_valid */
#define INPUT_FIRST_RX21        2       /* HDMI 2.1 receivers 0 / 1 are inputs 2 / 3 in the bit masks */

/*
 * Rebuilds the status flags of the port record of an HDMI 2.1 receiver from its receiver record. Called by
 * hdmi_rx21_copy_link_timing and hdmi_rx21_run_link_state. Each flag is set or cleared on its own:
 *  - published flag byte +0xd: FLAG_CVTEM from the record's cvtem_present; four flags from the bits of the
 *    record's VRR flags byte (bit 0 or 2, bit 1, bit 4, bit 3); FLAG_HDR_SOURCE and FLAG_HDCP_STATUS from
 *    bit (receiver + 2) of hdr_source_active_flag and hdcp_rx_status_mask;
 *  - status halfword +0xe: bit 14 from hdmi_rx21_get_status_byte7, bit 15 from hdmi_rx21_get_hdmi_mode_copy,
 *    bit 13 from hdmi_rx21_is_frl_mode;
 *  - halfword +0x12 bit 6: only for a port record in link state 5 (LINK_READY) the result of
 *    audio_check_hdmi21_rate_valid(0, receiver); for any other state that routine is called with (1, receiver),
 *    its result is dropped and the bit is cleared.
 *   st:   the port record
 *   port: HDMI 2.1 receiver 0 or 1
 *   rec:  the receiver record (400 bytes)
 */
void hdmi_rx21_update_port_status_flags(unsigned char *st, unsigned int port, unsigned char *rec)
{
    unsigned char p;

    if (rec[RX_CVTEM_PRESENT])
        st[PORT_PUBLISHED_FLAGS] |= FLAG_CVTEM;
    else
        st[PORT_PUBLISHED_FLAGS] &= ~FLAG_CVTEM;
    if ((rec[RX_VRR_FLAGS] & 1) || (rec[RX_VRR_FLAGS] & 4))
        st[PORT_PUBLISHED_FLAGS] |= FLAG_VRR_BIT0_OR_2;
    else
        st[PORT_PUBLISHED_FLAGS] &= ~FLAG_VRR_BIT0_OR_2;
    if (rec[RX_VRR_FLAGS] & 2)
        st[PORT_PUBLISHED_FLAGS] |= FLAG_VRR_BIT1;
    else
        st[PORT_PUBLISHED_FLAGS] &= ~FLAG_VRR_BIT1;
    if (rec[RX_VRR_FLAGS] & 0x10)
        st[PORT_PUBLISHED_FLAGS] |= FLAG_VRR_BIT4;
    else
        st[PORT_PUBLISHED_FLAGS] &= ~FLAG_VRR_BIT4;
    p = port;
    if (rec[RX_VRR_FLAGS] & 8)
        st[PORT_PUBLISHED_FLAGS] |= FLAG_VRR_BIT3;
    else
        st[PORT_PUBLISHED_FLAGS] &= 0x7f;
    if ((hdr_source_active_flag >> (p + INPUT_FIRST_RX21)) & 1)
        st[PORT_PUBLISHED_FLAGS] |= FLAG_HDR_SOURCE;
    else
        st[PORT_PUBLISHED_FLAGS] &= ~FLAG_HDR_SOURCE;
    if ((hdcp_rx_status_mask >> (p + INPUT_FIRST_RX21)) & 1)
        st[PORT_PUBLISHED_FLAGS] |= FLAG_HDCP_STATUS;
    else
        st[PORT_PUBLISHED_FLAGS] &= ~FLAG_HDCP_STATUS;
    if (hdmi_rx21_get_status_byte7(p))
        *(unsigned short *)(st + PORT_STATUS_0XE) |= STATUS_BYTE7;
    else
        *(unsigned short *)(st + PORT_STATUS_0XE) &= ~STATUS_BYTE7;
    if (hdmi_rx21_get_hdmi_mode_copy(p))
        *(unsigned short *)(st + PORT_STATUS_0XE) |= STATUS_HDMI_MODE;
    else
        *(unsigned short *)(st + PORT_STATUS_0XE) &= ~STATUS_HDMI_MODE;
    if (st[PORT_LINK_STATE] != LINK_READY) {
        audio_check_hdmi21_rate_valid(1, p);
        *(unsigned short *)(st + PORT_FLAGS_0X12) &= ~FLAGS12_AUDIO_RATE_OK;
    } else if ((unsigned char)audio_check_hdmi21_rate_valid(0, p))
        *(unsigned short *)(st + PORT_FLAGS_0X12) |= FLAGS12_AUDIO_RATE_OK;
    else
        *(unsigned short *)(st + PORT_FLAGS_0X12) &= ~FLAGS12_AUDIO_RATE_OK;
    if (hdmi_rx21_is_frl_mode(port & 0xff))
        *(unsigned short *)(st + PORT_STATUS_0XE) |= STATUS_FRL_MODE;
    else
        *(unsigned short *)(st + PORT_STATUS_0XE) &= ~STATUS_FRL_MODE;
}
