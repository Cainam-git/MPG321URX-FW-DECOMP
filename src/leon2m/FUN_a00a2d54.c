/* leon2m FUN_a00a2d54 @ 0xa00a2d54-0xa00a2d6c (6 words).
 * Returns entry n of the word table at 0x14d1f0 (4-byte entries, n taken as 16 bits). One of the
 * six-word table-lookup routines at 0xa00a2afc-0xa00a2e74 (same form as FUN_a00a2c1c). A leaf routine without a
 * register window.
 */
extern const unsigned int DAT_0014d1f0[];

unsigned int FUN_a00a2d54(unsigned short n)
{
    return DAT_0014d1f0[n];
}
