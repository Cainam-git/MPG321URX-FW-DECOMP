/* leon2s FUN_a00dbed4 @ 0xa00dbed4  MATCH (-mcpu=v8 -Os -g)
 * Returns at once when DAT_a80787ff == DAT_a80787fe. Otherwise calls FUN_a00db53c when DAT_a807883f != 0, else
 * copies DAT_a80787fe into DAT_a80787ff. The goto form gives the firmware's branch layout: be to the end on
 * equality, bne to the call, and the store in the delay slot of the branch to the end.
 */
extern unsigned char DAT_a80787fe;
extern unsigned char DAT_a80787ff;
extern unsigned char DAT_a807883f;
extern int FUN_a00db53c();

void FUN_a00dbed4(void)
{
  if (DAT_a80787ff == DAT_a80787fe) goto end;
  if (DAT_a807883f != 0) goto call;
  DAT_a80787ff = DAT_a80787fe;
  goto end;
call:
  FUN_a00db53c();
end:
  return;
}
