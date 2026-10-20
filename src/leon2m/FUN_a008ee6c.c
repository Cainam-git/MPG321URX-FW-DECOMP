/* leon2m FUN_a008ee6c @ 0xa008ee6c  MATCH (-mcpu=v8 -O3 -g, twin)
 * Twin of FUN_a008ec48: same code, constants swapped; byte-exact.
 * See FUN_a008ec48 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_0010051f[];
extern unsigned short DAT_a802afc0;

void FUN_a008ee6c(unsigned char param_1, unsigned char param_2)
{
    unsigned int i;
    unsigned int idx;

    param_1 &= 0xff;

    if (param_1 == 0xff) {
        if ((param_2 & 0xff) == 1) {
            DAT_a802afc0 = 0xffff;
        } else {
            DAT_a802afc0 = 0;
        }
    }

    i = 0;
    idx = 0;
    do {
        if (DAT_0010051f[idx * 2 + 1] == param_1)
            break;
        i++;
        idx = (unsigned char)i;
    } while (idx <= 15);

    idx &= 0xf;
    if (idx == 0)
        return;

    if ((param_2 & 0xff) == 1) {
        DAT_a802afc0 |= (1 << idx);
    } else {
        DAT_a802afc0 &= ~(1 << idx);
    }
}
