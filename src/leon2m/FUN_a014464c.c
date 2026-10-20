/* leon2m FUN_a014464c @ 0xa014464c (-mcpu=v8 -O2 -g)
 * Loads the byte at index 2 * (param_1 & 0xFF) of the table at 0x1A6DB2 and passes it through FUN_a0125198,
 * FUN_a0142218 and FUN_a01421c4, masking each result to a byte; returns the last result. The call chain is the
 * same as in FUN_a0144574, with the table lookup in front.
 */
extern int FUN_a0125198(int);  /* 0xa0125198 */
extern int FUN_a0142218(int);  /* 0xa0142218 */
extern int FUN_a01421c4(int);  /* 0xa01421c4 */
extern const unsigned char DAT_001a6db2[];  /* 0x1a6db2 */

int FUN_a014464c(int param_1)
{
    int r1 = FUN_a0125198(DAT_001a6db2[(param_1 & 0xff) * 2]);
    int r2 = FUN_a0142218(r1 & 0xff);
    int r3 = FUN_a01421c4(r2 & 0xff);
    return r3 & 0xff;
}
