/* leon2m FUN_a00a2c1c @ 0xa00a2c1c (-mcpu=v8 -O2)
 * Returns entry n of the byte table at 0x12e2f8 (1-byte entries, n taken as 16 bits). One of the six-word
 * table-lookup routines at 0xa00a2afc-0xa00a2e74. A leaf routine without a register window.
 */
extern unsigned char DAT_0012e2f8[]; /* 0x12e2f8 */

unsigned char FUN_a00a2c1c(unsigned short param_1)
{
    return DAT_0012e2f8[param_1];
}
