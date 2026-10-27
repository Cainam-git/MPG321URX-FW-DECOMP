/* FUN_a014e9d8 (leon2m 0xa014e9d8-0xa014ea54, 124 bytes), flags -mcpu=v8 -O3 -g.
 * void (unsigned char x). Looks for the first of the four 4-bit fields of the halfword DAT_a802cc82 (bits 0..3,
 * 4..7, 8..11, 12..15) that equals x and removes it: the fields above it move down by one position (the
 * bits below it are kept); the halfword is unchanged when no field matches.
 * Source form: every access goes to DAT_a802cc82 itself inside the loop; the loop optimiser keeps it in a
 * register (load before the loop, store on both exits).
 */
extern unsigned short DAT_a802cc82;

void FUN_a014e9d8(unsigned char x)
{
    unsigned char i;
    int s;

    for (i = 0; i < 4; i++) {
        s = i * 4;
        if (((DAT_a802cc82 >> s) & 0xf) == x) {
            DAT_a802cc82 = ((DAT_a802cc82 << (16 - s)) >> (16 - s)) | ((DAT_a802cc82 >> (s + 4)) << s);
            break;
        }
    }
}
