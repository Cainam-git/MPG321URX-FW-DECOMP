/* FUN_a014dc28: calls FUN_a0111028(2), then FUN_a0111088(1) when bit 0 of mask is set and FUN_a0111088(2) (tail
 * call) when bit 1 is set. No direct callers were found (the address may be reached through a pointer).
 * The callees take one byte argument here (the firmware sets only %o0 before each call).
 */
extern void FUN_a0111028(unsigned char n);
extern void FUN_a0111088(unsigned char n);

void FUN_a014dc28(unsigned char mask)
{
    FUN_a0111028(2);
    if (mask & 1)
        FUN_a0111088(1);
    if (mask & 2)
        FUN_a0111088(2);
}
