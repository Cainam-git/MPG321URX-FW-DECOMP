/* leon2m FUN_a0124f98 @ 0xa0124f98 (-mcpu=v8 -O2 -g)
 * Returns byte 2 of the 4-byte entry (param_1 & 0xFF) of the table at 0x1A4288 (ldub with displacement 2).
 */
extern unsigned char ARR_001a4288[]; /* 0x1a4288 */

unsigned char FUN_a0124f98(unsigned int param_1)
{
    return ARR_001a4288[(param_1 & 0xff) * 4 + 2];
}
