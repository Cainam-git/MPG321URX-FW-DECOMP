/* leon2m FUN_a00c9e9c @ 0xa00c9e9c-0xa00c9f44 (42 words), flags -mcpu=v8 -O3 -g.
 * Twin of FUN_a00c135c.
 * Code facts: value = byte 0xa802d049 (param 2), 0xa802d0a1 (param 3) or 0xa802d0d9 (other); d = (u8)(value -
 * 0x30); d > 1 -> return 0xff; else bit 15 of the word at 0xa802d290+0x174 = d & 1 (andn 0x8000 / or (d&1)<<15,
 * the shifted value is computed before the test), FUN_a00db690(), FUN_a00b88cc(), FUN_a00baa6c(p),
 * FUN_a00ba950(p), FUN_a00bab80(p, 6) with p = the u8 parameter; return 0.
 * Source form: the record base DAT_a802d290; 'int diff = value - 0x30;' then a separate u8 copy 'd = diff' used
 * for the test and the bit (the fw keeps the 'and 0xff' re-extension of the 3-arm u8 value before the add, then
 * 'and 0xff' for d; a u8 diff folds the first one, a u16 diff gives sll/srl, a signed char value gives sll/sra);
 * u8/void prototypes.
 * Compiler aids: none.
 */
struct R290 { unsigned char pad[0x174]; unsigned int w174; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802d049;
extern unsigned char DAT_a802d0a1;
extern unsigned char DAT_a802d0d9;
extern void FUN_a00db690(void);
extern void FUN_a00b88cc(void);
extern void FUN_a00baa6c(unsigned char);
extern void FUN_a00ba950(unsigned char);
extern void FUN_a00bab80(unsigned char, int);

int FUN_a00c9e9c(unsigned char param_1)
{
  unsigned char value;
  int diff;
  unsigned char d;

  if (param_1 == 2)
    value = DAT_a802d049;
  else if (param_1 == 3)
    value = DAT_a802d0a1;
  else
    value = DAT_a802d0d9;
  diff = value - 0x30;
  d = diff;
  if (d > 1)
    return 0xff;
  DAT_a802d290.w174 = (DAT_a802d290.w174 & ~0x8000) | ((d & 1) << 15);
  FUN_a00db690();
  FUN_a00b88cc();
  FUN_a00baa6c(param_1);
  FUN_a00ba950(param_1);
  FUN_a00bab80(param_1, 6);
  return 0;
}
