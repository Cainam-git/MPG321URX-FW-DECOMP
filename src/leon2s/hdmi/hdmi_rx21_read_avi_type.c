/* hdmi_rx21_read_avi_type  (FUN_a009facc)
 *
 * Return the packet type byte of the AVI InfoFrame area of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: packet type
 * Name basis: derived - low byte of register word 0x10 (byte 0x40); 0x82 = AVI InfoFrame received
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009facc, flags -mcpu=v8 -Os -g (section default).
 * Source form: the block 1 pointer is volatile: the firmware reads the full word with ld + and 0xff; a plain
 * pointer lets gcc narrow it to ldub +0x43 (same convention as src/leon2s/audio/audio_calc_hdmi21_sample_rate.c).
 */
/* Word 0x10 (byte offset 0x40) of register block 1 of an HDMI 2.1 receiver. */
struct hdmi_rx21_block1 {
    unsigned char pad[0x40];
    unsigned int word_0x40;
};

/* Register block addresses of an HDMI 2.1 receiver (13 words per receiver, table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks {
    unsigned int block0;                /* +0 */
    volatile struct hdmi_rx21_block1 *block1;   /* +4: 0xCE009100 (+0x1000 for receiver 1) */
    unsigned char rest[0x2c];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];

/*
 * Return the low byte of the word at byte offset 0x40 of register block 1: the packet type of the AVI InfoFrame
 * area (0x82 when an AVI InfoFrame has been received). Read by the mode-detect state hdmi_rx21_modedet_watch_stable.
 *   port  HDMI 2.1 receiver 0/1
 */
unsigned char hdmi_rx21_read_avi_type(unsigned char port)
{
    return ARR_a807db00[port].block1->word_0x40;
}
