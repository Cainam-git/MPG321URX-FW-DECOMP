/* leon2m FUN_a00d2a28 @ 0xa00d2a28-0xa00d2a98 (28 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Command handler taking a pointer to a received frame: saves bit 7 of the word 0xa802d47c (0xa802d290+0x1ec) in
 * byte 0xa8025c56, sets that bit to (frame byte 7 != 0), and when the bit changed calls FUN_a00db12c(0) and sets
 * bit 1 (0x02) of byte 0xa802b08e. Returns 0xe0. The bit is a 1-bit bit-field.
 */
struct R290 { unsigned char p000[0x1ec]; unsigned int hi : 24, b7 : 1, lo : 7; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern void FUN_a00db12c(int);

int FUN_a00d2a28(unsigned char *p)
{
    DAT_a8025c56 = DAT_a802d290.b7;
    DAT_a802d290.b7 = p[7] != 0;
    if (DAT_a8025c56 != DAT_a802d290.b7) {
        FUN_a00db12c(0);
        DAT_a802b08e |= 2;
    }
    return 0xe0;
}
