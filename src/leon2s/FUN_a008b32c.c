/* FUN_a008b32c (leon2s 0xa008b32c-0xa008b53c, 528 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 sel, u8 val, u8 en). Stores val to DAT_a8076690[sel], then a jump table (0xa008b308) on sel 0..8:
 * 0: en == 0 sets bits 2..3 of 0xcf011018; otherwise writes the low nibble of 0xcf011200 with val, clears
 *    bits 2..3 of 0xcf011018 when DAT_a807cd80 is 0, and clears bit 5 of 0xcf011008 when val == 1 and
 *    DAT_a8076688 is 0, else sets it.
 * 1: 0xcf01122c = 0xc0, low nibble of 0xcf011204 = val.
 * 2 / 3: 0xcf011230 / 0xcf011234 = 0xc0, low / high nibble of 0xcf011208 = val, FUN_a0091ebc(0 / 1, val).
 * 4 / 5: low / high nibble of 0xcf011210 = val. 6 / 7: low nibble of 0xcf01120c / 0xcf011218 = val, then sets
 *    bit 1 / bit 0 of 0xcf0111c0. 8: low nibble of 0xcf011214 = val.
 * Source form: K&R parameter definition; case 0 reads DAT_a8076688 into an unsigned int f before
 * 'x = v == 1; if (x & ~f)'.
 */
extern unsigned char DAT_a8076690[];
extern unsigned char DAT_a8076688;
extern unsigned char DAT_a807cd80;
extern void FUN_a0091ebc(unsigned char, unsigned char);

#define R(a) (*(volatile unsigned int *)(a))

void FUN_a008b32c(sel, val, en)
    unsigned char sel, val, en;
{
    unsigned char v;
    unsigned int x;
    unsigned int f;

    DAT_a8076690[sel] = val;
    switch (sel) {
    case 0:
        if (en) {
            v = val;
            R(0xcf011200) = (R(0xcf011200) & 0xf0) | (v & 0xf);
            if (DAT_a807cd80 == 0)
                R(0xcf011018) &= ~0xc;
            f = DAT_a8076688;
            x = v == 1;
            if (x & ~f)
                R(0xcf011008) &= ~0x20;
            else
                R(0xcf011008) |= 0x20;
        } else
            R(0xcf011018) |= 0xc;
        break;
    case 1:
        R(0xcf01122c) = 0xc0;
        R(0xcf011204) = (R(0xcf011204) & 0xf0) | (val & 0xf);
        break;
    case 2:
        R(0xcf011230) = 0xc0;
        v = val;
        R(0xcf011208) = (R(0xcf011208) & 0xf0) | (v & 0xf);
        FUN_a0091ebc(0, v);
        break;
    case 3:
        R(0xcf011234) = 0xc0;
        v = val;
        R(0xcf011208) = (R(0xcf011208) & 0xf) | ((v & 0xf) << 4);
        FUN_a0091ebc(1, v);
        break;
    case 4:
        R(0xcf011210) = (R(0xcf011210) & 0xf0) | (val & 0xf);
        break;
    case 5:
        R(0xcf011210) = (R(0xcf011210) & 0xf) | ((val & 0xf) << 4);
        break;
    case 6:
        R(0xcf01120c) = (R(0xcf01120c) & 0xf0) | (val & 0xf);
        R(0xcf0111c0) |= 2;
        break;
    case 7:
        R(0xcf011218) = (R(0xcf011218) & 0xf0) | (val & 0xf);
        R(0xcf0111c0) |= 1;
        break;
    case 8:
        R(0xcf011214) = (R(0xcf011214) & 0xf0) | (val & 0xf);
        break;
    }
}
