/* audio_dp_status_bit6  (FUN_a008b8d4)
 *
 * Return bit 6 of audio status register 4 of a DP receiver.
 *   port: DP receiver 0/1
 * Returns: 0 or 1
 * Name basis: descriptive - single register bit; callers audio_check_dp_fifo_unmute and audio_poll_dp_status
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008b8d4 @ 0xa008b8d4 (-mcpu=v8 -Os -g).
 * Source form: the reader's prototype is unsigned, so the shift is logical.
 */
extern unsigned int dp_status_reg_read8(unsigned int, unsigned short);

/*
 * Return bit 6 of register 4 of the status block of a DP receiver (0 or 1).
 *   port: DP receiver 0 or 1
 * audio_poll_dp_status samples it and then writes 0x40 to the same register.
 */
unsigned char audio_dp_status_bit6(unsigned int port)

{
  port = port & 0xff;
  return (dp_status_reg_read8(port,4) >> 6) & 1;
}
