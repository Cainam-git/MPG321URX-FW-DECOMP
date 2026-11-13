/* ipc_pack_flag_and_bit_index  (FUN_a0132dd8)
 *
 * Pack a flag and the index of the highest set bit of a mask into one byte.
 * Returns: packed byte
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * FUN_a0132dd8 (leon2m 0xa0132dd8-0xa0132e1c, 68 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the result is assigned to an unsigned char local before the return.
 */
/*
 * Pack a flag and a bit number into one byte.
 *   mask: the bit number is the first shift i (0..7) for which mask >> i equals 1: the position of the highest
 *         set bit of mask, or 8 when mask is 0.
 *   flag: only bit 0 is used.
 * Returns (flag & 1) << 4 | bit number. Nothing calls this routine.
 */
unsigned char ipc_pack_flag_and_bit_index(unsigned char mask, unsigned char flag)
{
    unsigned char packed;
    unsigned char i;

    for (i = 0; i < 8; i++)
        if ((mask >> i) == 1)
            break;
    packed = ((flag & 1) << 4) | i;
    return packed;
}
