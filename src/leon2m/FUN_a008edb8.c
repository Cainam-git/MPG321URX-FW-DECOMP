/* leon2m FUN_a008edb8 @ 0xa008edb8-0xa008ee6c (45 words), flags -mcpu=v8 -O3 -g.
 * Keeps a 16-bit mask in DAT_a802afd8. id == 0xff with on == 0 clears the mask first. Then it searches the 16
 * two-byte ROM entries at 0x10051f for the one whose second byte (offset +1) equals id; the found index (& 0xf,
 * 16 = not found wraps to 0) selects entry idx: index 0 changes nothing (early return), otherwise
 * DAT_a802afc8[idx] = on and mask bit idx is set (on != 0) or cleared.
 * Source form: as FUN_a008ec48 (same table search): two loop counters, unsigned int i and the u8-truncated idx.
 */
extern const unsigned char DAT_0010051f[];
extern unsigned char DAT_a802afc8[];
extern unsigned short DAT_a802afd8;

void FUN_a008edb8(unsigned char id, unsigned char on)
{
    unsigned int i;
    unsigned int idx;

    if (id == 0xff) {
        if (on == 0)
            DAT_a802afd8 = 0;
    }

    i = 0;
    idx = 0;
    do {
        if (DAT_0010051f[idx * 2 + 1] == id)
            break;
        i++;
        idx = (unsigned char)i;
    } while (idx <= 15);

    idx &= 0xf;
    if (idx == 0)
        return;

    DAT_a802afc8[idx] = on;
    if (on) {
        DAT_a802afd8 |= (1 << idx);
    } else {
        DAT_a802afd8 &= ~(1 << idx);
    }
}
