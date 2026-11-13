/* hdmi_rx21_audio_status_bit1  (FUN_a009c434)
 *
 * Return bit 1 of the audio status register of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: bit value
 * Name basis: descriptive - selects which byte holds the sample-rate code in hdmi_rx21_get_audio_freq_code
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009c434 @ 0xa009c434-0xa009c468 (13 words), flags -mcpu=v8 -Os -g.
 * Source form: the table is a 52-byte struct array; the receiver is an unsigned char.
 */
/* One entry of the table at 0xA807DB00 (0x34 bytes per receiver): the addresses of the register blocks. */
struct hdmi_rx21_reg_blocks { unsigned int block0; unsigned int block1; unsigned char rest[0x2c]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned int reg_test_bit(unsigned int, unsigned int);

/*
 * Return bit 1 of the first register of block 1 of an HDMI 2.1 receiver (1 or 0).
 *   port: HDMI 2.1 receiver 0/1
 * Called by hdmi_rx21_get_audio_freq_code, which reads the sample-rate code from bits 16..19 of that register when
 * this is 1 and from bits 24..27 when it is 0.
 */
int hdmi_rx21_audio_status_bit1(unsigned char port)
{
    return reg_test_bit(1, ARR_a807db00[port].block1) != 0;
}
