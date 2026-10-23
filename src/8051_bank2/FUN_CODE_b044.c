/* 8051_bank2 FUN_CODE_b044 @ 0xb044 (357 B), OPTIMIZE(8,SPEED) LARGE. LARGE parameters id (generic pointer, 0x0902)
 * and tab (generic pointer, 0x0905, passed in the parameter block); locals i 0x0908, j 0x0909, f 0x090A.
 * Caller: FUN_CODE_0003 (0x00ca), with the three bytes read into its buffer and the CODE table 0xCB8C.
 * tab is a list of 8-byte records; bytes +5, +6, +7 hold three values (a, b, c), and a == 0xFF ends the list.
 * For record i = 0 .. 0xFE: f = 0; each of id[0], id[1], id[2] marks the first of a, b, c it equals whose bit
 * (1, 2, 4) is still clear in f; c == 0xFF also sets bit 4. All three bits set returns i; the end of the list or
 * of the loop returns 0xFF.
 * Source forms the bytes depend on: 'i = 0;' in front of the loop as well (two stores to 0x0908); 'break' at the
 * list end (CPL A / JNZ to the shared 'return 0xFF'); 'continue' after a set bit; j loop 'j != 3'. No aids.
 */
struct rec8 { unsigned char r[5]; unsigned char a; unsigned char b; unsigned char c; };
unsigned char FUN_CODE_b044(unsigned char *id, struct rec8 *tab)
{
    unsigned char i;
    unsigned char j;
    unsigned char f;
    i = 0;
    for (i = 0; i < 0xff; i++) {
        f = 0;
        if (tab[i].a == 0xff) break;
        for (j = 0; j != 3; j++) {
            if (id[j] == tab[i].a && !(f & 1)) {
                f |= 1;
                continue;
            }
            if (id[j] == tab[i].b && !(f & 2)) {
                f |= 2;
                continue;
            }
            if (id[j] == tab[i].c && !(f & 4)) f |= 4;
        }
        if (tab[i].c == 0xff) f |= 4;
        if ((f & 7) == 7) return i;
    }
    return 0xff;
}
