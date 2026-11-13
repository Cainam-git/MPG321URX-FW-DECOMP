/* input_set_link_state  (FUN_a006d53c)
 *
 * Set the link state of a port record and clear its retry flag.
 *   record: port record
 *   state: new state
 * Name basis: derived - rec[0] is the state of all three link state machines
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006d53c @ 0xa006d53c, flags -mcpu=v8 -Os -g.
 */

/* Set byte +0 (the link state) of a port record and clear its byte +0x11. */
void input_set_link_state(unsigned char *record, unsigned char state)
{
  *record = state;
  record[0x11] = 0;
}
