/* hdcp_tx_hdmi_state_read_repeater_info  (FUN_a00c8c64)
 *
 * State handler: read the repeater's status and its list of downstream devices.
 * Name basis: derived - one state handler of the per-output copy-protection state machine; called from
 *   hdcp_tx_hdmi_run_state; two-byte header, capability check, KSV list; prints
 *
 * Matching notes
 * --------------
 * FUN_a00c8c64 (leon2s, 0xa00c8c64-0xa00c90b4, 1104 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the source_code switch has a case below 0x41 with the default action (0x31 here; any of 0x30..0x39 gives
 *    the same code): the compiler drops its compare, but it makes 0x41 the root of the compare tree as in the
 *    firmware; the 0x51 case sets rx = 0;
 *  - device_count is assigned before the record stores and the record takes it from that variable;
 *  - list_length is an unsigned short computed before the 0x33 write;
 *  - every failure exit has its own 'step_result = STEP_AGAIN; return;' (the compiler merges them);
 *  - an_bytes is 24 bytes (firmware frame layout: an_bytes at %fp-32, status at -40, capabilities at -41);
 *    hdcp_tx_hdmi_generate_an fills the first 8.
 */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_29_31 : 3;
    unsigned int repeater : 1;          /* word 0 bit 28: clear = hdcp_tx_hdmi_state_check_v prints 'not repeater' */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bits_18_22 : 5;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int state : 8;             /* +2: the state hdcp_tx_hdmi_run_state dispatches on */
    unsigned char device_count;         /* +3: status byte 0 & 0x7F */
    unsigned char level;                /* +4: status byte 1 & 7 */
    unsigned char count_overflow;       /* +5: status byte 0 bit 7 */
    unsigned char level_overflow;       /* +6: status byte 1 bit 3 */
    unsigned char bytes_7_23[17];
};

/* TX channel record of one HDMI output (28 bytes each, table at 0xA807D580). */
struct hdmi_tx_channel_record {
    unsigned char byte_0;
    unsigned char source_code;          /* +1: input code of the input that feeds the output */
    unsigned char pad[26];
};

/* Result of a state handler. hdcp_tx_select_next_state picks the next state from it; for this state (0x14):
   STEP_NEXT -> 0x15 (hdcp_tx_hdmi_state_check_v), STEP_OTHER -> 1 with bit23 set, STEP_BACK -> 1,
   STEP_AGAIN -> state kept (hdcp_tx_service_port turns it into STEP_BACK once the time limit of the state,
   5000 for 0x14, has run out). */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};

/* Input codes (byte +1 of the TX channel record). */
enum {
    INPUT_CODE_HDMI20_0 = 0x31,         /* HDMI 2.0 receiver 0 */
    INPUT_CODE_HDMI20_1 = 0x41,         /* HDMI 2.0 receiver 1 */
    INPUT_CODE_HDMI21_0 = 0x51,         /* HDMI 2.1 receiver 0 */
    INPUT_CODE_HDMI21_1 = 0x61          /* HDMI 2.1 receiver 1 */
};

#define BCAPS_BIT5          0x20        /* capability byte: without it the handler stays in this state */
#define STATUS0_COUNT       0x7f        /* status byte 0: number of downstream devices */
#define STATUS0_OVERFLOW    0x80
#define STATUS1_LEVEL       7           /* status byte 1: level */
#define STATUS1_OVERFLOW    8
#define ENTRY_LENGTH        5           /* bytes per downstream device entry */
#define AN_BYTES            8           /* bytes read by hdcp_tx_hdmi_generate_an */

/* Registers of the HDMI 2.0 receiver block (hdmi_reg_*). */
#define RX_REG_STATUS0      0x200       /* the two status bytes, then the 8 bytes from the output */
#define RX_REG_STATUS1      0x201
#define RX_REG_AN           0x202       /* 0x202..0x209 */
#define RX_REG_33           0x33
#define RX_REG_34           0x34
#define RX_REG_LIST_LEN_LO  0x35        /* number of list bytes */
#define RX_REG_LIST_LEN_HI  0x36
#define RX_REG_CONTROL      0x37        /* bit 2 set, bit 0 pulsed; bit 0 reads 1 when the value is ready */

extern struct hdcp_tx_record hdcp_tx_records[];
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern unsigned char hdcp_tx_repeater_v[];
extern unsigned char hdcp_rx_get_port_status_bit(unsigned char);
extern unsigned char hdcp_tx_hdmi_read_bcaps(unsigned char, unsigned char *);
extern unsigned char hdmi_tx_ddc_read_at(unsigned char, unsigned char *);
extern unsigned char hdmi_tx_ddc_reset(unsigned char);
extern void hdcp_tx_hdmi_read_ksv_fifo(unsigned char, unsigned char, unsigned short);
extern void hdcp_tx_hdmi_generate_an(unsigned char, unsigned char *, unsigned char);
extern int dbg_printf(const char *, ...);
extern void hdmi_reg_write8(unsigned char, unsigned short, unsigned char);
extern void hdmi_reg_update_bits(unsigned char, unsigned short, unsigned int, unsigned char);
extern unsigned int hdmi_reg_read8(unsigned char, unsigned short);
extern void timer_delay_long_units(unsigned int);

/*
 * State 0x14 of an HDMI output: read the downstream device's two status bytes and its device list, and let an
 * HDMI 2.0 receiver block compute the 20-byte check value that the next state compares.
 *
 *   port  the HDMI output, 0 or 1
 *
 * Called by hdcp_tx_hdmi_run_state when the output's state is 0x14 (hdcp_tx_select_next_state enters it from
 * state 0x13 when the record's repeater bit is set). It reports through step_result (STEP_*).
 *
 * Phases, in order:
 *   1. step_result = STEP_NEXT; rx = the HDMI 2.0 receiver block used for the computation: 1 when the output
 *      is fed by input code 0x41 or 0x61, else 0.
 *   2. Checks that end in STEP_AGAIN: hdcp_rx_get_port_status_bit(port) set; then (bit23 cleared) the capability
 *      byte (DDC device 0x74, offset 0x40) cannot be read or has bit 5 clear; the two status bytes (offset 0x41)
 *      cannot be read.
 *   3. Status byte 0 bit 7 or status byte 1 bit 3 set: the matching overflow byte = 1, STEP_OTHER.
 *   4. Store device_count (byte 0 & 0x7F), level (byte 1 & 7) and the two overflow bits (both 0 here) in the
 *      record. A DDC master that does not come back idle (hdmi_tx_ddc_reset) gives STEP_AGAIN.
 *   5. hdcp_tx_hdmi_read_ksv_fifo reads device_count * 5 list bytes (offset 0x43) and passes them to register
 *      0x38 of block rx and to the output's engine. With no devices it prints 'get count = 0' and clears the
 *      repeater bit, so hdcp_tx_hdmi_state_check_v then prints 'not repeater' and gives STEP_BACK.
 *   6. Block rx registers: the status bytes to 0x200 / 0x201, the 8 bytes the output holds at its registers
 *      0x15..0x1C (hdcp_tx_hdmi_generate_an with 1 only reads them) to 0x202..0x209, 0 to 0x33 / 0x34 and the
 *      number of list bytes to 0x35 (low) / 0x36 (high).
 *   7. Set bit 2 of register 0x37, pulse bit 0 (clear, wait 10 delay units, set) and wait, with no limit, until
 *      bit 0 reads 1.
 *   8. Copy registers 0x20A..0x21D to hdcp_tx_repeater_v, each group of four in reverse order. Because
 *      hdcp_tx_hdmi_state_check_v reverses the bytes it reads at offset 0x20 the same way, it compares byte k
 *      of the device's value with register 0x20A + k.
 */
void hdcp_tx_hdmi_state_read_repeater_info(unsigned char port)
{
    unsigned char an_bytes[24];
    unsigned char status[2];
    unsigned char capabilities;
    unsigned char rx;
    unsigned char device_count;
    unsigned char i;
    unsigned short list_length;

    /* 1. Default result, and the receiver block that computes the check value. */
    rx = 0;
    hdcp_tx_records[port].step_result = STEP_NEXT;
    switch (hdmi_tx_output_records[port].source_code) {
    case INPUT_CODE_HDMI20_0:
        rx = 0;
        break;
    case INPUT_CODE_HDMI20_1:
        rx = 1;
        break;
    case INPUT_CODE_HDMI21_0:
        rx = 0;
        break;
    case INPUT_CODE_HDMI21_1:
        rx = 1;
        break;
    }
    /* 2. Conditions that keep the output in this state. */
    if (hdcp_rx_get_port_status_bit(port)) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    hdcp_tx_records[port].bit23 = 0;
    if (hdcp_tx_hdmi_read_bcaps(port, &capabilities)) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    if ((capabilities & BCAPS_BIT5) == 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    if (hdmi_tx_ddc_read_at(port, status)) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    /* 3. An overflow bit set by the device: note it and leave by the other way. */
    if (status[0] & STATUS0_OVERFLOW) {
        hdcp_tx_records[port].count_overflow = 1;
        hdcp_tx_records[port].step_result = STEP_OTHER;
        return;
    }
    if (status[1] & STATUS1_OVERFLOW) {
        hdcp_tx_records[port].level_overflow = 1;
        hdcp_tx_records[port].step_result = STEP_OTHER;
        return;
    }
    /* 4. Keep the device's counts; hdcp_repeater_report_downstream sums them later. */
    device_count = status[0] & STATUS0_COUNT;
    hdcp_tx_records[port].device_count = device_count;
    hdcp_tx_records[port].level = status[1] & STATUS1_LEVEL;
    hdcp_tx_records[port].count_overflow = status[0] >> 7;
    hdcp_tx_records[port].level_overflow = (status[1] >> 3) & 1;
    if (hdmi_tx_ddc_reset(port)) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    /* 5. The device list. */
    hdcp_tx_hdmi_read_ksv_fifo(port, rx, device_count * ENTRY_LENGTH);
    if (device_count == 0) {
        dbg_printf("\nget count = 0");
        hdcp_tx_records[port].repeater = 0;
    }
    /* 6. Inputs of the computation in block rx. */
    hdmi_reg_write8(rx, RX_REG_STATUS0, status[0]);
    hdmi_reg_write8(rx, RX_REG_STATUS1, status[1]);
    hdcp_tx_hdmi_generate_an(port, an_bytes, 1);
    for (i = 0; i < AN_BYTES; i++)
        hdmi_reg_write8(rx, i + RX_REG_AN, an_bytes[i]);
    list_length = device_count * ENTRY_LENGTH;
    hdmi_reg_write8(rx, RX_REG_33, 0);
    hdmi_reg_write8(rx, RX_REG_34, 0);
    hdmi_reg_write8(rx, RX_REG_LIST_LEN_LO, list_length & 0xff);
    hdmi_reg_write8(rx, RX_REG_LIST_LEN_HI, list_length >> 8);
    /* 7. Start it and wait for the ready bit. */
    hdmi_reg_update_bits(rx, RX_REG_CONTROL, 4, 1);
    hdmi_reg_update_bits(rx, RX_REG_CONTROL, 1, 0);
    timer_delay_long_units(10);
    hdmi_reg_update_bits(rx, RX_REG_CONTROL, 1, 1);
    while ((hdmi_reg_read8(rx, RX_REG_CONTROL) & 1) == 0)
        ;
    /* 8. The 20-byte result, as five groups of four bytes, each group high register first. */
    hdcp_tx_repeater_v[0] = hdmi_reg_read8(rx, 0x20d);
    hdcp_tx_repeater_v[1] = hdmi_reg_read8(rx, 0x20c);
    hdcp_tx_repeater_v[2] = hdmi_reg_read8(rx, 0x20b);
    hdcp_tx_repeater_v[3] = hdmi_reg_read8(rx, 0x20a);
    hdcp_tx_repeater_v[4] = hdmi_reg_read8(rx, 0x211);
    hdcp_tx_repeater_v[5] = hdmi_reg_read8(rx, 0x210);
    hdcp_tx_repeater_v[6] = hdmi_reg_read8(rx, 0x20f);
    hdcp_tx_repeater_v[7] = hdmi_reg_read8(rx, 0x20e);
    hdcp_tx_repeater_v[8] = hdmi_reg_read8(rx, 0x215);
    hdcp_tx_repeater_v[9] = hdmi_reg_read8(rx, 0x214);
    hdcp_tx_repeater_v[10] = hdmi_reg_read8(rx, 0x213);
    hdcp_tx_repeater_v[11] = hdmi_reg_read8(rx, 0x212);
    hdcp_tx_repeater_v[12] = hdmi_reg_read8(rx, 0x219);
    hdcp_tx_repeater_v[13] = hdmi_reg_read8(rx, 0x218);
    hdcp_tx_repeater_v[14] = hdmi_reg_read8(rx, 0x217);
    hdcp_tx_repeater_v[15] = hdmi_reg_read8(rx, 0x216);
    hdcp_tx_repeater_v[16] = hdmi_reg_read8(rx, 0x21d);
    hdcp_tx_repeater_v[17] = hdmi_reg_read8(rx, 0x21c);
    hdcp_tx_repeater_v[18] = hdmi_reg_read8(rx, 0x21b);
    hdcp_tx_repeater_v[19] = hdmi_reg_read8(rx, 0x21a);
}
