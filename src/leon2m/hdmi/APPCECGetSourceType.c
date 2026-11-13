/* APPCECGetSourceType  (FUN_a0083d80)
 *
 * Identify the connected console from its CEC vendor ID or name.
 * Returns: 0..2 (Play, Nint, XBOX) or 0xFF
 * Note: Returns 0xFF when more than one input is in the layout.
 * Name basis: proven - prints 'APPCECGetSourceType= %x' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0083d80 @ 0xa0083d80, flags -mcpu=v8 -O3 -g.
 * Source form: the flag name_is_play is set in both arms of an if/else, the vendor-ID block stores
 * 'result = 0' again before the 'if (!name_is_play) result = 0xff;' test, and the name search is a separate
 * 'if (result == 0xff)' block.
 */
/* Both tables are compared byte for byte; byte 0 of each block is not looked at. */
extern unsigned char hdmi_cec_vendor_id_bytes[], hdmi_cec_source_name[];
extern unsigned char user_settings_pip_pbp_mode;
extern int dbg_printf(const char *fmt, ...);

#define CONSOLE_COUNT    3                  /* result 0 = Play, 1 = Nint, 2 = XBOX */
#define CONSOLE_UNKNOWN  0xff
#define CONSOLE_PLAY     0                  /* the vendor ID of this row (08 00 46) needs the name "Play" as well */

/*
 * Work out which kind of console is on the CEC link. Returns 0 (Play), 1 (Nint), 2 (XBOX) or 0xFF (none).
 *
 * The result is 0xFF whenever picture mode is not 0 (user_settings_pip_pbp_mode != 0). Otherwise the three
 * vendor ID bytes (bytes 1 to 3 of hdmi_cec_vendor_id_bytes) are looked up first; a match on the first row
 * counts only if the stored name also reads "Play". Without a result from the ID, the four-letter name (bytes 1
 * to 4 of hdmi_cec_source_name) is looked up instead.
 *
 * Called from UserGetCECSourceMode and osd_draw_signal_message. The first line printed is the three vendor ID bytes in decimal.
 */
unsigned char APPCECGetSourceType(void)
{
  unsigned char result = CONSOLE_UNKNOWN;
  unsigned char vendor_ids[CONSOLE_COUNT][3] = { { 0x08, 0x00, 0x46 }, { 0x00, 0x09, 0xbf }, { 0x00, 0x03, 0xff } };
  unsigned char i;
  int name_is_play;

  dbg_printf("%d %d %d --> \r\n", hdmi_cec_vendor_id_bytes[1], hdmi_cec_vendor_id_bytes[2], hdmi_cec_vendor_id_bytes[3]);
  if (user_settings_pip_pbp_mode != 0)
    return CONSOLE_UNKNOWN;

  /* By vendor ID; the last matching row wins. */
  for (i = 0; i < CONSOLE_COUNT; i++)
    if (vendor_ids[i][0] == hdmi_cec_vendor_id_bytes[1] && vendor_ids[i][1] == hdmi_cec_vendor_id_bytes[2] && vendor_ids[i][2] == hdmi_cec_vendor_id_bytes[3])
      result = i;
  if (result == CONSOLE_PLAY) {
    if (hdmi_cec_source_name[1] == 'P' && hdmi_cec_source_name[2] == 'l' && hdmi_cec_source_name[3] == 'a' && hdmi_cec_source_name[4] == 'y')
        name_is_play = 1;
    else
        name_is_play = 0;
    result = CONSOLE_PLAY;
    if (!name_is_play)
      result = CONSOLE_UNKNOWN;
  }

  /* No result from the ID: by name. */
  if (result == CONSOLE_UNKNOWN) {
    unsigned char names[CONSOLE_COUNT][4] = { { 'P', 'l', 'a', 'y' }, { 'N', 'i', 'n', 't' }, { 'X', 'B', 'O', 'X' } };

    result = CONSOLE_UNKNOWN;
    for (i = 0; i < CONSOLE_COUNT; i++)
      if (names[i][0] == hdmi_cec_source_name[1] && names[i][1] == hdmi_cec_source_name[2] && names[i][2] == hdmi_cec_source_name[3]
          && names[i][3] == hdmi_cec_source_name[4])
        result = i;
  }
  dbg_printf("\033[1;31mAPPCECGetSourceType= %x\r\n\033[m", result);

  return result;
}
