/* leon2m FUN_a0124f7c @ 0xa0124f7c (-mcpu=v8 -O2 -g)
 * Returns byte 1 of entry (param_1 & 0xFF) of the table at 0x1A4288 (4-byte entries). The array-index form gives
 * the firmware's add followed by ldub [%o0+1]; a pointer-cast form gives ldub [%o0+%g1] instead.
 */
extern unsigned char ARR_001a4288[]; /* 0x1a4288 */

unsigned char FUN_a0124f7c(unsigned int param_1)
{
    return ARR_001a4288[(param_1 & 0xff) * 4 + 1];
}
