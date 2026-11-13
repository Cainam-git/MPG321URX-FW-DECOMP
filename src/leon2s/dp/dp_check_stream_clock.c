/* dp_check_stream_clock  (FUN_a00aec50)
 *
 * Arm the stream clock check of a port, or return whether it passes or has timed out.
 * Returns: 1 when a check passes or more than 0x10 ticks went by; 0 otherwise and when arming
 * Name basis: descriptive - 24-bit value against 0x8000 and a register bit, with a time-out
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00aec50 @ 0xa00aec50-0xa00aee08 (-mcpu=v8 -Os -g).
 * Source form: the 0x8000 test reads a copy (measured) of the value taken before the result variable is set
 * to 0, so one clear serves both paths as in the firmware; all exits go through the label out.
 */
#define CHECK_TIMEOUT_TICKS 0x10                /* ticks after which the check passes without the conditions */
#define STREAM_CLOCK_TARGET 0x8000              /* value the shifted counts of registers 0x85..0x87 must reach */

extern unsigned int dp_stream_clock_check_word;
extern unsigned int timer_get_ticks(void);
extern unsigned char dp_get_reg461_bit0(unsigned char);
extern unsigned char dp_reg_read8(unsigned char, unsigned short);
extern unsigned int dp_status_reg_read8(unsigned char, unsigned short);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern void dp_status_reg_write8(unsigned char, unsigned short, unsigned char);

/*
 * Check the stream clock of a DP receiver; called once per round of dp_start_stream.
 *
 * With init set, only arms the check: writes 4 to register 0 of the status block and 8 to register 0x4E0, stores
 * the present tick count in dp_stream_clock_check_word (it is the time stamp for the time-out) and returns 0.
 *
 * Without init it returns 1 when one of these holds, and 0 otherwise:
 *  - more than 0x10 ticks have passed since the stamp (time-out; the registers are written as when arming);
 *  - bit 0 of register 0x461 is set (dp_get_reg461_bit0) and bit 3 of register 0x4E0 is set (then 8 is written
 *    back to 0x4E0);
 *  - bit 0 of register 0x461 is clear, and the 24-bit count of registers 0x85..0x87, shifted right by 3 (bit 4
 *    of register 0xD7) or by 2 (bit 2 of 0xD7) and by 1 more when bit 5 of register 0xD5 is set, is exactly
 *    0x8000 while bit 2 of status register 0 is set (then 4 is written to it).
 * Each time it returns 1 the stamp is renewed.
 *   port: DP receiver
 *   init: 1 = arm the check
 */
unsigned char dp_check_stream_clock(unsigned char port, unsigned char init)
{
  unsigned int value = 0;
  unsigned char late;
  if (init)
  {
    dp_status_reg_write8(port, 0, 4);
    dp_reg_write8(port, 0x4e0, 8);
    dp_stream_clock_check_word = timer_get_ticks();
    goto out;
  }
  late = (timer_get_ticks() - dp_stream_clock_check_word) > CHECK_TIMEOUT_TICKS;
  if (late == 0)
  {
    if (dp_get_reg461_bit0(port))
    {
      if ((dp_reg_read8(port, 0x4e0) & 8) == 0)
      {
        goto out;
      }
      dp_reg_write8(port, 0x4e0, 8);
    }
    else
    {
      value = dp_reg_read8(port, 0x85);
      value <<= 8;
      value |= dp_reg_read8(port, 0x86);
      value <<= 8;
      value |= dp_reg_read8(port, 0x87);
      if (dp_reg_read8(port, 0xd7) & 0x10)
      {
        value >>= 3;
      }
      else
        if (dp_reg_read8(port, 0xd7) & 4)
      {
        value >>= 2;
      }
      if (dp_reg_read8(port, 0xd5) & 0x20)
      {
        value >>= 1;
      }
      {
        unsigned int measured = value;

        value = 0;
        if (measured != STREAM_CLOCK_TARGET || (dp_status_reg_read8(port, 0) & 4) == 0)
          goto out;
      }
      dp_status_reg_write8(port, 0, 4);
    }
    value = 1;
    dp_stream_clock_check_word = timer_get_ticks();
  }
  else
  {
    dp_status_reg_write8(port, 0, 4);
    dp_reg_write8(port, 0x4e0, 8);
    value = 1;
    dp_stream_clock_check_word = timer_get_ticks();
  }
  out:
  return value & 1;

}
