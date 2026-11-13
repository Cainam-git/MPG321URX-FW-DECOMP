/* hdmi_rx21_read_vtotal  (FUN_a009c09c)
 *
 * Return the vertical total (lines per frame) of an HDMI 2.1 receiver.
 *   p: HDMI 2.1 receiver 0/1
 * Returns: line count, 1 when unknown
 * Name basis: derived - used as V_TOTAL in hdmi_rx21_detect_timing_change and H_Total prints; taken from block
 *   8 (register 0x58, or a ratio of 0x4C and 0x54) when byte +0x2D of the receiver record is set
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009c09c @ 0xa009c09c-0xa009c188 (-mcpu=v8 -Os -g)
 * Source form: one if with '&&' for the two non-zero tests and a single 'v = 0' else arm; the register words are
 * volatile and read as often as in the firmware (w4c twice).
 */
#define BLOCK0_VTOTAL   0x3c            /* byte offset in block 0 */
#define BLOCK8_REG_4C   0x4c            /* byte offsets in block 8 */
#define BLOCK8_REG_54   0x54
#define BLOCK8_REG_58   0x58
#define RX21_RECORD_CVTEM_PRESENT 0x2d  /* byte of the 400-byte receiver record */

/* One entry of the table at 0xA807DB00 (0x34 bytes per receiver): the addresses of the register blocks. */
struct hdmi_rx21_reg_blocks {
    volatile unsigned int *block0;
    unsigned char pad4[0x1c];
    volatile unsigned int *block8;
    unsigned char rest[0x34 - 0x24];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char hdmi_rx21_input_records[];    /* HDMI 2.1 receiver records */
extern unsigned char hdmi_rx21_two_port_mode_flags[];     /* per receiver, set by FRL_PLL ('2PortMode') */

/*
 * Return the vertical total (lines per frame) of an HDMI 2.1 receiver, or 1 when the value comes out as 0.
 *   p: HDMI 2.1 receiver 0/1
 * When the receiver's record has cvtem_present (byte +0x2D) clear, the value is the low half of the register at
 * block 0 + 0x3C. Otherwise it comes from block 8: the upper half of the register at +0x58 when that is not 0;
 * else d = ((word at +0x54 >> 2) << f) as 16 bits and ((word at +0x4C << f) + d / 2) / d, with f =
 * hdmi_rx21_two_port_mode_flags[p] (0 when either is 0).
 * Called by hdmi_rx21_detect_timing_change and hdmi_rx21_update_mode_info.
 */
unsigned short hdmi_rx21_read_vtotal(unsigned char p)
{
    unsigned short vtotal;
    unsigned short divisor;
    unsigned char shift;
    volatile unsigned int *regs;

    if (hdmi_rx21_input_records[p * 400 + RX21_RECORD_CVTEM_PRESENT]) {
        regs = ARR_a807db00[p].block8;
        if (regs[BLOCK8_REG_58 / 4] >> 16)
            vtotal = regs[BLOCK8_REG_58 / 4] >> 16;
        else {
            shift = hdmi_rx21_two_port_mode_flags[p];
            divisor = (regs[BLOCK8_REG_54 / 4] >> 2) << shift;
            if ((regs[BLOCK8_REG_4C / 4] << shift) != 0 && divisor != 0)
                vtotal = ((regs[BLOCK8_REG_4C / 4] << shift) + (divisor >> 1)) / divisor;
            else
                vtotal = 0;
        }
    } else
        vtotal = ARR_a807db00[p].block0[BLOCK0_VTOTAL / 4];

    if (vtotal == 0)
        return 1;
    return vtotal;
}
