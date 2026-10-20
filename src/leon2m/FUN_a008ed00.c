/* leon2m FUN_a008ed00 @ 0xa008ed00 (-mcpu=v8 -O3 -g)
 * Twin of FUN_a008ec48: same code, other constants.
 * See FUN_a008ec48 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_0010051f[];
extern unsigned short DAT_a802afda;

void FUN_a008ed00(unsigned char param_1, unsigned char param_2)
{
    unsigned int i;
    unsigned int idx;

    param_1 &= 0xff;

    if (param_1 == 0xff) {
        if ((param_2 & 0xff) == 1) {
            DAT_a802afda = 0xffff;
        } else {
            DAT_a802afda = 0;
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
        DAT_a802afda |= (1 << idx);
    } else {
        DAT_a802afda &= ~(1 << idx);
    }
}
