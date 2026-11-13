/* dp_set_dsc_4_slices_option  (FUN_a00b14dc)
 *
 * Store the 'DSC 3440 4 slices' option byte and print it with the port number.
 *   first: number printed after 'L' (the command passes the port)
 *   level: value stored and printed as '4 slices'
 * Note: Reached by mailbox command 0x33, which then runs dp_program_port; that routine writes other values to
 *   DP registers 0x454 and 0x459 when the byte is 1.
 * Name basis: proven - prints 'Model Enable 500 Cut5 L%d DSC 3440 4 slices = %d' with its two arguments; the
 *   second is stored at 0xA8079308
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b14dc @ 0xa00b14dc (-mcpu=v8 -Os -g).
 * Source form: dbg_printf is declared without a prototype; the format text is at DAT_a006c540 and its address
 * is passed.
 */
extern unsigned int DAT_a006c540;
extern unsigned char dp_dsc_4_slices_option;
extern int dbg_printf();

/*
 * Store the second argument in the byte dp_dsc_4_slices_option (0xA8079308), then print both arguments with dbg_printf
 * and the text at 0xA006C540. Mailbox command 0x33 reaches it. dp_program_port compares the byte with 1 to
 * choose the values it writes to DP receiver registers 0x454 and 0x459.
 *   first: first value to print
 *   level: value to store and print
 */
void dp_set_dsc_4_slices_option(unsigned char first, unsigned char level)

{
  dp_dsc_4_slices_option = level;
  dbg_printf(&DAT_a006c540,first,level);
  return;
}
