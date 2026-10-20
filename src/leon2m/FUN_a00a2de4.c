/* leon2m FUN_a00a2de4 @ 0xa00a2de4-0xa00a2dfc (6 words).
 * Returns entry n of the word table at 0x155950 (4-byte entries, n taken as 16 bits). One of the
 * six-word table-lookup routines at 0xa00a2afc-0xa00a2e74 (same form as FUN_a00a2c1c). A leaf routine without a
 * register window.
 */
extern const unsigned int DAT_00155950[];

unsigned int FUN_a00a2de4(unsigned short n)
{
    return DAT_00155950[n];
}
