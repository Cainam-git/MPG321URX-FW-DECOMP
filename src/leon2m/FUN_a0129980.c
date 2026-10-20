/* leon2m FUN_a0129980 @ 0xa0129980  bitmask of the port entries whose source is present
 * ( -mcpu=v8 -O3 -g -msoft-float).
 *
 * For each of the 7 port entries (18-byte records at 0xA802E116, the table of the line-rate switch chain): bit i of
 * the halfword 0xA802CA00 = FUN_a0124d24(entry[i] byte +0x10) != 0 AND FUN_a0125140(entry[i] byte +0x10) != 0xFF,
 * else cleared.
 */
struct Entry { unsigned short h0, h2; unsigned char b4, b5; unsigned short h6, h8, ha, hc, he; unsigned char b10, b11; };
extern struct Entry DAT_a802e116[7];
extern unsigned short DAT_a802ca00;
extern unsigned char FUN_a0124d24(unsigned char);
extern unsigned char FUN_a0125140(unsigned char);

void FUN_a0129980(void)
{
    unsigned char i;

    for (i = 0; i <= 6; i++) {
        if (FUN_a0124d24(DAT_a802e116[i].b10) && FUN_a0125140(DAT_a802e116[i].b10) != 0xff)
            DAT_a802ca00 |= 1 << i;
        else
            DAT_a802ca00 &= ~(1 << i);
    }
}
