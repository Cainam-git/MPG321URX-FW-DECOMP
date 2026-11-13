/* audio_is_source_selected  (FUN_a008b2bc)
 *
 * Return whether a source number is set in the audio select registers.
 *   source: audio source id (4/6 DP, 8/10 HDMI 2.0, 12/14 HDMI 2.1)
 * Returns: 1 when selected
 * Name basis: descriptive - bits 4..7 of 0xCF011254 / 0xCF011258
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008b2bc @ 0xa008b2bc (-mcpu=v8 -Os -g).
 * Source form: the two registers are volatile word accesses; the field is compared with the masked argument.
 */
#define reg_audio_select_0x1254 (*(volatile unsigned int *)0xcf011254)
#define reg_audio_select_0x1258 (*(volatile unsigned int *)0xcf011258)

/*
 * Tell whether a source id is selected in the audio select registers.
 *   source: audio source id (4 and 6 DP, 8 and 10 HDMI 2.0, 12 and 14 HDMI 2.1); only its low 4 bits count
 * Returns 1 when bits 4..7 of register 0xCF011258 or of register 0xCF011254 equal those 4 bits, else 0.
 */
unsigned int audio_is_source_selected(unsigned int source)

{
  unsigned int selected;
  
  selected = 0;
  if (((reg_audio_select_0x1258 & 0xf0) >> 4 == (source & 0xf)) ||
     ((reg_audio_select_0x1254 & 0xf0) >> 4 == (source & 0xf))) {
    selected = 1;
  }
  return selected;
}
