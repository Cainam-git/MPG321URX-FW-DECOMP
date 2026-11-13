/* hdmi_rx21_read_audio_cts  (FUN_a009c58c)
 *
 * Return the audio clock value CTS received by an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: CTS
 * Name basis: derived - 24-bit value used as CTS in audio_calc_hdmi21_sample_rate
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009c58c @ 0xa009c58c (-mcpu=v8 -Os -g)
 * Source form: the table is indexed as unsigned int elements ([port * 13 + 1]), which gives the smul and the
 * ld [%o0 + 4] of the firmware.
 */
#define RX21_BLOCK_WORDS 13             /* words per receiver in the table of register block addresses */
#define BLOCK1_WORD      1              /* index of block 1 in that entry */
#define BLOCK1_CTS_REG   0xc            /* byte offset of the CTS register in block 1 */

extern unsigned int hdmi_rx21_reg_blocks[];     /* table of register block addresses */

/*
 * Return the audio clock regeneration value CTS of an HDMI 2.1 receiver: the low 24 bits of the word at
 * block 1 + 0xC.
 *   port: HDMI 2.1 receiver 0/1
 * Called by hdmi_rx21_read_audio_status.
 */
unsigned int hdmi_rx21_read_audio_cts(unsigned int port)
{
    return (*(unsigned int *)(hdmi_rx21_reg_blocks[(port & 0xff) * RX21_BLOCK_WORDS + BLOCK1_WORD] + BLOCK1_CTS_REG)) & 0xffffff;
}
