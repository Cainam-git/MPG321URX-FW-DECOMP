/* hdmi_rx21_set_audio_mode_bits  (FUN_a00a2374)
 *
 * Set audio register 9 bits 16 and 18 of an HDMI 2.1 receiver by mode.
 *   port: receiver
 *   mode
 * Name basis: descriptive - mode 0 clears both, 2 sets bit 16 only, others set both; caller audio_configure
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2374, flags -mcpu=v8 -Os -g (section default). Every access indexes the record with (port & 0xff).
 */
/* Register block addresses of an HDMI 2.1 receiver (13 words per receiver, table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks {
    volatile unsigned int *block0;      /* +0 */
    volatile unsigned int *block1;      /* +4: 0xCE009100 (+0x1000 for receiver 1) */
    unsigned char rest[0x34 - 8];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern void reg_set_bit(unsigned int, volatile unsigned int *);
extern void reg_clear_bit(unsigned int, volatile unsigned int *);

/*
 * Set bits 0x10 and 0x12 of word 9 of register block 1 of receiver `port` by `mode`:
 *   mode 0: clear both; mode 2: set 0x10, clear 0x12; any other mode: set both.
 * Called by audio_configure.
 *   port  HDMI 2.1 receiver 0/1
 *   mode  mode
 */
void hdmi_rx21_set_audio_mode_bits(unsigned int port, unsigned char mode)
{
    if (mode == 0) {
        reg_clear_bit(0x10, ARR_a807db00[port & 0xff].block1 + 9);
        reg_clear_bit(0x12, ARR_a807db00[port & 0xff].block1 + 9);
    } else if (mode == 2) {
        reg_set_bit(0x10, ARR_a807db00[port & 0xff].block1 + 9);
        reg_clear_bit(0x12, ARR_a807db00[port & 0xff].block1 + 9);
    } else {
        reg_set_bit(0x10, ARR_a807db00[port & 0xff].block1 + 9);
        reg_set_bit(0x12, ARR_a807db00[port & 0xff].block1 + 9);
    }
}
