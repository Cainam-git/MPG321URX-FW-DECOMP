/* leon2m FUN_a01252fc @ 0xa01252fc (-mcpu=v8 -O2 -g)
 * Returns byte +0xC of entry p1 & 0xff of the 0x16-byte table at 0x1A42A8. Same code as FUN_a01252c4 with other
 * constants.
 */
extern unsigned char DAT_001a42a8[]; /* 0x1a42a8 */

unsigned char FUN_a01252fc(unsigned int param_1)
{
    return DAT_001a42a8[(param_1 & 0xff) * 0x16 + 0xc];
}
