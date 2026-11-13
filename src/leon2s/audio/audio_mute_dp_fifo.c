/* audio_mute_dp_fifo  (FUN_a008b934)
 *
 * Mute the audio FIFO of a DP receiver and mark it muted.
 *   port: DP receiver 0/1
 * Note: Sets bit 6 and clears bit 4 of DP register 0x50, writes 0xFF to status registers 4 and 3, sets bit n
 *   and clears bit n + 4 of audio_dp_fifo_muted_flag.
 * Name basis: derived - sets reg 0x50 bit 6, clears its bit 4 and the status registers, sets the muted bit
 *   undone by the 'DP fifo mute off' path
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008b934 @ 0xa008b934 (-mcpu=v8 -Os -g).
 * Source form: the port is masked once and used for both shifts; an explicit "& 0x1f" on the shift counts would
 * make the compiler mask again, so it is left out.
 */
extern unsigned char audio_dp_fifo_muted_flag;
extern void dp_reg_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern void dp_status_reg_write8(unsigned int, unsigned int, unsigned int);

/*
 * Mute the audio FIFO of a DP receiver and record it in audio_dp_fifo_muted_flag.
 *   port: DP receiver 0 or 1
 *
 * Sets bit 6 of receiver register 0x50, writes 0xFF to status registers 4 and 3, and clears bit 4 of register
 * 0x50. In the flag byte, bit "port" is set and bit "port + 4" is cleared.
 * audio_unmute_dp_fifo resets the FIFO and clears bit 6 of register 0x50 again.
 */
void audio_mute_dp_fifo(unsigned char port)
{
    unsigned int receiver;

    receiver = port & 0xff;
    dp_reg_update_bits(receiver, 0x50, 0x40, 1);
    dp_status_reg_write8(receiver, 4, 0xff);
    dp_status_reg_write8(receiver, 3, 0xff);
    dp_reg_update_bits(receiver, 0x50, 0x10, 0);
    audio_dp_fifo_muted_flag = ((1 << receiver) | audio_dp_fifo_muted_flag) & ~(0x10 << receiver);
}
