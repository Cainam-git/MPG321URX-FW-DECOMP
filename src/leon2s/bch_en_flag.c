/* bch_en_flag (leon2s 0xa0075190-0xa0075278, 232 bytes, including the ret/restore tail), flags -mcpu=v8 -Os -g.
 * Works on the 0x898-byte port record ARR_a807a9f0[port]. mode 0: clears halfword +0 and byte +2, clears the
 * three bytes at +0x31 with FUN_a00b15ac(p, 0, 3), toggles byte +0x29 between 0 and 1 and, when bit 1 of
 * DAT_a8078634 is set, prints "[EQ]: Port%c bch_en_flag = %d\n\n" with 'A' + port and byte +0x29.
 * mode 3: only clears the three bytes at +0x31. Any other mode: clears the whole record (0x898 bytes).
 * Source form: switch on mode; the record is a byte row of a two-dimensional array indexed by an unsigned
 * char copy of the port (a structure form schedules the first stores differently).
 */
extern unsigned char ARR_a807a9f0[][0x898];
extern unsigned int DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern void *FUN_a00b15ac(void *, int, unsigned int);

void bch_en_flag(unsigned int port, int mode)
{
    unsigned char p = port;

    switch (mode) {
    case 0:
        *(unsigned short *)ARR_a807a9f0[p] = 0;
        ARR_a807a9f0[p][2] = 0;
        FUN_a00b15ac(&ARR_a807a9f0[p][0x31], 0, 3);
        if (ARR_a807a9f0[p][0x29])
            ARR_a807a9f0[p][0x29] = 0;
        else
            ARR_a807a9f0[p][0x29] = 1;
        if (DAT_a8078634 & 2)
            FUN_a0073044("[EQ]: Port%c bch_en_flag = %d\n\n", (char)(port + 0x41), ARR_a807a9f0[p][0x29]);
        break;
    case 3:
        FUN_a00b15ac(&ARR_a807a9f0[p][0x31], 0, 3);
        break;
    default:
        FUN_a00b15ac(ARR_a807a9f0[p], 0, 0x898);
        break;
    }
}
