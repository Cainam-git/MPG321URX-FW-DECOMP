/* leon2m FUN_a0127a08 @ 0xa0127a08 (-mcpu=v8 -O2 -g)
 * Returns byte 0xA802A443 when (p & 0xff) == 0xff, else byte DAT_a802a440[p & 0xff].
 */
extern unsigned char DAT_a802a440[];
extern unsigned char DAT_a802a443;

unsigned char FUN_a0127a08(unsigned int param_1)
{
    if ((param_1 & 0xff) == 0xff) {
        return DAT_a802a443;
    }
    return DAT_a802a440[param_1 & 0xff];
}
