/* dp_aux_build_reply  (FUN_CODE_147a)
 *
 * Answer one DisplayPort AUX request with the emulated receiver's DPCD or EDID bytes.
 *   type: 0 native read, 1 native write, 2 I2C read, 3 I2C write
 *   p: request bytes
 *   sel: receiver port
 * Note: sel 0 = receiver port 0 (0xDCDx), 1 = port 1 (0xDCCx); writes the reply bytes to the AUX transmit
 *   port.
 * Name basis: proven - AUX request codes 9/8/1/5/0/4 (native read/write, I2C-over-AUX) from the callers; DPCD
 *   0x000 caps, 0x100, 0x202 lane status 0x77, 0x600, 0x2200, 0x68028, I2C 0x50
 *
 * Matching notes
 * --------------
 * Byte-exact with OPTIMIZE(8,SPEED) LARGE over 0x147A..0x1C3C (1986 bytes); register bank 3 ('using 3').
 * The parameters request_kind, request (generic pointer) and port sit in the LARGE block at XDATA 0xA55B.
 * Source forms the exact build depends on:
 * - reg_dp_aux_window is volatile: every loop stores to the same data register count times, and only volatile
 *   keeps each store.
 * - The I2C read loop has the read written in both arms of 'if (port == 0)' (edid_offset_port0 + i /
 *   edid_offset_port1 + i); Keil merges the tails.
 * - The locals e1..e5 are never used; they stay as declared.
 */
extern unsigned char volatile xdata reg_dp_aux_window[];
extern unsigned char xdata reg_dp_aux_reply_len_port0, reg_dp_aux_reply_len_port1;
extern unsigned char xdata dp_aux_link_config_port0[], dp_aux_link_config_port1[];
extern unsigned char xdata dp_aux_port_state_flags, dp_power_up_request;
struct aux_loop_state { unsigned char i; unsigned char count; };   /* IDATA 0x5B / 0x5C */
extern struct aux_loop_state idata irq_ext1_loop_counters;
extern unsigned char idata dp_aux_edid_offset_port0, dp_aux_edid_offset_port1;
extern bit dp_aux_empty_reply_flag;
extern unsigned char code dp_aux_edid[0x10], dp_aux_dpcd_link_status[8], dp_aux_dpcd_rx_caps[12], dp_aux_dpcd_ext_rx_caps[16], dp_aux_dpcd_0400_bytes[4];

/* request_kind, chosen by the callers from the high nibble of request byte 0. */
#define AUX_NATIVE_READ   0     /* 0x9_ */
#define AUX_NATIVE_WRITE  1     /* 0x8_ */
#define AUX_I2C_READ      2     /* 0x1_ / 0x5_ */
#define AUX_I2C_WRITE     3     /* 0x0_ / 0x4_ */

/* Request bytes as the callers collect them from the receiver's FIFO. */
#define REQ_ADDR_19_16  0       /* low nibble: address bits 19..16 (high nibble = request code) */
#define REQ_ADDR_15_8   1
#define REQ_ADDR_7_0    2       /* for I2C requests: the I2C address */
#define REQ_LENGTH      3       /* byte count - 1; the callers load the reply count with this + 1 */
#define REQ_DATA        4       /* first data byte of a write */

#define ADDR_NIBBLE_ALL 0x0f    /* address bits 19..16 all set: no answer */
#define EDID_I2C_ADDR   0x50    /* the only I2C address answered (from dp_aux_edid) */
#define LINK_CONFIG_LEN 7       /* bytes in dp_aux_link_config_port<N> (DPCD 0x100..0x106) */

/* Bits of dp_aux_port_state_flags, shifted left by port * 4. */
#define PORT_LANES_TRAINED 1    /* set when 0x202 / 0x203 are answered with 7 or 0x77 */
#define PORT_POWERED_ON    2    /* set / cleared by writes of 1 / 2 to DPCD 0x600 */

/*
 * dp_aux_build_reply - answer one DisplayPort AUX request for the receiver the 8051 handles itself: the reply
 * bytes are written one by one to the port's AUX data register (XDATA 0xDCDD for port 0, 0xDCCD for port 1).
 *   request_kind  AUX_NATIVE_READ / AUX_NATIVE_WRITE / AUX_I2C_READ / AUX_I2C_WRITE
 *   request       request bytes (REQ_* above)
 *   port          0 = receiver port 0 (registers 0xDCDx), 1 = receiver port 1 (0xDCCx)
 * The reply count is the value the caller put in reg_dp_aux_reply_len_port<N> (request length + 1, or 0 for a
 * request of three bytes or fewer).
 * Called from dp_aux_answer_port0 and dp_aux_answer_port1 after they have read the request.
 *
 * Phases:
 *   1. Pick the port's reply count, data register and link configuration bytes.
 *   2. Native read: answer by address (bits 15..8 select the area):
 *        0x000..0x00B  dp_aux_dpcd_rx_caps, zeros past its end; 0x00E: 0x80, then zeros
 *        0x100..       the port's link configuration bytes, zeros past 0x106 (a start at 0x105 or above gets
 *                      no bytes at all)
 *        0x200..0x208  dp_aux_dpcd_link_status, except 0x202 / 0x203, which are built from the low nibbles of
 *                      link configuration bytes 0x101 / 0x102 and byte 0x103
 *        0x200C        bytes read from dp_aux_dpcd_link_status[0x0C..], which are the bytes at CODE 0x6C18
 *                      (dp_aux_dpcd_rx_caps[4..])
 *        0x2200..      dp_aux_dpcd_ext_rx_caps, zeros past 0x220F
 *        0x400..0x403  the four bytes at CODE 0x6C30, zeros after them
 *        0x6__         2 when the port's PORT_POWERED_ON bit is clear, 1 when it is set; then zeros
 *        0x68028       count bytes of 1
 *      Any other address, or address bits 19..16 all set: the empty reply of phase 6.
 *   3. Native write: reply count to 0. Writes to 0x100..0x106 are stored in the link configuration bytes;
 *      a one-byte write of 2 / 1 to 0x600 clears / sets PORT_POWERED_ON, and a 1 also sets dp_power_up_request.
 *   4. I2C read: only address 0x50 is answered, count bytes of dp_aux_edid from the port's running offset, which
 *      then moves on by count; other addresses get the empty reply. Nothing is sent for a count of 0.
 *   5. I2C write: reply count to 0. To 0x50 with a non-zero count: the port's EDID offset = first data byte; to
 *      any other address: offset 0.
 *   6. Empty reply: count zero bytes when the flag was set.
 */
void dp_aux_build_reply(unsigned char request_kind, unsigned char *request, unsigned char port) using 3
{
    unsigned char data_reg;     /* low byte of the port's AUX data register in reg_dp_aux_window (0xDC00..) */
    unsigned char *link_config; /* the port's copy of DPCD 0x100..0x106 */
    int index;
    unsigned char shift, e1, e2, e3, e4, e5;

    /* Phase 1: port set-up. */
    dp_aux_empty_reply_flag = 0;
    if (port == 0) {
        irq_ext1_loop_counters.count = reg_dp_aux_reply_len_port0;
        data_reg = 0xdd;
        link_config = dp_aux_link_config_port0;
    } else {
        irq_ext1_loop_counters.count = reg_dp_aux_reply_len_port1;
        data_reg = 0xcd;
        link_config = dp_aux_link_config_port1;
    }
    switch (request_kind) {
    case AUX_NATIVE_READ:
        /* Phase 2: native read. */
        if ((request[REQ_ADDR_19_16] & 0x0f) == ADDR_NIBBLE_ALL) {
            dp_aux_empty_reply_flag = 1;
            break;
        }
        if (request[REQ_ADDR_15_8] == 6) {
            /* DPCD 0x600: power state as last written by the source. */
            shift = port * 4;
            if (!(dp_aux_port_state_flags & (PORT_POWERED_ON << shift))) reg_dp_aux_window[data_reg] = 2;
            else reg_dp_aux_window[data_reg] = 1;
            for (irq_ext1_loop_counters.i = 0; irq_ext1_loop_counters.i < irq_ext1_loop_counters.count - 1; irq_ext1_loop_counters.i++)
                reg_dp_aux_window[data_reg] = 0;
        } else if (request[REQ_ADDR_15_8] == 0) {
            if (request[REQ_ADDR_7_0] < 0x0c) {
                /* DPCD 0x000..0x00B: receiver capabilities. */
                for (irq_ext1_loop_counters.i = 0; irq_ext1_loop_counters.i < irq_ext1_loop_counters.count; irq_ext1_loop_counters.i++) {
                    if (irq_ext1_loop_counters.i + request[REQ_ADDR_7_0] < 0x0c) reg_dp_aux_window[data_reg] = dp_aux_dpcd_rx_caps[irq_ext1_loop_counters.i + request[REQ_ADDR_7_0]];
                    else reg_dp_aux_window[data_reg] = 0;
                }
            } else if (request[REQ_ADDR_7_0] == 0x0e) {
                for (irq_ext1_loop_counters.i = 0; irq_ext1_loop_counters.i < irq_ext1_loop_counters.count; irq_ext1_loop_counters.i++) {
                    if (irq_ext1_loop_counters.i == 0) reg_dp_aux_window[data_reg] = 0x80;
                    else reg_dp_aux_window[data_reg] = 0;
                }
            } else {
                dp_aux_empty_reply_flag = 1;
            }
        } else if (request[REQ_ADDR_15_8] == 1) {
            /* DPCD 0x100..: what the source wrote there (phase 3). */
            if (request[REQ_ADDR_7_0] < 5) {
                for (irq_ext1_loop_counters.i = 0; irq_ext1_loop_counters.i < irq_ext1_loop_counters.count; irq_ext1_loop_counters.i++) {
                    index = irq_ext1_loop_counters.i + request[REQ_ADDR_7_0];
                    if (index < LINK_CONFIG_LEN) reg_dp_aux_window[data_reg] = link_config[index];
                    else reg_dp_aux_window[data_reg] = 0;
                }
            }
        } else if (request[REQ_ADDR_15_8] == 2) {
            /* DPCD 0x200..0x208: link status; 0x202 / 0x203 follow the written link configuration. */
            if (request[REQ_ADDR_7_0] < 9) {
                for (irq_ext1_loop_counters.i = 0; irq_ext1_loop_counters.i < irq_ext1_loop_counters.count; irq_ext1_loop_counters.i++) {
                    if (irq_ext1_loop_counters.i + request[REQ_ADDR_7_0] == 2) {
                        if (link_config[3] == 0) reg_dp_aux_window[data_reg] = 0;
                        else if ((link_config[2] & 0x0f) == 1) {
                            if ((link_config[1] & 0x0f) == 1) reg_dp_aux_window[data_reg] = 1;
                            else reg_dp_aux_window[data_reg] = 0x11;
                        } else if ((link_config[1] & 0x0f) == 1) {
                            reg_dp_aux_window[data_reg] = 7;
                            dp_aux_port_state_flags |= (1 << (port * 4));
                        } else {
                            reg_dp_aux_window[data_reg] = 0x77;
                            dp_aux_port_state_flags |= (1 << (port * 4));
                        }
                    } else if (irq_ext1_loop_counters.i + request[REQ_ADDR_7_0] == 3) {
                        if (link_config[3] == 0) reg_dp_aux_window[data_reg] = 0;
                        else if ((link_config[2] & 0x0f) == 1) {
                            if ((link_config[1] & 0x0f) == 4) reg_dp_aux_window[data_reg] = 0x11;
                            else reg_dp_aux_window[data_reg] = 0;
                        } else if ((link_config[1] & 0x0f) == 4) {
                            reg_dp_aux_window[data_reg] = 0x77;
                            dp_aux_port_state_flags |= (1 << (port * 4));
                        } else {
                            reg_dp_aux_window[data_reg] = 0;
                        }
                    } else {
                        reg_dp_aux_window[data_reg] = dp_aux_dpcd_link_status[irq_ext1_loop_counters.i + request[REQ_ADDR_7_0]];
                    }
                }
            } else {
                dp_aux_empty_reply_flag = 1;
            }
        } else if (request[REQ_ADDR_15_8] == 0x20) {
            /* DPCD 0x200C: indexes past the 8-byte link status table, into the bytes at CODE 0x6C18. */
            if (request[REQ_ADDR_7_0] == 0x0c) {
                for (irq_ext1_loop_counters.i = 0; irq_ext1_loop_counters.i < irq_ext1_loop_counters.count; irq_ext1_loop_counters.i++)
                    reg_dp_aux_window[data_reg] = dp_aux_dpcd_link_status[request[REQ_ADDR_7_0] + irq_ext1_loop_counters.i];
            } else {
                dp_aux_empty_reply_flag = 1;
            }
        } else if (request[REQ_ADDR_15_8] == 0x22) {
            /* DPCD 0x2200..0x220F: extended receiver capabilities. */
            for (irq_ext1_loop_counters.i = 0; irq_ext1_loop_counters.i < irq_ext1_loop_counters.count; irq_ext1_loop_counters.i++) {
                if (irq_ext1_loop_counters.i + request[REQ_ADDR_7_0] < 0x10) reg_dp_aux_window[data_reg] = dp_aux_dpcd_ext_rx_caps[irq_ext1_loop_counters.i + request[REQ_ADDR_7_0]];
                else reg_dp_aux_window[data_reg] = 0;
            }
        } else if (request[REQ_ADDR_15_8] == 4) {
            /* DPCD 0x400..0x403. */
            for (irq_ext1_loop_counters.i = 0; irq_ext1_loop_counters.i < irq_ext1_loop_counters.count; irq_ext1_loop_counters.i++) {
                if (irq_ext1_loop_counters.i + request[REQ_ADDR_7_0] < 4) reg_dp_aux_window[data_reg] = dp_aux_dpcd_0400_bytes[irq_ext1_loop_counters.i + request[REQ_ADDR_7_0]];
                else reg_dp_aux_window[data_reg] = 0;
            }
        } else if ((request[REQ_ADDR_19_16] & 0x0f) == 6 && request[REQ_ADDR_15_8] == 0x80 && request[REQ_ADDR_7_0] == 0x28) {
            /* DPCD 0x68028. */
            for (irq_ext1_loop_counters.i = 0; irq_ext1_loop_counters.i < irq_ext1_loop_counters.count; irq_ext1_loop_counters.i++)
                reg_dp_aux_window[data_reg] = 1;
        } else {
            dp_aux_empty_reply_flag = 1;
        }
        break;
    case AUX_NATIVE_WRITE:
        /* Phase 3: native write; nothing is sent back. */
        if (port == 0) reg_dp_aux_reply_len_port0 = 0;
        else reg_dp_aux_reply_len_port1 = 0;
        if ((request[REQ_ADDR_19_16] & 0x0f) == ADDR_NIBBLE_ALL) break;
        if (request[REQ_ADDR_15_8] == 1) {
            for (irq_ext1_loop_counters.i = 0; irq_ext1_loop_counters.i < irq_ext1_loop_counters.count; irq_ext1_loop_counters.i++) {
                if (request[REQ_ADDR_7_0] + irq_ext1_loop_counters.i < LINK_CONFIG_LEN) link_config[irq_ext1_loop_counters.i + request[REQ_ADDR_7_0]] = request[irq_ext1_loop_counters.i + REQ_DATA];
            }
        } else if (request[REQ_ADDR_15_8] == 6 && request[REQ_ADDR_7_0] == 0) {
            if (request[REQ_LENGTH] == 0 && request[REQ_DATA] == 2) {
                dp_aux_port_state_flags &= ~(PORT_POWERED_ON << (port * 4));
            } else if (request[REQ_LENGTH] == 0 && request[REQ_DATA] == 1) {
                dp_aux_port_state_flags |= (PORT_POWERED_ON << (port * 4));
                if (dp_power_up_request == 0) dp_power_up_request = 1;
            }
        }
        break;
    case AUX_I2C_READ:
        /* Phase 4: I2C read, EDID only. */
        if (irq_ext1_loop_counters.count > 0) {
            if (request[REQ_ADDR_7_0] == EDID_I2C_ADDR) {
                for (irq_ext1_loop_counters.i = 0; irq_ext1_loop_counters.i < irq_ext1_loop_counters.count; irq_ext1_loop_counters.i++)
{ if (port == 0) reg_dp_aux_window[data_reg] = dp_aux_edid[dp_aux_edid_offset_port0 + irq_ext1_loop_counters.i]; else reg_dp_aux_window[data_reg] = dp_aux_edid[dp_aux_edid_offset_port1 + irq_ext1_loop_counters.i]; }
                if (port == 0) dp_aux_edid_offset_port0 += irq_ext1_loop_counters.count;
                else dp_aux_edid_offset_port1 += irq_ext1_loop_counters.count;
            } else {
                dp_aux_empty_reply_flag = 1;
            }
        }
        break;
    case AUX_I2C_WRITE:
        /* Phase 5: I2C write: sets the EDID read offset. */
        if (port == 0) reg_dp_aux_reply_len_port0 = 0;
        else reg_dp_aux_reply_len_port1 = 0;
        if (request[REQ_ADDR_7_0] == EDID_I2C_ADDR) {
            if (irq_ext1_loop_counters.count > 0) {
                if (port == 0) dp_aux_edid_offset_port0 = request[REQ_DATA];
                else dp_aux_edid_offset_port1 = request[REQ_DATA];
            }
        } else {
            if (port == 0) dp_aux_edid_offset_port0 = 0;
            else dp_aux_edid_offset_port1 = 0;
        }
        break;
    }
    /* Phase 6: empty reply. */
    if (dp_aux_empty_reply_flag) {
        for (irq_ext1_loop_counters.i = 0; irq_ext1_loop_counters.i < irq_ext1_loop_counters.count; irq_ext1_loop_counters.i++)
            reg_dp_aux_window[data_reg] = 0;
    }
}
