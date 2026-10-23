/* leon2m FUN_a012cd68 @ 0xa012cd68-0xa012ce18 (44 words).
 * Port i, when bit i of DAT_a802c9fb is set (FUN_a0125350(i)): on == 0 -> FUN_a0133f84(1 << i); otherwise
 * x = FUN_a0125380(i), k = byte 0xA802E1A0[0x1b + i] and FUN_a0133fbc(1 << i, len, x >> 7) with len =
 * DAT_001a6ad8[k], or, for k == 0xff, nibble i of DAT_a802cb08 times 128. The same per-port step as the loop of
 * FUN_a012c188. Called by FUN_a01519d8 and FUN_a0151aa4.
 * FUN_a0125350 returns 0 or 1; it is declared here with an unsigned char result (the code tests the low byte).
 */
extern unsigned int DAT_a802cb08;
extern unsigned char DAT_a802e1a0[];
extern const unsigned short DAT_001a6ad8[];
extern unsigned char FUN_a0125350(unsigned char);
extern unsigned short FUN_a0125380(unsigned char);
extern void FUN_a0133f84(unsigned char);
extern void FUN_a0133fbc(unsigned char, unsigned short, unsigned char);

void FUN_a012cd68(unsigned char i, unsigned char on)
{
    unsigned short x, len;

    if (FUN_a0125350(i)) {
        if (on) {
            x = FUN_a0125380(i);
            if (DAT_a802e1a0[0x1b + i] == 0xff)
                len = ((DAT_a802cb08 >> (i * 4)) & 0xf) << 7;
            else
                len = DAT_001a6ad8[DAT_a802e1a0[0x1b + i]];
            FUN_a0133fbc(1 << i, len, x >> 7);
        } else
            FUN_a0133f84(1 << i);
    }
}
