/* leon2m FUN_a00a285c @ 0xa00a285c-0xa00a2874 (6 words).
 * Returns entry n of the word table at 0x1081f0 (4-byte entries, n taken as 16 bits). One of the
 * six-word table-lookup routines at 0xa00a2afc-0xa00a2e74 and 0xa00a285c-0xa00a28bc (same form as FUN_a00a2c1c). A leaf
 * routine without a register window.
 */
extern const unsigned int DAT_001081f0[];

unsigned int FUN_a00a285c(unsigned short n)
{
    return DAT_001081f0[n];
}
