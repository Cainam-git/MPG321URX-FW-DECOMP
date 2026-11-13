/* hdmi_rx21_audio_bit17_is_clear  (FUN_a009c3f0)
 *
 * Read bit 17 of the audio status register 50 times; return 1 when the last reading is clear.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: 1 when clear
 * Name basis: descriptive - reads register word 10 fifty times; first field of the audio status block read by
 *   hdmi_rx21_read_audio_status
 *
 * Matching notes
 * --------------
 * FUN_a009c3f0 (leon2s 0xa009c3f0-0xa009c434, 68 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: the register block of the receiver (volatile MMIO) is read through a pointer; the loop variable and the
 * last value are the only locals.
 */
#define AUDIO_BIT17_READS 50            /* the register is read this many times */
#define AUDIO_REG_0x28    10            /* word index of the register in block 1 */

/* One entry of the table at 0xA807DB00 (0x34 bytes per receiver): the addresses of the register blocks. */
struct hdmi_rx21_reg_blocks { unsigned int block0; volatile unsigned int *block1; unsigned char pad[0x34 - 8]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];

/*
 * Read bit 17 of the register at block 1 + 0x28 of an HDMI 2.1 receiver 50 times and return 1 when the last
 * reading was clear, else 0.
 *   port: HDMI 2.1 receiver 0/1
 * Called by hdmi_rx21_read_audio_status, which stores the result as the first field of the audio status block.
 */
unsigned int hdmi_rx21_audio_bit17_is_clear(unsigned char port)
{
    volatile unsigned int *block1 = ARR_a807db00[port].block1;
    unsigned char i;
    unsigned int bit17;

    for (i = 0; i < AUDIO_BIT17_READS; i++)
        bit17 = block1[AUDIO_REG_0x28] & 0x20000;
    return bit17 == 0;
}
