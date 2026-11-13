/* hdmi_tx_set_packet_switch  (FUN_a00a89c0)
 *
 * Program one packet-forwarding group of an HDMI output for its input type.
 *   group: group 0..2
 *   input_code
 *   port: HDMI TX port
 *   value
 *   reg59_bit: flag
 *   group_bit: flag
 * Returns: 1 when done
 * Name basis: derived - groups 0..2 via hdmi_tx_select_packet_source and hdmi_tx_sys_reg_update_bits
 *   (registers 0x50..0x59)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a89c0 @ 0xa00a89c0-0xa00a8cac (187 words), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - a switch on the group, with the input-code range test written (unsigned char)(code - 0x31) > 0x50 in
 *    groups 0 and 1;
 *  - ctrl_bit30 is read through a bit-field of the channel record;
 *  - the compared bits of register 0x33 go into an unsigned char local first and stand on the right of the
 *    compare.
 */

/* Packet groups of an HDMI output, in the order hdmi_tx_run_step and HDMITX_PacketSwitch_Bypass set them. */
enum {
    PACKET_GROUP_0 = 0,
    PACKET_GROUP_1 = 1,
    PACKET_GROUP_2 = 2
};

/* Input codes. */
#define INPUT_CODE_HDMI20_0  0x31
#define INPUT_CODE_HDMI20_1  0x41
#define INPUT_CODE_HDMI21_0  0x51
#define INPUT_CODE_HDMI21_1  0x61
#define INPUT_CODE_DP_0      0x71
#define INPUT_CODE_DP_1      0x81
#define INPUT_CODE_RANGE     (INPUT_CODE_DP_1 - INPUT_CODE_HDMI20_0)

/* Registers of the port's HDMI transmitter system block (hdmi_tx_sys_reg_bases); SC_MaskSetByte reaches
   the same blocks as list 4, block = port. */
#define REG_LIST_HDMI_TX_SYS 4
#define SYS_REG_50           0x50
#define SYS_REG_54           0x54
#define SYS_REG_55           0x55       /* group 1 value, low byte */
#define SYS_REG_56           0x56       /* group 1 value, high byte */
#define SYS_REG_57           0x57
#define SYS_REG_58           0x58
#define SYS_REG_59           0x59
#define SYS_REG54_PULSE      0x80       /* set and cleared again at once */

/* Bank 0 registers of the transmitter compared when both flags are set. */
#define HDMI_TX_BANK_0       0
#define TX_REG_33            0x33       /* bits 4..5 */
#define TX_REG_3F            0x3f       /* bits 0..1 */

#define HDMI_TX_PORTS        2

/* Word 0 of the 28-byte TX channel record (hdmi_tx_output_records), seen as bit-fields from bit 31 down. */
struct hdmi_tx_channel_record {
    unsigned int ctrl_bit31 : 1;
    unsigned int ctrl_bit30 : 1;
    unsigned int word0_rest : 30;
    unsigned int words[6];
};
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern unsigned int hdmi_tx_select_packet_source(unsigned char, unsigned char, unsigned char);
extern void hdmi_tx_sys_reg_update_bits(unsigned char, unsigned char, unsigned char, unsigned char);
extern void SC_MaskSetByte(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern unsigned int hdmi_tx_reg_read8(unsigned char, unsigned short, unsigned short);

/*
 * Set packet group `group` (0..2) of HDMI output `port` for the input `input_code`. The register writes made
 * here go to the port's transmitter system block; hdmi_tx_sys_reg_update_bits sets the masked bits when its
 * last argument is 1 and clears them for any other value.
 *
 *   value      group 1 only: written to registers 0x55 (low byte) and 0x56 (high byte)
 *   reg59_bit  group 0: register 0x59 bit 2; group 1: register 0x59 bit 4; group 2: see below
 *   group_bit  group 0: register 0x50 bit 0; group 1: register 0x54 bits 0..2; group 2: see below
 *
 * Callers: hdmi_tx_run_step (step PACKETS_OWN_AVI) and HDMITX_PacketSwitch_Bypass, both with groups 0, 1, 2
 * in turn and group 1 with value 0x27 (hdmi_tx_run_step may then set group 0 once more for a DP input).
 *
 * In order:
 *   1. hdmi_tx_select_packet_source writes the source number of the input code into the group's packet
 *      source register for this port; its result is the first answer.
 *   2. Group 0 and group 1 write their bits as listed above (group 1 then pulses bit 7 of register 0x54);
 *      an input code outside 0x31..0x81 fails.
 *      Group 2 sets registers 0x57 / 0x58 / 0x59 bit 1 by input type: HDMI inputs 0xA (ctrl_bit30 of the
 *      channel record set) or 0xB / bits 0..4 = 0 / clear; DP inputs 4 / bits 0..4 = 0x10 / set; any other
 *      code fails. Then bits 0 and 3 of register 0x59 are set when reg59_bit << 3 | group_bit equals 1
 *      (reg59_bit 0 and group_bit 1) and cleared otherwise.
 *      Any other group fails.
 *   3. With both flags set, it fails unless bits 4..5 of bank 0 register 0x33 equal bits 0..1 of bank 0
 *      register 0x3F.
 *   4. A port above 1 fails (after all writes).
 *
 * Returns 1 when done, 0 when any check failed.
 */
unsigned char hdmi_tx_set_packet_switch(unsigned char group, unsigned char input_code, unsigned char port,
                           unsigned short value, unsigned char reg59_bit, unsigned char group_bit)
{
    unsigned char ok;
    unsigned char reg33_bits;

    ok = hdmi_tx_select_packet_source(group, input_code, port) & 1;
    switch (group) {
    case PACKET_GROUP_0:
        hdmi_tx_sys_reg_update_bits(port, SYS_REG_59, 4, reg59_bit);
        hdmi_tx_sys_reg_update_bits(port, SYS_REG_50, 1, group_bit);
        if ((unsigned char)(input_code - INPUT_CODE_HDMI20_0) > INPUT_CODE_RANGE)
            ok = 0;
        break;
    case PACKET_GROUP_1:
        SC_MaskSetByte(REG_LIST_HDMI_TX_SYS, port, SYS_REG_55, 0xff, value);
        SC_MaskSetByte(REG_LIST_HDMI_TX_SYS, port, SYS_REG_56, 0xff, value >> 8);
        hdmi_tx_sys_reg_update_bits(port, SYS_REG_59, 0x10, reg59_bit);
        hdmi_tx_sys_reg_update_bits(port, SYS_REG_54, 7, group_bit);
        hdmi_tx_sys_reg_update_bits(port, SYS_REG_54, SYS_REG54_PULSE, 1);
        hdmi_tx_sys_reg_update_bits(port, SYS_REG_54, SYS_REG54_PULSE, 0);
        if ((unsigned char)(input_code - INPUT_CODE_HDMI20_0) > INPUT_CODE_RANGE)
            ok = 0;
        break;
    case PACKET_GROUP_2:
        if (input_code == INPUT_CODE_HDMI20_0 || input_code == INPUT_CODE_HDMI20_1 ||
            input_code == INPUT_CODE_HDMI21_0 || input_code == INPUT_CODE_HDMI21_1) {
            if (hdmi_tx_output_records[port].ctrl_bit30)
                SC_MaskSetByte(REG_LIST_HDMI_TX_SYS, port, SYS_REG_57, 0xff, 0xa);
            else
                SC_MaskSetByte(REG_LIST_HDMI_TX_SYS, port, SYS_REG_57, 0xff, 0xb);
            SC_MaskSetByte(REG_LIST_HDMI_TX_SYS, port, SYS_REG_58, 0x1f, 0);
            hdmi_tx_sys_reg_update_bits(port, SYS_REG_59, 2, 0);
        } else if (input_code == INPUT_CODE_DP_0 || input_code == INPUT_CODE_DP_1) {
            SC_MaskSetByte(REG_LIST_HDMI_TX_SYS, port, SYS_REG_57, 0xff, 4);
            SC_MaskSetByte(REG_LIST_HDMI_TX_SYS, port, SYS_REG_58, 0x1f, 0x10);
            hdmi_tx_sys_reg_update_bits(port, SYS_REG_59, 2, 1);
        } else
            ok = 0;
        hdmi_tx_sys_reg_update_bits(port, SYS_REG_59, 9, (reg59_bit << 3) | group_bit);
        break;
    default:
        ok = 0;
        break;
    }
    if (group_bit & reg59_bit) {
        reg33_bits = hdmi_tx_reg_read8(port, HDMI_TX_BANK_0, TX_REG_33) >> 4 & 3;
        if ((hdmi_tx_reg_read8(port, HDMI_TX_BANK_0, TX_REG_3F) & 3) != reg33_bits)
            ok = 0;
    }
    if (port >= HDMI_TX_PORTS)
        ok = 0;
    return ok;
}
