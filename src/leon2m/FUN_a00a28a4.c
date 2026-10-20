/* leon2m FUN_a00a28a4 @ 0xa00a28a4-0xa00a28bc (6 words).
 * Returns entry n of the byte table at 0x115588 (1-byte entries, n taken as 16 bits). One of the
 * six-word table-lookup routines at 0xa00a2afc-0xa00a2e74 and 0xa00a285c-0xa00a28bc (same form as FUN_a00a2c1c). A leaf
 * routine without a register window.
 */
extern const unsigned char DAT_00115588[];

unsigned char FUN_a00a28a4(unsigned short n)
{
    return DAT_00115588[n];
}
