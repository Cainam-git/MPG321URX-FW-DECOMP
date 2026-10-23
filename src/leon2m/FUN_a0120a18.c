/* leon2m FUN_a0120a18 @ 0xa0120a18-0xa0120b38 (288 bytes)  hfreq of input block 'port' in 100 Hz units
 * Flags -mcpu=v8 -O3 -g.
 * cnt = 13-bit line-period count of input block `port` (register 0x12/0x13, 96 MHz ticks per line).
 * 147 <= cnt <= 8000: rate = (96000000 / cnt + 50) / 100 (integer divide, then ROUNDED to 100 Hz).
 *   e.g. 480p (525 lines) at 60.000 Hz: 31500 Hz -> cnt 3047 -> 315; an input of 31551.9 Hz -> cnt 3042 or
 *   3043
 *   (hardware) -> 316 or 315: this value decides whether such a timing stays inside the FRC Back Check window
 *   (FUN_a0131518).
 * otherwise: second source FUN_a00f92d4(port) == 1 -> 120000 / (reg 0x57 + 1), else 0xFFFF.
 * Then sets register 0x2E bit 7 (FUN_a00f2068) when rate <= 332 (33.2 kHz), clears it otherwise. Result kept in
 * DAT_a802c9e8.
 */
extern unsigned short DAT_a802c9e8;
extern unsigned short FUN_a00f21f0(unsigned char port, unsigned char reg);
extern unsigned char FUN_a00f92d4(unsigned char port);
extern unsigned short FUN_a00f1ce4(unsigned char port, unsigned char reg);
extern void FUN_a00f2068(unsigned char port, unsigned char reg, unsigned char mask, unsigned char val);

unsigned short FUN_a0120a18(unsigned char port)
{
    unsigned int cnt;

    cnt = FUN_a00f21f0(port, 0x12) & 0x1fff;
    if ((unsigned short)(cnt - 147) > 0x1ead) {
        /* count out of range (no measurement): second source, or 0xFFFF */
        if (FUN_a00f92d4(port) == 1)
            DAT_a802c9e8 = 120000 / (unsigned short)(FUN_a00f1ce4(port, 0x57) + 1);
        else
            DAT_a802c9e8 = 0xffff;
    } else
        DAT_a802c9e8 = (96000000 / cnt + 50) / 100;
    if (DAT_a802c9e8 <= 0x14c)
        FUN_a00f2068(port, 0x2e, 0x80, 1);
    else
        FUN_a00f2068(port, 0x2e, 0x80, 0);
    return DAT_a802c9e8;
}
