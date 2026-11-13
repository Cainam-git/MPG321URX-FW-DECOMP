/* audio_set_unit_frequency  (FUN_a008b53c)
 *
 * Program the frequency word of one audio unit.
 *   unit: audio unit
 *   v: frequency setting
 * Name basis: descriptive - 3-byte value from the argument to unit registers 4..6; mailbox command 0x93
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008b53c @ 0xa008b53c (-mcpu=v8 -Os -g).
 * Source form: audio_reg_write_masked is declared without a prototype and the unused parameters 3 to 6 are
 * kept; the last call passes parameters 5 and 6 on, as the firmware does.
 */
extern void audio_reg_write8();
extern int audio_reg_write_masked();

/*
 * Program the frequency word of one audio unit (mailbox command 0x93).
 *   unit:    audio unit
 *   setting: frequency setting
 *
 * word = ((setting << 17) / 12) << 9. The three bytes of word / 10000 go to registers 4, 5 and 6 of the unit,
 * low byte first. Then bit 2 of register 2 and bit 4 of register 7 are cleared; these are the bits
 * audio_enable_unit_dp and audio_enable_unit_hdmi set and clear.
 * The other four parameters are not used here; the last two are handed on to the final write.
 */
void audio_set_unit_frequency(unsigned char unit, int setting, unsigned int unused_3, unsigned int unused_4,
                 unsigned int extra_5, unsigned int extra_6)

{
  unsigned int word;
  
  word = (unsigned int)(setting << 0x11) / 0xc << 9;
  audio_reg_write8(unit,4,word / 10000 & 0xff);
  audio_reg_write8(unit,5,word / 0x271000 & 0xff);
  audio_reg_write8(unit,6,word / 0x27100000);
  audio_reg_write_masked(unit,2,4,0);
  audio_reg_write_masked(unit,7,0x10,0,extra_5,extra_6);
  return;
}
