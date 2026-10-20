/* leon2m FUN_a01252fc @ 0xa01252fc (-mcpu=v8 -O2 -g)
 * Twin of FUN_a01252c4: same code, other constants.
 */
extern unsigned char DAT_001a42a8[]; /* 0x1a42a8 */

unsigned char FUN_a01252fc(unsigned int param_1)
{
    return DAT_001a42a8[(param_1 & 0xff) * 0x16 + 0xc];
}
