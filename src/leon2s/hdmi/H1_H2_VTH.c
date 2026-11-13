/* H1_H2_VTH  (H1_H2_VTH)
 *
 * Print the debug line '[HDMI21]: H1_H2_VTH' when HDMI 2.1 messages are switched on.
 * Note: Only prints; no register is changed.
 * Name basis: proven - original name printed: '[HDMI21]: H1_H2_VTH'
 *
 * Matching notes
 * --------------
 * leon2s H1_H2_VTH @ 0xa007f798, flags -mcpu=v8 -Os -g.
 * Source form: the routine has no parameter in the firmware (the callers' port argument is not used here).
 */
extern unsigned int dbg_hdmi_message_flags;
extern unsigned int dbg_print_string();

#define HDMI_MSG_HDMI21 0x800   /* dbg_hdmi_message_flags bit 11: the "[HDMI21]" lines */

/*
 * Print the line "[HDMI21]: H1_H2_VTH " (and a carriage return) when the "[HDMI21]" debug messages are on.
 * Nothing else happens; no register is changed.
 */
void H1_H2_VTH(void)

{
  if ((dbg_hdmi_message_flags & HDMI_MSG_HDMI21) != 0) {
    dbg_print_string("[HDMI21]: H1_H2_VTH \015");
    return;
  }
  return;
}
