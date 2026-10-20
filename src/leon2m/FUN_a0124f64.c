/* leon2m FUN_a0124f64 @ 0xa0124f64 (-mcpu=v8 -O2)
 */
extern unsigned char DAT_001a4288[]; /* at 0x1a4288 */

unsigned char FUN_a0124f64(unsigned int param_1)
{
    return DAT_001a4288[(param_1 & 0xff) * 4];
}
