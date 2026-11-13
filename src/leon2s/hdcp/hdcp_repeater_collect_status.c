/* hdcp_repeater_collect_status  (FUN_a00c55c8)
 *
 * Pass the device lists and summed counts of a DisplayPort input's outputs to its receiver.
 * Note: Only outputs whose bit is set in the input's output_bits; summary to registers 0x2AA / 0x2AB and
 *   0x401.
 * Name basis: derived - device entries of each selected output copied to receiver registers 0xE8 and 0x401;
 *   sum, maximum level, overflow flags and the counter written to 0x2AA / 0x2AB / 0x401
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c55c8 @ 0xa00c55c8, flags -mcpu=v8 -Os -g (the section default).
 * Source form: port is an unsigned int indexed as port & 0xff; receiver is an unsigned int (the register
 * helpers mask it); the bit test of the output loop is 'if (((mask >> k) & 1) == 0) continue;'; the counters
 * and flags are unsigned chars declared in the order sum, max_level, count_overflow, level_overflow, flag_0x8,
 * flag_0x7.
 */
/* Protection record of an output (24 bytes); only the bytes this routine uses are named. */
struct hdcp_tx_record {
    unsigned char byte_0x0;
    unsigned char byte_0x1;
    unsigned char byte_0x2;             /* bit 4 tested */
    unsigned char device_count;         /* +3: entries of ENTRY_LENGTH bytes in the engine */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;
    unsigned char byte_0x8;
    unsigned char bytes_9_23[15];
};
/* Protection record of an input (16 bytes); only output_bits is named. */
struct hdcp_rx_record {
    unsigned char bytes_0_3[4];
    unsigned char output_bits;          /* +4: bit n = output n shows this input */
    unsigned char bytes_5_15[11];
};

#define HDCP_TX_OUTPUTS 3
#define FIRST_DP_INPUT  4               /* receiver number = input - 4 */
#define ENTRY_LENGTH    5               /* bytes per downstream device entry */
#define ENGINE_CMD_0B   0xb             /* hdcp_tx_engine_start_command code, here with length 0x4015 */
#define ENGINE_CMD_END  0               /* code 0, length 0: after the entries */

extern struct hdcp_tx_record hdcp_tx_records[];
extern struct hdcp_rx_record hdcp_rx_record_hdmi20[];
extern unsigned int hdcp_repeater_counters[];
extern unsigned char hdcp_repeater_report_flag;
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned char dp_reg_read8(unsigned char, unsigned short);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern unsigned char hdcp_tx_reg_read(unsigned char, unsigned short);

/*
 * Report the devices behind the outputs that show a DisplayPort input to that input's receiver.
 *
 *   port  the DisplayPort input, 4 or 5 (its receiver is port - 4)
 *
 * Called by input_update_port_records for inputs 4 and 5 when the input is shown on an output and its record
 * bit downstream_reported is clear; that routine sets the bit afterwards. The HDMI inputs get
 * hdcp_repeater_report_downstream, which does the same on other registers.
 *
 * Phases, in order:
 *   1. hdcp_repeater_report_flag = 1. Bit 4 of register 0x40E is set and polled until it reads clear; then
 *      0xB to 0x400, 0x15 to 0x403, 0x40 to 0x402 and 0xF to 0xE9, polled until the low nibble of 0xE9 reads
 *      0. Both polls have no limit.
 *   2. For each output whose bit is set in the input's output_bits: the engine of the output is started with
 *      code 0xB, length 0x4015, its device_count * 5 bytes are read from register 1 of its protection block
 *      and each is written to registers 0xE8 and 0x401, and the command is ended. Unlike the HDMI report,
 *      an overflow seen so far does not stop the copying. Totals: device_count summed, level as maximum,
 *      the flags of bytes +5, +6, +7 and +8 ORed (flag_0x7 also set when bit 4 of byte +2 is set).
 *   3. With bit 7 of register 0x30 set around the two writes: register 0x2AA = count_overflow << 7 | sum
 *      (count_overflow is also set first when bit 7 of the sum is set) and 0x2AB = level_overflow << 3 |
 *      maximum level.
 *   4. The five summary bytes, written twice to register 0x401, the first time followed by 0x80:
 *        byte 0  maximum level << 1 | bit 4 of the sum
 *        byte 1  (sum & 0xF) << 4 | count_overflow << 3 | level_overflow << 2 | flag_0x8 << 1 | flag_0x7
 *        bytes 2..4  hdcp_repeater_counters[port], bits 16..23, 8..15, 0..7
 *      For these bytes count_overflow is also set when the sum passes 0x1F and level_overflow when the maximum
 *      level passes 4. Before the second copy 0xB is written to 0x400, 0 to 0x403 and 0x80 to 0x402.
 *   5. The counter is incremented and hdcp_repeater_report_flag cleared.
 */
void hdcp_repeater_collect_status(unsigned int port)
{
    unsigned int receiver = port - FIRST_DP_INPUT;
    unsigned char sum = 0;
    unsigned char max_level = 0;
    unsigned char count_overflow = 0;
    unsigned char level_overflow = 0;
    unsigned char flag_0x8 = 0;
    unsigned char flag_0x7 = 0;
    unsigned char output;
    unsigned char i;
    unsigned char value;
    unsigned char summary_0;
    unsigned char summary_1;

    hdcp_repeater_report_flag = 1;
    dp_reg_update_bits(receiver, 0x40e, 0x10, 1);
    while (dp_reg_read8(receiver, 0x40e) & 0x10)
        ;
    dp_reg_write8(receiver, 0x400, 0xb);
    dp_reg_write8(receiver, 0x403, 0x15);
    dp_reg_write8(receiver, 0x402, 0x40);
    dp_reg_write8(receiver, 0xe9, 0xf);
    while (dp_reg_read8(receiver, 0xe9) & 0xf)
        ;
    for (output = 0; output < HDCP_TX_OUTPUTS; output++) {
        if (((hdcp_rx_record_hdmi20[port & 0xff].output_bits >> output) & 1) == 0)
            continue;
        hdcp_tx_engine_start_command(output, ENGINE_CMD_0B, 0x4015);
        for (i = 0; i < hdcp_tx_records[output].device_count * ENTRY_LENGTH; i++) {
            value = hdcp_tx_reg_read(output, 1);
            dp_reg_write8(receiver, 0xe8, value);
            dp_reg_write8(receiver, 0x401, value);
        }
        hdcp_tx_engine_start_command(output, ENGINE_CMD_END, 0);
        sum += hdcp_tx_records[output].device_count;
        count_overflow |= hdcp_tx_records[output].count_overflow;
        if (hdcp_tx_records[output].level > max_level)
            max_level = hdcp_tx_records[output].level;
        level_overflow |= hdcp_tx_records[output].level_overflow;
        flag_0x8 |= hdcp_tx_records[output].byte_0x8;
        flag_0x7 |= hdcp_tx_records[output].byte_0x7;
        if (hdcp_tx_records[output].byte_0x2 & 0x10)
            flag_0x7 = 1;
    }
    if (sum & 0x80)
        count_overflow = 1;
    dp_reg_update_bits(receiver, 0x30, 0x80, 1);
    dp_reg_write8(receiver, 0x2aa, (count_overflow << 7) | sum);
    dp_reg_write8(receiver, 0x2ab, (level_overflow << 3) | max_level);
    dp_reg_update_bits(receiver, 0x30, 0x80, 0);
    if (sum > 0x1f)
        count_overflow = 1;
    if (max_level > 4)
        level_overflow = 1;
    summary_0 = (max_level * 2) | ((sum & 0x10) >> 4);
    dp_reg_write8(receiver, 0x401, summary_0);
    summary_1 = ((sum & 0xf) << 4) | (count_overflow << 3) | (level_overflow << 2) | (flag_0x8 * 2) | flag_0x7;
    dp_reg_write8(receiver, 0x401, summary_1);
    dp_reg_write8(receiver, 0x401, hdcp_repeater_counters[port & 0xff] >> 16);
    dp_reg_write8(receiver, 0x401, hdcp_repeater_counters[port & 0xff] >> 8);
    dp_reg_write8(receiver, 0x401, hdcp_repeater_counters[port & 0xff]);
    dp_reg_write8(receiver, 0x401, 0x80);
    dp_reg_write8(receiver, 0x400, 0xb);
    dp_reg_write8(receiver, 0x403, 0);
    dp_reg_write8(receiver, 0x402, 0x80);
    dp_reg_write8(receiver, 0x401, summary_0);
    dp_reg_write8(receiver, 0x401, summary_1);
    dp_reg_write8(receiver, 0x401, hdcp_repeater_counters[port & 0xff] >> 16);
    dp_reg_write8(receiver, 0x401, hdcp_repeater_counters[port & 0xff] >> 8);
    dp_reg_write8(receiver, 0x401, hdcp_repeater_counters[port & 0xff]);
    hdcp_repeater_counters[port & 0xff]++;
    hdcp_repeater_report_flag = 0;
}
