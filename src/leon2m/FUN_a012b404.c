/* FUN_a012b404 (leon2m 0xa012b404-0xa012b418, 20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Calls FUN_a0137cdc(c) with its byte argument as a tail call; the nop after it is the -g line nop. Called by
 * FUN_a013dc6c. It lies between FUN_a012b3f0 and FUN_a012b418. Source form: an unsigned char parameter passed on
 * (and 0xff before the call).
 */
extern void FUN_a0137cdc(unsigned char);

void FUN_a012b404(unsigned char c)
{
    FUN_a0137cdc(c);
}
