/* leon2m FUN_a00be140 @ 0xa00be140-0xa00be1c0 (32 words), flags -mcpu=v8 -O3 -g.
 * Reply builder: writes '0', '0' and a third digit into bytes 7, 8 and 9 of the transmit buffer 0xa802d078: when
 * byte 0xa802d2af (0xa802d290+0x1f) is 0 the digit is '0' + bit 20 of the word 0xa802d33c (0xa802d290+0xac),
 * otherwise '0'. Then the frame header is filled with FUN_a00bac3c(0x4c), the port's receive state is cleared
 * (FUN_a00ba950) and 11 bytes are sent (FUN_a00babe4). No direct callers (reached through a table).
 */
struct R290 { unsigned char p000[0x1f]; unsigned char b01f; unsigned char p020[0xac - 0x20]; unsigned int w0ac; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c(unsigned char);
extern void FUN_a00ba950(unsigned char);
extern void FUN_a00babe4(unsigned char, unsigned char);

void FUN_a00be140(unsigned char port)
{
    DAT_a802d078[7] = '0';
    DAT_a802d078[8] = '0';
    if (DAT_a802d290.b01f == 0)
        DAT_a802d078[9] = ((DAT_a802d290.w0ac >> 20) & 1) + '0';
    else
        DAT_a802d078[9] = '0';
    FUN_a00bac3c(0x4c);
    FUN_a00ba950(port);
    FUN_a00babe4(port, 0xb);
}
