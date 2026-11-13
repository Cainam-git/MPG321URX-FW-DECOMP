/* HDMITX_PacketSwitch_Bypass  (HDMITX_PacketSwitch_Bypass)
 *
 * Pass the data packets of an HDMI or DP input straight through to an HDMI output.
 *   port: HDMI TX port
 *   input: input code 0x31..0x81
 * Name basis: proven - original name printed ('HDMITX_PacketSwitch_Bypass HDMI RX in Fail', '... wrong
 *   ucInput')
 *
 * Matching notes
 * --------------
 * HDMITX_PacketSwitch_Bypass (leon2s 0xa00a8cac-0xa00a8ec4, 536 bytes), flags -mcpu=v8 -Os -g (section
 * default). The range ends with the unreachable ret/restore pair after the final tail call.
 * Source forms the exact build depends on:
 *  - input and port are unsigned char copies for the first calls; the two group 2 calls of the DP arm pass the
 *    parameters themselves (the firmware masks them again there);
 *  - the HDMI arm collects failures in an int with |=; the DP arm writes 'ok &= call' for group 1 and
 *    'ok = call & ok' for group 2, each arm of the if holding its complete call.
 */

/* Input codes. */
#define INPUT_CODE_HDMI20_0  0x31
#define INPUT_CODE_HDMI20_1  0x41
#define INPUT_CODE_HDMI21_0  0x51
#define INPUT_CODE_HDMI21_1  0x61
#define INPUT_CODE_DP_0      0x71
#define INPUT_CODE_DP_1      0x81

/* Packet groups of hdmi_tx_set_packet_switch. */
enum {
    PACKET_GROUP_0 = 0,
    PACKET_GROUP_1 = 1,
    PACKET_GROUP_2 = 2
};
#define GROUP1_VALUE 0x27               /* the value both callers give group 1 */

/* The first six bytes of hdmi_tx_packet_state (per_dp_input): three bytes for each DP input. */
struct per_dp_input_bytes { unsigned char byte_0; unsigned char byte_1; unsigned char byte_2; };
extern struct per_dp_input_bytes hdmi_tx_packet_state[];
extern int dbg_printf(const char *, ...);
extern unsigned char hdmi_tx_set_packet_switch(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char,
                                  unsigned char);

/*
 * Set the three packet groups of HDMI output `port` for the input `input` (an input code). Called by
 * hdmi_tx_run_step in step PACKETS_BYPASS.
 *
 * The last two arguments of hdmi_tx_set_packet_switch (reg59_bit, group_bit) by input type:
 *
 *   group   HDMI 2.0 / 2.1 input   DP input (bytes of hdmi_tx_packet_state for that DP input)
 *   0       1, 0                   0, 1
 *   1       0, 1                   1, 1 when byte 0 is non-zero, else 0, 0
 *   2       0, 0                   0, 1 when byte 1 or byte 2 is non-zero, else 0, 0
 *
 * All three groups are always set. When any of them fails, the HDMI or DP failure text is printed; any other
 * input code only prints 'wrong ucInput'. The prints pass 0, not the port.
 */
void HDMITX_PacketSwitch_Bypass(unsigned int port, unsigned int input)
{
    unsigned char input_code = input;
    unsigned char tx_port;
    unsigned char ok = 1;
    unsigned char dp_input;
    unsigned char result;
    int failed;

    switch (input_code) {
    case INPUT_CODE_HDMI20_0:
    case INPUT_CODE_HDMI20_1:
    case INPUT_CODE_HDMI21_0:
    case INPUT_CODE_HDMI21_1:
        tx_port = port;
        failed = hdmi_tx_set_packet_switch(PACKET_GROUP_0, input_code, tx_port, 0, 1, 0) == 0;
        failed |= hdmi_tx_set_packet_switch(PACKET_GROUP_1, input_code, tx_port, GROUP1_VALUE, 0, 1) == 0;
        failed |= hdmi_tx_set_packet_switch(PACKET_GROUP_2, input_code, tx_port, 0, 0, 0) == 0;
        if (failed)
            dbg_printf("HDMITX_PacketSwitch_Bypass HDMI RX in Fail !!! %d\r\n", 0);
        break;
    case INPUT_CODE_DP_0:
    case INPUT_CODE_DP_1:
        tx_port = port;
        result = hdmi_tx_set_packet_switch(PACKET_GROUP_0, input_code, tx_port, 0, 0, 1);
        dp_input = input_code != INPUT_CODE_DP_0;
        ok = result & 1;
        if (hdmi_tx_packet_state[dp_input].byte_0)
            ok &= hdmi_tx_set_packet_switch(PACKET_GROUP_1, input_code, tx_port, GROUP1_VALUE, 1, 1);
        else
            ok &= hdmi_tx_set_packet_switch(PACKET_GROUP_1, input_code, tx_port, GROUP1_VALUE, 0, 0);
        if (hdmi_tx_packet_state[dp_input].byte_2 | hdmi_tx_packet_state[dp_input].byte_1)
            ok = hdmi_tx_set_packet_switch(PACKET_GROUP_2, input, port, 0, 0, 1) & ok;
        else
            ok = hdmi_tx_set_packet_switch(PACKET_GROUP_2, input, port, 0, 0, 0) & ok;
        break;
    default:
        dbg_printf("HDMITX_PacketSwitch_Bypass wrong ucInput !  s%d\r\n", 0);
        break;
    }
    /* ok stays 1 in the HDMI and the default arm. */
    if (!ok)
        dbg_printf("HDMITX_PacketSwitch_Bypass DP RX in Fail !!!  %d\r\n", 0);
}
