/* leon2m FUN_a01198b4 @ 0xa01198b4  MATCH (-mcpu=v8 -O2 -g)
 * Returns entry (param_1 & 0xFF) of the 256-byte table at 0xA802C9B8. The array-subscript form gives the operand
 * order '[%g1 + %o0]' (base first).
 */
extern unsigned char DAT_a802c9b8[]; /* 0xa802c9b8 */

unsigned char FUN_a01198b4(unsigned int param_1)
{
    return DAT_a802c9b8[param_1 & 0xff];
}
