/* FUN_a014e9d8 (leon2m 0xa014e9d8-0xa014ea54, 124 bytes), flags -mcpu=v8 -O3 -g.
 * void (unsigned char x). Finds the first of the four 4-bit fields of the halfword DAT_a802cc82 (lowest first,
 * s = 4 * field index) that equals x and stores ((v << (16 - s)) >> (16 - s)) | ((v >> (s + 4)) << s) back
 * (int arithmetic with arithmetic right shifts): for s > 0 the fields above the match move down by four bits
 * and the bits below it are kept; for s = 0 the result is v | (v >> 4). The halfword is unchanged when no
 * field matches.
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
