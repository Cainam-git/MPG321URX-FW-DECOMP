/* FUN_a0099560 (leon2s 0xa0099560-0xa0099610, 176 bytes), flags -mcpu=v8 -Os -g.
 * Clears fields of the 0xb0-byte record DAT_a807d680[port & 0xff]: bytes 0x8e, 0x8f, 0x91 and the four
 * bytes 0x92..0x95. Byte 0x90 = 100 / DAT_a8078630 (signed division) when DAT_a8078630 is not 0, else 0.
 * Then FUN_a00b15ac(record + 0x3e, 0, 0x50) clears the 0x50 bytes at +0x3e (tail call).
 * Source form: every access names DAT_a807d680[port & 0xff] directly; GCC keeps the first address in a
 * temporary and a copy for the loop, as the firmware does.
 */
struct R { unsigned char pad[0x3e]; unsigned char blk[0x50]; unsigned char b8e, b8f, b90, b91; unsigned char a92[4]; unsigned char rest[0xb0 - 0x96]; };
extern struct R DAT_a807d680[];
extern unsigned char DAT_a8078630;
extern void FUN_a00b15ac(void *, int, int);

void FUN_a0099560(unsigned int port)
{
    unsigned char i;

    DAT_a807d680[port & 0xff].b8e = 0;
    DAT_a807d680[port & 0xff].b8f = 0;
    DAT_a807d680[port & 0xff].b91 = 0;
    for (i = 0; i < 4; i++)
        DAT_a807d680[port & 0xff].a92[i] = 0;
    if (DAT_a8078630 != 0)
        DAT_a807d680[port & 0xff].b90 = 100 / DAT_a8078630;
    else
        DAT_a807d680[port & 0xff].b90 = 0;
    FUN_a00b15ac(DAT_a807d680[port & 0xff].blk, 0, 0x50);
}
