/* leon2m FUN_a012a1a0 @ 0xa012a1a0-0xa012a228 (34 words, leaf), flags -mcpu=v8 -O3 -g.
 * Clears the halfword DAT_a802ca12, then fills the 16 bytes DAT_a802cae0[0..15] from p[0..15] (or with 0x3a when
 * p is null) and adds every byte to DAT_a802ca12. The p loop reloads DAT_a802ca12 each pass (p may alias it).
 * Source form: the null-pointer arm is written first ('if (!p)').
 */
extern unsigned short DAT_a802ca12;
extern unsigned char DAT_a802cae0[];

void FUN_a012a1a0(const unsigned char *p)
{
    unsigned char i;

    DAT_a802ca12 = 0;
    if (!p) {
        for (i = 0; i < 16; i++) {
            DAT_a802cae0[i] = 0x3a;
            DAT_a802ca12 += 0x3a;
        }
    } else {
        for (i = 0; i < 16; i++) {
            unsigned char v = p[i];

            DAT_a802cae0[i] = v;
            DAT_a802ca12 += v;
        }
    }
}
