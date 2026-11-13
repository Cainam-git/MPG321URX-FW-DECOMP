/* hdcp_repeater_report_downstream  (FUN_a00c4e70)
 *
 * Write the summed device counts, flags and report counter of the outputs showing an HDMI input to it.
 * Name basis: derived - sums over every output whose bit is set in the input's output_bits; called for HDMI
 *   inputs 0..3 by input_update_port_records
 *
 * Matching notes
 * --------------
 * FUN_a00c4e70 (leon2s 0xa00c4e70-0xa00c55c8, 1880 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the window index is advanced with 'index++;' statements before
 * each write; the 0x35 value and the summary bytes use (unsigned char)device_total; the register reads are
 * declared with unsigned char results; the list loop bound device_count * 5 is computed in the condition.
 */

/* Protection record of an input (16 bytes; six in a row from hdcp_rx_record_hdmi20). Only output_bits is
   used here. */
struct hdcp_rx_record {
    unsigned char bytes_0_3[4];
    unsigned char output_bits;          /* +4: bit n = output n shows this input */
    unsigned char bytes_5_15[11];
};

/* Protection record of an output (24 bytes, docs/DATA.md). The bytes used here are filled by
   hdcp_tx_hdmi_state_read_repeater_info from the two status bytes it reads, h[0] and h[1], and stepped by
   hdcp_tx_hdmi_state_start_engine. */
struct hdcp_tx_record {
    unsigned char bytes_0_1[2];
    unsigned char byte_0x2;             /* bit 4 tested here */
    unsigned char device_count;         /* +3: h[0] & 0x7F; that many 5-byte entries are read */
    unsigned char level;                /* +4: h[1] & 7; at most 7 */
    unsigned char count_overflow;       /* +5: h[0] bit 7, or set when device_count would pass 0x7F */
    unsigned char level_overflow;       /* +6: h[1] bit 3, or set when level would pass 7 */
    unsigned char byte_0x7;
    unsigned char byte_0x8;
    unsigned char bytes_9_23[15];
};

#define LAST_HDMI20_PORT    1           /* inputs 0, 1: HDMI 2.0 registers 0x305 / 0x310..0x312 */
#define HDCP_TX_OUTPUTS     3
#define ENTRY_LENGTH        5           /* bytes per downstream device entry */
#define ENGINE_CMD_0B       0xb         /* hdcp_tx_engine_start_command code, here with length 0x4005 */
#define ENGINE_CMD_END      0           /* code 0, length 0: after the entries */

extern struct hdcp_rx_record hdcp_rx_record_hdmi20[];
extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned int hdcp_repeater_counters[];
extern unsigned char hdcp_repeater_report_flag;
extern unsigned char hdcp_repeater_device_sum;
extern void hdmi_port_reg_write8(unsigned char, unsigned short, unsigned char);
extern void hdmi_port_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned char hdmi_port_reg_read8(unsigned char, unsigned short);
extern void hdmi_reg_update_bits(unsigned char, unsigned short, unsigned int, unsigned char);
extern unsigned char hdmi_reg_read8(unsigned char, unsigned short);
extern void hdmi_reg_write8(unsigned char, unsigned short, unsigned char);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern unsigned char hdcp_tx_reg_read(unsigned char, unsigned short);

/*
 * Report the devices behind the outputs that show an HDMI input to that input's receiver.
 *
 *   port  the HDMI input, 0..3 (0, 1 HDMI 2.0, 2, 3 HDMI 2.1)
 *
 * Called by input_update_port_records for inputs 0..3 when the input is shown on an output and its record bit
 * downstream_reported is clear; that routine sets the bit afterwards. The DisplayPort inputs get
 * hdcp_repeater_collect_status instead.
 *
 * Phases, in order:
 *   1. Set bit 6 of register 0x88 and bit 4 of 0x37 (cleared again in phase 6), hdcp_repeater_report_flag = 1.
 *   2. Prepare the receiver: HDMI 2.0 sets bit 3 of 0x305 and waits (no limit) until it reads clear, then
 *      0x2E to 0x310 and 5 to 0x311 (bit 7 of 0x310 set around it); HDMI 2.1 sets bit 3 at (0xA6 = 9,
 *      0xA5 = 1), writes 0x21 to 0xA5 until that bit reads clear, then 0x50 to 0xA6 and 0 to 0xA4.
 *   3. For each output whose bit is set in the input's output_bits: while no overflow has been seen, copy the
 *      output's device entries (device_count * 5 bytes from register 1 of its protection block) to register
 *      0x38 and to the list (0x312 on HDMI 2.0, index 5 on through 0xA5 / 0xA7 on HDMI 2.1), and add the
 *      output's values to the totals: device_count summed, level as maximum, the four flags ORed.
 *   4. hdcp_repeater_device_sum = the total; registers 0x2F, 0x30 and 0x33..0x36: total, overflow flags,
 *      maximum level and the number of list bytes (total * 5).
 *   5. The five summary bytes, written twice: after the list (with 0x80 after them) and again from the
 *      start (HDMI 2.0: after 0x2E to 0x310; HDMI 2.1: at indices 0..4, then 0x20 to 0xA4).
 *      byte 0  maximum level << 1 | bit 4 of the total
 *      byte 1  (total & 0xF) << 4 | count_overflow << 3 | level_overflow << 2 | flag_0x8 << 1 | flag_0x7
 *              (flag_0x8 / flag_0x7 = the outputs' byte_0x8 / byte_0x7 ORed; flag_0x7 also when byte_0x2 bit 4)
 *      bytes 2..4  the input's counter hdcp_repeater_counters[port], bits 16..23, 8..15, 0..7
 *      For these bytes the overflow flags are also set when the total passes 0x1F or the level passes 4.
 *   6. Count the report in hdcp_repeater_counters[port]; clear bit 4 of 0x37 and bit 6 of 0x88.
 */
void hdcp_repeater_report_downstream(unsigned char port)
{
    unsigned char output, index, max_level, count_overflow, level_overflow, flag_0x8, flag_0x7, value;
    unsigned short device_total, n;

    /* 1. */
    hdmi_port_reg_update_bits(port, 0x88, 0x40, 1);
    hdmi_port_reg_update_bits(port, 0x37, 0x10, 1);
    hdcp_repeater_report_flag = 1;
    index = 0;
    device_total = 0;
    max_level = 0;
    count_overflow = 0;
    level_overflow = 0;
    flag_0x8 = 0;
    flag_0x7 = 0;
    /* 2. */
    if (port <= LAST_HDMI20_PORT) {
        hdmi_reg_update_bits(port, 0x305, 8, 1);
        while (hdmi_reg_read8(port, 0x305) & 8)
            ;
    } else {
        hdmi_port_reg_write8(port, 0xa6, 9);
        hdmi_port_reg_write8(port, 0xa4, 0);
        hdmi_port_reg_write8(port, 0xa5, 1);
        hdmi_port_reg_update_bits(port, 0xa7, 8, 1);
        do
            hdmi_port_reg_write8(port, 0xa5, 0x21);
        while (hdmi_port_reg_read8(port, 0xa7) & 8);
    }
    if (port <= LAST_HDMI20_PORT) {
        hdmi_reg_write8(port, 0x310, 0x2e);
        hdmi_reg_update_bits(port, 0x310, 0x80, 1);
        hdmi_reg_write8(port, 0x311, 5);
        hdmi_reg_update_bits(port, 0x310, 0x80, 0);
    } else {
        hdmi_port_reg_write8(port, 0xa6, 0x50);
        hdmi_port_reg_write8(port, 0xa4, 0);
    }
    /* 3. The outputs that show this input. */
    for (output = 0; output < HDCP_TX_OUTPUTS; output++) {
        if ((hdcp_rx_record_hdmi20[port].output_bits >> output) & 1) {
            if (hdcp_tx_records[output].count_overflow != 0)
                count_overflow = 1;
            if (hdcp_tx_records[output].level_overflow != 0)
                level_overflow = 1;
            /* Once an overflow is set, by this output or an earlier one, no more entries are copied. */
            if (count_overflow == 0 && level_overflow == 0) {
                hdcp_tx_engine_start_command(output, ENGINE_CMD_0B, 0x4005);
                for (n = 0; n < hdcp_tx_records[output].device_count * ENTRY_LENGTH; n++) {
                    value = hdcp_tx_reg_read(output, 1);
                    hdmi_port_reg_write8(port, 0x38, value);
                    if (port <= LAST_HDMI20_PORT) {
                        hdmi_port_reg_write8(port, 0x312, value);
                    } else {
                        index = n + 5;
                        hdmi_port_reg_write8(port, 0xa5, index);
                        hdmi_port_reg_write8(port, 0xa7, value);
                    }
                }
                hdcp_tx_engine_start_command(output, ENGINE_CMD_END, 0);
                device_total += hdcp_tx_records[output].device_count;
                count_overflow |= hdcp_tx_records[output].count_overflow;
                if (hdcp_tx_records[output].level > max_level)
                    max_level = hdcp_tx_records[output].level;
                level_overflow |= hdcp_tx_records[output].level_overflow;
                flag_0x8 |= hdcp_tx_records[output].byte_0x8;
                flag_0x7 |= hdcp_tx_records[output].byte_0x7;
                if (hdcp_tx_records[output].byte_0x2 & 0x10)
                    flag_0x7 = 1;
            }
        }
    }
    /* 4. The totals. */
    hdcp_repeater_device_sum = device_total;
    if (device_total > 0x7f)
        count_overflow = 1;
    hdmi_port_reg_write8(port, 0x2f, (count_overflow << 7) | device_total);
    hdmi_port_reg_write8(port, 0x30, (level_overflow << 3) | max_level);
    hdmi_port_reg_write8(port, 0x33, 0);
    hdmi_port_reg_write8(port, 0x34, 0);
    hdmi_port_reg_write8(port, 0x35, (unsigned char)device_total * 5);
    hdmi_port_reg_write8(port, 0x36, (device_total * 5) >> 8);
    /* 5. The summary bytes, with the second pair of limits. */
    if (device_total > 0x1f)
        count_overflow = 1;
    if (max_level > 4)
        level_overflow = 1;
    if (port <= LAST_HDMI20_PORT) {
        hdmi_port_reg_write8(port, 0x312, (max_level << 1) | (((unsigned char)device_total & 0x10) >> 4));
        hdmi_port_reg_write8(port, 0x312, (((unsigned char)device_total & 0xf) << 4) | (count_overflow << 3) | (level_overflow << 2) | (flag_0x8 << 1) | flag_0x7);
        hdmi_port_reg_write8(port, 0x312, hdcp_repeater_counters[port] >> 16);
        hdmi_port_reg_write8(port, 0x312, hdcp_repeater_counters[port] >> 8);
        hdmi_port_reg_write8(port, 0x312, hdcp_repeater_counters[port]);
        hdmi_port_reg_write8(port, 0x312, 0x80);
        hdmi_port_reg_write8(port, 0x310, 0x2e);
        hdmi_port_reg_write8(port, 0x312, (max_level << 1) | (((unsigned char)device_total & 0x10) >> 4));
        hdmi_port_reg_write8(port, 0x312, (((unsigned char)device_total & 0xf) << 4) | (count_overflow << 3) | (level_overflow << 2) | (flag_0x8 << 1) | flag_0x7);
        hdmi_port_reg_write8(port, 0x312, hdcp_repeater_counters[port] >> 16);
        hdmi_port_reg_write8(port, 0x312, hdcp_repeater_counters[port] >> 8);
        hdmi_port_reg_write8(port, 0x312, hdcp_repeater_counters[port]);
    } else {
        /* After the list: indices index + 1 .. index + 5, and 0x80 at index + 6 (index is 0 when no entry
           was copied). */
        index++;
        hdmi_port_reg_write8(port, 0xa5, index);
        hdmi_port_reg_write8(port, 0xa7, (max_level << 1) | (((unsigned char)device_total & 0x10) >> 4));
        index++;
        hdmi_port_reg_write8(port, 0xa5, index);
        hdmi_port_reg_write8(port, 0xa7, (((unsigned char)device_total & 0xf) << 4) | (count_overflow << 3) | (level_overflow << 2) | (flag_0x8 << 1) | flag_0x7);
        index++;
        hdmi_port_reg_write8(port, 0xa5, index);
        hdmi_port_reg_write8(port, 0xa7, hdcp_repeater_counters[port] >> 16);
        index++;
        hdmi_port_reg_write8(port, 0xa5, index);
        hdmi_port_reg_write8(port, 0xa7, hdcp_repeater_counters[port] >> 8);
        index++;
        hdmi_port_reg_write8(port, 0xa5, index);
        hdmi_port_reg_write8(port, 0xa7, hdcp_repeater_counters[port]);
        index++;
        hdmi_port_reg_write8(port, 0xa5, index);
        hdmi_port_reg_write8(port, 0xa7, 0x80);
        /* Again at indices 0..4. */
        hdmi_port_reg_write8(port, 0xa5, 0);
        hdmi_port_reg_write8(port, 0xa7, (max_level << 1) | (((unsigned char)device_total & 0x10) >> 4));
        hdmi_port_reg_write8(port, 0xa5, 1);
        hdmi_port_reg_write8(port, 0xa7, (((unsigned char)device_total & 0xf) << 4) | (count_overflow << 3) | (level_overflow << 2) | (flag_0x8 << 1) | flag_0x7);
        hdmi_port_reg_write8(port, 0xa5, 2);
        hdmi_port_reg_write8(port, 0xa7, hdcp_repeater_counters[port] >> 16);
        hdmi_port_reg_write8(port, 0xa5, 3);
        hdmi_port_reg_write8(port, 0xa7, hdcp_repeater_counters[port] >> 8);
        hdmi_port_reg_write8(port, 0xa5, 4);
        hdmi_port_reg_write8(port, 0xa7, hdcp_repeater_counters[port]);
        hdmi_port_reg_write8(port, 0xa4, 0x20);
    }
    /* 6. */
    hdcp_repeater_counters[port]++;
    hdmi_port_reg_update_bits(port, 0x37, 0x10, 0);
    hdmi_port_reg_update_bits(port, 0x88, 0x40, 0);
}
