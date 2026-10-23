/* leon2m FUN_a008ee6c @ 0xa008ee6c (-mcpu=v8 -O3 -g)
 * When p1 == 0xFF sets halfword 0xA802AFC0 to 0xFFFF (p2 == 1) or 0 (other p2). Then searches i = 0 .. 15 for the
 * first 2-byte entry of the table at 0x10051F whose byte +1 equals p1; with idx = i & 0xF (no match gives 0), sets
 * (p2 == 1) or clears bit idx of halfword 0xA802AFC0 when idx != 0. Same code as FUN_a008ec48 with other
 * constants.
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
