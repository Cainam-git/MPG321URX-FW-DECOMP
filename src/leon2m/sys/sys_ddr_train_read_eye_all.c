/* sys_ddr_train_read_eye_all  (FUN_a00ea1f0)
 *
 * Run the read window training for a number of data bytes.
 * Name basis: derived - loop over sys_ddr_train_read_eye; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ea1f0 @ 0xa00ea1f0, flags -mcpu=v8 -O2 -g.
 * Source form: byte_count is a signed int (signed compare); the callee is declared without a parameter list.
 */
extern void sys_ddr_train_read_eye();

/*
 * Run sys_ddr_train_read_eye for data bytes 0 .. byte_count - 1 (nothing when byte_count <= 0). The other
 * arguments are passed on unchanged, with the byte number inserted as the fourth argument. Returns `unit`.
 * Nothing in the image calls it.
 */
int sys_ddr_train_read_eye_all(unsigned int unit, unsigned int arg2, unsigned int arg3, unsigned int arg4, int byte_count, unsigned int arg6)
{
  int byte_idx;
  for (byte_idx = 0; byte_idx < byte_count; byte_idx++)
    sys_ddr_train_read_eye(unit, arg2, arg3, byte_idx, arg4, arg6);
  return unit;
}
