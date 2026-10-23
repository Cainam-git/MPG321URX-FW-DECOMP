/* leon2m FUN_a00a2c04 @ 0xa00a2c04 (-mcpu=v8 -O2)
 * Returns entry n of the word table at 0x125928 (4-byte entries, n taken as 16 bits). One of the six-word
 * table-lookup routines at 0xa00a2afc-0xa00a2e74 (same form as FUN_a00a2c1c). A leaf routine without a register window.
 */
/* extern array at 0x125928 (DRAM) */
extern unsigned int DAT_00125928[];

unsigned int FUN_a00a2c04(unsigned short param_1)
{
    return DAT_00125928[param_1];
}
