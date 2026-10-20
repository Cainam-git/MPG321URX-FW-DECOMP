/* leon2m FUN_a0142e8c @ 0xa0142e8c (-mcpu=v8 -O2 -g)
 * Returns byte 9 of row (param_1 & 0xFF) of the 42-byte-stride (0x2A) table at 0xa802e224.
 */
extern unsigned char ARR_a802e224[]; /* 0xa802e224 */

unsigned char FUN_a0142e8c(unsigned int param_1)
{
    return ARR_a802e224[(param_1 & 0xff) * 0x2a + 9];
}
