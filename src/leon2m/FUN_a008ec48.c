/* leon2m FUN_a008ec48 @ 0xa008ec48..0xa008ed00 (184 bytes, 46 words)  BYTE-EXACT
 * Flags: -mcpu=v8 -O3 -g.
 * Judge: jf 100.00 match=True; rawcmp.py 0 mismatches / 46 words (a008ec48 a008ed00).
 * What it does (code facts): keeps a 16-bit mask in DAT_a802afdc. param_1 == 0xff = "all":
 * the mask is first set to 0xffff (param_2 == 1) or 0. Then it searches the 16 two-byte ROM
 * entries at 0x10051f for the one whose second byte (offset +1) equals param_1; the found
 * index (& 0xf, 16 = not found wraps to 0) selects mask bit idx, which is set (param_2 == 1)
 * or cleared. Index 0 changes nothing (early return).
 * Callers: FUN_a0086ae8, FUN_a0091094.
 * Aids: none. The two loop counters (unsigned int i and the u8-truncated idx) are what the fw
 * keeps (%o3 incremented, %o4 = %o3 & 0xff); a single 'unsigned char i' for-loop gives 53.19.
 * From the mechanical draft, only the table name changed DAT_10051f -> DAT_0010051f
 * (the 99.00 cap was the non-address name).
 */
extern unsigned char DAT_0010051f[];
extern unsigned short DAT_a802afdc;

void FUN_a008ec48(unsigned char param_1, unsigned char param_2)
{
    unsigned int i;
    unsigned int idx;

    param_1 &= 0xff;

    if (param_1 == 0xff) {
        if ((param_2 & 0xff) == 1) {
            DAT_a802afdc = 0xffff;
        } else {
            DAT_a802afdc = 0;
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
        DAT_a802afdc |= (1 << idx);
    } else {
        DAT_a802afdc &= ~(1 << idx);
    }
}
