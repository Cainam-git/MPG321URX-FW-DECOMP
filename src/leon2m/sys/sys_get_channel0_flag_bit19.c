/* sys_get_channel0_flag_bit19  (FUN_a014e010)
 *
 * Return bit 19 of the flag word at +0x70 of channel record 0.
 * Returns: 0 or 1
 * Name basis: descriptive - plain getter; called from APPGetFRCMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e010 @ 0xa014e010 (-mcpu=v8 -O2 -g, the section default).
 * Source form: the decompiler's type names are kept; the flag word is the label of the word at +0x70 of channel
 * record 0.
 */
typedef unsigned int uint;

#define CHANNEL_FLAG_BIT19 19   /* bit 19 of the flag word at +0x70 of the channel record */
extern unsigned int channel_records_flags;      /* flag word (+0x70) of channel record 0 */

/*
 * Return bit 19 of the flag word of channel 0.
 *
 * Called by APPGetFRCMode, which tests the result for 1 before it compares the refresh rate with the panel row.
 */
uint sys_get_channel0_flag_bit19(void)

{
  return channel_records_flags >> CHANNEL_FLAG_BIT19 & 1;
}
