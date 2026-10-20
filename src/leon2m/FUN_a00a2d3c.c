/* leon2m FUN_a00a2d3c @ 0xa00a2d3c-0xa00a2d54 (6 words).
 * Returns entry n of the byte table at 0x14b2f0 (1-byte entries, n taken as 16 bits). One of the
 * six-word table-lookup routines at 0xa00a2afc-0xa00a2e74 (same form as FUN_a00a2c1c). A leaf routine without a
 * register window.
 */
extern const unsigned char DAT_0014b2f0[];

unsigned char FUN_a00a2d3c(unsigned short n)
{
    return DAT_0014b2f0[n];
}
