/* leon2m FUN_a00a2cc4 @ 0xa00a2cc4-0xa00a2cdc (6 words).
 * Returns entry n of the word table at 0x13a3fc (4-byte entries, n taken as 16 bits). One of the
 * six-word table-lookup routines at 0xa00a2afc-0xa00a2e74 (same form as FUN_a00a2c1c). A leaf routine without a
 * register window.
 */
extern const unsigned int DAT_0013a3fc[];

unsigned int FUN_a00a2cc4(unsigned short n)
{
    return DAT_0013a3fc[n];
}
