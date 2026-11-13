/* pq_api_set_fga_selector  (FUN_a0149178)
 *
 * Store the selector for index 0x30, otherwise report an unknown index.
 * Name basis: derived - prints 'SYSAPI_ConfigFGADG : DG Unknow!!!!!' for other indexes; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149178 @ 0xa0149178-0xa0149210 (38 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - a local record {selector, value} on the stack, both defaults set first;
 *  - nested ifs (one if with an && test gives other registers for -1 and the sethi, and swaps the second
 *    xor / subx pair);
 *  - the selector is stored and loaded back from the record before the test.
 */

/* The selector and value chosen for an area code; only the selector is used. */
struct fga_area {
    unsigned char selector;
    unsigned short value;
};
extern unsigned char dbg_is_print_enabled(unsigned int level);
extern int dbg_printf(const char *fmt, ...);
extern void pq_fga_set_selector(unsigned char);

#define FGA_AREA_UNKNOWN   0xff         /* no selector for this code */
#define FGA_AREA_GROUP_1X  0x10         /* high nibble of the codes that are looked at */
#define FGA_AREA_GROUP_3X  0x30
#define FGA_AREA_0X30      0x30         /* the only known code: selector 0 */
#define DBG_SYSAPI         0x40         /* debug class of the SYSAPI 'DG Unknow' messages */

/*
 * Store the FGA selector (device_settings_fga_storage_device, through pq_fga_set_selector) for an area code.
 *
 *   code  only 0x30 is known and gives selector 0; any other code stores nothing and, when debug class
 *         DBG_SYSAPI is switched on, prints "SYSAPI_ConfigFGADG : DG Unknow!!!!!"
 *
 * The value 0x8000 chosen together with selector 0 is not used. Nothing in the firmware calls this routine.
 */
void pq_api_set_fga_selector(unsigned char code)
{
  struct fga_area area;

  area.selector = FGA_AREA_UNKNOWN;
  area.value = 0;
  if ((code & 0xf0) == FGA_AREA_GROUP_1X || (code & 0xf0) == FGA_AREA_GROUP_3X) {
    if (code == FGA_AREA_0X30) {
      area.selector = 0;
      area.value = 0x8000;
    }
  }
  if (area.selector == FGA_AREA_UNKNOWN) {
    if (dbg_is_print_enabled(DBG_SYSAPI))
      dbg_printf("\033[1;31mSYSAPI_ConfigFGADG : DG Unknow!!!!!\r\n\033[m");
  } else {
    pq_fga_set_selector(area.selector);
  }
}
