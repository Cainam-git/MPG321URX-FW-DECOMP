/* hdmi_rx21_frl_rate_is_zero  (FUN_a0098300)
 *
 * Return whether the source requested no FRL rate (TMDS) on an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: 1 when zero
 * Name basis: derived - bits 24..27 of register word 0x90 = FRL rate (printed as 'FRL_Rate' by
 *   hdmi_rx21_update_frl_rate)
 *
 * Matching notes
 * --------------
 * FUN_a0098300 (leon2s, 0xa0098300-0xa0098330, 48 bytes, 12 words, leaf).
 * Flags: -mcpu=v8 -Os -g.
 * The record stride is 0x34 bytes. The register block is volatile (MMIO: the firmware reads the full word with ld and
 * shifts); the RAM table itself is not volatile.
 */
#define B6_LTS_STATUS 0x90              /* byte offset of the link-training status register in block 6 */

/* One entry of the table at 0xA807DB00 (0x34 bytes per receiver): the addresses of the register blocks. */
struct hdmi_rx21_reg_blocks { unsigned char pad[0x18]; volatile unsigned int *block6; unsigned char rest[0x34 - 0x1c]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];

/*
 * Return 1 when bits 24..27 (the FRL rate) of the link-training status register of an HDMI 2.1 receiver (block 6
 * + 0x90) are 0, else 0.
 *   port: HDMI 2.1 receiver 0/1
 * Called by DRV_HDMI21_RXDetect_FSM_LTS_2, DRV_HDMI21_RXDetect_FSM_LTS_3 and audio_calc_hdmi21_sample_rate.
 */
int hdmi_rx21_frl_rate_is_zero(unsigned int port)
{
    unsigned int status = ARR_a807db00[port & 0xff].block6[B6_LTS_STATUS / 4];
    return ((status >> 0x18) & 0xf) == 0;
}
