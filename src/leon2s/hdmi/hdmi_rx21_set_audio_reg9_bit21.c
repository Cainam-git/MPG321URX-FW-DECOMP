/* hdmi_rx21_set_audio_reg9_bit21  (FUN_a00a2320)
 *
 * Set or clear bit 21 of audio register 9 of an HDMI 2.1 receiver.
 *   port: receiver
 *   on: 1 = set
 * Name basis: descriptive - caller audio_configure
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2320, flags -mcpu=v8 -Os -g (section default; the routine has its own cflags entry with the same
 * flags). Same code as hdmi_rx21_set_audio_mute with other constants.
 */
/* Register block addresses of an HDMI 2.1 receiver (13 words per receiver, table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks {
    unsigned int block0;                /* +0 */
    unsigned char *block1;              /* +4: 0xCE009100 (+0x1000 for receiver 1) */
    unsigned char rest[0x2c];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern void reg_set_bit(int, unsigned char *);
extern void reg_clear_bit(int, unsigned char *);

/*
 * Set (`on` == 1) or clear (any other value) bit 0x15 of the word array at byte offset 0x24 (word 9) of register
 * block 1 of receiver `port`. Called by audio_configure.
 *   port  HDMI 2.1 receiver 0/1
 *   on    1 = set
 */
void hdmi_rx21_set_audio_reg9_bit21(unsigned char port, unsigned char on)
{
  if (on == 1) {
    reg_set_bit(0x15, ARR_a807db00[port].block1 + 0x24);
    return;
  }
  reg_clear_bit(0x15, ARR_a807db00[port].block1 + 0x24);
}
