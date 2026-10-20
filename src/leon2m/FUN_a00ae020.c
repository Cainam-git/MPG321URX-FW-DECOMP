/* leon2m FUN_a00ae020 @ 0xa00ae020-0xa00ae174 (85 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * With m = (byte 0xa802d3eb & 3) * 2 + 4 (0xa802d290 + 0x15b): FUN_a00b3ed0(0, 0, 0, 0); for m == 10
 * FUN_a00b32e4(0, 0, 0x792, 3, 10, 2, 0) and FUN_a00b32e4(1, 0, 0x3092, 3, 0xc, 1, 0x11), else
 * FUN_a00b32e4(0, 0, 0x792, 3, m, 3, 0); then FUN_a00b32e4(0, 0, 0x792, 0x12, m, 3, 0). The byte is stepped back to
 * (byte + 4) % 5; when the new value is 3 or 4, FUN_a00ad970(value / 4) is called. Then FUN_a00ad86c(byte & 3, 1),
 * FUN_a00d9120, FUN_a00d4998 and bit 1 (0x02) of byte 0xa802b08e is set. FUN_a00adec0 steps forwards.
 */
struct St {
    unsigned char pad[0x15b];
    unsigned char b15b;
};
extern struct St DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a00ad86c(unsigned char, unsigned char);
extern void FUN_a00ad970(unsigned char);
extern void FUN_a00b32e4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00b3ed0(unsigned char, unsigned char, unsigned int, unsigned int);
extern void FUN_a00d9120(void);
extern void FUN_a00d4998(void);

void FUN_a00ae020(void)
{
    unsigned char m;

    m = ((DAT_a802d290.b15b & 3) * 2 + 4) & 0xff;
    FUN_a00b3ed0(0, 0, 0, 0);

    if (m == 10) {
        FUN_a00b32e4(0, 0, 0x792, 3, 10, 2, 0);
        FUN_a00b32e4(1, 0, 0x3092, 3, 0xc, 1, 0x11);
    } else {
        FUN_a00b32e4(0, 0, 0x792, 3, m, 3, 0);
    }

    FUN_a00b32e4(0, 0, 0x792, 0x12, m, 3, 0);

    DAT_a802d290.b15b = (DAT_a802d290.b15b + 4) % 5;
    if (DAT_a802d290.b15b == 3 || DAT_a802d290.b15b == 4)
        FUN_a00ad970(DAT_a802d290.b15b / 4);
    FUN_a00ad86c(DAT_a802d290.b15b & 3, 1);
    FUN_a00d9120();
    FUN_a00d4998();
    DAT_a802b08e = DAT_a802b08e | 2;
}
