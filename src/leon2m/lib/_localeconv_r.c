/* _localeconv_r  (FUN_a015c1b4)
 *
 * Return the address of the static locale conventions record.
 * Returns: pointer to the lconv record
 * Name basis: proven - returns a fixed data address; called by localeconv
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015c1b4 @ 0xa015c1b4, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept. lconv is the object at address 0x1a84f4 (file offset 0x2b04f4);
 * it is named by its address so that the reference follows when the object moves.
 */
typedef unsigned int undefined4;
extern unsigned char lconv[];

/*
 * Return the address of lconv (0x1A84F4), the locale conventions record. The state record parameter that
 * localeconv passes is not used.
 */
undefined4 _localeconv_r(void)

{
  return lconv;
}
