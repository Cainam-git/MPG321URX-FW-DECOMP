/* dp_aux_track_link_training  (FUN_CODE_34c8)
 *
 * Mirror a snooped DP AUX request into the receiver's link status registers.
 *   type: 0 native read, 1 native write
 *   p: request bytes
 *   sel: receiver port
 * Name basis: derived - DPCD writes 0x102/0x103 set lane status 0x77/0x11 at receiver regs 0x97/0x98; 0x600
 *   power state; callers dp_aux_snoop_port0/1
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_34c8 @ 0x34c8..0x38a7 (991 B)  OPTIMIZE(8,SPEED) LARGE; register bank 3 ('using 3').
 * Parameters request_kind (R7), request (generic pointer) and port in the LARGE block at XDATA 0xA55A..0xA55D;
 * locals data_reg 0xA55E and link_config 0xA55F..0xA561. The unused locals unused_1/_4/_5 stay declared.
 * Source form: the position tests are written 'request[REQ_ADDR_7_0] + i == k', the first store index
 *   'i + request[REQ_ADDR_7_0]', the second 'request[REQ_ADDR_7_0] + i'.
 */
extern unsigned char xdata reg_dp_aux_reply_len_port0, reg_dp_aux_reply_len_port1;
extern unsigned char xdata dp_aux_link_config_port0[], dp_aux_link_config_port1[];
extern unsigned char xdata dp_aux_port_state_flags;
struct aux_loop_state { unsigned char i; unsigned char count; };   /* IDATA 0x5B / 0x5C */
extern struct aux_loop_state idata irq_ext1_loop_counters;
extern bit dp_aux_empty_reply_flag;
extern void dp_mrx_write_reg(unsigned char port, unsigned char reg, unsigned char value);
extern unsigned char dp_mrx_read_reg(unsigned char port, unsigned char reg);

/* request_kind, chosen by the callers from the high nibble of request byte 0 (as dp_aux_build_reply). */
#define AUX_NATIVE_READ   0     /* 0x9_ */
#define AUX_NATIVE_WRITE  1     /* 0x8_ */

/* Request bytes as the callers collect them from the receiver's FIFO. */
#define REQ_ADDR_15_8   1
#define REQ_ADDR_7_0    2
#define REQ_LENGTH      3       /* byte count - 1 */
#define REQ_DATA        4       /* first data byte of a write */

/* Bits of dp_aux_port_state_flags, shifted left by port * 4 (as dp_aux_build_reply). */
#define PORT_LANES_TRAINED 1
#define PORT_POWERED_ON    2

/* Registers of the DisplayPort receiver, read and written with dp_mrx_read_reg / dp_mrx_write_reg. Their function
 * is not shown beyond the values written here. */
#define MRX_REG_8D        0x8d  /* low nibble 1, 2 or 4: how many status nibbles of 0x97 / 0x98 are set */
#define MRX_REG_8E        0x8e
#define MRX_REG_8F        0x8f
#define MRX_LANE_STATUS_A 0x97  /* nibbles 0 and 1 */
#define MRX_LANE_STATUS_B 0x98  /* nibbles 2 and 3 */
#define MRX_REG_99        0x99
#define MRX_REG_A8        0xa8

/*
 * dp_aux_track_link_training - copy what the computer writes over the DisplayPort AUX channel into the
 * receiver's own registers, so that the receiver's state follows the requests that the 8051 answers itself
 * (dp_aux_build_reply answers the same requests).
 *   request_kind  AUX_NATIVE_READ or AUX_NATIVE_WRITE; any other value does nothing
 *   request       request bytes (REQ_* above)
 *   port          receiver port 0 or 1
 * Called from dp_aux_snoop_port0 and dp_aux_snoop_port1 after they have collected a request and loaded the port's
 * reply count (request length + 1, or 0 for a request of three bytes or fewer).
 *
 * In order:
 *   - Native read of 0x6__: receiver reg 0xA8 = 2 when the port's PORT_POWERED_ON bit is clear, 1 when it is set.
 *   - Native write to 0x1__: the bytes for 0x102 and 0x103 are stored in the port's link configuration copy.
 *       0x102: with reg 0x8F at 0, regs 0x97, 0x98, 0x99 are cleared. Otherwise a value whose low nibble is
 *       above 1 sets 7 in each status nibble that reg 0x8D asks for (see MRX_REG_8D), sets bit 0 of reg 0x99 and
 *       writes 7 to reg 0xA8; a value of 0 sets the port's PORT_LANES_TRAINED bit.
 *       0x103: a non-zero value, with the low nibble of reg 0x8E at 1, sets 1 in each status nibble that reg
 *       0x8D asks for.
 *   - One-byte native write to 0x600: 2 clears and 1 sets the port's PORT_POWERED_ON bit.
 */
void dp_aux_track_link_training(unsigned char request_kind, unsigned char *request, unsigned char port) using 3
{
    unsigned char data_reg;     /* stored, never read (dp_aux_build_reply uses it as the AUX data register) */
    unsigned char *link_config; /* the port's copy of DPCD 0x100..0x106 */
    unsigned char shift, unused_1, unused_4, unused_5;

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
        if (request[REQ_ADDR_15_8] == 6) {
            shift = port * 4;
            if (!(dp_aux_port_state_flags & (PORT_POWERED_ON << shift))) dp_mrx_write_reg(port, MRX_REG_A8, 2);
            else dp_mrx_write_reg(port, MRX_REG_A8, 1);
        }
        break;
    case AUX_NATIVE_WRITE:
        if (request[REQ_ADDR_15_8] == 1) {
            /* Walk the written bytes; only the ones that land on 0x102 and 0x103 matter. */
            for (irq_ext1_loop_counters.i = 0; irq_ext1_loop_counters.i < irq_ext1_loop_counters.count; irq_ext1_loop_counters.i++) {
                if (request[REQ_ADDR_7_0] + irq_ext1_loop_counters.i == 2) {
                    link_config[irq_ext1_loop_counters.i + request[REQ_ADDR_7_0]] = request[irq_ext1_loop_counters.i + REQ_DATA];
                    if (dp_mrx_read_reg(port, MRX_REG_8F) == 0) {
                        dp_mrx_write_reg(port, MRX_LANE_STATUS_A, 0);
                        dp_mrx_write_reg(port, MRX_LANE_STATUS_B, 0);
                        dp_mrx_write_reg(port, MRX_REG_99, 0);
                    } else if ((link_config[irq_ext1_loop_counters.i + request[REQ_ADDR_7_0]] & 0x0f) > 1) {
                        if ((dp_mrx_read_reg(port, MRX_REG_8D) & 0x0f) == 1) {
                            dp_mrx_write_reg(port, MRX_LANE_STATUS_A, 7);
                            dp_mrx_write_reg(port, MRX_LANE_STATUS_B, 0);
                        } else if ((dp_mrx_read_reg(port, MRX_REG_8D) & 0x0f) == 2) {
                            dp_mrx_write_reg(port, MRX_LANE_STATUS_A, 0x77);
                            dp_mrx_write_reg(port, MRX_LANE_STATUS_B, 0);
                        } else if ((dp_mrx_read_reg(port, MRX_REG_8D) & 0x0f) == 4) {
                            dp_mrx_write_reg(port, MRX_LANE_STATUS_A, 0x77);
                            dp_mrx_write_reg(port, MRX_LANE_STATUS_B, 0x77);
                        }
                        dp_mrx_write_reg(port, MRX_REG_99, dp_mrx_read_reg(port, MRX_REG_99) | 1);
                        dp_mrx_write_reg(port, MRX_REG_A8, 7);
                    } else if (link_config[irq_ext1_loop_counters.i + request[REQ_ADDR_7_0]] == 0) {
                        dp_aux_port_state_flags |= (PORT_LANES_TRAINED << (port * 4));
                    }
                }
                if (request[REQ_ADDR_7_0] + irq_ext1_loop_counters.i == 3) {
                    link_config[request[REQ_ADDR_7_0] + irq_ext1_loop_counters.i] = request[irq_ext1_loop_counters.i + REQ_DATA];
                    if (link_config[irq_ext1_loop_counters.i + request[REQ_ADDR_7_0]] > 0 && (dp_mrx_read_reg(port, MRX_REG_8E) & 0x0f) == 1) {
                        if ((dp_mrx_read_reg(port, MRX_REG_8D) & 0x0f) == 1) {
                            dp_mrx_write_reg(port, MRX_LANE_STATUS_A, 1);
                            dp_mrx_write_reg(port, MRX_LANE_STATUS_B, 0);
                        } else if ((dp_mrx_read_reg(port, MRX_REG_8D) & 0x0f) == 2) {
                            dp_mrx_write_reg(port, MRX_LANE_STATUS_A, 0x11);
                            dp_mrx_write_reg(port, MRX_LANE_STATUS_B, 0);
                        } else if ((dp_mrx_read_reg(port, MRX_REG_8D) & 0x0f) == 4) {
                            dp_mrx_write_reg(port, MRX_LANE_STATUS_A, 0x11);
                            dp_mrx_write_reg(port, MRX_LANE_STATUS_B, 0x11);
                        }
                    }
                }
            }
        } else if (request[REQ_ADDR_15_8] == 6 && request[REQ_ADDR_7_0] == 0) {
            /* DPCD 0x600, one byte (REQ_LENGTH 0). */
            if (request[REQ_LENGTH] == 0 && request[REQ_DATA] == 2) {
                dp_aux_port_state_flags &= ~(PORT_POWERED_ON << (port * 4));
            } else if (request[REQ_LENGTH] == 0 && request[REQ_DATA] == 1) {
                dp_aux_port_state_flags |= (PORT_POWERED_ON << (port * 4));
            }
        }
        break;
    }
}
