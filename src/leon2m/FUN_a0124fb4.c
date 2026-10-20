/* leon2m FUN_a0124fb4 @ 0xa0124fb4 (-mcpu=v8 -O2 -g)
 * Returns byte 3 of the 4-byte entry (param_1 & 0xFF) of the table at 0x1A4288. The table is a plain
 * (non-volatile) unsigned char array, like DAT_001a42a8 in FUN_a01252fc.
 */
extern unsigned char DAT_001a4288[]; /* 0x1a4288 */

unsigned char FUN_a0124fb4(unsigned int param_1)
{
    return DAT_001a4288[(param_1 & 0xff) * 4 + 3];
}
