/* leon2m FUN_a0150e80 @ 0xa0150e80-0xa0150f44 (49 words), flags -mcpu=v8 -O3 -g.
 *
 * unsigned short(u8 c, u16 k). v = byte DAT_a802e3e2 / DAT_a802e3e3 / DAT_a802e3e4 for c 0 / 1 / 2, else 0x80.
 * v == 0x80 returns k unchanged. With bit 7 of v clear: k > 0x80 - v gives v + k - 0x80, otherwise 0. With bit 7
 * set: k = v + k - 0x80 (16 bits), limited to 0xff. Returns k.
 * Source form: as FUN_a0150f44 (same code for the bytes DAT_a802e3e5..e7): v is preset to 0x80 before the switch
 * (no default case); the bit-7-clear arm is written first.
 */
extern unsigned char DAT_a802e3e2, DAT_a802e3e3, DAT_a802e3e4;

unsigned short FUN_a0150e80(unsigned char c, unsigned short k)
{
    unsigned char v;

    v = 0x80;
    switch (c) {
    case 0:
        v = DAT_a802e3e2;
        break;
    case 1:
        v = DAT_a802e3e3;
        break;
    case 2:
        v = DAT_a802e3e4;
        break;
    }
    if (v != 0x80) {
        if (!(v & 0x80)) {
            if (k > 0x80 - v)
                k = v + k - 0x80;
            else
                k = 0;
        } else {
            k = v + k - 0x80;
            if (k > 0xff)
                k = 0xff;
        }
    }
    return k;
}
