/* leon2m FUN_a008ed00 @ 0xa008ed00 (-mcpu=v8 -O3 -g)
 * When p1 == 0xFF sets halfword 0xA802AFDA to 0xFFFF (p2 == 1) or 0 (other p2). Then searches i = 0 .. 15 for the
 * first 2-byte entry of the table at 0x10051F whose byte +1 equals p1; with idx = i & 0xF (no match gives 0), sets
 * (p2 == 1) or clears bit idx of halfword 0xA802AFDA when idx != 0. Same code as FUN_a008ec48 with other
 * constants.
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
