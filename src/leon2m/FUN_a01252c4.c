/* leon2m FUN_a01252c4 @ 0xa01252c4  MATCH (-mcpu=v8 -O2 -g)
 * Returns byte 0x11 of row (param_1 & 0xFF) of the 22-byte-stride table at 0x1A42A8. The sibling functions read
 * offsets 1 and 2 of the same table.
 */
extern unsigned char DAT_001a42a8[]; /* 0x1a42a8 */

unsigned char FUN_a01252c4(unsigned int param_1)
{
    return DAT_001a42a8[(param_1 & 0xff) * 0x16 + 0x11];
}
