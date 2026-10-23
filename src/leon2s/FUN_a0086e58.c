/* FUN_a0086e58 (leon2s 0xa0086e58-0xa0086fb0, 344 bytes), flags -mcpu=v8 -Os -g.
 * Sets bit 7 of out[0], reads 8 bytes into a zeroed local buffer with FUN_a0086400(port, 0x90, 0x200, 7, buf)
 * and clears bit 7 again when that returns 0. Copies buf[0], buf[1], buf[2..5] to out[1], out[2], out[4..7] and
 * splits buf[6] and buf[7] into 2-bit fields: buf[6] bits 0-1, 2-3, 4-5, 6-7 to out[8], out[0xc], out[9],
 * out[0xd]; buf[7] the same way to out[0xa], out[0xe], out[0xb], out[0xf]. For port 0 calls FUN_a0086400(0,
 * 0x90, 0x2003, 0, buf). out[3] = buf[0] when FUN_a00866a4() != 0 and port is 0; otherwise out[3] = 0 and
 * FUN_a00863d4(port, 0x80, 0x2003, 0, buf).
 */
extern unsigned char FUN_a00863d4(unsigned char, unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned char FUN_a0086400(unsigned char, unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned char FUN_a00866a4(void);

void FUN_a0086e58(unsigned char port, unsigned char *out)
{
    unsigned char buf[8] = {0};

    out[0] |= 0x80;
    if (FUN_a0086400(port, 0x90, 0x200, 7, buf) == 0)
        out[0] &= 0x7f;
    out[1] = buf[0];
    out[2] = buf[1];
    out[4] = buf[2];
    out[5] = buf[3];
    out[6] = buf[4];
    out[7] = buf[5];
    out[8] = buf[6] & 3;
    out[0xc] = (buf[6] & 0xc) >> 2;
    out[9] = (buf[6] & 0x30) >> 4;
    out[0xd] = buf[6] >> 6;
    out[0xa] = buf[7] & 3;
    out[0xe] = (buf[7] & 0xc) >> 2;
    out[0xb] = (buf[7] & 0x30) >> 4;
    out[0xf] = buf[7] >> 6;
    if (port == 0)
        FUN_a0086400(0, 0x90, 0x2003, 0, buf);
    if (FUN_a00866a4() != 0 && port == 0)
        out[3] = buf[0];
    else {
        out[3] = 0;
        FUN_a00863d4(port, 0x80, 0x2003, 0, buf);
    }
}
