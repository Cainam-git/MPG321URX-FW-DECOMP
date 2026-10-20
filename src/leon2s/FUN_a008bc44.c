/* FUN_a008bc44 (leon2s 0xa008bc44-0xa008bd1c, 216 bytes), flags -mcpu=v8 -Os -g.
 * For i = 0 and 1: when bit 6 of FUN_a00a6bb8(i, 0x50) is set, clears byte i of DAT_a80766a0. Otherwise, when
 * FUN_a00b2064() minus word i of DAT_a8078b4c is above 50, stores a new FUN_a00b2064() value there, sets byte
 * i of DAT_a80766a0 to 1 when FUN_a008b8d4(i) is non-zero (else 0) and calls FUN_a00a6fc0(i, 4, 0x40).
 * Returns byte 0 | byte 1 << 1 of DAT_a80766a0.
 * Source form: byte 0 is read through the inlined static helper byte0(); a direct DAT_a80766a0[0] read swaps
 * the registers of the two final loads.
 */
extern unsigned char DAT_a80766a0[];
extern unsigned int DAT_a8078b4c[];
extern unsigned int FUN_a00a6bb8(unsigned int param_1, unsigned short param_2);
extern unsigned int FUN_a00b2064(void);
extern unsigned char FUN_a008b8d4(unsigned int);
extern void FUN_a00a6fc0(unsigned int, unsigned short, unsigned int);

static unsigned char byte0(const unsigned char *a)
{
    return a[0];
}

unsigned char FUN_a008bc44(void)
{
    unsigned char i = 0;

    for (i = 0; i < 2; i++) {
        if (!(FUN_a00a6bb8(i, 0x50) & 0x40)) {
            if (FUN_a00b2064() - DAT_a8078b4c[i] > 50) {
                DAT_a8078b4c[i] = FUN_a00b2064();
                if (FUN_a008b8d4(i) == 0)
                    DAT_a80766a0[i] = 0;
                else
                    DAT_a80766a0[i] = 1;
                FUN_a00a6fc0(i, 4, 0x40);
            }
        } else {
            DAT_a80766a0[i] = 0;
        }
    }
    return byte0(DAT_a80766a0) | DAT_a80766a0[1] << 1;
}
