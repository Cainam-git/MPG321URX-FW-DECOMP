/* hdmi_rx21_measure_payload_delay  (u32payload_delay)
 *
 * Measure the FRL payload count of an HDMI 2.1 receiver and set the delay bit.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: the payload count scaled by the FRL clock of the rate (the target handed to FRL_PLL); 0 on time-out
 * Name basis: derived - prints 'Payload Cnt' and 'u32payload_delay abnormal' (a variable name, so the label is
 *   replaced)
 *
 * Matching notes
 * --------------
 * u32payload_delay (leon2s 0xa00967ec-0xa0096a6c, 640 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - K&R parameter definition (the byte parameter is copied raw and masked at each use);
 *  - the register-block pointers are volatile, as in the prototypes of the bit helpers;
 *  - the poll counter is post-incremented inside the loop body;
 *  - the divisions are written '/ 511 >> 6' and '/ 681 >> 6' (a single divisor 32704 is pre-shifted by GCC).
 */

#define HDMI_MSG_MODEDET_FLOW   0x04    /* dbg_hdmi_message_flags bit 2: the "[MODEDET]" lines */

#define MAX_POLLS               10      /* the polled bit must be set within this many polls */
#define FRL_RATE_COUNT          6       /* rows of hdmi_rx21_frl_clocks_mhz, for FRL rates 1..6 */
#define DELAY_LIMIT             100     /* results up to this clear B6_DELAY_BIT, larger ones set it */

/* Block 6 registers (word indexes) and their bits. */
#define B6_REG_48               (0x48 / 4)
#define B6_DELAY_BIT            0x19    /* bit 25: set when the result is above DELAY_LIMIT */
#define B6_REG_48_BIT26         0x1a    /* cleared at the start, set when a result is returned */
#define B6_REG_64               (0x64 / 4)
#define B6_REG_64_BIT0          0       /* set before the wait */
#define B6_REG_64_BIT1          1       /* waited for */
#define B6_PAYLOAD_COUNT        (0x68 / 4)  /* printed >> 8 as "Payload Cnt" */

/* Link-training record of each receiver (0xb0 bytes, hdmi_rx21_lts_records): byte 1 is the FRL rate. */
#define LTS_RECORD_SIZE         0xb0
#define LTS_FRL_RATE            1

/* Register block addresses of one HDMI 2.1 receiver (0x34 bytes, hdmi_rx21_reg_blocks). */
struct rx21_reg_blocks {
    volatile unsigned int *block0;
    unsigned int blocks_1_to_5[5];
    volatile unsigned int *block6;      /* +0x18 */
    unsigned char blocks_7_to_12[0x34 - 0x1c];
};
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern unsigned char hdmi_rx21_two_port_mode_flags[];
extern unsigned char hdmi_rx21_lts_records[];        /* link-training records */
extern unsigned int dbg_hdmi_message_flags;
extern const int hdmi_rx21_frl_clocks_mhz[FRL_RATE_COUNT];
extern void reg_set_bit(unsigned int, volatile unsigned int *);
extern void reg_clear_bit(unsigned int, volatile unsigned int *);
extern unsigned int reg_test_bit(unsigned int, volatile unsigned int *);
extern void timer_delay_long_units(int);
extern void *lib_memcpy(void *, const void *, unsigned int);
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);

/*
 * Count the FRL payload of an HDMI 2.1 receiver and turn the count into the target that
 * DRV_HDMI_ModeDetect_FSM_FRL_Payload hands to FRL_PLL.
 *
 *   port  HDMI 2.1 receiver 0 or 1 (printed as the letter 'A' + port)
 *
 * Returns ((count >> 10) * clock) / 511 >> 6 for FRL rates above 2, the same with 681 for rates 1 and 2,
 * where count is block 6 register 0x68 and clock the FRL rate's entry of hdmi_rx21_frl_clocks_mhz (the rate
 * is not range-checked). Returns 0 when the polled bit stays clear ("u32payload_delay abnormal").
 *
 * Order: B6_DELAY_BIT and bit 26 of block 6 register 0x48 cleared, hdmi_rx21_two_port_mode_flags cleared, bit 12
 * of block 0 word 2 cleared, a pulse on bit 8 of block 0 word 1; then bit 0 of block 6 register 0x64 is set
 * and its bit 1 polled, once per delay. With a result, B6_DELAY_BIT tells whether it is above DELAY_LIMIT,
 * and bit 26 of register 0x48 is set.
 */
unsigned int hdmi_rx21_measure_payload_delay(port)
    unsigned char port;
{
    unsigned int polls;
    unsigned int target;
    unsigned int frl_rate;
    int clocks_mhz[FRL_RATE_COUNT];

    reg_clear_bit(B6_DELAY_BIT, hdmi_rx21_reg_blocks[port].block6 + B6_REG_48);
    reg_clear_bit(B6_REG_48_BIT26, hdmi_rx21_reg_blocks[port].block6 + B6_REG_48);
    hdmi_rx21_two_port_mode_flags[port] = 0;
    reg_clear_bit(0xc, hdmi_rx21_reg_blocks[port].block0 + 2);
    reg_set_bit(8, hdmi_rx21_reg_blocks[port].block0 + 1);
    timer_delay_long_units(1);
    reg_clear_bit(8, hdmi_rx21_reg_blocks[port].block0 + 1);

    /* Wait for bit 1 of register 0x64; a bit seen only on the 11th poll also counts as a failure. */
    polls = 0;
    reg_set_bit(B6_REG_64_BIT0, hdmi_rx21_reg_blocks[port].block6 + B6_REG_64);
    do {
        timer_delay_long_units(1);
        if (polls++ > MAX_POLLS)
            break;
    } while (reg_test_bit(B6_REG_64_BIT1, hdmi_rx21_reg_blocks[port].block6 + B6_REG_64) == 0);
    if (polls > MAX_POLLS) {
        if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
            dbg_print_string("[MODEDET]: u32payload_delay abnormal\n");
        return 0;
    }

    /* Scale the count by the link clock of the FRL rate. */
    lib_memcpy(clocks_mhz, hdmi_rx21_frl_clocks_mhz, sizeof(clocks_mhz));
    if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
        dbg_printf("[MODEDET]: Port%c Payload Cnt 0x%08x\n", (char)(port + 'A'),
                     hdmi_rx21_reg_blocks[port].block6[B6_PAYLOAD_COUNT] >> 8);
    frl_rate = hdmi_rx21_lts_records[port * LTS_RECORD_SIZE + LTS_FRL_RATE];
    if (frl_rate > 2)
        target = ((hdmi_rx21_reg_blocks[port].block6[B6_PAYLOAD_COUNT] >> 10) * clocks_mhz[frl_rate - 1]) / 511 >> 6;
    else
        target = ((hdmi_rx21_reg_blocks[port].block6[B6_PAYLOAD_COUNT] >> 10) * clocks_mhz[frl_rate - 1]) / 681 >> 6;
    if (target <= DELAY_LIMIT)
        reg_clear_bit(B6_DELAY_BIT, hdmi_rx21_reg_blocks[port].block6 + B6_REG_48);
    else
        reg_set_bit(B6_DELAY_BIT, hdmi_rx21_reg_blocks[port].block6 + B6_REG_48);
    reg_set_bit(B6_REG_48_BIT26, hdmi_rx21_reg_blocks[port].block6 + B6_REG_48);
    return target;
}
