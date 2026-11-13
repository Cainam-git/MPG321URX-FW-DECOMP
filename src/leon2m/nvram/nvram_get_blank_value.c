/* nvram_get_blank_value  (FUN_a012ce18)
 *
 * Return 0xFFFF, the value of an unwritten storage cell.
 * Returns: 0xFFFF
 * Name basis: descriptive - constant; used by the defaults writers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012ce18 @ 0xa012ce18-0xa012ce24 (3 words), flags -mcpu=v8 -O2 -g.
 * Leaf. The value goes through an unsigned short local before the return ('unsigned short r; r = 0xffff;
 * return r;'): the firmware builds it as 'sethi %hi(0xffff0000); srl 16', and a plain 'return 0xffff' gives
 * sethi/or 0x3ff instead.
 */
#define BLANK_VALUE 0xffff

/*
 * Return 0xFFFF. The routines that fill the settings records with their defaults store it in the "blank check"
 * halfword (+0x3C) of the settings record, and the start-up check of the stored settings expects to find it
 * there (nvram_load_default_settings_record, nvram_validate_settings_at_startup).
 */
unsigned short nvram_get_blank_value(void)
{
  unsigned short value;

  value = BLANK_VALUE;
  return value;
}
