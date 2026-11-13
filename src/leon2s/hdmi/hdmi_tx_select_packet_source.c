/* hdmi_tx_select_packet_source  (FUN_a00a88b8)
 *
 * Write an input's source number into the packet source field of a packet group and HDMI TX port.
 *   port: packet group 0..2, the index into the two register tables
 *   source: input code
 *   field: HDMI TX port: 0 = bits 0..2 of the first table's register, 1 = bits 0..2 of the second, 2 = bits
 *       4..6 of the second
 * Returns: 1 when the input code and the TX port are valid, else 0
 * Name basis: derived - input codes 0x31/0x41/0x51/0x71/0x81/0x61 -> 0..5 into a 3-bit field of the group's
 *   register (tables 0xA807874C / 0xA8078758); the caller hdmi_tx_set_packet_switch passes (group, input code,
 *   TX port)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a88b8, flags -mcpu=v8 -Os -g.
 * Source form: result `ok` = 1 is cleared in each failing case and returned as ok & 1; the shifted value is
 * truncated to a byte before the AND with 0x70.
 */
extern volatile unsigned int *hdmi_tx_packet_source_regs_first[];
extern volatile unsigned int *hdmi_tx_packet_source_regs_second[];
extern void lib_write_masked_byte(volatile unsigned int *, unsigned int, unsigned int);

#define INPUT_CODE_HDMI20_0 0x31        /* input codes of the sources */
#define INPUT_CODE_HDMI20_1 0x41
#define INPUT_CODE_HDMI21_0 0x51
#define INPUT_CODE_HDMI21_1 0x61
#define INPUT_CODE_DP_0     0x71
#define INPUT_CODE_DP_1     0x81

#define PACKET_SOURCE_FIELD_A 0         /* bits 2..0 of the register in the first table */
#define PACKET_SOURCE_FIELD_B 1         /* bits 2..0 of the register in the second table */
#define PACKET_SOURCE_FIELD_C 2         /* bits 6..4 of the register in the second table */

/*
 * Write the source number of an input into one of three 3-bit fields of a packet group's packet source
 * registers. The numbers are 0 for HDMI 2.0 input 0 (0x31), 1 for HDMI 2.0 input 1 (0x41), 2 for HDMI 2.1
 * input 0 (0x51), 3 for DP input 0 (0x71), 4 for DP input 1 (0x81) and 5 for HDMI 2.1 input 1 (0x61).
 * The only caller, hdmi_tx_set_packet_switch, passes (packet group, input code, HDMI TX port), so:
 *   port:   the packet group 0..2, the index into the two register tables (not an HDMI TX port)
 *   source: input code. Any other code writes 0 and makes the result 0.
 *   field:  the HDMI TX port, which selects the field to write (PACKET_SOURCE_FIELD_*); any other value
 *           writes nothing and makes the result 0
 * Returns 1 when the input code and the field are valid, else 0.
 */
unsigned char hdmi_tx_select_packet_source(unsigned char port, unsigned char source, unsigned char field)
{
    unsigned char ok = 1;
    unsigned char number;

    switch (source) {
    case INPUT_CODE_HDMI20_0: number = 0; break;
    case INPUT_CODE_HDMI20_1: number = 1; break;
    case INPUT_CODE_HDMI21_0: number = 2; break;
    case INPUT_CODE_DP_0: number = 3; break;
    case INPUT_CODE_DP_1: number = 4; break;
    case INPUT_CODE_HDMI21_1: number = 5; break;
    default: number = 0; ok = 0; break;
    }
    switch (field) {
    case PACKET_SOURCE_FIELD_A:
        lib_write_masked_byte(hdmi_tx_packet_source_regs_first[port], 7, number & 7);
        break;
    case PACKET_SOURCE_FIELD_B:
        lib_write_masked_byte(hdmi_tx_packet_source_regs_second[port], 7, number & 7);
        break;
    case PACKET_SOURCE_FIELD_C:
        lib_write_masked_byte(hdmi_tx_packet_source_regs_second[port], 0x70, (unsigned char)(number << 4) & 0x70);
        break;
    default:
        ok = 0;
        break;
    }
    return ok & 1;
}
