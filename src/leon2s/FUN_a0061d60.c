/* FUN_a0061d60 (leon2s 0xa0061d60-0xa0061eb4, 340 bytes), flags -mcpu=v8 -Os -g.
 * Reads 27 bytes into DAT_a8078a40[0..26] with the function pointer DAT_a807cd74(DAT_a8078a38,
 * DAT_a8076270 + i), then fills the record DAT_a8078aa0 (the block FUN_a0062308 initialises) from them:
 * halfword +0x88 = (b[4] & 0x3e) << 4; halfwords +8..+0x18 = b[6..0xe] << 4 (b[8] at +0xc unshifted);
 * byte +0x58 = b[0xf] >> 4; +2 = (b[0xf] & 0xf) << 6 | (b[0x10] & 0xfc); +4 = ((b[0x10] & 3) << 6 | b[0x11]) << 2;
 * the nine halfwords from +0x5a = b[0x12..0x1a] << 2; byte +1 = 0.
 * Source form: the record fields are written in ascending order of the source bytes.
 */
struct Cal { unsigned char b0, b1; unsigned short h[0x2b]; unsigned char b58, b59; unsigned short w[9]; unsigned char pad[0x88 - 0x6c]; unsigned short h88; };
extern struct Cal DAT_a8078aa0;
extern unsigned char DAT_a8078a40[];
extern unsigned char DAT_a8078a38;
extern unsigned short DAT_a8076270;
extern unsigned char (*DAT_a807cd74)(unsigned char, unsigned short);

void FUN_a0061d60(void)
{
    unsigned char i;

    for (i = 0; i < 0x1b; i++)
        DAT_a8078a40[i] = DAT_a807cd74(DAT_a8078a38, DAT_a8076270 + i);
    DAT_a8078aa0.h88 = (DAT_a8078a40[4] & 0x3e) << 4;
    DAT_a8078aa0.h[3] = DAT_a8078a40[6] << 4;
    DAT_a8078aa0.h[4] = DAT_a8078a40[7] << 4;
    DAT_a8078aa0.h[5] = DAT_a8078a40[8];
    DAT_a8078aa0.h[6] = DAT_a8078a40[9] << 4;
    DAT_a8078aa0.h[7] = DAT_a8078a40[0xa] << 4;
    DAT_a8078aa0.h[8] = DAT_a8078a40[0xb] << 4;
    DAT_a8078aa0.h[9] = DAT_a8078a40[0xc] << 4;
    DAT_a8078aa0.h[10] = DAT_a8078a40[0xd] << 4;
    DAT_a8078aa0.h[11] = DAT_a8078a40[0xe] << 4;
    DAT_a8078aa0.b58 = DAT_a8078a40[0xf] >> 4;
    DAT_a8078aa0.h[0] = (DAT_a8078a40[0xf] & 0xf) << 6 | (DAT_a8078a40[0x10] & 0xfc);
    DAT_a8078aa0.h[1] = ((DAT_a8078a40[0x10] & 3) << 6 | DAT_a8078a40[0x11]) << 2;
    for (i = 0; i < 9; i++)
        DAT_a8078aa0.w[i] = DAT_a8078a40[0x12 + i] << 2;
    DAT_a8078aa0.b1 = 0;
}
