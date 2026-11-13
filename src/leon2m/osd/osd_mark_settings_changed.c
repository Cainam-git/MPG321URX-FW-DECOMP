/* osd_mark_settings_changed  (FUN_a00b88b8)
 *
 * Request that the changed settings are saved.
 * Note: Sets bit 1 of byte 0xA802B08E (taken by osd_take_settings_changed).
 * Name basis: proven - glossary: bit 1 of 0xA802B08E = settings-changed request; callers are menu choice
 *   handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b88b8 @ 0xa00b88b8 (-mcpu=v8 -O2 -g)
 * Source form: written as 'x = x | 2' with a void return statement.
 */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit 1 of osd_request_bits */

extern unsigned char osd_request_bits;

/* Set the settings-changed request (bit 1 of osd_request_bits); called by the menu choice handlers. */
void osd_mark_settings_changed(void)

{
  osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
  return;
}
