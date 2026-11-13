/* hdmi_rx21_read_audio_n  (FUN_a009c558)
 *
 * Return the audio clock value N received by an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: N
 * Name basis: derived - 24-bit value used as N in audio_calc_hdmi21_sample_rate (fs = link clock * N / (128 *
 *   CTS))
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009c558 @ 0xa009c558-0xa009c58c (13 words), flags -mcpu=v8 -Os -g. Leaf.
 * Source form: the register block is read through a volatile pointer (hardware registers); word 2 is loaded first.
 */
/* One entry of the table at 0xA807DB00 (0x34 bytes per receiver): the addresses of the register blocks. */
struct hdmi_rx21_reg_blocks { unsigned int block0; volatile unsigned int *block1; unsigned char pad[0x34 - 8]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];

/*
 * Return the audio clock regeneration value N of an HDMI 2.1 receiver (24 bits): the low byte of the word at
 * block 1 + 8 as bits 16..23, and bits 16..31 of the word at block 1 + 4 as bits 0..15.
 *   port: HDMI 2.1 receiver 0/1
 * Called by hdmi_rx21_read_audio_status.
 */
unsigned int hdmi_rx21_read_audio_n(unsigned char port)
{
    volatile unsigned int *block1 = ARR_a807db00[port].block1;
    unsigned int high_byte = block1[2] & 0xff;

    return high_byte << 16 | block1[1] >> 16;
}
