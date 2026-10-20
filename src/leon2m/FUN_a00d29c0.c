/* leon2m FUN_a00d29c0 @ 0xa00d29c0-0xa00d2a28 (26 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Command handler taking a pointer to a received frame: saves bit 9 of the word 0xa802d290 in byte 0xa8025c56,
 * sets that bit to (frame byte 7 != 0), and when the bit changed calls FUN_a00d5918() and sets bit 1 (0x02) of
 * byte 0xa802b08e. Returns 0xe0. The bit is a 1-bit bit-field.
 */
struct R290 { unsigned int hi : 22, b9 : 1, lo : 9; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern void FUN_a00d5918(void);

int FUN_a00d29c0(unsigned char *p)
{
    DAT_a8025c56 = DAT_a802d290.b9;
    DAT_a802d290.b9 = p[7] != 0;
    if (DAT_a8025c56 != DAT_a802d290.b9) {
        FUN_a00d5918();
        DAT_a802b08e |= 2;
    }
    return 0xe0;
}
