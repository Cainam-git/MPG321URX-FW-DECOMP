/* input_update_port_records  (FUN_a00c601c)
 *
 * Update the record and the event bits of all six inputs.
 * Name basis: derived - per input: input_port_raise_event, hdcp_repeater_report_downstream or
 *   hdcp_repeater_collect_status, input_port_handle_reg71_bits or hdcp_rx_dp_poll_v_calculation,
 *   input_port_fix_reg2e
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c601c @ 0xa00c601c-0xa00c6730 (1812 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - word 0 of both records is a union of the word, a big-endian bit-field view (first field = bit 31) and,
 *    for the input record, a byte view; bit 31 of the output record is read as 'word >> 31';
 *  - the three per-output hot-plug tests are a switch of three calls (the compiler merges their common tails);
 *  - separate byte locals for the event bit of the first block (event_bit) and of the second (port_event_bit);
 *  - send_report starts at 0 once before the port loop; the 'output_bits != 0' test before the output loop
 *    and the 'port > LAST_INPUT_PORT' return after it are never true at run time but stay in the source;
 *  - hdmi_port_reg_read8 is declared with an unsigned char result (the callee returns the low byte) and
 *    reg5_value is an unsigned char.
 */

/*
 * Input ports 0..5. Each has a 16-byte copy-protection input record in the table that starts at
 * hdcp_rx_record_hdmi20: ports 0 and 1 are the HDMI 2.0 receivers, ports 2 and 3 the HDMI 2.1 receivers
 * (their records start at 0xA807D5E8) and ports 4 and 5 the DisplayPort inputs (records from 0xA807D608),
 * reached as DisplayPort unit port - 4.
 */
#define LAST_HDMI20_PORT 1
#define LAST_HDMI_PORT   3
#define LAST_INPUT_PORT  5

/* Video outputs 0..2, one 24-byte record each in hdcp_tx_records (the outputs that hdcp_tx_task serves). */
#define LAST_OUTPUT      2

/* Word 0 of an input record, bit 31 first. */
struct hdcp_rx_record_bits {
    unsigned int bits_24_31 : 8;
    unsigned int bit23 : 1;                 /* set by input_port_handle_reg71_bits, hdcp_rx_dp_poll_v_calculation
                                               and hdcp_rx_dp_task; copied to the output records here */
    unsigned int downstream_reported : 1;   /* bit 22: set here once the downstream report has been written
                                               to the input; cleared to have it written again */
    unsigned int bit21 : 1;                 /* copied to bit 20 of the output records */
    unsigned int bits_0_20 : 21;
};
struct hdcp_rx_record_bytes {
    unsigned char byte_0x0;
    unsigned char byte_0x1;
    unsigned char previous_output_bits;     /* output_bits as last handled here */
    unsigned char byte_0x3;                 /* copied to byte +0x14 of output record 2 for ports 4 and 5 */
};
struct hdcp_rx_record {
    union {
        unsigned int word;
        struct hdcp_rx_record_bits bits;
        struct hdcp_rx_record_bytes bytes;
    } u;
    unsigned char output_bits;              /* bit n: output n shows this input (see below) */
    unsigned char _5[7];
    unsigned char byte_0xc;
    unsigned char byte_0xd;
    unsigned char _e[2];
};

/* Word 0 of an output record, bit 31 first. Bit 31 is set by hdcp_tx_init_port_record. */
struct hdcp_tx_record_bits {
    unsigned int bits_24_31 : 8;
    unsigned int bit23 : 1;
    unsigned int bit22 : 1;
    unsigned int bit21 : 1;
    unsigned int bit20 : 1;
    unsigned int bits_0_19 : 20;
};
struct hdcp_tx_record {
    union {
        unsigned int word;
        struct hdcp_tx_record_bits bits;
    } u;
    unsigned char _4[0x10];
    unsigned char byte_0x14;                /* hdcp_tx_init_port_record sets 0x1F */
    unsigned char _15[3];
};

extern struct hdcp_rx_record hdcp_rx_record_hdmi20[];
extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char input_port_event_flags;
extern unsigned char input_get_port_option_level(unsigned char);
extern unsigned char hdmi_tx_get_source_code(unsigned char);
extern unsigned char input_get_port_source_code(unsigned char);
extern int dp_tx_hpd_is_low(unsigned char);
extern unsigned char hdmi_port_reg_read8(unsigned char, unsigned short);
extern void hdmi_port_reg_write8(unsigned char, unsigned short, unsigned char);
extern void hdmi_port_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned char input_port_code_to_index(unsigned char);
extern void input_port_raise_event(unsigned char, unsigned char);
extern unsigned char input_port_get_reg2e_bit5(unsigned char);
extern void hdcp_repeater_report_downstream(unsigned char);
extern void hdcp_repeater_collect_status(unsigned char);
extern void input_port_handle_reg71_bits(unsigned char);
extern void hdcp_rx_dp_poll_v_calculation(unsigned char);
extern void input_port_fix_reg2e(unsigned char);

/*
 * Bring the copy-protection input record of every input port in line with the outputs that show that input,
 * and run the per-pass services of the inputs. Called by input_run_port_services after the copy-protection
 * tasks of the receivers and of the outputs (hdcp_tx_task). It does nothing unless at least one of the outputs
 * 0..2 is enabled (input_get_port_option_level: bit n and bit n + 8 of input_port_option_mask set).
 *
 * For each input port 0..5, in this order:
 *  1. Rebuild output_bits: bit n is set when output n is enabled, its source code converts to this port's
 *     number (input_port_code_to_index) and bit 31 of its output record is set. Outputs 0 and 1 take the
 *     source code from hdmi_tx_get_source_code(0 / 1), output 2 from input_get_port_source_code(0). A
 *     disabled output keeps its bit.
 *  2. No output shows the input: when it had outputs before, input_port_raise_event(port, 0), the
 *     downstream_reported bit is cleared and the change stored. Nothing else is done for this port.
 *  3. The set of outputs changed: the port's bit in input_port_event_flags is set, a fixed register
 *     sequence is written (HDMI ports only), input_port_raise_event(port, 1) when the input had no output
 *     before, downstream_reported is cleared and the change stored.
 *  4. For each output n that shows the input and has bit 31 of its record set:
 *     - the hot-plug test of the output (dp_tx_hpd_is_low 5, 6 and 0 for outputs 0, 1, 2) returning 1
 *       sets the port's event bit and marks the port for step 7;
 *     - bit 23 of the output record clear: downstream_reported is cleared, no report is sent this pass and
 *       the remaining outputs are skipped;
 *     - otherwise bit 22 of the output record = bit 23 of the input record, and when that is set: bit 22
 *       set, byte +0x14 of output record 2 (output 2 only) = byte +3 of the input record (DisplayPort
 *       inputs) or 1 (HDMI inputs), bit 20 of the output record = bit 21 of the input record.
 *  5. Downstream report, when step 4 allows it and it has not been written yet: an HDMI port with bit 5 of
 *     register 0x2E clear gets hdcp_repeater_report_downstream, one with bit 5 set gets input_port_fix_reg2e
 *     instead (and the report waits for a later pass); a DisplayPort input gets hdcp_repeater_collect_status.
 *     downstream_reported is set after either report.
 *  6. Per-pass service once the report is written: input_port_handle_reg71_bits (HDMI) or
 *     hdcp_rx_dp_poll_v_calculation (DisplayPort); every HDMI port then gets input_port_fix_reg2e.
 *  7. A port marked in step 4: downstream_reported is cleared (the report is written again on a later pass)
 *     and a fixed register sequence clears registers 0x2F and 0x30 (HDMI) or 0x2AA and 0x2AB (DisplayPort).
 * The meaning of the registers written here is not shown in the firmware.
 */
void input_update_port_records(void)
{
    unsigned char send_report = 0;  /* cleared in step 4 when an output record has bit 23 clear */
    unsigned char hpd_low_seen;     /* an output that shows this input reported its hot-plug line low */
    unsigned char port, output, port_event_bit, dp_unit, event_bit;
    unsigned char reg5_value;

    if (!input_get_port_option_level(0) && !input_get_port_option_level(1) && !input_get_port_option_level(2))
        return;
    for (port = 0; port <= LAST_INPUT_PORT; port++) {
        /* Step 1: which enabled outputs show this input. */
        if (input_get_port_option_level(0)) {
            if (port == input_port_code_to_index(hdmi_tx_get_source_code(0)) && hdcp_tx_records[0].u.word >> 31)
                hdcp_rx_record_hdmi20[port].output_bits |= 1;
            else
                hdcp_rx_record_hdmi20[port].output_bits &= ~1;
        }
        if (input_get_port_option_level(1)) {
            if (port == input_port_code_to_index(hdmi_tx_get_source_code(1)) && hdcp_tx_records[1].u.word >> 31)
                hdcp_rx_record_hdmi20[port].output_bits |= 2;
            else
                hdcp_rx_record_hdmi20[port].output_bits &= ~2;
        }
        if (input_get_port_option_level(2)) {
            if (port == input_port_code_to_index(input_get_port_source_code(0)) && hdcp_tx_records[2].u.word >> 31)
                hdcp_rx_record_hdmi20[port].output_bits |= 4;
            else
                hdcp_rx_record_hdmi20[port].output_bits &= ~4;
        }

        /* Step 2: no output shows this input. */
        if (hdcp_rx_record_hdmi20[port].output_bits == 0) {
            if (hdcp_rx_record_hdmi20[port].output_bits != hdcp_rx_record_hdmi20[port].u.bytes.previous_output_bits) {
                input_port_raise_event(port, 0);
                hdcp_rx_record_hdmi20[port].u.bits.downstream_reported = 0;
                hdcp_rx_record_hdmi20[port].u.bytes.previous_output_bits = hdcp_rx_record_hdmi20[port].output_bits;
            }
            continue;
        }

        /* Step 3: the set of outputs showing this input changed. */
        if (hdcp_rx_record_hdmi20[port].output_bits != hdcp_rx_record_hdmi20[port].u.bytes.previous_output_bits) {
            /* Event bit of the port: 1 << port, written as 0x10 / 0x20 for ports 4 and 5. */
            event_bit = 1 << port;
            if (port > LAST_HDMI_PORT)
                event_bit = (port == 4) ? 0x10 : 0x20;
            input_port_event_flags |= event_bit;
            if (port <= LAST_HDMI20_PORT) {
                hdmi_port_reg_update_bits(port, 0x305, 7, 1);
            } else if (port <= LAST_HDMI_PORT) {
                hdmi_port_reg_write8(port, 0xa6, 9);
                hdmi_port_reg_write8(port, 0xa4, 0);
                hdmi_port_reg_write8(port, 0xa5, 1);
                hdmi_port_reg_update_bits(port, 0xa7, 4, 1);
                hdmi_port_reg_write8(port, 0xa6, 1);
                hdmi_port_reg_update_bits(port, 0xa7, 3, 1);
            }
            if (hdcp_rx_record_hdmi20[port].u.bytes.previous_output_bits == 0)
                input_port_raise_event(port, 1);
            hdcp_rx_record_hdmi20[port].u.bits.downstream_reported = 0;
            hdcp_rx_record_hdmi20[port].u.bytes.previous_output_bits = hdcp_rx_record_hdmi20[port].output_bits;
        }

        /* Step 4: hot-plug test and record bits of each output that shows this input. */
        hpd_low_seen = 0;
        if (hdcp_rx_record_hdmi20[port].output_bits != 0) {
            port_event_bit = 1 << port;
            send_report = 1;
            if (port > LAST_HDMI_PORT) {
                if (port == 4)
                    port_event_bit = 0x10;
                else
                    port_event_bit = 0x20;
            }
            for (output = 0; output <= LAST_OUTPUT; output++) {
                if ((hdcp_rx_record_hdmi20[port].output_bits >> output) & 1) {
                    if (hdcp_tx_records[output].u.word >> 31) {
                        /* Hot-plug test numbers: 5 for output 0, 6 for output 1, 0 for output 2. */
                        switch (output) {
                        case 0:
                            if (dp_tx_hpd_is_low(5) == 1) {
                                input_port_event_flags |= port_event_bit;
                                hpd_low_seen = 1;
                            }
                            break;
                        case 1:
                            if (dp_tx_hpd_is_low(6) == 1) {
                                input_port_event_flags |= port_event_bit;
                                hpd_low_seen = 1;
                            }
                            break;
                        case 2:
                            if (dp_tx_hpd_is_low(0) == 1) {
                                input_port_event_flags |= port_event_bit;
                                hpd_low_seen = 1;
                            }
                            break;
                        }
                    }
                }
                if ((hdcp_rx_record_hdmi20[port].output_bits >> output) & 1) {
                    if (hdcp_tx_records[output].u.word >> 31) {
                        /* Output record without bit 23: no report this pass, the other outputs are skipped. */
                        if (hdcp_tx_records[output].u.bits.bit23 != 1) {
                            hdcp_rx_record_hdmi20[port].u.bits.downstream_reported = 0;
                            send_report = 0;
                            break;
                        }
                        /* Bit 22 is written twice when bit 23 of the input record is set. */
                        hdcp_tx_records[output].u.bits.bit22 = hdcp_rx_record_hdmi20[port].u.bits.bit23;
                        if (hdcp_rx_record_hdmi20[port].u.bits.bit23) {
                            hdcp_tx_records[output].u.bits.bit22 = 1;
                            if (output == 2) {
                                if (port > LAST_HDMI_PORT)
                                    hdcp_tx_records[output].byte_0x14 = hdcp_rx_record_hdmi20[port].u.bytes.byte_0x3;
                                else
                                    hdcp_tx_records[output].byte_0x14 = 1;
                            }
                            hdcp_tx_records[output].u.bits.bit20 = hdcp_rx_record_hdmi20[port].u.bits.bit21;
                        }
                    }
                }
            }
        }
        if (port > LAST_INPUT_PORT)
            return;

        /* Step 5: write the downstream report to the input once. */
        if (send_report && !hdcp_rx_record_hdmi20[port].u.bits.downstream_reported) {
            if (port <= LAST_HDMI_PORT) {
                if (!input_port_get_reg2e_bit5(port)) {
                    hdcp_repeater_report_downstream(port);
                    hdcp_rx_record_hdmi20[port].u.bits.downstream_reported = 1;
                } else {
                    input_port_fix_reg2e(port);
                }
            } else {
                hdcp_repeater_collect_status(port);
                hdcp_rx_record_hdmi20[port].u.bits.downstream_reported = 1;
            }
        }

        /* Step 6: per-pass service of the input. */
        if (hdcp_rx_record_hdmi20[port].u.bits.downstream_reported) {
            if (port <= LAST_HDMI_PORT)
                input_port_handle_reg71_bits(port);
            else
                hdcp_rx_dp_poll_v_calculation(port);
        }
        if (port <= LAST_HDMI_PORT)
            input_port_fix_reg2e(port);

        /* Step 7: an output reported its hot-plug line low. */
        if (hpd_low_seen) {
            hdcp_rx_record_hdmi20[port].u.bits.downstream_reported = 0;
            if (port <= LAST_HDMI_PORT) {
                /* Register 5 gets value | 9 and then its old value, only while bit 4 of register 0x30 is set. */
                if (hdmi_port_reg_read8(port, 0x30) & 0x10) {
                    reg5_value = hdmi_port_reg_read8(port, 5);
                    hdmi_port_reg_write8(port, 5, reg5_value | 9);
                    hdmi_port_reg_write8(port, 5, reg5_value);
                }
                hdmi_port_reg_write8(port, 0x2f, 0);
                hdmi_port_reg_write8(port, 0x30, 0);
            } else {
                /* Registers 0x2AA and 0x2AB are written while bit 7 of register 0x30 is set. */
                dp_unit = port - 4;
                dp_reg_update_bits(dp_unit, 0x30, 0x80, 1);
                dp_reg_write8(dp_unit, 0x2aa, 0);
                dp_reg_write8(dp_unit, 0x2ab, 0);
                dp_reg_update_bits(dp_unit, 0x30, 0x80, 0);
            }
        }
    }
}
