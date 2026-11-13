/* audio_update_dp_32k_mode  (FUN_a008c5d8)
 *
 * Switch an audio unit's 32 kHz setting when the DP sample rate enters or leaves it.
 *   source: source 4 or 6
 *   unit: audio unit
 * Note: The change test uses the window 28000 < rate < 36000, but the setting is then chosen by rate < 36000
 *   alone.
 * Name basis: derived - window 28000 < fs < 36000 from audio_calc_dp_sample_rate for the change test, fs <
 *   36000 for the choice; unit regs 2 bit 3 and 1 bit 6
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008c5d8 @ 0xa008c5d8-0xa008c6f8 (288 bytes, with the ret/restore tail), flags -mcpu=v8 -Os -g.
 * Source form: the comparison result goes through a byte flag "changed" (0, set to 1 when the two tests
 * differ).
 */
/* The 20-byte port record; only the halfword at +0x12 is used here. */
struct port_record {
    unsigned char pad[0x12];
    unsigned short flags;               /* +0x12 */
};
extern struct port_record input_port_records[];
extern unsigned char audio_dp_32k_mode;
extern unsigned int audio_calc_dp_sample_rate(unsigned char);
extern void audio_flag_dp_resync(unsigned char);
extern void audio_reg_write_masked(unsigned char, unsigned short, unsigned char, unsigned char);

#define AUDIO_SRC_DP0 4                 /* audio source ids of the two DP receivers */
#define AUDIO_SRC_DP1 6
#define RATE_32K_LOW  28000             /* Hz; the window around 32 kHz is above this ... */
#define RATE_32K_HIGH 36000             /* ... and below this */

/*
 * Switch the 32 kHz setting of an audio unit when the DP sample rate enters or leaves the window.
 *   source: audio source id, 4 (DP receiver 0) or 6 (DP receiver 1); anything else does nothing
 *   unit:   audio unit whose registers are changed
 *
 * The rate comes from audio_calc_dp_sample_rate. The routine acts when "audio_dp_32k_mode is 1" differs from
 * "rate is above 28000 and below 36000". Then it requests a FIFO resync for the receiver and clears bit 6
 * of the flags of port record "receiver + 4". After that a rate below 36000 sets audio_dp_32k_mode to 1
 * and clears bit 3 of unit register 2 and bit 6 of unit register 1; any other rate clears the byte and sets
 * those two bits. (The second test is only "below 36000", so a rate of 28000 or less takes the first branch.)
 */
void audio_update_dp_32k_mode(unsigned char source, unsigned char unit)
{
    unsigned char receiver;
    unsigned char changed = 0;
    unsigned int rate;

    if (source == AUDIO_SRC_DP0)
        receiver = 0;
    else if (source == AUDIO_SRC_DP1)
        receiver = 1;
    else
        return;
    rate = audio_calc_dp_sample_rate(receiver);
    if ((audio_dp_32k_mode == 1) != (rate > RATE_32K_LOW && rate < RATE_32K_HIGH))
        changed = 1;
    if (changed) {
        audio_flag_dp_resync(receiver);
        input_port_records[receiver + 4].flags &= ~0x40;
        if (rate < RATE_32K_HIGH) {
            audio_dp_32k_mode = 1;
            audio_reg_write_masked(unit, 2, 8, 0);
            audio_reg_write_masked(unit, 1, 0x40, 0);
        } else {
            audio_dp_32k_mode = 0;
            audio_reg_write_masked(unit, 2, 8, 8);
            audio_reg_write_masked(unit, 1, 0x40, 0x40);
        }
    }
}
