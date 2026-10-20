/* leon2m FUN_a01298d8 @ 0xa01298d8  bitmask of the port entries whose source is present (hand;
 * BYTE-EXACT at -mcpu=v8 -O3 -g -msoft-float).
 *
 * For each of the 7 port entries (18-byte records at 0xA802E116, the table of the line-rate switch chain): bit i of
 * the halfword 0xA802C9FE = FUN_a0124bf4(entry[i] byte +0x10) != 0 AND FUN_a0125140(entry[i] byte +0x10) != 0xFF,
 * else cleared then FUN_a0136f4c(mask) (tail call).
 */
struct Entry { unsigned short h0, h2; unsigned char b4, b5; unsigned short h6, h8, ha, hc, he; unsigned char b10, b11; };
extern struct Entry DAT_a802e116[7];
extern unsigned short DAT_a802c9fe;
extern unsigned char FUN_a0124bf4(unsigned char);
extern unsigned char FUN_a0125140(unsigned char);
extern void FUN_a0136f4c(unsigned short);

void FUN_a01298d8(void)
{
    unsigned char i;

    for (i = 0; i <= 6; i++) {
        if (FUN_a0124bf4(DAT_a802e116[i].b10) && FUN_a0125140(DAT_a802e116[i].b10) != 0xff)
            DAT_a802c9fe |= 1 << i;
        else
            DAT_a802c9fe &= ~(1 << i);
    }
    FUN_a0136f4c(DAT_a802c9fe);
}
