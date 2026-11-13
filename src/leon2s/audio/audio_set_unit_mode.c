/* audio_set_unit_mode  (FUN_a008bd1c)
 *
 * Set the 2-bit mode field of an audio unit.
 *   unit: audio unit
 *   mode: 0..3
 * Name basis: descriptive - bits 0..1 of unit register 2
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008bd1c @ 0xa008bd1c (-mcpu=v8 -Os -g).
 * Source form: audio_reg_read8 and audio_reg_write8 are declared without a prototype and the unused parameters
 * 3 to 6 are kept; the write passes parameters 4 to 6 on, as the firmware does.
 */
extern int audio_reg_write8();
extern int audio_reg_read8();

/*
 * Set bits 0..1 of register 2 of an audio unit to "mode"; the other bits are kept. The mode is not masked, so a
 * value above 3 also sets higher bits.
 *   unit: audio unit
 *   mode: 0..3
 * The other parameters are not used here; the last three are handed on to the write.
 */
void audio_set_unit_mode(unsigned int unit, unsigned int mode, unsigned int unused_3, unsigned int extra_4,
                 unsigned int extra_5, unsigned int extra_6)

{
  unsigned int old;
  
  unit = unit & 0xff;
  old = audio_reg_read8(unit,2);
  audio_reg_write8(unit,2,(mode | old & 0xfffffffc) & 0xff,extra_4,extra_5,extra_6);
  return;
}
