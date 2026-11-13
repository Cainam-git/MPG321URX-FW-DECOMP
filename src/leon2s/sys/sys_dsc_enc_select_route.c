/* sys_dsc_enc_select_route  (FUN_a00dcc80)
 *
 * Select the encoder's route for a case and print its name.
 * Name basis: descriptive - prints one of several ROM texts by case
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00dcc80 @ 0xa00dcc80-0xa00dccd8 (22 words), flags -mcpu=v8 -Os -g.
 * The print is a tail call of func_0xa0f834c4 with the string; each string has its own load of the address, then
 * one shared 'call; restore'.
 */
extern unsigned char dsc_encoder_record_source;
extern void sys_dsc_enc_set_route_bits(unsigned char);
extern void dbg_print_string(char *);

/* Pass the encoder's source (dsc_encoder_record_source: 0, 2 or 3) to sys_dsc_enc_set_route_bits and print
 * its name: "DSC Source: DISP" for 0, "P2" for 2, "P3" for 3; any other value prints a "[WRN] ... NG" line. */
void sys_dsc_enc_select_route(void)
{
  unsigned char source = dsc_encoder_record_source;

  sys_dsc_enc_set_route_bits(source);
  if (source == 0)
    dbg_print_string("DSC Source: DISP \n");
  else if (source == 2)
    dbg_print_string("DSC Source: P2 \n");
  else if (source == 3)
    dbg_print_string("DSC Source: P3 \n");
  else
    dbg_print_string("[WRN] DSC Source: NG!!!! \n");
}
