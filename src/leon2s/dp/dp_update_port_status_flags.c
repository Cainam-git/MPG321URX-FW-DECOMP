/* dp_update_port_status_flags  (FUN_a006e820)
 *
 * Refresh the signal and stream flags of a DP port record.
 * Name basis: derived - flag byte +0xD from the DP receiver tests; callers dp_check_timing_change and
 *   dp_run_link_state
 *
 * Matching notes
 * --------------
 * FUN_a006e820 (leon2s 0xa006e820-0xa006e990), flags -mcpu=v8 -Os -g.
 * Source form: every flag bit is written with its own if/else (set, or clear with and-not); the record is
 * touched through its fields, the halfword at +0x12 through its own field.
 */
/* Port record of the input program (20 bytes); only the fields used here. */
struct port_record {
    unsigned char link_state;           /* 2 = LINK_STATE_POWER_ON, 1 = POWER_OFF */
    unsigned char bytes_0x01_0x0c[12];
    unsigned char published_flags;      /* +0x0d: the bits below */
    unsigned char bytes_0x0e_0x11[4];
    unsigned short flags_0x12;          /* bit 6 set here */
};

/* Bits of published_flags. */
#define PF_BIT0            0x01         /* link state 2: set while dp_is_link_trained is 1; above 2: always set */
#define PF_STREAM_PRESENT  0x02
#define PF_TRAINED_REG223  0x04         /* dp_is_trained_with_reg223_bit7: link trained and register 0x223 bit 7 */
#define PF_SELECTOR_BIT0   0x08         /* bits 0 and 1 of dp_probe_selector_levels */
#define PF_SELECTOR_BIT1   0x10
#define PF_HDCP_STATUS     0x20         /* from hdcp_rx_status_mask */
#define PF_HDR_ACTIVE      0x40         /* from hdr_source_active_flag */

extern unsigned char hdr_source_active_flag;
extern unsigned char hdcp_rx_status_mask;
extern unsigned char dp_is_link_trained(unsigned char port);
extern unsigned char dp_is_stream_present(unsigned int param_1);
extern unsigned char dp_is_trained_with_reg223_bit7(unsigned char param_1);
extern unsigned char dp_probe_selector_levels(unsigned char port);
extern unsigned char dp_update_range_flag(struct port_record *st, unsigned int port);

/*
 * Recompute the flag byte (+0x0d) of the port record of a DP input.
 *
 *   rec   port record of the input
 *   port  input number (also the index into the status bits of hdr_source_active_flag and
 *         hdcp_rx_status_mask, which keep this input's bit at position port + 4)
 *
 * Called from dp_check_timing_change and dp_run_link_state.
 *
 * Link state 2 or below: only bit 0 survives; for state 2 it is set from dp_is_link_trained(port) == 1,
 * for the other states it keeps its old value. Link state above 2: bit 0 is set, and bits 1..6 are
 * recomputed from the receiver tests below. The same pass sets bit 6 of the halfword at +0x12 from
 * dp_update_range_flag.
 */
void dp_update_port_status_flags(struct port_record *rec, unsigned char port)
{
    unsigned char selector_levels;

    if (rec->link_state <= 2) {
        if (rec->link_state == 2) {
            if (dp_is_link_trained(port) == 1)
                rec->published_flags |= PF_BIT0;
            else
                rec->published_flags &= ~PF_BIT0;
        }
        rec->published_flags &= PF_BIT0;
    } else {
        rec->published_flags |= PF_BIT0;
        if (dp_is_stream_present(port))
            rec->published_flags |= PF_STREAM_PRESENT;
        else
            rec->published_flags &= ~PF_STREAM_PRESENT;
        if (dp_is_trained_with_reg223_bit7(port))
            rec->published_flags |= PF_TRAINED_REG223;
        else
            rec->published_flags &= ~PF_TRAINED_REG223;
        selector_levels = dp_probe_selector_levels(port);
        if (selector_levels & 1)
            rec->published_flags |= PF_SELECTOR_BIT0;
        else
            rec->published_flags &= ~PF_SELECTOR_BIT0;
        if (selector_levels & 2)
            rec->published_flags |= PF_SELECTOR_BIT1;
        else
            rec->published_flags &= ~PF_SELECTOR_BIT1;
        if (dp_update_range_flag(rec, port))
            rec->flags_0x12 |= 0x40;
        else
            rec->flags_0x12 &= ~0x40;
        if ((hdr_source_active_flag >> (port + 4)) & 1)
            rec->published_flags |= PF_HDR_ACTIVE;
        else
            rec->published_flags &= ~PF_HDR_ACTIVE;
        if ((hdcp_rx_status_mask >> (port + 4)) & 1)
            rec->published_flags |= PF_HDCP_STATUS;
        else
            rec->published_flags &= ~PF_HDCP_STATUS;
    }
}
