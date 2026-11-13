/* ipc_api_set_hdr_peak_luminance  (FUN_a014e024)
 *
 * Ask the input processor to store the panel's peak luminance for the HDR handling.
 * Name basis: derived - forwards to the command 0x76 sender on mailbox portal 1; mailbox command 0x76, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e024 @ 0xa014e024 (-mcpu=v8 -O2 -g).
 * Source form: the decompiler's form is kept.
 */
typedef unsigned short undefined2;
extern int ipc_set_hdr_peak_luminance();

/*
 * Forward on to ipc_set_hdr_peak_luminance (mailbox command 0x76).
 *   peak_luminance  the panel's peak luminance, passed on unchanged
 */
void ipc_api_set_hdr_peak_luminance(undefined2 peak_luminance)

{
  ipc_set_hdr_peak_luminance(peak_luminance);
  return;
}
