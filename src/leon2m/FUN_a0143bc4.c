/* FUN_a0143bc4 (leon2m, 0xa0143bc4-0xa0143c14, 80 bytes, 20 words).
 * Flags: -mcpu=v8 -O3 -g.
 * Code facts: n = (u8)FUN_a0142218((u8)FUN_a0125198((u8)param_1)); returns 2 when the top nibble of
 * the u16 at DAT_a802e116 + n*0x12 is 5, else 0 (fw: clr/mov 2 then 'and %i0,2,%i0' = the u8
 * return extension narrowed by nonzero-bits).
 * Fixes vs draft: BEHAVIOUR: FUN_a0125198 runs FIRST and its result feeds FUN_a0142218 (the draft
 * called FUN_a0142218() with no argument first and indexed by FUN_a0125198's result); FUN_a0125198
 * takes one argument; no second parameter. Aids: none.
 */
extern unsigned char DAT_a802e116;
extern int FUN_a0125198();
extern int FUN_a0142218();

unsigned int FUN_a0143bc4(unsigned int param_1)
{
  unsigned int uVar1;
  unsigned char uVar2;

  uVar1 = FUN_a0125198(param_1 & 0xff);
  uVar1 = FUN_a0142218(uVar1 & 0xff) & 0xff;
  uVar2 = 0;
  if (*(unsigned short *)(&DAT_a802e116 + (uVar1 & 0xff) * 0x12) >> 0xc == 5) {
    uVar2 = 2;
  }
  return uVar2;
}
