/* audio_poll_dp_status  (FUN_a008bc44)
 *
 * Sample the audio status of both DP receivers and return them as two bits.
 * Returns: bit mask
 * Name basis: descriptive - every 50 ticks reads status bit 6 per receiver unless muted; caller
 *   audio_update_units
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008bc44 @ 0xa008bc44-0xa008bd1c (216 bytes), flags -mcpu=v8 -Os -g.
 * Source form: byte 0 of audio_dp_status is read through the inlined static helper byte0(); a direct read of
 * audio_dp_status[0] swaps the registers of the two final loads.
 */
extern unsigned char audio_dp_status[];
extern unsigned int audio_dp_status_ticks[];
extern unsigned int dp_reg_read8(unsigned int param_1, unsigned short param_2);
extern unsigned int timer_get_ticks(void);
extern unsigned char audio_dp_status_bit6(unsigned int);
extern void dp_status_reg_write8(unsigned int, unsigned short, unsigned int);

#define DP_AUDIO_SAMPLE_INTERVAL 50     /* ticks between two samples of one receiver */

static unsigned char byte0(const unsigned char *a)
{
    return a[0];
}

/*
 * Sample bit 6 of status register 4 of both DP receivers and return the two results as bits 0 and 1.
 *
 * For each receiver: while bit 6 of its register 0x50 is set (the bit audio_mute_dp_fifo sets), its entry in
 * audio_dp_status is 0. Otherwise, once more than 50 ticks have passed since the last sample, the entry
 * becomes bit 6 of the receiver's status register 4 (audio_dp_status_bit6) and 0x40 is written to that register.
 * Returns audio_dp_status[0] | audio_dp_status[1] << 1. Called by audio_update_units.
 */
unsigned char audio_poll_dp_status(void)
{
    unsigned char receiver = 0;

    for (receiver = 0; receiver < 2; receiver++) {
        if (!(dp_reg_read8(receiver, 0x50) & 0x40)) {
            if (timer_get_ticks() - audio_dp_status_ticks[receiver] > DP_AUDIO_SAMPLE_INTERVAL) {
                audio_dp_status_ticks[receiver] = timer_get_ticks();
                if (audio_dp_status_bit6(receiver) == 0)
                    audio_dp_status[receiver] = 0;
                else
                    audio_dp_status[receiver] = 1;
                dp_status_reg_write8(receiver, 4, 0x40);
            }
        } else {
            audio_dp_status[receiver] = 0;
        }
    }
    return byte0(audio_dp_status) | audio_dp_status[1] << 1;
}
