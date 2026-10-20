/* leon2m FUN_a01250a8 @ 0xa01250a8 (-mcpu=v8 -O2 -g)
 * 
 */
extern unsigned char DAT_001a42a8[]; /* 0x1a42a8 */

unsigned char FUN_a01250a8(unsigned int param_1)
{
    return DAT_001a42a8[(param_1 & 0xff) * 0x16 + 1];
}
